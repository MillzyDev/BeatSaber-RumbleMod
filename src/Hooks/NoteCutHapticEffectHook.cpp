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
    if ((getModConfig().enabled.GetValue()) && (getModConfig().strength.GetValue() > 0) && (getModConfig().duration.GetValue() > 0)) {
        self->hapticFeedbackController->PlayHapticFeedback(XRNode(saberType.value), static_cast<HapticPresetSO*>(NoteCutHapticEffectHook::rumblePreset));
    }

    return;
}

void NoteCutHapticEffectHook::AddHooks() {
    INSTALL_HOOK(getLogger(), NoteCutHapticEffect_HitNote)
}

void NoteCutHapticEffectHook::RemoveHooks() {
    UNINSTALL_HOOK(getLogger(), NoteCutHapticEffect_HitNote);
}