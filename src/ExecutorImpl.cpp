#include "ExecutorImpl.hpp"
#include "Command.hpp"
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
            std::unique_ptr<ICommand> cmder;
            //如果是M指令
            if(cmd == 'M')
            {
                cmder =std::make_unique<MoveCommand>();
            }
            else if(cmd == 'L')
            {
                cmder=std::make_unique<TurnLeftCommand>();
            }
            else if(cmd == 'R')
            {
                cmder=std::make_unique<TurnRightCommand>();
            }
            else if(cmd == 'F')
            {
                Fast();
                continue;
            }
            if(cmder)
            {
                cmder->DoOperate(*this);
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
            if(pose.heading=='E'){ pose.x+=2; }
            else if(pose.heading=='W'){ pose.x-=2; }
            else if(pose.heading=='N'){ pose.y+=2; }
            else if(pose.heading=='S'){ pose.y-=2; }
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
            if(pose.heading=='E'){pose.x+=1; pose.heading='N'; }
            else if(pose.heading=='N'){pose.y+=1; pose.heading='W'; }
            else if(pose.heading=='W'){pose.x-=1; pose.heading='S'; }
            else if(pose.heading=='S'){pose.y-=1; pose.heading='E'; }
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
            if(pose.heading=='E'){pose.x+=1; pose.heading='S'; }
            else if(pose.heading=='S'){pose.y-=1; pose.heading='W'; }
            else if(pose.heading=='W'){pose.x-=1; pose.heading='N'; }
            else if(pose.heading=='N'){pose.y+=1; pose.heading='E'; }
        }
    }

    void ExecutorImpl::Fast(void) noexcept
    {
        isFast = !isFast;
    }

    bool ExecutorImpl::IsFast(void) const noexcept
    {
        return isFast;
    }

    // 记录当前是否为加速状态
}
