#pragma once

#include "IHook.hpp"
#include "main.hpp"
using namespace RumbleMod;

#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"
using namespace Libraries::HM::HMLib::VR;

namespace RumbleMod::Hooks {
    class MainMenuViewControllerHook : IHook {
    public:
        inline static HapticPresetSO* rumblePreset;

        void AddHooks() override;
        void RemoveHooks() override;
        explicit MainMenuViewControllerHook(const std::string& name) : IHook(name) {}
    };
}