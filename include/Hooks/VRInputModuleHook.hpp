#pragma once

#include "IHook.hpp"
#include "main.hpp"
using namespace RumbleMod;

namespace RumbleMod::Hooks {
    class VRInputModuleHook : IHook {
    public:
        void AddHooks() override;
        void RemoveHooks() override;
        explicit VRInputModuleHook(const std::string& name) : IHook(name) {}
    };
}