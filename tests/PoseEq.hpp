#pragma once
#include "Executor.hpp"
#include <tuple>

namespace adas
{
    bool operator==(const Pose& lhs, const Pose& rhs) noexcept;
}