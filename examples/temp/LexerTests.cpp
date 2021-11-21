#include "LexerTests.h"

#include "coil/ExecutionInput.h"
#include "coil/DefaultLexer.h"

#include "common/ExamplesCommon.h"

#include <iostream>
#include <random>
#include <sstream>
#include <string_view>

namespace
{
    struct ExecutionInputWithStorage
    {
        coil::ExecutionInput input;
        std::vector<std::string> storage;
    };

    void dump(std::ostream& os, std::string_view name, coil::Expected<coil::ExecutionInput, std::string> const& self)
    {
        os << name << ":" << std::endl;

        if (!self)
        {
            os << "Error: " << self.error() << std::endl;
            return;
        }

        os << "{\n";
        os << "\tobject: '" << self->objectName << "'\n";
        os << "\tfunction: '" << self->functionName << "'\n";

        os << "\targs: {";
        for (auto const& arg : self->arguments)
            os << "'" << arg << "',";
        os << "}\n";

        os << "\tnamed args: {\n";
        for (auto const& pair : self->namedArguments)
            os << "\t\t'" << pair.first << "': '" << pair.second << "',\n";
        os << "\t}\n";

        os << "}" << std::endl;
    }

    template<typename Lexer>
    bool validate(std::string_view str, coil::Expected<coil::ExecutionInput, std::string> expected)
    {
        std::cout << "Testing '" << str << "'";

        Lexer lexer;
        auto actual = lexer(str);

        bool passed = false;
        if (actual && expected)
        {
            passed = actual.value() == expected.value();
        }
        else if (!actual && !expected)
        {
            passed = actual.error() == expected.error();
        }

        std::cout << (passed ? " [SUCCESS]" : " [FAILURE]") << std::endl;

        if (!passed)
        {
            dump(std::cout, "Expected", expected);
            dump(std::cout, "Actual", actual);
            std::cout << std::endl;
        }

        return passed;
    }

    coil::ExecutionInput expects(std::string_view objectName, std::string_view functionName, std::vector<std::string_view> args, std::unordered_map<std::string_view, std::string_view> namedArgs)
    {
        coil::ExecutionInput input;
        input.objectName = objectName;
        input.functionName = functionName;

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
            return std::string_view{storage.back()};
        };

        input.objectName = generateNewString(true, false);
        input.functionName = generateNewString(false, false);

        for (std::size_t i = 0; i < argsCount; i++)
            input.arguments.push_back(generateNewString(false, true));

        for (std::size_t i = 0; i < namedArgsCount; i++)
        {
            auto key = generateNewString(false, false);
            auto value = generateNewString(false, true);
            input.namedArguments.emplace(key, value);
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

    template<typename Lexer>
    void testLexer()
    {
        validate<Lexer>("obj.func arg1 arg2 arg3=foo arg4=bar", expects("obj", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
        validate<Lexer>("func arg1 arg2 arg3=foo arg4=bar", expects("", "func", { "arg1", "arg2" }, { {"arg3", "foo"}, {"arg4", "bar"} }));
        validate<Lexer>("", expects("", "", {}, {}));

        validate<Lexer>(".func", coil::makeUnexpected("Unexpected token '.' at the beginning of the expression"));
        validate<Lexer>("=val", coil::makeUnexpected("Unexpected token '=' at the beginning of the expression"));

        validate<Lexer>("target.func=arg", coil::makeUnexpected("Unexpected token '='; previous token group is already complete"));
        validate<Lexer>("target.func arg=val=foo", coil::makeUnexpected("Unexpected token '='; previous token group is already complete"));
        validate<Lexer>("target.func.foo", coil::makeUnexpected("Unexpected token '.'; previous token group is already complete"));

        validate<Lexer>("target.func arg=", coil::makeUnexpected("Unexpected token '=' at the end of the expression"));
        validate<Lexer>("target.", coil::makeUnexpected("Unexpected token '.' at the end of the expression"));

        validate<Lexer>("target.=foo", coil::makeUnexpected("Unexpected token '='; previous token group already has a token"));
        validate<Lexer>("target.func arg=.foo", coil::makeUnexpected("Unexpected token '.'; previous token group already has a token"));

        validate<Lexer>("arg1 arg2=foo obj.func", coil::makeUnexpected("Unexpected token '.' when the function name has already been defined"));
        validate<Lexer>("obj.func obj2.func2", coil::makeUnexpected("Unexpected token '.' when the function name has already been defined"));

        validate<Lexer>("arg=val", coil::makeUnexpected("Unexpected named argument at the beginning of the expression"));

        std::default_random_engine engine{};
        std::size_t const generationsCount = 5000;
        std::size_t failures = 0;
        for (std::size_t i = 0; i < generationsCount; i++)
        {
            auto inputWithStorage = generateRandomInput(engine);
            auto str = generateRandomInputString(engine, inputWithStorage.input);
            if (!validate<Lexer>(str, inputWithStorage.input))
                failures++;
        }

        std::cout << "Automatic tests completed: " << failures << " failed" << std::endl << std::endl;
    }
}

void lexer_tests::run()
{
    testLexer<coil::DefaultLexer>();
}

