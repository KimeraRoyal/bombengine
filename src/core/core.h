#include <memory>

namespace bombengine
{
    struct Core
    {
    private:
        bool m_running;

        Core();

        bool Update();
        void Draw();

        bool PollEvents();

    public:
        ~Core();

        void Run();

        static std::shared_ptr<Core> Initialize();
    };
}