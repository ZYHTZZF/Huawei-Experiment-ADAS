#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /*
    Executor的具体实现
    */
    class ExecutorImpl : public Executor
    {
        public:
        //构造函数，传入初始姿态
        explicit ExecutorImpl(const Pose &pose) noexcept;
        //默认析构函数
        ~ExecutorImpl(void) noexcept = default;

        //不能拷贝
        ExecutorImpl(const ExecutorImpl &) = delete;
        //不能赋值
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;
        public:
        //查询当前汽车姿态，重写基类的纯虚函数
        Pose Query(void) const noexcept override;

        private:
        Pose pose;
    };

} //namespace adas