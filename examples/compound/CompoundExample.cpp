#include "CompoundExample.h"

#include "common/ExamplesCommon.h"

#include "coil/StdLibCompat.h" // implementation of TypeSerializer and TypeName for some C++ Standard Library types

#include <numeric>
#include <sstream>
#include <vector>

namespace
{
    struct Point
    {
        float x = 0.0f;
        float y = 0.0f;

        Point& operator+=(Point const& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Point& operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        friend Point operator*(Point const& lhs, float rhs)
        {
            Point result = lhs;
            result *= rhs;
            return result;
        }

        std::string toString() const
        {
            std::stringstream ss;
            ss << "(" << x << "," << y << ")";
            return ss.str();
        }
    };

    class ParticleSystem
    {
    public:
        struct Particle
        {
            std::string id;
            Point position;
            Point velocity;
        };

        void add(std::string_view id, Point position, Point velocity)
        {
            m_particles.push_back(Particle{std::string{id}, std::move(position), std::move(velocity)});
        }

        Particle* get(std::string_view id)
        {
            for (Particle& particle : m_particles)
                if (particle.id == id)
                    return &particle;

            return nullptr;
        }

        void update(float dt)
        {
            for (Particle& particle : m_particles)
                particle.position += particle.velocity * dt;
        }

        std::vector<Particle> const& getParticles()
        {
            return m_particles;
        }

    private:
        std::vector<Particle> m_particles;
    };
}

namespace coil
{
    template<>
    struct TypeSerializer<Point>
    {
        static Expected<Point, coil::String> fromString(Value const& input)
        {
            if (input.subvalues.size() != 2)
                return errors::createMismatchedSubvaluesError<Point>(input, 2);

            auto x = TypeSerializer<float>::fromString(input.subvalues[0]);
            auto y = TypeSerializer<float>::fromString(input.subvalues[1]);

            if (!x)
                return errors::createGenericError<Point>(input, x.error());
            if (!y)
                return errors::createGenericError<Point>(input, y.error());

            return Point{*x, *y};
        }

        static coil::String toString(Point const& value)
        {
            return coil::fromStdString(value.toString());
        }
    };

    // This struct only needs to be serialized, so there is no "fromString" method
    template<>
    struct TypeSerializer<ParticleSystem::Particle>
    {
        static coil::String toString(ParticleSystem::Particle const& particle)
        {
            std::stringstream ss;
            ss << "{'" << particle.id << "': p " << particle.position.toString() << ", v " << particle.velocity.toString() << "}";
            return coil::fromStdString(ss.str());
        }
    };
}

void CompoundExample::run()
{
    coil::Bindings bindings;

    ParticleSystem system;

    bindings["particles.add"] = coil::bind(&ParticleSystem::add, &system);
    bindings["particles.get"] = coil::bind(&ParticleSystem::get, &system);
    bindings["particles.update"] = coil::bind(&ParticleSystem::update, &system);
    bindings["particles.list"] = [&system](coil::Context context) {
        context.logline("ID\tPos\tVel");
        context.logline("--\t---\t---");
        for (ParticleSystem::Particle const& particle : system.getParticles())
            context.loglinef("%s\t%s\t%s", particle.id.c_str(), particle.position.toString().c_str(), particle.velocity.toString().c_str());
    };

    Point pivot;
    bindings["pivot"] = coil::variable(&pivot);

    bindings["sum_all"] = [](std::vector<float> const& numbers) { return std::accumulate(numbers.begin(), numbers.end(), 0.0f); };

    bindings["get_arg_or_pi"] = [](std::optional<float> arg) { return arg.value_or(3.14f); };

    common::printSectionHeader("Commands can accept and return compound objects:");
    common::executeCommand(bindings, "particles.add p1 1,1 1,1");
    common::executeCommand(bindings, "particles.add p2 0,1 1,0");
    common::executeCommand(bindings, "particles.add p3 1,0 0,1");
    common::executeCommand(bindings, "particles.list");
    common::executeCommand(bindings, "particles.update 2.0");
    common::executeCommand(bindings, "particles.list");
    common::executeCommand(bindings, "particles.get p2");
    common::executeCommand(bindings, "particles.get unknown_particle");

    common::printSectionHeader("You can also have variables of compound type:");
    common::executeCommand(bindings, "pivot");
    common::executeCommand(bindings, "pivot (1 1)");

    common::printSectionHeader("You can pass compound arguments in several ways (the last one is useful for flags):");
    common::executeCommand(bindings, "pivot (1.5, 1.5)");
    common::executeCommand(bindings, "pivot (1.5 , 1.5)");
    common::executeCommand(bindings, "pivot (1.5 ; 1.5)");
    common::executeCommand(bindings, "pivot (1.5 1.5)");
    common::executeCommand(bindings, "pivot (1.5,1.5)");
    common::executeCommand(bindings, "pivot (1.5;1.5)");
    common::executeCommand(bindings, "pivot (1.5 | 1.5)");

    common::printSectionHeader("You can omit the parenthesis as long as you don't have spaces between the subvalues:");
    common::executeCommand(bindings, "pivot 1.5,1.5");
    common::executeCommand(bindings, "pivot 1.5;1.5");
    common::executeCommand(bindings, "pivot 1.5|1.5");

    common::printSectionHeader("You will get an error if the number of subvalues are mismatched");
    common::executeCommand(bindings, "pivot 1 1");
    common::executeCommand(bindings, "pivot (1, 1, 1)");
    common::executeCommand(bindings, "pivot (1)");

    common::printSectionHeader("Some STL types can be used with StdLibCompat.h:");
    common::executeCommand(bindings, "sum_all ()");
    common::executeCommand(bindings, "sum_all (1)");
    common::executeCommand(bindings, "sum_all (1 2 3)");
    common::executeCommand(bindings, "sum_all 1,2,3,5,8");
    common::executeCommand(bindings, "get_arg_or_pi 1");
    common::executeCommand(bindings, "get_arg_or_pi 2");
    common::executeCommand(bindings, "get_arg_or_pi ()");
}
