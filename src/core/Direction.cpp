#include "Direction.hpp"
namespace adas
{
    static const Direction directions[4] = {
        {0, 'E'},
        {1, 'S'},
        {2, 'W'},
        {3, 'N'},
    };
    static const Point points[4] = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1},
    };
    const Direction &Direction::GetDirection(const char heading) noexcept
    {
        for (const auto &direction : directions)
        {
            if (direction.heading == heading)
                return direction;
        }
        return directions[3];
    }
    Direction::Direction(const unsigned index, const char heading) noexcept
    {
        Direction::index = index;
        Direction::heading = heading;
    }
    const Point &Direction::Move() const noexcept
    {
        for (unsigned i = 0; i < 4; i++)
        {
            if (Direction::index == i)
                return points[i];
        }
        return points[3];
    }
    const Direction &Direction::LeftOne() const noexcept
    {
        for (unsigned i = 0; i < 4; i++)
        {
            if (Direction::index == i)
                return directions[(i + 3) % 4];
        }
        return directions[2];
    }
    const Direction &Direction::RightOne() const noexcept
    {
        for (unsigned i = 0; i < 4; i++)
        {
            if (Direction::index == i)
                return directions[(i + 1) % 4];
        }
        return directions[0];
    }
    const char Direction::GetHeading() const noexcept
    {
        return Direction::heading;
    }
}