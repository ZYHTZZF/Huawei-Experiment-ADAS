#include "ExecutorImpl.hpp"
// #include "Command.hpp"
// #include <new>
// #include <memory>
// #include <unordered_map>
# include "cmder/CmderFactory.hpp"
# include "core/Singleton.hpp"
#include<algorithm>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // 只在C++17下有效
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept {
        
        // std::unordered_map<char, std::function<void(PoseHandler& PoseHandler)>> cmderMap{
        //     {'M', MoveCommand()},
        //     {'L', TurnLeftCommand()},
        //     {'R', TurnRightCommand()},
        //     {'F', FastCommand()},
        //     {'B', ReverseCommand()},
        // };
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(
            cmders.begin(),
            cmders.end(),
            [this](const Cmder &cmder) noexcept{
                cmder(poseHandler).DoOperate(poseHandler);
            }
        );
        // for(const auto cmd : commands)
        // {
        //     //根据操作查找驱动表
        //     const auto it = cmderMap.find(cmd);
        //     if(it != cmderMap.end())
        //     {
        //         //找到对应的操作，执行
        //         it->second(poseHandler);
        //     }
        // }
    }
    // 记录当前是否为加速状态
}
