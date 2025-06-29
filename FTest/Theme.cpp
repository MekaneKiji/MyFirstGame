#pragma once

namespace MyApp {
    public ref class ThemeManager {
    private:
        static bool isDarkMode = false;
    public:
        static event System::EventHandler^ ThemeChanged;

        static void SetDarkMode(bool darkMode) {
            isDarkMode = darkMode;
            ThemeChanged(nullptr, System::EventArgs::Empty);
        }

        static bool IsDarkMode() { return isDarkMode; }
    };
}