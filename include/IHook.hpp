#pragma once

#include "main.hpp"

#include <string>
#include <vector>

namespace RumbleMod {

    /*
     * DECLARE IHOOK INTERFACE CLASS
     */

    class IHook {
    private:
        static std::vector<IHook*> hooks;
    protected:
        std::string name;

    public:
        static bool InstallHooks();
        static bool UninstallHooks();

        explicit IHook(const std::string& name);

        virtual void AddHooks();
        virtual void RemoveHooks();
    };
}