#pragma once

#include "Point.hpp"
/**
 * 方向类
 */
namespace adas {
class Direction final {
public:
    static const Direction& GetDirection(const char heading) noexcept;

public:
    Direction(const unsigned index, const char heading) noexcept;

public:
    const Point& Move(void) const noexcept;
    const Direction& LeftOne(void) const noexcept;
    const Direction& RightOne(void) const noexcept;

    const char GetHeading(void) const noexcept;

private:
    unsigned index; //方向索引0 1 2 3 
    char heading;   //方向字符E S W N
};
} // namespace adas