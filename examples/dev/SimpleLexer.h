#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace coil
{
    struct ExecutionInput;
}

// TODO implement properly
struct SimpleLexer
{
public:
    coil::ExecutionInput operator()(std::string str) const;

private:
    void split(std::string str, std::vector<std::string>& tokens) const;

    template<typename Iter>
    void splitBySpace(Iter&& begin, Iter&& end, std::vector<std::string>& tokens) const
    {
        if (begin == end)
            return;

        std::stringstream ss{ std::string{begin, end} };

        std::string token;
        while (ss >> token)
        {
            tokens.push_back(std::move(token));
            token.clear();
        }
    }

    template<typename Iter>
    void add(Iter&& begin, Iter&& end, std::vector<std::string>& tokens) const
    {
        tokens.emplace_back(std::forward<Iter>(begin), std::forward<Iter>(end));
    }
};
