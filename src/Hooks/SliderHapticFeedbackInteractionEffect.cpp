#include "main.hpp"
#include "hooking.hpp"
#include "Configuration/ModConfig.hpp"

#include "GlobalNamespace/HapticFeedbackController.hpp"
#include "GlobalNamespace/SliderHapticFeedbackInteractionEffect.hpp"

#include "Libraries/HM/HMLib/VR/HapticPresetSO.hpp"

using namespace GlobalNamespace;
using namespace Libraries::HM::HMLib;

MAKE_HOOK_FIND_CLASS_UNSAFE_INSTANCE(SliderHapticFeedbackInteractionEffect_ctor, "", "SliderHapticFeedbackInteractionEffect", ".ctor", void,
    SliderHapticFeedbackInteractionEffect *self
) {
    SliderHapticFeedbackInteractionEffect_ctor(self);
    if (getModConfig().arcEnabled.GetValue()) {
        self->hapticPreset->strength = getModConfig().arcStrength.GetValue();
    }
}

void InstallSliderHapticFeedbackInteractionEffectHooks(Logger &logger) {
    INSTALL_HOOK(logger, SliderHapticFeedbackInteractionEffect_ctor);
}

RegisterInstallFunction(InstallSliderHapticFeedbackInteractionEffectHooks);