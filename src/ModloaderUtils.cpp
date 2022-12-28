#include "ModloaderUtils.hpp"

namespace RumbleMod {
    bool ModloaderUtils::modIsInstalled(std::string id) {
        std::unordered_map<std::string, const Mod> mods = Modloader::getMods();

        bool installed = false;

        for (std::unordered_map<std::string, const Mod>::iterator it = mods.begin(); it != mods.end(); it++) {
            if (it->first == id) installed = true;
        }

        return installed;
    }
}