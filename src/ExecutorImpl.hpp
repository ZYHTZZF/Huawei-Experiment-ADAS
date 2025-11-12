#pragma once
#include "Executor.hpp"
#include <string>
#include "core/PoseHandler.hpp"

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
        PoseHandler poseHandler;
    };
} // namespace adas

/////////////////10.29记录，完成至ppt的page41