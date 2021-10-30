#pragma once

#include "IHook.hpp"
#include "main.hpp"
using namespace RumbleMod;

namespace RumbleMod::Hooks {
    class ObstacleSaberSparkleEffectManagerHook : IHook {
    public:
        void AddHooks() override;
        void RemoveHooks() override;
        explicit ObstacleSaberSparkleEffectManagerHook(const std::string& name) : IHook(name) {}
    };
}