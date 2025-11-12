#pragma once
#include "ActionGroup.hpp"
#include "ExecutorImpl.hpp"
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
    class MoveCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;

            if (poseHandler.IsFast())
            {
                actionGroup.PushAction(action);
            }

            actionGroup.PushAction(action);
            return actionGroup;
        }
    };

    class TurnLeftCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto moveAction = poseHandler.IsReverse()
                                        ? ActionType::BACKWARD_1_STEP_ACTION
                                        : ActionType::FORWARD_1_STEP_ACTION;

            const auto turnAction = poseHandler.IsReverse()
                                        ? ActionType::REVERSE_TURNLEFT_ACTION
                                        : ActionType::TURNLEFT_ACTION;

            // when fast, first move (forward/backward) then turn once
            if (poseHandler.IsFast())
            {
                actionGroup.PushAction(moveAction);
            }

            actionGroup.PushAction(turnAction);
            return actionGroup;
        }

        // void operator()(PoseHandler &poseHandler) const noexcept
        // {
        //     if(poseHandler.IsFast()){
        //         if(poseHandler.IsReverse()){
        //             poseHandler.Backward();
        //         }
        //         else{
        //             poseHandler.Forward();
        //         }
        //     }
        //     if(poseHandler.IsReverse()){
        //         poseHandler.TurnRight();
        //     }
        //     else{
        //         poseHandler.TurnLeft();
        //     }

        // };
    };
    class TurnRightCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto moveAction = poseHandler.IsReverse()
                                        ? ActionType::BACKWARD_1_STEP_ACTION
                                        : ActionType::FORWARD_1_STEP_ACTION;

            const auto turnAction = poseHandler.IsReverse()
                                        ? ActionType::REVERSE_TURNRIGHT_ACTION
                                        : ActionType::TURNRIGHT_ACTION;

            // when fast, first move (forward/backward) then turn once
            if (poseHandler.IsFast())
            {
                actionGroup.PushAction(moveAction);
            }

            actionGroup.PushAction(turnAction);
            return actionGroup;
        }
        // void operator()(PoseHandler &poseHandler) const noexcept
        // {
        //     if (poseHandler.IsFast())
        //     {
        //         if (poseHandler.IsReverse())
        //         {
        //             poseHandler.Backward();
        //         }
        //         else
        //         {
        //             poseHandler.Forward();
        //         }
        //     }
        //     if (poseHandler.IsReverse())
        //     {
        //         poseHandler.TurnLeft();
        //     }
        //     else
        //     {
        //         poseHandler.TurnRight();
        //     }
        // };
    };

    class FastCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            actionGroup.PushAction(ActionType::BE_FAST_ACTION);
            return actionGroup;
        }
        // public:
        //     void operator()(PoseHandler &poseHandler) const noexcept
        //     {
        //         poseHandler.Fast();
        //     };
    };

    class ReverseCommand final //: public ICommand
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            actionGroup.PushAction(ActionType::BE_REVERSE_ACTION);
            return actionGroup;
        }
        // void operator()(PoseHandler &poseHandler) const noexcept
        // {
        //     poseHandler.Reverse();
        // };
    };
}