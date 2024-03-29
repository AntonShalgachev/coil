#include "PropertiesExample.h"

#include "common/ExamplesCommon.h"

#include <cmath>
#include <vector>

namespace
{
    class Window
    {
    public:
        std::size_t width = 1920;
        std::size_t height = 1080;

        float getAspect() const
        {
            return 1.0f * width / height;
        }
        void setAspect(float aspect)
        {
            width = static_cast<std::size_t>(aspect * height);
        }
    };

    float getWindowDiagonal(Window const* window)
    {
        return std::hypotf(1.0f * window->width, 1.0f * window->height);
    }

    void setWindowDiagonal(Window* window, float value)
    {
        float scale = value / getWindowDiagonal(window);
        window->width = static_cast<std::size_t>(window->width * scale);
        window->height = static_cast<std::size_t>(window->height * scale);
    }
}

void PropertiesExample::run()
{
    coil::Bindings bindings;

    Window window;

    bindings["window.print_size"] = [&window](coil::Context context) { context.loglinef("%zux%zu", window.width, window.height); };
    bindings["window.aspect"] = coil::bindProperty(&Window::getAspect, &Window::setAspect, &window);
    bindings["window.diagonal"] = coil::bindProperty(&getWindowDiagonal, &setWindowDiagonal, &window);

    bindings["window.readonly_aspect"] = coil::bindProperty(&Window::getAspect, &window);
    bindings["window.readonly_diagonal"] = coil::bindProperty(&getWindowDiagonal, &window);

    std::vector<int> data = {3, 1, 4};
    bindings["data"] = [&data](coil::Context context) {
        context.log("{ ");
        for (auto const& value : data)
            context.logf("%d ", value);
        context.log("}");
    };
    bindings["data.size"] = coil::property([&data]() { return data.size(); }, [&data](std::size_t size) { data.resize(size); });

    common::printSectionHeader("Properties behave as if the were variables");
    common::executeCommand(bindings, "window.print_size");
    common::executeCommand(bindings, "window.aspect");
    common::executeCommand(bindings, "window.aspect 1.3");
    common::executeCommand(bindings, "window.print_size");
    common::executeCommand(bindings, "window.diagonal");
    common::executeCommand(bindings, "window.diagonal 1500");
    common::executeCommand(bindings, "window.print_size");
    common::executeCommand(bindings, "data");
    common::executeCommand(bindings, "data.size");
    common::executeCommand(bindings, "data.size 7");
    common::executeCommand(bindings, "data");

    common::printSectionHeader("Read-only properties produce a clear error when trying to set their value:");
    common::executeCommand(bindings, "window.readonly_aspect");
    common::executeCommand(bindings, "window.readonly_aspect 1.5");
    common::executeCommand(bindings, "window.readonly_diagonal");
    common::executeCommand(bindings, "window.readonly_diagonal 1200");
}
