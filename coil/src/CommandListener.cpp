#include "CommandListener.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

namespace
{
	struct Tokenizer
	{
	public:
		Tokenizer(std::string str)
		{
			split(std::move(str));
		}

		std::vector<std::string> getTokens() && { return std::move(m_tokens); }

	private:
		void split(std::string str)
		{
			char constexpr quoteSeparator = '"';

			auto begin = str.cbegin();
			auto end = str.cend();

			while (true)
			{
				auto leftQuoteIt = std::find(begin, end, quoteSeparator);

				splitBySpace(begin, leftQuoteIt);

				if (leftQuoteIt == end)
					break;

				auto quotedStringIt = std::next(leftQuoteIt);
				auto rightQuoteIt = std::find(quotedStringIt, end, quoteSeparator);

				add(quotedStringIt, rightQuoteIt);

				if (rightQuoteIt == end)
					throw std::invalid_argument("imbalanced quotes");

				begin = std::next(rightQuoteIt);
			}
		}

		template<typename Iter>
		void splitBySpace(Iter&& begin, Iter&& end)
		{
			if (begin == end)
				return;

			std::stringstream ss{ std::string{begin, end} };

			std::string token;
			while (ss >> token)
			{
				m_tokens.push_back(std::move(token));
				token.clear();
			}
		}

		template<typename Iter>
		void add(Iter&& begin, Iter&& end)
		{
			m_tokens.emplace_back(std::forward<Iter>(begin), std::forward<Iter>(end));
		}

		std::vector<std::string> m_tokens;
	};

    void ltrim(std::string& s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    void rtrim(std::string& s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    void trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
    }
}

bool cmdapi::CommandListener::unbind(std::string const& name)
{
	return unbind<void>(name);
}

void cmdapi::CommandListener::unbindAll()
{
	return unbindAll<void>();
}

bool cmdapi::CommandListener::removeObject(std::string const& name)
{
	if (name.empty())
		return false;

    m_objects.erase(name);

	return true;
}

void cmdapi::CommandListener::removeAllObjects()
{
    m_objects.clear();
}

cmdapi::ExecutionResult cmdapi::CommandListener::execute(std::string command)
{
    std::string target;
    std::string rest;

    // TODO implement parser properly

    auto spacePos = command.find_first_of(" \t\n\v\f\r");
    auto dotPos = command.find('.');
    if (dotPos != std::string::npos && dotPos < spacePos)
    {
        target = command.substr(0, dotPos);
        trim(target);
        rest = command.substr(dotPos + 1);
    }
    else
    {
        rest = std::move(command);
    }

    std::vector<std::string> tokens = Tokenizer{ std::move(rest) }.getTokens();

    detail::CallContext context;

    context.target = std::move(target);

    if (!tokens.empty())
    {
        context.name = tokens[0];
        tokens.erase(tokens.begin());
        context.arguments = std::move(tokens);
    }

    execute(context);

    return context.result;
}

void cmdapi::CommandListener::execute(detail::CallContext& context)
{
	if (context.name.empty())
	{
        context.result.errors.push_back("No command name is specified");
		return;
	}

    if (context.target.empty())
        return objectTrampoline<void>({}, context);

    auto it = m_objects.find(context.target);
    if (it == m_objects.end())
    {
        context.result.errors.push_back(utils::formatString("Object '%s' is not registered", context.target.c_str()));
        return;
    }

    AnyObject& obj = it->second;
    obj.invokeTrampoline(this, context);
}
