#include "main.hpp"
#include "Config/ModConfig.hpp"

#include "Hooks/NoteCutHapticEffectHook.hpp"
using namespace RumbleMod::Hooks;

#include "GlobalNamespace/ObstacleSaberSparkleEffectManager.hpp"
#include "GlobalNamespace/NoteCutHapticEffect.hpp"
#include "GlobalNamespace/HapticFeedbackController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/XR/XRNode.hpp"
using namespace UnityEngine::XR;

#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"
using namespace Libraries::HM::HMLib::VR;

MAKE_HOOK_MATCH(NoteCutHapticEffect_HitNote, &NoteCutHapticEffect::HitNote, void,
    NoteCutHapticEffect* self, SaberType saberType
) {
    static float originalStrength = self->rumblePreset->strength;
    static float originalDuration = self->rumblePreset->duration;

    if (getModConfig().enabled.GetValue()) {
        self->rumblePreset->strength = getModConfig().strength.GetValue();
        self->rumblePreset->duration = getModConfig().duration.GetValue();
        getLogger().info("Note Rumble: strength=%f, duration=%f", getModConfig().strength.GetValue(), getModConfig().duration.GetValue());
    } else {
        self->rumblePreset->strength = originalStrength;
        self->rumblePreset->duration = originalDuration;
    }

    NoteCutHapticEffect_HitNote(self, saberType);
}

void NoteCutHapticEffectHook::AddHooks() {
    INSTALL_HOOK(getLogger(), NoteCutHapticEffect_HitNote)
}

void NoteCutHapticEffectHook::RemoveHooks() {
    UNINSTALL_HOOK(getLogger(), NoteCutHapticEffect_HitNote);
}