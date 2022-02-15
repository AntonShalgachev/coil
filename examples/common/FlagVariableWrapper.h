#pragma once

template<typename E>
struct FlagsVariableWrapper
{
public:
    FlagsVariableWrapper(E* variable) : m_variable(variable)
    {
        static_assert(!std::is_const_v<E>, "Variable shouldn't be const");
    }

    E const& operator()(std::vector<E> const& args)
    {
        if (!args.empty())
        {
            using UT = std::underlying_type_t<E>;

            auto newValue = UT{ 0 };
            for (auto arg : args)
                newValue = static_cast<UT>(newValue) | static_cast<UT>(arg);

            get() = static_cast<E>(newValue);
        }

        return get();
    }

private:
    E& get() const
    {
        return *m_variable;
    }

    E* m_variable = nullptr;
};

template<typename E, typename C>
struct MemberFlagsVariableWrapper
{
public:
    MemberFlagsVariableWrapper(E C::* variable, C* object) : m_variable(variable), m_object(object)
    {
        static_assert(!std::is_const_v<E>, "Variable shouldn't be const");
    }

    E const& operator()(std::vector<E> const& args)
    {
        if (!args.empty())
        {
            using UT = std::underlying_type_t<E>;

            auto newValue = UT{ 0 };
            for (auto arg : args)
                newValue = static_cast<UT>(newValue) | static_cast<UT>(arg);

            get() = static_cast<E>(newValue);
        }

        return get();
    }

private:
    E& get()
    {
        return m_object->*m_variable;
    }

    E C::* m_variable = nullptr;
    C* m_object = nullptr;
};
