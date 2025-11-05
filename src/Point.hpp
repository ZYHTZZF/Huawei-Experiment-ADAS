#pragma once

namespace adas
{
    class Point final
    {
    public:
        Point(const int x, const int y) noexcept;

        Point(const Point &rhs) noexcept;            // 拷贝构造
        Point &operator=(const Point &rhs) noexcept; // 拷贝赋值
        Point &operator=(Point &&rhs) noexcept;      // 移动
        Point &operator+=(const Point &rhs) noexcept;

    public:
        int GetX(void) const noexcept;
        int GetY(void) const noexcept;

    private:
        int x;
        int y;
    };
}