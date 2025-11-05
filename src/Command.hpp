#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        // 给出析构函数和纯虚函数DoOperate的声明
        virtual ~ICommand(void) noexcept = default;
        virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
    };
    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Move();
        }
    };
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler& poseHandler) const noexcept
        {
            poseHandler.TurnLeft();
        }
    };
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.TurnRight();
        }
    };
}