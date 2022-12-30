#include "UI/SettingsUI.hpp"
#include "logging.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"

#include "bsml/shared/BSML.hpp"


DEFINE_TYPE(RumbleMod::UI, SettingsUI);

namespace RumbleMod::UI {
    void SettingsUI::ctor(::GlobalNamespace::MainFlowCoordinator *mainFlowCoordinator,
                          ::RumbleMod::UI::FlowCoordinators::SettingsFlowCoordinator *settingsFlowCoordinator) {
        DEBUG("ctor");
        _mainFlowCoordinator = mainFlowCoordinator;
        _settingsFlowCoordinator = settingsFlowCoordinator;
        _menuButton = BSML::MenuButton::Make_new("RumbleMod", "Customise controller feedback!",
                                                 std::bind(&SettingsUI::ShowFlow, this));
    }

    void SettingsUI::ShowFlow() {
        _mainFlowCoordinator->YoungestChildFlowCoordinatorOrSelf()
            ->PresentFlowCoordinator(_settingsFlowCoordinator, nullptr,
                                     ::HMUI::ViewController::AnimationDirection::Horizontal, false, false);
    }

    void SettingsUI::Initialize() {
        DEBUG("Init");
        ::BSML::Register::RegisterMenuButton(_menuButton);
    }

    void SettingsUI::Dispose() {
        DEBUG("Dispose");
        ::BSML::Register::UnRegisterMenuButton(_menuButton);
    }
}