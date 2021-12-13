#include "gtest/gtest.h"
#include "coil/DefaultLexer.h"

#include <random>

namespace coil
{
    std::ostream& operator<<(std::ostream& os, coil::ExecutionInput const& input)
    {
        os << "['" << input.objectName << "' , '" << input.functionName << "', {";

        auto delim = "";
        for (auto const& arg : input.arguments)
        {
            os << delim << "'" << arg << "'";
            delim = ", ";
        }

        os << "}, {";

        delim = "";
        for (auto const& pair : input.namedArguments)
        {
            os << delim << "{'" << pair.first << "': '" << pair.second << "'},";
            delim = ", ";
        }

        os << "}]";

        return os;
    }

    template<typename T, typename E>
    std::ostream& operator<<(std::ostream& os, coil::Expected<T, E> const& expected)
    {
        if (expected)
            return os << expected.value();

        return os << "'" << expected.error() << "'";
    }

    namespace detail
    {
        template<typename E>
        std::ostream& operator<<(std::ostream& os, detail::Unexpected<E> const& unexpected)
        {
            return os << "'" << unexpected.value() << "'";
        }
    }
}

bool operator==(std::reference_wrapper<coil::ExecutionInput> const& lhs, coil::ExecutionInput const& rhs)
{
    return lhs.get() == rhs;
}

namespace
{
    coil::ExecutionInput createInput(std::string_view objectName, std::string_view functionName, std::vector<std::string_view> args, std::vector<std::pair<std::string_view, std::string_view>> namedArgs)
    {
        coil::ExecutionInput input;
        input.objectName = objectName;
        input.functionName = functionName;

        input.arguments = std::move(args);
        input.namedArguments = std::move(namedArgs);

        return input;
    }

    struct ExecutionInputWithStorage
    {
        coil::ExecutionInput input;
        std::vector<std::string> storage;
    };

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
    ExecutionInputWithStorage generateRandomInput(RandomEngine& engine)
    {
        std::size_t generation = 0;

        ExecutionInputWithStorage inputWithStorage;
        coil::ExecutionInput& input = inputWithStorage.input;

        std::uniform_int_distribution<std::size_t> argsCountDist{ 0, 3 };

        std::size_t argsCount = argsCountDist(engine);
        std::size_t namedArgsCount = argsCountDist(engine);

        std::size_t const maxStorageSize = 2 + argsCount + 2 * namedArgsCount;
        inputWithStorage.storage.reserve(maxStorageSize);

        auto generateNewString = [&storage = inputWithStorage.storage, &engine, &generation, maxStorageSize](bool allowEmpty, bool allowNumber)
        {
            // to prevent storage reallocation
            if (storage.size() >= maxStorageSize)
                throw std::runtime_error("Maximum allocations reached");

            storage.push_back(generateRandomString(engine, generation++, allowEmpty, allowNumber));
            return std::string_view{ storage.back() };
        };

        input.objectName = generateNewString(true, false);
        input.functionName = generateNewString(false, false);

        for (std::size_t i = 0; i < argsCount; i++)
            input.arguments.push_back(generateNewString(false, true));

        for (std::size_t i = 0; i < namedArgsCount; i++)
        {
            auto key = generateNewString(false, false);
            auto value = generateNewString(false, true);
            input.namedArguments.emplace_back(key, value);
        }

        return inputWithStorage;
    }

    template<typename RandomEngine>
    std::string generateRandomInputString(RandomEngine& engine, coil::ExecutionInput const& input)
    {
        auto randomSpaces = [&engine](std::ostream& os)
        {
            std::uniform_int_distribution<std::size_t> amountDist{ 0, 2 };
            std::size_t amount = amountDist(engine);
            for (std::size_t i = 0; i < amount; i++)
                os << ' ';
        };

        std::stringstream ss;

        randomSpaces(ss);

        if (!input.objectName.empty())
        {
            randomSpaces(ss);
            ss << input.objectName;
            randomSpaces(ss);
            ss << '.';
            randomSpaces(ss);
        }

        ss << input.functionName << ' ';
        randomSpaces(ss);

        for (auto const& arg : input.arguments)
        {
            ss << arg << ' ';
            randomSpaces(ss);
        }

        for (auto const& pair : input.namedArguments)
        {
            ss << pair.first;
            randomSpaces(ss);
            ss << "=";
            randomSpaces(ss);
            ss << pair.second << ' ';
            randomSpaces(ss);
        }

        randomSpaces(ss);

        return ss.str();
    }
}

TEST(LexerTests, TestEmpty)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer(""), createInput("", "", {}, {}));

    EXPECT_EQ(lexer(""), createInput("", "", {}, {}));
    EXPECT_EQ(lexer("   "), createInput("", "", {}, {}));
    EXPECT_EQ(lexer("\t\t"), createInput("", "", {}, {}));
    EXPECT_EQ(lexer("\t  \t"), createInput("", "", {}, {}));
}

TEST(LexerTests, TestNoArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func"), createInput("", "func", {}, {}));

    EXPECT_EQ(lexer(" func "), createInput("", "func", {}, {}));
    EXPECT_EQ(lexer("\tfunc\t"), createInput("", "func", {}, {}));
    EXPECT_EQ(lexer(" \t func \t "), createInput("", "func", {}, {}));
}

TEST(LexerTests, TestArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1"), createInput("", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("func arg1 arg2"), createInput("", "func", { "arg1", "arg2" }, {}));

    EXPECT_EQ(lexer("func   arg1"), createInput("", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("func \t arg1"), createInput("", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("func\t \targ1"), createInput("", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("func arg1   arg2"), createInput("", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("func arg1 \t arg2"), createInput("", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("func \t arg1 \t arg2"), createInput("", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("  func\targ1\targ2  "), createInput("", "func", { "arg1", "arg2" }, {}));
}

TEST(LexerTests, TestNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1=foo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func arg1=foo arg2=bar"), createInput("", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));

    EXPECT_EQ(lexer("func arg1 = foo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func arg1\t=\tfoo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func arg1\t = \tfoo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func    arg1 = foo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func\targ1\t=\tfoo"), createInput("", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("func\targ1=foo\targ2=bar"), createInput("", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
    EXPECT_EQ(lexer("func\targ1\t=\tfoo\targ2\t=\tbar"), createInput("", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
    EXPECT_EQ(lexer("  func  arg1\t=foo   arg2=bar  "), createInput("", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
}

TEST(LexerTests, TestArgsAndNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1 arg2 arg3=foo arg4=bar"), createInput("", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));

    EXPECT_EQ(lexer("func   arg1  arg2\targ3 =foo  arg4=\t  bar  "), createInput("", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
    EXPECT_EQ(lexer(" func   arg1\targ2 arg3=  foo arg4\t\t=   bar"), createInput("", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
}

TEST(LexerTests, TestNoArgsWithTarget)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("obj.func"), createInput("obj", "func", {}, {}));

    EXPECT_EQ(lexer(" obj.func "), createInput("obj", "func", {}, {}));
    EXPECT_EQ(lexer("\tobj .func\t"), createInput("obj", "func", {}, {}));
    EXPECT_EQ(lexer(" \t obj.\tfunc \t "), createInput("obj", "func", {}, {}));
    EXPECT_EQ(lexer(" \t obj .\tfunc \t "), createInput("obj", "func", {}, {}));
    EXPECT_EQ(lexer(" \t obj.func \t "), createInput("obj", "func", {}, {}));
}

TEST(LexerTests, TestArgsWithTarget)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("obj.func arg1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj.func arg1 arg2"), createInput("obj", "func", { "arg1", "arg2" }, {}));

    EXPECT_EQ(lexer("obj.func   arg1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj . func   arg1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj\t.\tfunc   arg1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj .func \t arg1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj\t.func\t \targ1"), createInput("obj", "func", { "arg1" }, {}));
    EXPECT_EQ(lexer("obj.\tfunc arg1   arg2"), createInput("obj", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("obj \t. func arg1 \t arg2"), createInput("obj", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("obj. \tfunc \t arg1 \t arg2"), createInput("obj", "func", { "arg1", "arg2" }, {}));
    EXPECT_EQ(lexer("  obj.func\targ1\targ2  "), createInput("obj", "func", { "arg1", "arg2" }, {}));
}

TEST(LexerTests, TestNamedArgsWithTarget)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("obj.func arg1=foo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj.func arg1=foo arg2=bar"), createInput("obj", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));

    EXPECT_EQ(lexer("obj .func arg1 = foo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj. func arg1\t=\tfoo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj.  func arg1\t = \tfoo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj  .func    arg1 = foo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj . func\targ1\t=\tfoo"), createInput("obj", "func", {}, { {"arg1", "foo"} }));
    EXPECT_EQ(lexer("obj \t. \tfunc\targ1=foo\targ2=bar"), createInput("obj", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
    EXPECT_EQ(lexer("obj\t.\tfunc\targ1\t=\tfoo\targ2\t=\tbar"), createInput("obj", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
    EXPECT_EQ(lexer("  obj.func  arg1\t=foo   arg2=bar  "), createInput("obj", "func", {}, { {"arg1", "foo"}, {"arg2", "bar"} }));
}

TEST(LexerTests, TestArgsAndNamedArgsWithTarget)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("obj.func arg1 arg2 arg3=foo arg4=bar"), createInput("obj", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));

    EXPECT_EQ(lexer("obj .\tfunc   arg1  arg2\targ3 =foo  arg4=\t  bar  "), createInput("obj", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
    EXPECT_EQ(lexer(" obj. \tfunc   arg1\targ2 arg3=  foo arg4\t\t=   bar"), createInput("obj", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
}

TEST(LexerTests, TestIntegerArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func 1"), createInput("", "func", { "1" }, {}));
    EXPECT_EQ(lexer("func 1 arg"), createInput("", "func", { "1", "arg" }, {}));
    EXPECT_EQ(lexer("func 1 arg 2"), createInput("", "func", { "1", "arg", "2" }, {}));

    EXPECT_EQ(lexer("obj.func 1"), createInput("obj", "func", { "1" }, {}));
    EXPECT_EQ(lexer("obj.func 1 arg"), createInput("obj", "func", { "1", "arg" }, {}));
    EXPECT_EQ(lexer("obj.func 1 arg 2"), createInput("obj", "func", { "1", "arg", "2" }, {}));
}

TEST(LexerTests, TestIntegerNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1=1"), createInput("", "func", {}, { { "arg1", "1" } }));
    EXPECT_EQ(lexer("func arg1=1 arg2=arg"), createInput("", "func", {}, { { "arg1", "1" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("func arg1=1 arg2=arg arg3=2"), createInput("", "func", {}, { { "arg1", "1" }, { "arg2", "arg" }, { "arg3", "2" } }));

    EXPECT_EQ(lexer("obj.func arg1=1"), createInput("obj", "func", {}, { { "arg1", "1" } }));
    EXPECT_EQ(lexer("obj.func arg1=1 arg2=arg"), createInput("obj", "func", {}, { { "arg1", "1" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("obj.func arg1=1 arg2=arg arg3=2"), createInput("obj", "func", {}, { { "arg1", "1" }, { "arg2", "arg" }, { "arg3", "2" } }));
}

TEST(LexerTests, TestFloatArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func 3.14"), createInput("", "func", { "3.14" }, {}));
    EXPECT_EQ(lexer("func 3.14 arg"), createInput("", "func", { "3.14", "arg" }, {}));
    EXPECT_EQ(lexer("func 3.14 arg 2.0"), createInput("", "func", { "3.14", "arg", "2.0" }, {}));

    EXPECT_EQ(lexer("obj.func 3.14"), createInput("obj", "func", { "3.14" }, {}));
    EXPECT_EQ(lexer("obj.func 3.14 arg"), createInput("obj", "func", { "3.14", "arg" }, {}));
    EXPECT_EQ(lexer("obj.func 3.14 arg 2.0"), createInput("obj", "func", { "3.14", "arg", "2.0" }, {}));
}

TEST(LexerTests, TestFloatNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1=3.14"), createInput("", "func", {}, { { "arg1", "3.14" } }));
    EXPECT_EQ(lexer("func arg1=3.14 arg2=arg"), createInput("", "func", {}, { { "arg1", "3.14" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("func arg1=3.14 arg2=arg arg3=2.0"), createInput("", "func", {}, { { "arg1", "3.14" }, { "arg2", "arg" }, { "arg3", "2.0" } }));

    EXPECT_EQ(lexer("obj.func arg1=3.14"), createInput("obj", "func", {}, { { "arg1", "3.14" } }));
    EXPECT_EQ(lexer("obj.func arg1=3.14 arg2=arg"), createInput("obj", "func", {}, { { "arg1", "3.14" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("obj.func arg1=3.14 arg2=arg arg3=2.0"), createInput("obj", "func", {}, { { "arg1", "3.14" }, { "arg2", "arg" }, { "arg3", "2.0" } }));
}

TEST(LexerTests, TestShortFloatArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func .14"), createInput("", "func", { ".14" }, {}));
    EXPECT_EQ(lexer("func .14 arg"), createInput("", "func", { ".14", "arg" }, {}));
    EXPECT_EQ(lexer("func .14 arg .0"), createInput("", "func", { ".14", "arg", ".0" }, {}));

    EXPECT_EQ(lexer("obj.func .14"), createInput("obj", "func", { ".14" }, {}));
    EXPECT_EQ(lexer("obj.func .14 arg"), createInput("obj", "func", { ".14", "arg" }, {}));
    EXPECT_EQ(lexer("obj.func .14 arg .0"), createInput("obj", "func", { ".14", "arg", ".0" }, {}));
}

TEST(LexerTests, TestShortFloatNamedArgs)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer("func arg1=.14"), createInput("", "func", {}, { { "arg1", ".14" } }));
    EXPECT_EQ(lexer("func arg1=.14 arg2=arg"), createInput("", "func", {}, { { "arg1", ".14" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("func arg1=.14 arg2=arg arg3=.0"), createInput("", "func", {}, { { "arg1", ".14" }, { "arg2", "arg" }, { "arg3", ".0" } }));

    EXPECT_EQ(lexer("obj.func arg1=.14"), createInput("obj", "func", {}, { { "arg1", ".14" } }));
    EXPECT_EQ(lexer("obj.func arg1=.14 arg2=arg"), createInput("obj", "func", {}, { { "arg1", ".14" }, { "arg2", "arg" } }));
    EXPECT_EQ(lexer("obj.func arg1=.14 arg2=arg arg3=.0"), createInput("obj", "func", {}, { { "arg1", ".14" }, { "arg2", "arg" }, { "arg3", ".0" } }));
}

TEST(LexerTests, TestErrors)
{
    coil::DefaultLexer lexer;

    EXPECT_EQ(lexer(".func"), coil::makeUnexpected("Unexpected token '.' at the beginning of the expression"));
    EXPECT_EQ(lexer("=val"), coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));

    EXPECT_EQ(lexer("target.func=arg"), coil::makeUnexpected("Unexpected token '='; previous token group is already complete"));
    EXPECT_EQ(lexer("target.func arg=val=foo"), coil::makeUnexpected("Unexpected token '='; previous token group is already complete"));
    EXPECT_EQ(lexer("target.func.foo"), coil::makeUnexpected("Unexpected token '.'; previous token group is already complete"));

    EXPECT_EQ(lexer("target.func arg="), coil::makeUnexpected("Unexpected token '=' at the end of the expression"));
    EXPECT_EQ(lexer("target."), coil::makeUnexpected("Unexpected token '.' at the end of the expression"));

    EXPECT_EQ(lexer("target.=foo"), coil::makeUnexpected("Unexpected token '='; previous token group already has a token"));
    EXPECT_EQ(lexer("target.func arg=.foo"), coil::makeUnexpected("Unexpected token '.'; previous token group already has a token"));

    EXPECT_EQ(lexer("arg1 arg2=foo obj.func"), coil::makeUnexpected("Unexpected token '.' when the function name has already been defined"));
    EXPECT_EQ(lexer("obj.func obj2.func2"), coil::makeUnexpected("Unexpected token '.' when the function name has already been defined"));
}

TEST(LexerTests, TestGenerated)
{
    std::default_random_engine engine{};
    std::size_t const generationsCount = 10000;
    coil::DefaultLexer lexer;

    for (std::size_t i = 0; i < generationsCount; i++)
    {
        auto inputWithStorage = generateRandomInput(engine);
        auto str = generateRandomInputString(engine, inputWithStorage.input);

        EXPECT_EQ(lexer(str), inputWithStorage.input);
    }
}
