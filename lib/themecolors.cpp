#include "themecolors.h"
#include "qcolor2stdstring.h"
#include <QtWidgets/QApplication>
#include <QtGui/QPalette>

namespace ColorConversion {

ThemeColors& ThemeColors::getInstance() {
    static ThemeColors instance;
    return instance;
}

ThemeColors::ThemeColors() : currentTheme(ColorTheme::System) {
    // Initialize color role names
    colorRoleNames[ColorRole::Primary] = "Primary";
    colorRoleNames[ColorRole::Secondary] = "Secondary";
    colorRoleNames[ColorRole::Accent] = "Accent";
    colorRoleNames[ColorRole::Success] = "Success";
    colorRoleNames[ColorRole::Warning] = "Warning";
    colorRoleNames[ColorRole::Error] = "Error";
    colorRoleNames[ColorRole::Info] = "Info";
    colorRoleNames[ColorRole::Background] = "Background";
    colorRoleNames[ColorRole::Surface] = "Surface";
    colorRoleNames[ColorRole::Card] = "Card";
    colorRoleNames[ColorRole::Dialog] = "Dialog";
    colorRoleNames[ColorRole::TextPrimary] = "TextPrimary";
    colorRoleNames[ColorRole::TextSecondary] = "TextSecondary";
    colorRoleNames[ColorRole::TextDisabled] = "TextDisabled";
    colorRoleNames[ColorRole::TextOnPrimary] = "TextOnPrimary";
    colorRoleNames[ColorRole::TextOnAccent] = "TextOnAccent";
    colorRoleNames[ColorRole::Border] = "Border";
    colorRoleNames[ColorRole::Divider] = "Divider";
    colorRoleNames[ColorRole::Hover] = "Hover";
    colorRoleNames[ColorRole::Pressed] = "Pressed";
    colorRoleNames[ColorRole::Focus] = "Focus";
    colorRoleNames[ColorRole::Disabled] = "Disabled";
    colorRoleNames[ColorRole::Shadow] = "Shadow";
    colorRoleNames[ColorRole::Overlay] = "Overlay";
    colorRoleNames[ColorRole::Selection] = "Selection";
    colorRoleNames[ColorRole::Link] = "Link";
    colorRoleNames[ColorRole::Visited] = "Visited";
    colorRoleNames[ColorRole::Palette1] = "Palette1";
    colorRoleNames[ColorRole::Palette2] = "Palette2";
    colorRoleNames[ColorRole::Palette3] = "Palette3";
    colorRoleNames[ColorRole::Palette4] = "Palette4";
    colorRoleNames[ColorRole::Palette5] = "Palette5";
    colorRoleNames[ColorRole::Palette6] = "Palette6";
    colorRoleNames[ColorRole::Palette7] = "Palette7";
    colorRoleNames[ColorRole::Palette8] = "Palette8";
    colorRoleNames[ColorRole::Palette9] = "Palette9";
    colorRoleNames[ColorRole::Palette10] = "Palette10";
    colorRoleNames[ColorRole::Palette11] = "Palette11";
    colorRoleNames[ColorRole::Palette12] = "Palette12";
    colorRoleNames[ColorRole::Palette13] = "Palette13";
    colorRoleNames[ColorRole::Palette14] = "Palette14";
    colorRoleNames[ColorRole::Palette15] = "Palette15";
    colorRoleNames[ColorRole::Palette16] = "Palette16";
    colorRoleNames[ColorRole::Palette17] = "Palette17";
    colorRoleNames[ColorRole::Palette18] = "Palette18";
    colorRoleNames[ColorRole::Palette19] = "Palette19";
    colorRoleNames[ColorRole::Palette20] = "Palette20";
    
    // Initialize colors for both themes
    initLightThemeColors();
    initDarkThemeColors();
}

void ThemeColors::initLightThemeColors() {
    // Basic UI colors
    lightThemeColors[ColorRole::Primary] = QColor("#1976D2");       // Material Blue
    lightThemeColors[ColorRole::Secondary] = QColor("#424242");     // Material Grey 800
    lightThemeColors[ColorRole::Accent] = QColor("#E91E63");        // Material Pink
    lightThemeColors[ColorRole::Success] = QColor("#4CAF50");       // Material Green
    lightThemeColors[ColorRole::Warning] = QColor("#FFC107");       // Material Amber
    lightThemeColors[ColorRole::Error] = QColor("#F44336");         // Material Red
    lightThemeColors[ColorRole::Info] = QColor("#2196F3");          // Material Light Blue
    
    // Background colors
    lightThemeColors[ColorRole::Background] = QColor("#FFFFFF");    // White
    lightThemeColors[ColorRole::Surface] = QColor("#F5F5F5");       // Material Grey 100
    lightThemeColors[ColorRole::Card] = QColor("#FFFFFF");          // White
    lightThemeColors[ColorRole::Dialog] = QColor("#FFFFFF");        // White
    
    // Text colors
    lightThemeColors[ColorRole::TextPrimary] = QColor("#212121");   // Material Grey 900
    lightThemeColors[ColorRole::TextSecondary] = QColor("#757575"); // Material Grey 600
    lightThemeColors[ColorRole::TextDisabled] = QColor("#9E9E9E");  // Material Grey 500
    lightThemeColors[ColorRole::TextOnPrimary] = QColor("#FFFFFF"); // White
    lightThemeColors[ColorRole::TextOnAccent] = QColor("#FFFFFF");  // White
    
    // Border & Divider colors
    lightThemeColors[ColorRole::Border] = QColor("#E0E0E0");        // Material Grey 300
    lightThemeColors[ColorRole::Divider] = QColor("#EEEEEE");       // Material Grey 200
    
    // State colors
    lightThemeColors[ColorRole::Hover] = QColor("#F5F5F5");         // Material Grey 100
    lightThemeColors[ColorRole::Pressed] = QColor("#E0E0E0");       // Material Grey 300
    lightThemeColors[ColorRole::Focus] = QColor("#BBDEFB");         // Material Blue 100
    lightThemeColors[ColorRole::Disabled] = QColor("#BDBDBD");      // Material Grey 400
    
    // Other UI colors
    lightThemeColors[ColorRole::Shadow] = QColor(0, 0, 0, 26);      // Black 10%
    lightThemeColors[ColorRole::Overlay] = QColor(0, 0, 0, 50);     // Black 20% 
    lightThemeColors[ColorRole::Selection] = QColor("#90CAF9");     // Material Blue 200
    
    // Semantic colors
    lightThemeColors[ColorRole::Link] = QColor("#1976D2");          // Material Blue
    lightThemeColors[ColorRole::Visited] = QColor("#6A1B9A");       // Material Purple 800
    
    // Palette colors - 20 distinct colors for light theme
    lightThemeColors[ColorRole::Palette1] = QColor("#F44336");      // Red
    lightThemeColors[ColorRole::Palette2] = QColor("#E91E63");      // Pink
    lightThemeColors[ColorRole::Palette3] = QColor("#9C27B0");      // Purple
    lightThemeColors[ColorRole::Palette4] = QColor("#673AB7");      // Deep Purple
    lightThemeColors[ColorRole::Palette5] = QColor("#3F51B5");      // Indigo
    lightThemeColors[ColorRole::Palette6] = QColor("#2196F3");      // Blue
    lightThemeColors[ColorRole::Palette7] = QColor("#03A9F4");      // Light Blue
    lightThemeColors[ColorRole::Palette8] = QColor("#00BCD4");      // Cyan
    lightThemeColors[ColorRole::Palette9] = QColor("#009688");      // Teal
    lightThemeColors[ColorRole::Palette10] = QColor("#4CAF50");     // Green
    lightThemeColors[ColorRole::Palette11] = QColor("#8BC34A");     // Light Green
    lightThemeColors[ColorRole::Palette12] = QColor("#CDDC39");     // Lime
    lightThemeColors[ColorRole::Palette13] = QColor("#FFEB3B");     // Yellow
    lightThemeColors[ColorRole::Palette14] = QColor("#FFC107");     // Amber
    lightThemeColors[ColorRole::Palette15] = QColor("#FF9800");     // Orange
    lightThemeColors[ColorRole::Palette16] = QColor("#FF5722");     // Deep Orange
    lightThemeColors[ColorRole::Palette17] = QColor("#795548");     // Brown
    lightThemeColors[ColorRole::Palette18] = QColor("#9E9E9E");     // Grey
    lightThemeColors[ColorRole::Palette19] = QColor("#607D8B");     // Blue Grey
    lightThemeColors[ColorRole::Palette20] = QColor("#000000");     // Black
}

void ThemeColors::initDarkThemeColors() {
    // Basic UI colors
    darkThemeColors[ColorRole::Primary] = QColor("#90CAF9");       // Material Blue 200
    darkThemeColors[ColorRole::Secondary] = QColor("#BDBDBD");     // Material Grey 400
    darkThemeColors[ColorRole::Accent] = QColor("#F48FB1");        // Material Pink 200
    darkThemeColors[ColorRole::Success] = QColor("#81C784");       // Material Green 300
    darkThemeColors[ColorRole::Warning] = QColor("#FFD54F");       // Material Amber 300
    darkThemeColors[ColorRole::Error] = QColor("#E57373");         // Material Red 300
    darkThemeColors[ColorRole::Info] = QColor("#64B5F6");          // Material Light Blue 300
    
    // Background colors
    darkThemeColors[ColorRole::Background] = QColor("#121212");    // Material Dark Background
    darkThemeColors[ColorRole::Surface] = QColor("#1E1E1E");       // Slightly lighter dark
    darkThemeColors[ColorRole::Card] = QColor("#242424");          // Even slightly lighter dark
    darkThemeColors[ColorRole::Dialog] = QColor("#2C2C2C");        // Lighter dark for dialog
    
    // Text colors
    darkThemeColors[ColorRole::TextPrimary] = QColor("#FFFFFF");   // White
    darkThemeColors[ColorRole::TextSecondary] = QColor("#B0B0B0"); // Light grey
    darkThemeColors[ColorRole::TextDisabled] = QColor("#707070");  // Mid-grey
    darkThemeColors[ColorRole::TextOnPrimary] = QColor("#000000"); // Black
    darkThemeColors[ColorRole::TextOnAccent] = QColor("#000000");  // Black
    
    // Border & Divider colors
    darkThemeColors[ColorRole::Border] = QColor("#424242");        // Material Grey 800
    darkThemeColors[ColorRole::Divider] = QColor("#323232");       // Slightly lighter than surface
    
    // State colors
    darkThemeColors[ColorRole::Hover] = QColor("#383838");         // Slightly lighter than card
    darkThemeColors[ColorRole::Pressed] = QColor("#505050");       // Slightly darker than hover
    darkThemeColors[ColorRole::Focus] = QColor("#0D47A1");         // Material Blue 900
    darkThemeColors[ColorRole::Disabled] = QColor("#424242");      // Material Grey 800
    
    // Other UI colors
    darkThemeColors[ColorRole::Shadow] = QColor(0, 0, 0, 80);      // Darker shadow for dark theme
    darkThemeColors[ColorRole::Overlay] = QColor(0, 0, 0, 90);     // Darker overlay for dark theme
    darkThemeColors[ColorRole::Selection] = QColor("#1565C0");     // Material Blue 800
    
    // Semantic colors
    darkThemeColors[ColorRole::Link] = QColor("#90CAF9");          // Material Blue 200
    darkThemeColors[ColorRole::Visited] = QColor("#CE93D8");       // Material Purple 200
    
    // Palette colors - 20 distinct colors for dark theme (brighter versions)
    darkThemeColors[ColorRole::Palette1] = QColor("#EF5350");      // Red 400
    darkThemeColors[ColorRole::Palette2] = QColor("#EC407A");      // Pink 400
    darkThemeColors[ColorRole::Palette3] = QColor("#AB47BC");      // Purple 400
    darkThemeColors[ColorRole::Palette4] = QColor("#7E57C2");      // Deep Purple 400
    darkThemeColors[ColorRole::Palette5] = QColor("#5C6BC0");      // Indigo 400
    darkThemeColors[ColorRole::Palette6] = QColor("#42A5F5");      // Blue 400
    darkThemeColors[ColorRole::Palette7] = QColor("#29B6F6");      // Light Blue 400
    darkThemeColors[ColorRole::Palette8] = QColor("#26C6DA");      // Cyan 400
    darkThemeColors[ColorRole::Palette9] = QColor("#26A69A");      // Teal 400
    darkThemeColors[ColorRole::Palette10] = QColor("#66BB6A");     // Green 400
    darkThemeColors[ColorRole::Palette11] = QColor("#9CCC65");     // Light Green 400
    darkThemeColors[ColorRole::Palette12] = QColor("#D4E157");     // Lime 400
    darkThemeColors[ColorRole::Palette13] = QColor("#FFEE58");     // Yellow 400
    darkThemeColors[ColorRole::Palette14] = QColor("#FFCA28");     // Amber 400
    darkThemeColors[ColorRole::Palette15] = QColor("#FFA726");     // Orange 400
    darkThemeColors[ColorRole::Palette16] = QColor("#FF7043");     // Deep Orange 400
    darkThemeColors[ColorRole::Palette17] = QColor("#8D6E63");     // Brown 400
    darkThemeColors[ColorRole::Palette18] = QColor("#BDBDBD");     // Grey 400
    darkThemeColors[ColorRole::Palette19] = QColor("#78909C");     // Blue Grey 400
    darkThemeColors[ColorRole::Palette20] = QColor("#FFFFFF");     // White
}

ColorTheme ThemeColors::detectSystemTheme() const {
    // Check if application palette's window color is dark or light
    if (QApplication::instance()) {
        QColor windowColor = QApplication::palette().color(QPalette::Window);
        // Calculate perceived brightness using common formula
        int brightness = (windowColor.red() * 299 + windowColor.green() * 587 + windowColor.blue() * 114) / 1000;
        return (brightness < 128) ? ColorTheme::Dark : ColorTheme::Light;
    }
    
    // Default to light theme if no application instance
    return ColorTheme::Light;
}

QColor ThemeColors::getColor(ColorRole role) const {
    // Get color for the current theme
    if (currentTheme == ColorTheme::System) {
        ColorTheme systemTheme = detectSystemTheme();
        return getColor(role, systemTheme);
    } else {
        return getColor(role, currentTheme);
    }
}

QColor ThemeColors::getColor(ColorRole role, ColorTheme theme) const {
    // Return the color for the specific theme
    if (theme == ColorTheme::System) {
        theme = detectSystemTheme();
    }
    
    if (theme == ColorTheme::Dark) {
        if (darkThemeColors.contains(role)) {
            return darkThemeColors[role];
        }
    } else { // Light theme
        if (lightThemeColors.contains(role)) {
            return lightThemeColors[role];
        }
    }
    
    // Return a default color if role not found
    return QColor(Qt::gray);
}

QString ThemeColors::getColorName(ColorRole role) const {
    if (colorRoleNames.contains(role)) {
        return colorRoleNames[role];
    }
    return "Unknown";
}

ColorTheme ThemeColors::getCurrentTheme() const {
    if (currentTheme == ColorTheme::System) {
        return detectSystemTheme();
    }
    return currentTheme;
}

void ThemeColors::setTheme(ColorTheme theme) {
    currentTheme = theme;
}

std::string ThemeColors::themeColorToString(ColorRole role) const {
    QColor color = getColor(role);
    return qColorToHexString(color, true);
}

std::vector<ColorRole> ThemeColors::getAllColorRoles() const {
    std::vector<ColorRole> roles;
    
    // Add all the color roles to the vector
    for (auto it = colorRoleNames.begin(); it != colorRoleNames.end(); ++it) {
        roles.push_back(it.key());
    }
    
    return roles;
}

std::vector<QColor> ThemeColors::getPaletteColors() const {
    return getPaletteColors(currentTheme == ColorTheme::System ? detectSystemTheme() : currentTheme);
}

std::vector<QColor> ThemeColors::getPaletteColors(ColorTheme theme) const {
    std::vector<QColor> paletteColors;
    
    // Get the correct theme colors
    const QMap<ColorRole, QColor>& themeColors = 
        (theme == ColorTheme::Dark || (theme == ColorTheme::System && detectSystemTheme() == ColorTheme::Dark)) 
        ? darkThemeColors : lightThemeColors;
    
    // Add the 20 palette colors to the vector
    for (int i = 1; i <= 20; i++) {
        ColorRole role = static_cast<ColorRole>(static_cast<int>(ColorRole::Palette1) + i - 1);
        paletteColors.push_back(themeColors[role]);
    }
    
    return paletteColors;
}

} // namespace ColorConversion 