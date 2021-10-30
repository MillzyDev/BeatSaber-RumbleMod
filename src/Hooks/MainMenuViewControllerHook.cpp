#include "main.hpp"
#include "Config/ModConfig.hpp"

#include "Hooks/MainViewControllerHook.hpp"
#include "Hooks/NoteCutHapticEffectHook.hpp"
using namespace RumbleMod::Hooks;

#include "GlobalNamespace/MainMenuViewController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/ScriptableObject.hpp"
using namespace UnityEngine;

MAKE_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void,
    MainMenuViewController* self, bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling
) {
    if (firstActivation)
        NoteCutHapticEffectHook::rumblePreset = ScriptableObject::CreateInstance<HapticPresetSO*>();

    MainMenuViewController_DidActivate(self, firstActivation, addedToHeirarchy, screenSystemEnabling);
}

void MainMenuViewControllerHook::AddHooks() {
    INSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}

void MainMenuViewControllerHook::RemoveHooks() {
    UNINSTALL_HOOK(getLogger(), MainMenuViewController_DidActivate);
}