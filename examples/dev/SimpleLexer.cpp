#include "SimpleLexer.h"

#include <stdexcept>
#include <algorithm>
#include <cctype>

#include "coil/ExecutionInput.h"

namespace
{
    void ltrim(std::string& s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
        {
            return !std::isspace(ch);
        }));
    }

    void rtrim(std::string& s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
        {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    void trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
    }
}

coil::ExecutionInput SimpleLexer::operator()(std::string str) const
{
    std::string target;
    std::string rest;

    auto spacePos = str.find_first_of(" \t\n\v\f\r");
    auto dotPos = str.find('.');
    if (dotPos != std::string::npos && dotPos < spacePos)
    {
        target = str.substr(0, dotPos);
        trim(target);
        rest = str.substr(dotPos + 1);
    }
    else
    {
        rest = std::move(str);
    }

    std::vector<std::string> tokens;
    split(std::move(rest), tokens);

    coil::ExecutionInput input;

    input.target = std::move(target);

    if (!tokens.empty())
    {
        input.name = tokens[0];
        tokens.erase(tokens.begin());

        // wtf Wtf WTF WTF!!! Burn this shit with the flamethrower
        for (auto&& token : tokens)
        {
            auto pos = token.find("=");
            if (pos == std::string::npos)
            {
                input.arguments.push_back(std::move(token));
            }
            else
            {
                auto key = token.substr(0, pos);
                auto value = token.substr(pos + 1);

                input.namedArguments.emplace(std::move(key), std::move(value));
            }
        }
    }

    return input;
}

void SimpleLexer::split(std::string str, std::vector<std::string>& tokens) const
{
    char constexpr quoteSeparator = '"';

    auto begin = str.cbegin();
    auto end = str.cend();

    while (true)
    {
        auto leftQuoteIt = std::find(begin, end, quoteSeparator);

        splitBySpace(begin, leftQuoteIt, tokens);

        if (leftQuoteIt == end)
            break;

        auto quotedStringIt = std::next(leftQuoteIt);
        auto rightQuoteIt = std::find(quotedStringIt, end, quoteSeparator);

        add(quotedStringIt, rightQuoteIt, tokens);

        if (rightQuoteIt == end)
            throw std::invalid_argument("imbalanced quotes");

        begin = std::next(rightQuoteIt);
    }
}
