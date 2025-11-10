#include "Executor.hpp"
#include "PoseEq.hpp"
#include <gtest/gtest.h>
#include <memory>

namespace adas
{
        // 测试用例，测试Execute方法，在加速状态下，朝向为E，起点为（0，0）时去执行BM指令是否正确
    TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 初始姿态为（0，0，E）
        // when
        executor->Execute("BM");
        // then
        const Pose target({-1, 0, 'E'});      // 如果指令正确执行，那么汽车应该向西移动1个单位，姿态变为（-1，0，E）
        ASSERT_EQ(target, executor->Query()); // 当M指令执行完，executor->Query()返回的姿态应该和target相
    }

    TEST(ExecutorReverseTest, should_return_S_given_status_is_back_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 初始姿态为（0，0，E）
        // when
        executor->Execute("BL");
        // then
        const Pose target({0, 0, 'S'});    
        ASSERT_EQ(target, executor->Query()); // 当L指令执行完，executor->Query()返回的姿态应该和target相等
    }

    TEST(ExecutorReverseTest, should_return_N_given_status_is_reverse_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 初始姿态为（0，0，E）
        // when
        executor->Execute("BR");
        // then
        const Pose target({0, 0, 'N'});    
        ASSERT_EQ(target, executor->Query()); // 当R指令执行完，executor->Query()返回的姿态应该和target相等
    }

    TEST(ExecutorReverseTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0,0,'N'})); // 默认起始状态是{0,0,'N'}
        // when
        executor->Execute("BBM"); // BBM等价于M
        // then
        const Pose target{0, 1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }


}
