#pragma once

#include "Executor.hpp"
#include "PoseHandler.hpp"
#include "Direction.hpp"
#include <string>
namespace adas
{
    class PoseHandler final {
        public:
            PoseHandler(const Pose& pose) noexcept;
            PoseHandler(const PoseHandler&) = delete;
            PoseHandler& operator=(const PoseHandler&) = delete;
        
        public:
            void Forward(void) noexcept;
            void Backward(void) noexcept;

            void TurnLeft(void) noexcept;
            void TurnRight(void) noexcept;

            void Fast(void) noexcept; // 切换加速状态
            void Reverse(void) noexcept; // 切换倒车状态

            bool IsFast(void) const noexcept; // 查询是否处于加速状态
            bool IsReverse(void) const noexcept; // 查询是否处于倒车状态
            
            Pose Query(void) const noexcept; // 查询当前位置


        private:
            Point point;
            const Direction* facing;
            bool isFast{false}; // 记录当前是否为加速状态
            bool reverse{false}; // 记录当前是否为倒车状态

    };
}