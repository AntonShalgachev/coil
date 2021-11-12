#include "LexerTests.h"

#include "SimpleLexer.h"
#include "coil/ExecutionInput.h"

#include <iostream>
#include <random>
#include <sstream>

namespace
{
    void dump(std::ostream& os, std::string_view name, coil::ExecutionInput const& self)
    {
        os << name << ":" << std::endl;

        os << "{\n";
        os << "\ttarget: '" << self.target << "'\n";
        os << "\tname: '" << self.name << "'\n";

        os << "\targs: {";
        for (auto const& arg : self.arguments)
            os << "'" << arg << "',";
        os << "}\n";

        os << "\tnamed args: {\n";
        for (auto const& pair : self.namedArguments)
            os << "\t\t'" << pair.first << "': '" << pair.second << "',\n";
        os << "\t}\n";

        os << "}" << std::endl;
    }

    template<typename Lexer>
    void validate(std::string_view str, coil::ExecutionInput expected)
    {
        std::cout << "Testing '" << str << "'";

        Lexer lexer;
        coil::ExecutionInput actual = lexer(std::string(str));

        bool const passed = actual == expected;

        std::cout << (passed ? " [SUCCESS]" : " [FAILURE]") << std::endl;

        if (!passed)
        {
            dump(std::cout, "Expected", expected);
            dump(std::cout, "Actual", actual);
        }
    }

    coil::ExecutionInput expects(std::string_view target, std::string_view name, std::vector<std::string> args, std::unordered_map<std::string, std::string> namedArgs)
    {
        coil::ExecutionInput input;
        input.target = target;
        input.name = name;

        input.arguments = std::move(args);
        input.namedArguments = std::move(namedArgs);

        return input;
    }

    template<typename RandomEngine>
    std::string generateRandomString(RandomEngine& engine, std::size_t generation, bool allowEmpty)
    {
        std::bernoulli_distribution isEmptyDist{ allowEmpty ? 0.5f : 0.0f };

        if (isEmptyDist(engine))
            return "";

        return std::string("str") + std::to_string(generation);
    }

    template<typename RandomEngine>
    coil::ExecutionInput generateRandomInput(RandomEngine& engine)
    {
        std::size_t generation = 0;

        coil::ExecutionInput input;

        input.target = generateRandomString(engine, generation++, true);
        input.name = generateRandomString(engine, generation++, false);

        std::uniform_int_distribution<std::size_t> argsCountDist{0, 3};

        std::size_t argsCount = argsCountDist(engine);
        std::size_t namedArgsCount = argsCountDist(engine);

        for (std::size_t i = 0; i < argsCount; i++)
            input.arguments.push_back(generateRandomString(engine, generation++, false));

        for (std::size_t i = 0; i < namedArgsCount; i++)
            input.namedArguments.emplace(generateRandomString(engine, generation++, false), generateRandomString(engine, generation++, false));

        return input;
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

        if (!input.target.empty())
        {
            randomSpaces(ss);
            ss << input.target;
            randomSpaces(ss);
            ss << '.';
            randomSpaces(ss);
        }

        ss << input.name << ' ';
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

        std::default_random_engine engine{};
        std::size_t const generationsCount = 50;
        for (int i = 0; i < generationsCount; i++)
        {
            auto input = generateRandomInput(engine);
            auto str = generateRandomInputString(engine, input);
            validate<Lexer>(str, input);
        }
    }
}

void lexer_tests::run()
{
    testLexer<SimpleLexer>();
}

