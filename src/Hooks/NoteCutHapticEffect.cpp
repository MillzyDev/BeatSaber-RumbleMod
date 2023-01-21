#include "main.hpp"
#include "hooking.hpp"
#include "Configuration/ModConfig.hpp"

#include "GlobalNamespace/HapticFeedbackController.hpp"
#include "GlobalNamespace/NoteCutHapticEffect.hpp"
#include "GlobalNamespace/SaberType.hpp"

#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"

using namespace GlobalNamespace;
using namespace Libraries::HM::HMLib;

MAKE_HOOK_FIND_CLASS_UNSAFE_INSTANCE(NoteCutHapticEffect_ctor, "", "NoteCutHapticEffect", ".ctor", void,
    NoteCutHapticEffect *self
) {
    NoteCutHapticEffect_ctor(self);
    if (getModConfig().noteEnabled.GetValue()) {
        float strength = getModConfig().noteStrength.GetValue();
        self->normalPreset->strength = strength;
        self->shortNormalPreset->strength = strength;
    }
    if (getModConfig().chainEnabled.GetValue()) {
        self->shortWeakPreset->strength = getModConfig().chainStrength.GetValue();
    }
}

void InstallNoteCutHapticEffectHooks(Logger &logger) {
    INSTALL_HOOK(logger, NoteCutHapticEffect_ctor);
}

RegisterInstallFunction(InstallNoteCutHapticEffectHooks);