#include "Common.h"

#include "gtest/gtest.h"

#include "coil/DefaultLexer.h"
#include "coil/String.h"

#include <list>
#include <random>

namespace
{
    coil::Value createValue(coil::StringView input)
    {
        return coil::Value{input};
    }

    template<typename... Args>
    auto args(Args&&... args)
    {
        return std::vector<coil::Value>{coil::Value{std::forward<Args>(args)}...};
    }

    coil::ExecutionInput createInput(coil::StringView name, std::vector<coil::Value> args, std::vector<coil::NamedValue> namedArgs)
    {
        coil::ExecutionInput input;
        input.name = name;
        input.arguments = convertVector(std::move(args));
        input.namedArguments = convertVector(std::move(namedArgs));

        return input;
    }

    template<typename RandomEngine>
    coil::String generateRandomString(RandomEngine& engine, std::size_t generation, bool allowEmpty, bool allowNumber, bool allowSpaces)
    {
        std::bernoulli_distribution isEmptyDist{allowEmpty ? 0.5f : 0.0f};

        if (isEmptyDist(engine))
            return "";

        std::bernoulli_distribution isNumberDist{allowNumber ? 0.5f : 0.0f};
        std::bernoulli_distribution containsSpacesDist{allowSpaces ? 0.5f : 0.0f};

        if (isNumberDist(engine))
            return "3.14";

        coil::String base = containsSpacesDist(engine) ? "str with spaces" : "str";

        return base + coil::toString(generation);
    }

    template<typename RandomEngine>
    auto addRandomSpaces(std::ostream& os, RandomEngine& engine)
    {
        std::uniform_int_distribution<std::size_t> amountDist{0, 2};
        std::size_t amount = amountDist(engine);
        for (std::size_t i = 0; i < amount; i++)
            os << ' ';
    };

    template<typename RandomEngine>
    coil::ExecutionInput generateRandomInput(RandomEngine& engine)
    {
        static std::list<coil::String> storage;
        std::size_t generation = 0;

        coil::ExecutionInput input;

        std::size_t const argsMax = 3;
        std::size_t const subargsMax = 3;

        std::uniform_int_distribution<std::size_t> argsCountDist{0, argsMax};
        std::uniform_int_distribution<std::size_t> compoundArgsCountDist{1, subargsMax};

        std::size_t argsCount = argsCountDist(engine);
        std::size_t namedArgsCount = argsCountDist(engine);
        std::size_t compoundArgsCount = compoundArgsCountDist(engine);

        storage.clear();

        auto addToStorage = [](coil::String str) {
            storage.push_back(std::move(str));
            return coil::StringView{storage.back()};
        };

        auto generateNewString = [&addToStorage, &engine, &generation](bool allowEmpty, bool allowNumber, bool allowSpaces) {
            return addToStorage(generateRandomString(engine, generation++, allowEmpty, allowNumber, allowSpaces));
        };

        auto generateIdentifierString = [&generateNewString]() { return generateNewString(false, false, false); };
        auto generateValueString = [&generateNewString]() { return generateNewString(true, true, true); };

        auto generateCompoundArgs = [&generateValueString](std::size_t count) {
            coil::Vector<coil::StringView> subvalues;

            for (std::size_t i = 0; i < count; i++)
                subvalues.pushBack(generateValueString());

            return coil::Value(std::move(subvalues));
        };

        input.name = generateIdentifierString();

        for (std::size_t i = 0; i < argsCount; i++)
            input.arguments.pushBack(generateCompoundArgs(compoundArgsCount));

        for (std::size_t i = 0; i < namedArgsCount; i++)
        {
            auto key = generateIdentifierString();
            auto value = generateCompoundArgs(compoundArgsCount);
            input.namedArguments.pushBack(coil::NamedValue{ key, value });
        }

        return input;
    }

    template<typename RandomEngine>
    coil::String generateRandomInputString(RandomEngine& engine, coil::ExecutionInput const& input)
    {
        std::stringstream ss;

        auto randomSpaces = [&ss, &engine]() { addRandomSpaces(ss, engine); };

        auto subvalueToStream = [&ss](coil::StringView subvalue) {
            bool hasSpaces = std::find(subvalue.begin(), subvalue.end(), ' ') != subvalue.end();
            bool isEmpty = subvalue.empty();
            if (hasSpaces || isEmpty)
                ss << '"' << subvalue << '"';
            else
                ss << subvalue;
        };

        auto valueToStream = [&ss, &randomSpaces, &subvalueToStream](coil::Value const& value) {
            if (value.subvalues.empty())
                return;

            if (value.subvalues.size() == 1)
            {
                subvalueToStream(value.subvalues[0]);
                return;
            }

            ss << '(';
            randomSpaces();

            for (coil::StringView subvalue : value.subvalues)
            {
                subvalueToStream(subvalue);
                ss << ' ';
                randomSpaces();
            }

            ss << ')';
        };

        randomSpaces();
        ss << input.name << ' ';
        randomSpaces();

        for (auto const& arg : input.arguments)
        {
            valueToStream(arg);
            ss << ' ';
            randomSpaces();
        }

        for (auto const& pair : input.namedArguments)
        {
            auto const& key = pair.key();
            auto const& arg = pair.value();

            ss << key;
            randomSpaces();
            ss << "=";
            randomSpaces();
            valueToStream(arg);
            ss << ' ';
            randomSpaces();
        }

        randomSpaces();

        std::string res = ss.str();
        return coil::String{ res.data(), res.size() };
    }
}

TEST(LexerTest, TestSpacesEmpty)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse(""), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse(" "), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse("\t"), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse("  "), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse("\t\t"), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse(" \t"), createInput("", {}, {}));
    EXPECT_EQ(lexer.parse("\t "), createInput("", {}, {}));
}

TEST(LexerTest, TestSpacesNoArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse(" foo.bar.func "), createInput("foo.bar.func", {}, {}));
}

TEST(LexerTest, TestSpacesArgs)
{
    coil::DefaultLexer lexer;

    auto input = createInput("func", args("arg1", "arg2"), {});

    EXPECT_EQ(lexer.parse(" func arg1 arg2 "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 arg2 "), input);
    EXPECT_EQ(lexer.parse(" func arg1  arg2 "), input);
}

TEST(LexerTest, TestSpacesNamedArgs)
{
    coil::DefaultLexer lexer;

    auto input = createInput("func", args(), {{"arg1", createValue("foo")}, {"arg2", createValue("bar")}});

    EXPECT_EQ(lexer.parse(" func arg1=foo arg2=bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1=foo arg2=bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 =foo arg2=bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1= foo arg2=bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 = foo arg2=bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 = foo arg2 =bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 = foo arg2= bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 = foo arg2 = bar "), input);
    EXPECT_EQ(lexer.parse(" func  arg1 = foo  arg2 = bar "), input);
}

TEST(LexerTests, TestCompoundArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg1,arg2"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func (arg1 arg2)"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func (arg1,arg2)"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func (arg1, arg2)"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func (arg1 , arg2)"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func ( arg1 , arg2 )"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
    EXPECT_EQ(lexer.parse("func ( arg1 arg2 )"), createInput("func", {createVectorValue({"arg1", "arg2"})}, {}));
}

TEST(LexerTests, TestCompoundNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg=arg1,arg2"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=(arg1 arg2)"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=(arg1,arg2)"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=(arg1, arg2)"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=(arg1 , arg2)"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=( arg1 , arg2 )"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
    EXPECT_EQ(lexer.parse("func arg=( arg1 arg2 )"), createInput("func", args(), {{"arg", createVectorValue({"arg1", "arg2"})}}));
}

TEST(LexerTests, TestCompoundNamedArgsEdgeCases)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg=arg(um)ent"), createInput("func", args("um", "ent"), {{"arg", createValue("arg")}}));
    EXPECT_EQ(lexer.parse("func arg=()"), createInput("func", args(), {{"arg", coil::Value{}}}));
    EXPECT_EQ(lexer.parse("func arg=( )"), createInput("func", args(), {{"arg", coil::Value{}}}));
    EXPECT_EQ(lexer.parse("func arg=(,)"), createInput("func", args(), {{"arg", coil::Value{}}}));
    EXPECT_EQ(lexer.parse("func arg=( , )"), createInput("func", args(), {{"arg", coil::Value{}}}));
}

TEST(LexerTests, TestEmpty)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse(""), createInput("", {}, {}));
}

TEST(LexerTests, TestNoArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func"), createInput("func", {}, {}));
}

TEST(LexerTests, TestArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg1"), createInput("func", args("arg1"), {}));
    EXPECT_EQ(lexer.parse("func arg1 arg2"), createInput("func", args("arg1", "arg2"), {}));
}

TEST(LexerTests, TestNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg1=foo"), createInput("func", args(), {{"arg1", createValue("foo")}}));
    EXPECT_EQ(lexer.parse("func arg1=foo arg2=bar"), createInput("func", args(), {{"arg1", createValue("foo")}, {"arg2", createValue("bar")}}));
}

TEST(LexerTests, TestArgsAndNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg1 arg2 arg3=foo arg4=bar"), createInput("func", args("arg1", "arg2"), {{"arg3", createValue("foo")}, {"arg4", createValue("bar")}}));
}

TEST(LexerTests, TestIntegerArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func 1"), createInput("foo.bar.func", args("1"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 1 arg"), createInput("foo.bar.func", args("1", "arg"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 1 arg 2"), createInput("foo.bar.func", args("1", "arg", "2"), {}));
}

TEST(LexerTests, TestIntegerNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func arg1=1"), createInput("foo.bar.func", args(), {{"arg1", createValue("1")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=1 arg2=arg"), createInput("foo.bar.func", args(), {{"arg1", createValue("1")}, {"arg2", createValue("arg")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=1 arg2=arg arg3=2"), createInput("foo.bar.func", args(), {{"arg1", createValue("1")}, {"arg2", createValue("arg")}, {"arg3", createValue("2")}}));
}

TEST(LexerTests, TestFloatArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func 3.14"), createInput("foo.bar.func", args("3.14"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 3.14 arg"), createInput("foo.bar.func", args("3.14", "arg"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 3.14 arg 2.0"), createInput("foo.bar.func", args("3.14", "arg", "2.0"), {}));
}

TEST(LexerTests, TestFloatNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func arg1=3.14"), createInput("foo.bar.func", {}, {{"arg1", createValue("3.14")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=3.14 arg2=arg"), createInput("foo.bar.func", {}, {{"arg1", createValue("3.14")}, {"arg2", createValue("arg")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=3.14 arg2=arg arg3=2.0"), createInput("foo.bar.func", {}, {{"arg1", createValue("3.14")}, {"arg2", createValue("arg")}, {"arg3", createValue("2.0")}}));
}

TEST(LexerTests, TestShortFloatArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func .14"), createInput("foo.bar.func", args(".14"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func .14 arg"), createInput("foo.bar.func", args(".14", "arg"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func .14 arg .0"), createInput("foo.bar.func", args(".14", "arg", ".0"), {}));
}

TEST(LexerTests, TestShortFloatNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("foo.bar.func arg1=.14"), createInput("foo.bar.func", args(), {{"arg1", createValue(".14")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=.14 arg2=arg"), createInput("foo.bar.func", args(), {{"arg1", createValue(".14")}, {"arg2", createValue("arg")}}));
    EXPECT_EQ(lexer.parse("foo.bar.func arg1=.14 arg2=arg arg3=.0"), createInput("foo.bar.func", args(), {{"arg1", createValue(".14")}, {"arg2", createValue("arg")}, {"arg3", createValue(".0")}}));
}

TEST(LexerTests, TestStrings)
{
    coil::DefaultLexer lexer;
    EXPECT_EQ(lexer.parse("foo.bar.func foo 'bar' baz"), createInput("foo.bar.func", args("foo", "bar", "baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func foo ' bar ' baz"), createInput("foo.bar.func", args("foo", " bar ", "baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 'foo bar baz'"), createInput("foo.bar.func", args("foo bar baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 'foo,bar,baz'"), createInput("foo.bar.func", args("foo,bar,baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 'foo;bar;baz'"), createInput("foo.bar.func", args("foo;bar;baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 'foo|bar|baz'"), createInput("foo.bar.func", args("foo|bar|baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func 'foo=bar=baz'"), createInput("foo.bar.func", args("foo=bar=baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func '(foo bar baz)'"), createInput("foo.bar.func", args("(foo bar baz)"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func ('foo   bar' baz)"), createInput("foo.bar.func", {createVectorValue({"foo   bar", "baz"})}, {}));

    EXPECT_EQ(lexer.parse("foo.bar.func foo \"bar\" baz"), createInput("foo.bar.func", args("foo", "bar", "baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func foo \" bar \" baz"), createInput("foo.bar.func", args("foo", " bar ", "baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"foo bar baz\""), createInput("foo.bar.func", args("foo bar baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"foo,bar,baz\""), createInput("foo.bar.func", args("foo,bar,baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"foo;bar;baz\""), createInput("foo.bar.func", args("foo;bar;baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"foo|bar|baz\""), createInput("foo.bar.func", args("foo|bar|baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"foo=bar=baz\""), createInput("foo.bar.func", args("foo=bar=baz"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func \"(foo bar baz)\""), createInput("foo.bar.func", args("(foo bar baz)"), {}));
    EXPECT_EQ(lexer.parse("foo.bar.func (\"foo   bar\" baz)"), createInput("foo.bar.func", {createVectorValue({"foo   bar", "baz"})}, {}));
}

TEST(LexerTests, TestErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("=val"), coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));
    EXPECT_EQ(lexer.parse("command=arg"), coil::makeUnexpected("Unexpected token '=': no name for the named argument is provided"));
    EXPECT_EQ(lexer.parse("command arg=val=foo"), coil::makeUnexpected("Unexpected token '=': no name for the named argument is provided"));
    EXPECT_EQ(lexer.parse("command arg="), coil::makeUnexpected("Expected an argument value, found end of string"));
    EXPECT_EQ(lexer.parse("command arg=="), coil::makeUnexpected("Expected an argument value, found '='"));
    EXPECT_EQ(lexer.parse("command arg==value"), coil::makeUnexpected("Expected an argument value, found '='"));
    EXPECT_EQ(lexer.parse("==value"), coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));
}

TEST(LexerTests, TestCompoundArgsErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func (arg,arg"), coil::makeUnexpected("Token '(' doesn't have a corresponding opening/closing token"));
    EXPECT_EQ(lexer.parse("func arg,arg)"), coil::makeUnexpected("Token ')' doesn't have a corresponding opening/closing token"));

    EXPECT_EQ(lexer.parse("func arg(ument"), coil::makeUnexpected("Token '(' doesn't have a corresponding opening/closing token"));
    EXPECT_EQ(lexer.parse("func argum)ent"), coil::makeUnexpected("Token ')' doesn't have a corresponding opening/closing token"));

    EXPECT_EQ(lexer.parse("func ("), coil::makeUnexpected("Token '(' doesn't have a corresponding opening/closing token"));
    EXPECT_EQ(lexer.parse("func )"), coil::makeUnexpected("Token ')' doesn't have a corresponding opening/closing token"));
}

TEST(LexerTests, TestStringsErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer.parse("func arg,arg\""), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));
    EXPECT_EQ(lexer.parse("func arg arg\""), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));
    EXPECT_EQ(lexer.parse("func \"arg,arg"), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));
    EXPECT_EQ(lexer.parse("func \"arg arg"), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));

    EXPECT_EQ(lexer.parse("func argum\"ent"), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));

    EXPECT_EQ(lexer.parse("func \""), coil::makeUnexpected("Token '\"' doesn't have a corresponding opening/closing quote"));
}

TEST(LexerTests, TestGenerated)
{
    std::default_random_engine engine{};
    std::size_t const generationsCount = 10000;
    coil::DefaultLexer lexer;

    auto test = [](auto const&, auto actualInput, coil::ExecutionInput const& expectedInput) { return actualInput == expectedInput; };

    for (std::size_t i = 0; i < generationsCount; i++)
    {
        auto input = generateRandomInput(engine);
        auto str = generateRandomInputString(engine, input);

        EXPECT_PRED3(test, str, lexer.parse(str), input);
    }
}
