#include "gtest/gtest.h"
#include "Common.h"

#include <random>

namespace
{
    coil::ArgValue createValue(std::string_view input)
    {
        return coil::ArgValue{input};
    }

    template<typename... Args>
    auto args(Args&&... args)
    {
        return std::vector<coil::ArgValue>{ coil::ArgValue{ std::forward<Args>(args) }... };
    }

    coil::ExecutionInput createInput(std::string_view name, std::vector<coil::ArgValue> args, std::vector<std::pair<std::string_view, coil::ArgValue>> namedArgs)
    {
        coil::ExecutionInput input;
        input.name = name;
        input.arguments = std::move(args);
        input.namedArguments = std::move(namedArgs);

        return input;
    }

    template<typename RandomEngine>
    std::string generateRandomString(RandomEngine& engine, std::size_t generation, bool allowEmpty, bool allowNumber)
    {
        std::bernoulli_distribution isEmptyDist{ allowEmpty ? 0.5f : 0.0f };

        if (isEmptyDist(engine))
            return "";

        std::bernoulli_distribution isNumberDist{ allowNumber ? 0.5f : 0.0f };

        if (isNumberDist(engine))
            return "3.14";

        return std::string("str") + std::to_string(generation);
    }

    template<typename RandomEngine>
    auto addRandomSpaces(std::ostream& os, RandomEngine& engine)
    {
        std::uniform_int_distribution<std::size_t> amountDist{ 0, 2 };
        std::size_t amount = amountDist(engine);
        for (std::size_t i = 0; i < amount; i++)
            os << ' ';
    };

    template<typename RandomEngine>
    coil::ExecutionInput generateRandomInput(RandomEngine& engine)
    {
        static std::vector<std::string> storage;
        std::size_t generation = 0;

        coil::ExecutionInput input;

        std::size_t const argsMax = 3;
        std::size_t const subargsMax = 3;

        std::uniform_int_distribution<std::size_t> argsCountDist{ 0, argsMax };
        std::uniform_int_distribution<std::size_t> compoundArgsCountDist{ 1, subargsMax };

        std::size_t argsCount = argsCountDist(engine);
        std::size_t namedArgsCount = argsCountDist(engine);
        std::size_t compoundArgsCount = compoundArgsCountDist(engine);

        storage.clear();
        std::size_t const maxStorageSize = 1 + argsMax + argsMax * (2 + subargsMax);
        storage.reserve(maxStorageSize);

        auto addToStorage = [](std::string str)
        {
            // to prevent storage reallocation
            if (storage.size() >= storage.capacity())
                throw std::runtime_error("generateRandomInput: Maximum allocations reached");

            storage.push_back(std::move(str));
            return std::string_view{ storage.back() };
        };

        auto generateNewString = [&addToStorage, &engine, &generation](bool allowEmpty, bool allowNumber)
        {
            return addToStorage(generateRandomString(engine, generation++, allowEmpty, allowNumber));
        };

        auto generateCompoundArgs = [&generateNewString](std::size_t count)
        {
            std::vector<std::string_view> subvalues;

            for (std::size_t i = 0; i < count; i++)
                subvalues.push_back(generateNewString(false, true));

            return coil::ArgValue(std::move(subvalues));
        };

        input.name = generateNewString(false, false);

        for (std::size_t i = 0; i < argsCount; i++)
            input.arguments.push_back(createValue(generateNewString(false, true)));

        for (std::size_t i = 0; i < namedArgsCount; i++)
        {
            auto key = generateNewString(false, false);
            auto value = generateCompoundArgs(compoundArgsCount);
            input.namedArguments.emplace_back(key, value);
        }

        return input;
    }

    template<typename RandomEngine>
    std::string generateRandomInputString(RandomEngine& engine, coil::ExecutionInput const& input)
    {
        std::stringstream ss;

        auto randomSpaces = [&ss, &engine]() { addRandomSpaces(ss, engine); };

        auto valueToStream = [&ss, &randomSpaces](coil::ArgValue const& value)
        {
            std::size_t count = value.subvalues.size();

            if (count == 0)
                return;

            if (count == 1)
            {
                ss << value.subvalues[0];
                return;
            }

            ss << '(';
            randomSpaces();

            for (std::string_view subvalue : value.subvalues)
            {
                ss << subvalue << ' ';
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
            auto const& key = pair.first;
            auto const& arg = pair.second;

            ss << key;
            randomSpaces();
            ss << "=";
            randomSpaces();
            valueToStream(arg);
            ss << ' ';
            randomSpaces();
        }

        randomSpaces();

        return ss.str();
    }
}

TEST(LexerTest, TestSpacesEmpty)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer(""), createInput("", {}, {}));
    EXPECT_EQ(lexer(" "), createInput("", {}, {}));
    EXPECT_EQ(lexer("\t"), createInput("", {}, {}));
    EXPECT_EQ(lexer("  "), createInput("", {}, {}));
    EXPECT_EQ(lexer("\t\t"), createInput("", {}, {}));
    EXPECT_EQ(lexer(" \t"), createInput("", {}, {}));
    EXPECT_EQ(lexer("\t "), createInput("", {}, {}));
}

TEST(LexerTest, TestSpacesNoArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer(" foo.bar.func "), createInput("foo.bar.func", {}, {}));
}

TEST(LexerTest, TestSpacesArgs)
{
    coil::DefaultLexer lexer;

    auto input = createInput("func", args("arg1", "arg2"), {});

    EXPECT_EQ(lexer(" func arg1 arg2 "), input);
    EXPECT_EQ(lexer(" func  arg1 arg2 "), input);
    EXPECT_EQ(lexer(" func arg1  arg2 "), input);
}

TEST(LexerTest, TestSpacesNamedArgs)
{
    coil::DefaultLexer lexer;

    auto input = createInput("func", args(), { { "arg1", createValue("foo") }, { "arg2", createValue("bar") } });

    EXPECT_EQ(lexer(" func arg1=foo arg2=bar "), input);
    EXPECT_EQ(lexer(" func  arg1=foo arg2=bar "), input);
    EXPECT_EQ(lexer(" func  arg1 =foo arg2=bar "), input);
    EXPECT_EQ(lexer(" func  arg1= foo arg2=bar "), input);
    EXPECT_EQ(lexer(" func  arg1 = foo arg2=bar "), input);
    EXPECT_EQ(lexer(" func  arg1 = foo arg2 =bar "), input);
    EXPECT_EQ(lexer(" func  arg1 = foo arg2= bar "), input);
    EXPECT_EQ(lexer(" func  arg1 = foo arg2 = bar "), input);
    EXPECT_EQ(lexer(" func  arg1 = foo  arg2 = bar "), input);
}

TEST(LexerTests, TestCompoundArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1,arg2"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func (arg1 arg2)"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func (arg1,arg2)"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func (arg1, arg2)"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func (arg1 , arg2)"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func ( arg1 , arg2 )"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
    EXPECT_EQ(lexer("func ( arg1 arg2 )"), createInput("func", { coil::ArgValue{ {"arg1", "arg2"} } }, {}));
}

TEST(LexerTests, TestCompoundNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg=arg1,arg2"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=(arg1 arg2)"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=(arg1,arg2)"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=(arg1, arg2)"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=(arg1 , arg2)"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=( arg1 , arg2 )"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
    EXPECT_EQ(lexer("func arg=( arg1 arg2 )"), createInput("func", args(), { { "arg", coil::ArgValue{ {"arg1", "arg2"} } } }));
}

TEST(LexerTests, TestCompoundNamedArgsEdgeCases)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg=arg(um)ent"), createInput("func", args("um", "ent"), { {"arg", createValue("arg")} }));
    EXPECT_EQ(lexer("func arg=()"), createInput("func", args(), { {"arg", coil::ArgValue{}} }));
    EXPECT_EQ(lexer("func arg=( )"), createInput("func", args(), { {"arg", coil::ArgValue{}} }));
    EXPECT_EQ(lexer("func arg=(,)"), createInput("func", args(), { {"arg", coil::ArgValue{}} }));
    EXPECT_EQ(lexer("func arg=( , )"), createInput("func", args(), { {"arg", coil::ArgValue{}} }));
}

TEST(LexerTests, TestEmpty)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer(""), createInput("", {}, {}));
}

TEST(LexerTests, TestNoArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func"), createInput("func", {}, {}));
}

TEST(LexerTests, TestArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1"), createInput("func", args("arg1"), {}));
    EXPECT_EQ(lexer("func arg1 arg2"), createInput("func", args("arg1", "arg2"), {}));
}

TEST(LexerTests, TestNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1=foo"), createInput("func", args(), { {"arg1", createValue("foo")} }));
    EXPECT_EQ(lexer("func arg1=foo arg2=bar"), createInput("func", args(), { {"arg1", createValue("foo")}, {"arg2", createValue("bar")} }));
}

TEST(LexerTests, TestArgsAndNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1 arg2 arg3=foo arg4=bar"), createInput("func", args("arg1", "arg2"), { {"arg3", createValue("foo")}, {"arg4", createValue("bar")} }));
}

TEST(LexerTests, TestIntegerArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("foo.bar.func 1"), createInput("foo.bar.func", args("1"), {}));
    EXPECT_EQ(lexer("foo.bar.func 1 arg"), createInput("foo.bar.func", args("1", "arg"), {}));
    EXPECT_EQ(lexer("foo.bar.func 1 arg 2"), createInput("foo.bar.func", args("1", "arg", "2"), {}));
}

TEST(LexerTests, TestIntegerNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("foo.bar.func arg1=1"), createInput("foo.bar.func", args(), { { "arg1", createValue("1") } }));
    EXPECT_EQ(lexer("foo.bar.func arg1=1 arg2=arg"), createInput("foo.bar.func", args(), { { "arg1", createValue("1") }, { "arg2", createValue("arg") } }));
    EXPECT_EQ(lexer("foo.bar.func arg1=1 arg2=arg arg3=2"), createInput("foo.bar.func", args(), { { "arg1", createValue("1") }, { "arg2", createValue("arg") }, { "arg3", createValue("2") } }));
}

TEST(LexerTests, TestFloatArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("foo.bar.func 3.14"), createInput("foo.bar.func", args("3.14"), {}));
    EXPECT_EQ(lexer("foo.bar.func 3.14 arg"), createInput("foo.bar.func", args("3.14", "arg"), {}));
    EXPECT_EQ(lexer("foo.bar.func 3.14 arg 2.0"), createInput("foo.bar.func", args("3.14", "arg", "2.0"), {}));
}

TEST(LexerTests, TestFloatNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("foo.bar.func arg1=3.14"), createInput("foo.bar.func", {}, { { "arg1", createValue("3.14") } }));
    EXPECT_EQ(lexer("foo.bar.func arg1=3.14 arg2=arg"), createInput("foo.bar.func", {}, { { "arg1", createValue("3.14") }, { "arg2", createValue("arg") } }));
    EXPECT_EQ(lexer("foo.bar.func arg1=3.14 arg2=arg arg3=2.0"), createInput("foo.bar.func", {}, { { "arg1", createValue("3.14") }, { "arg2", createValue("arg") }, { "arg3", createValue("2.0") } }));
}

TEST(LexerTests, TestShortFloatArgs)
{
   coil::DefaultLexer lexer;

   EXPECT_EQ(lexer("foo.bar.func .14"), createInput("foo.bar.func", args(".14"), {}));
   EXPECT_EQ(lexer("foo.bar.func .14 arg"), createInput("foo.bar.func", args(".14", "arg"), {}));
   EXPECT_EQ(lexer("foo.bar.func .14 arg .0"), createInput("foo.bar.func", args(".14", "arg", ".0"), {}));
}

TEST(LexerTests, TestShortFloatNamedArgs)
{
   coil::DefaultLexer lexer;

   EXPECT_EQ(lexer("foo.bar.func arg1=.14"), createInput("foo.bar.func", args(), { { "arg1", createValue(".14") } }));
   EXPECT_EQ(lexer("foo.bar.func arg1=.14 arg2=arg"), createInput("foo.bar.func", args(), { { "arg1", createValue(".14") }, { "arg2", createValue("arg") } }));
   EXPECT_EQ(lexer("foo.bar.func arg1=.14 arg2=arg arg3=.0"), createInput("foo.bar.func", args(), { { "arg1", createValue(".14") }, { "arg2", createValue("arg") }, { "arg3", createValue(".0") } }));
}

TEST(LexerTests, TestErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("=val"), coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));
    EXPECT_EQ(lexer("command=arg"), coil::makeUnexpected("Unexpected token '=': no named for the named argument is provided"));
    EXPECT_EQ(lexer("command arg=val=foo"), coil::makeUnexpected("Unexpected token '=': no named for the named argument is provided"));
    EXPECT_EQ(lexer("command arg="), coil::makeUnexpected("Expected an argument value, found end of string"));
    EXPECT_EQ(lexer("command arg=="), coil::makeUnexpected("Expected an argument value, found '='"));
    EXPECT_EQ(lexer("command arg==value"), coil::makeUnexpected("Expected an argument value, found '='"));
    EXPECT_EQ(lexer("==value"), coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));
}

TEST(LexerTests, TestCompoundArgsErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func (arg,arg"), coil::makeUnexpected("Token '(' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func arg,arg)"), coil::makeUnexpected("Token ')' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func arg,arg\""), coil::makeUnexpected("Token '\"' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func \"arg,arg"), coil::makeUnexpected("Token '\"' doesn't have an opening/closing token"));

    EXPECT_EQ(lexer("func arg(ument"), coil::makeUnexpected("Token '(' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func argum)ent"), coil::makeUnexpected("Token ')' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func argum\"ent"), coil::makeUnexpected("Token '\"' doesn't have an opening/closing token"));

    EXPECT_EQ(lexer("func ("), coil::makeUnexpected("Token '(' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func )"), coil::makeUnexpected("Token ')' doesn't have an opening/closing token"));
    EXPECT_EQ(lexer("func \""), coil::makeUnexpected("Token '\"' doesn't have an opening/closing token"));
}

TEST(LexerTests, TestGenerated)
{
    std::default_random_engine engine{};
    std::size_t const generationsCount = 10000;
    coil::DefaultLexer lexer;

    for (std::size_t i = 0; i < generationsCount; i++)
    {
        auto input = generateRandomInput(engine);
        auto str = generateRandomInputString(engine, input);

        EXPECT_EQ(lexer(str), input);
    }
}