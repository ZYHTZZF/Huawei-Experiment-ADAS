#include "Executor.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace adas
{
    // 重载Pose的==，用的全局函数，用于比较第二个姿态对象是不是相对
    bool operator==(const Pose &lhs, const Pose &rhs) noexcept
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    // 下面二个测试用例，测试静态方法Executor::NewExecutor
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given 给定测试条件
        // 测试条件就是调用Executor的静态方法NewExecutor，返回一个指向Executor对象的智能指针executor，这样我们就不需要去delete了
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给了初始姿势
        // when

        // then
        const Pose target({0, 0, 'E'}); // 构造一个姿势对象target，其内容为{0,0,'E'}
        // 既然构造函数给了初始姿势，那么查询executor的姿势，应该和target相等
        // 所以这里用了断言：executor->Query()返回的姿势对象，应该和target相等，否则测试失败，说明Executor的实现有问题
        ASSERT_EQ(target, executor->Query()); // ASSERT_EQ内部调用了重载的Pose的==
    }
    // 测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 没有给初始姿势，使用默认的
        // when

        // then
        const Pose target({0, 0, 'N'}); // 默认姿势是{0,0,'N'}
        ASSERT_EQ(target, executor->Query());
    }
}