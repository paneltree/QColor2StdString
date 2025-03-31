#ifndef THEMECOLORS_H
#define THEMECOLORS_H

#include <QtGui/QColor>
#include <QString>
#include <QMap>
#include <vector>
#include <string>

namespace ColorConversion {

enum class ColorTheme {
    Light,
    Dark,
    System // Uses the current system theme
};

enum class ColorRole {
    // Basic UI colors
    Primary,
    Secondary,
    Accent,
    Success,
    Warning,
    Error,
    Info,
    
    // Background colors
    Background,
    Surface,
    Card,
    Dialog,
    
    // Text colors
    TextPrimary,
    TextSecondary,
    TextDisabled,
    TextOnPrimary,
    TextOnAccent,
    
    // Border & Divider colors
    Border,
    Divider,
    
    // State colors
    Hover,
    Pressed,
    Focus,
    Disabled,
    
    // Other UI colors
    Shadow,
    Overlay,
    Selection,
    
    // Semantic colors
    Link,
    Visited,
    
    // Palette colors (1-20)
    Palette1,
    Palette2,
    Palette3,
    Palette4,
    Palette5,
    Palette6,
    Palette7,
    Palette8,
    Palette9,
    Palette10,
    Palette11,
    Palette12,
    Palette13,
    Palette14,
    Palette15,
    Palette16,
    Palette17,
    Palette18,
    Palette19,
    Palette20
};

class ThemeColors {
public:
    // Get the singleton instance
    static ThemeColors& getInstance();

    // Get color for a specific role in the current theme
    QColor getColor(ColorRole role) const;
    
    // Get color for a specific role in a specific theme
    QColor getColor(ColorRole role, ColorTheme theme) const;
    
    // Get color name for a role
    QString getColorName(ColorRole role) const;
    
    // Get current theme
    ColorTheme getCurrentTheme() const;
    
    // Set current theme
    void setTheme(ColorTheme theme);
    
    // Convert theme color to string
    std::string themeColorToString(ColorRole role) const;
    
    // Get a list of all color roles
    std::vector<ColorRole> getAllColorRoles() const;
    
    // Get a list of all predefined palette colors for the current theme
    std::vector<QColor> getPaletteColors() const;
    
    // Get a list of all predefined palette colors for a specific theme
    std::vector<QColor> getPaletteColors(ColorTheme theme) const;

private:
    // Private constructor for singleton
    ThemeColors();
    
    // Initialize colors for light theme
    void initLightThemeColors();
    
    // Initialize colors for dark theme
    void initDarkThemeColors();
    
    // Detect system theme
    ColorTheme detectSystemTheme() const;
    
    // Current theme
    ColorTheme currentTheme;
    
    // Maps to store colors for each theme
    QMap<ColorRole, QColor> lightThemeColors;
    QMap<ColorRole, QColor> darkThemeColors;
    
    // Map to store color role names
    QMap<ColorRole, QString> colorRoleNames;
};

} // namespace ColorConversion

#endif // THEMECOLORS_H 