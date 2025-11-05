#pragma once
#include "ExecutorImpl.hpp"

namespace adas
{
    class ICommand
    {
    public:
        // 给出析构函数和纯虚函数DoOperate的声明
        virtual ~ICommand(void) noexcept = default;
        virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
    };
    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept override
        {
            executor.Move();
        }
    };
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept
        {
            executor.TurnLeft();
        }
    };
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(ExecutorImpl &executor) const noexcept
        {
            executor.TurnRight();
        }
    };
}