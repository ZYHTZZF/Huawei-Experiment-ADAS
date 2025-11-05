#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <new>
#include <memory>
#include <unordered_map>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // 只在C++17下有效
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept {
        //表驱动
        std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
        //建立操作M和前进指令的映射
        cmderMap.emplace('M', std::make_unique<MoveCommand>());
        cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
        cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
        cmderMap.emplace('F', std::make_unique<FastCommand>());
        for(const auto cmd : commands)
        {
            //根据操作查找驱动表
            const auto it = cmderMap.find(cmd);
            if(it != cmderMap.end())
            {
                //找到对应的操作，执行
                it->second->DoOperate(poseHandler);
            }

        
        }
    }


    // 记录当前是否为加速状态
}
