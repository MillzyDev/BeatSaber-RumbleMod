#pragma once

#include "IHook.hpp"
#include "main.hpp"
using namespace RumbleMod;

namespace RumbleMod::Hooks {
    class SaberClashEffectHook : IHook {
    public:
        void AddHooks() override;
        void RemoveHooks() override;
        explicit SaberClashEffectHook(const std::string& name) : IHook(name) {}
    };
}