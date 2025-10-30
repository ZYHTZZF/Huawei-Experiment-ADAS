#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /*
    Executor的具体实现
    */
    class ExecutorImpl final : public Executor
    {
    public:
        // 构造函数，传入初始姿态
        explicit ExecutorImpl(const Pose &pose) noexcept;
        // 默认析构函数
        ~ExecutorImpl(void) noexcept = default;

        // 不能拷贝
        ExecutorImpl(const ExecutorImpl &) = delete;
        // 不能赋值
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        // 查询当前汽车姿态，重写基类的纯虚函数
        Pose Query(void) const noexcept override;
        // 第二阶段新增加的纯虚函数，执行一个用字符串表示的指令
        void Execute(const std::string &commands) noexcept override;

    private:
        class ICommand
        {
        public:
            // 给出析构函数和纯虚函数DoOperate的声明
            virtual ~ICommand(void) noexcept = default;
            virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
        };
        // 当前汽车姿态
        Pose pose;
        // 是否处于加速状态，默认是false
        bool isFast;
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;         // 切换加速状态
        bool IsFast(void) const noexcept; // 查询是否处于加速状态
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

   // private:
    //    Pose pose;
    //    bool fast{false}; // 记录当前是否为加速状态
    };
} // namespace adas

/////////////////10.29记录，完成至ppt的page41