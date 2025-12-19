#pragma once
#include "Cmder0rchestrator.hpp"

namespace adas
{
    class Normal0rchestrator : public Cmder0rchestrator
    {
    public:
        ActionGroup Move(const PoseHandler &poseHandler) const noexcept override;
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAction(GetStepAction(poseHandler));
            return actionGroup;
        }
    }
}

//////11.14记录，完成至实验四ppt的page61

