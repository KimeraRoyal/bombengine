#include <core/core.h>

#include "core/window/window.h"

using namespace bombengine;

int main()
{
    std::shared_ptr<Core> core = Core::Initialize();

    std::shared_ptr<Window> window = core->GetWindowManager()->CreateWindow(WindowProperties("Demo Scene", glm::ivec2(100), c_defaultWindowSize, SDL_WINDOW_OPENGL));

    core->Run();

    return 0;
}
