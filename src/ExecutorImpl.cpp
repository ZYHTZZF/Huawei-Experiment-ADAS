#include "ExecutorImpl.hpp"

#include <new>
#include <memory>
namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose) ,isFast(false) {}

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
                std::unique_ptr<MoveCommand> cmder=std::make_unique<MoveCommand>();
                cmder->DoOperate(*this);
            }
            else if(cmd == 'L')
            {
                std::unique_ptr<TurnLeftCommand> cmder=std::make_unique<TurnLeftCommand>();
                cmder->DoOperate(*this);
            }
            else if(cmd == 'R')
            {
                TurnRight();
            }
            else if(cmd == 'F')
            {
                isFast=!isFast;
            }
        }
    }
    void ExecutorImpl::Move(void) noexcept
    {
        if(!isFast)
        {
            if(pose.heading=='E'){ pose.x+=1; }
            else if(pose.heading=='W'){ pose.x-=1; }
            else if(pose.heading=='N'){ pose.y+=1; }
            else if(pose.heading=='S'){ pose.y-=1; }
        }
        else
        {
            //代码省略
        }
    }
    void ExecutorImpl::TurnLeft(void) noexcept
    {
        if(!isFast)
        {
            if(pose.heading=='E'){ pose.heading='N'; }
            else if(pose.heading=='N'){ pose.heading='W'; }
            else if(pose.heading=='W'){ pose.heading='S'; }
            else if(pose.heading=='S'){ pose.heading='E'; }
        }
        else
        {
            //代码省略
        }
    }

    void ExecutorImpl::TurnRight(void) noexcept
    {
        if(!isFast)
        {
            if(pose.heading=='E'){ pose.heading='S'; }
            else if(pose.heading=='S'){ pose.heading='W'; }
            else if(pose.heading=='W'){ pose.heading='N'; }
            else if(pose.heading=='N'){ pose.heading='E'; }
        }
        else
        {
            //代码省略
        }
    }
}
