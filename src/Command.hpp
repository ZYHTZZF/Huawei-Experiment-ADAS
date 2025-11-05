#pragma once
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
    //class ICommand
    //{
    //public:
    //    // 给出析构函数和纯虚函数DoOperate的声明
    //    virtual ~ICommand(void) noexcept = default;
    //    virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
    //};
    class MoveCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     if (poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //         poseHandler.Move();
        //     }
        //     else
        //     {
        //         poseHandler.Move();
        //     }
        // }

        void operator()(PoseHandler& poseHandler)const noexcept {
            if(poseHandler.IsFast()){
                poseHandler.Move();
            }
            poseHandler.Move();
        };
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler& poseHandler) const noexcept
        // {
        //     if(poseHandler.IsFast())
        //     {
        //         poseHandler.Move();
        //         poseHandler.TurnLeft();
        //     }
        //     else{
        //         poseHandler.TurnLeft();
        //     }
        // }
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if(poseHandler.IsFast()){
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
    };
    class TurnRightCommand final //: public ICommand
    {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept
    //     {
    //         if(poseHandler.IsFast())
    //         {
    //             poseHandler.Move();
    //             poseHandler.TurnRight();
    //         }
    //         else{
    //             poseHandler.TurnRight();
    //         }
    //     }
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if(poseHandler.IsFast()){
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
    };

    class FastCommand final //: public ICommand
    {
    public:
        // void DoOperate(PoseHandler &poseHandler) const noexcept override
        // {
        //     poseHandler.Fast();
        // }
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        };
    };
}