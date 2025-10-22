#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // 只在C++17下有效
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept {
        for(const auto cmd : commands)
        {
            //如果是M指令
            if(cmd == 'M')
            {
                if(pose.heading == 'E') { pose.x += 1; }
                else if(pose.heading == 'W') { pose.x -= 1; }
                else if(pose.heading == 'N') { pose.y += 1; }
                else if(pose.heading == 'S') { pose.y -= 1; }

            }
        }
    }
}
