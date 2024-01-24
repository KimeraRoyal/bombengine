#include <core/core.h>

#include "demoscene.h"
#include "core/window/window.h"

using namespace bombengine;

int main()
{
    const std::shared_ptr<BombCore> core = BombCore::Initialize();

    const std::shared_ptr<Window> window = core->GetWindows()->CreateWindow(WindowProperties("Demo Scene", glm::ivec2(100), c_defaultWindowSize, SDL_WINDOW_OPENGL));
    const std::shared_ptr<bombdemo::DemoScene> scene = core->GetScenes()->CreateScene<bombdemo::DemoScene>();

    core->GameLoop();

    return 0;
}
