#include "PoseEq.hpp"

namespace adas
{
    // 重载Pose的==，用的全局函数，用于比较第二个姿态对象是不是相对
    bool operator==(const Pose &lhs, const Pose &rhs) noexcept
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
}

