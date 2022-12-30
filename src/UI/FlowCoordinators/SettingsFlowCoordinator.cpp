#include "UI/FlowCoordinators/SettingsFlowCoordinator.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(RumbleMod::UI::FlowCoordinators, SettingsFlowCoordinator);

namespace RumbleMod::UI::FlowCoordinators {
    void SettingsFlowCoordinator::Inject(::GlobalNamespace::MainFlowCoordinator *mainFlowCoordinator,
                                         ::RumbleMod::UI::ViewControllers::SettingsViewController *settingsViewController) {
        _mainFlowCoordinator = mainFlowCoordinator;
        _settingsViewController = settingsViewController;
    }

    void SettingsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
        if (!firstActivation) return;
        set_showBackButton(true);
        SetTitle("RumbleMod", ::HMUI::ViewController::AnimationType::In);
        ProvideInitialViewControllers(_settingsViewController, nullptr, nullptr, nullptr, nullptr);
    }

    void SettingsFlowCoordinator::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {
    }

    void SettingsFlowCoordinator::BackButtonWasPressed() {
        parentFlowCoordinator->DismissFlowCoordinator(this, ::HMUI::ViewController::AnimationDirection::Horizontal,
                                                      nullptr, false);
    }
}