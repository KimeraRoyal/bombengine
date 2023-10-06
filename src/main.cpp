#include <iostream>

#include <core/core.h>

int main()
{
    std::shared_ptr<bombengine::Core> core = bombengine::Core::Initialize();
    core->Run();

    return 0;
}
