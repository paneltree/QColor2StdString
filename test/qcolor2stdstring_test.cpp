#include "qcolor2stdstring.h"
#include <gtest/gtest.h>
#include <QtGui/QColor>

namespace {

// Test QColor to std::string conversion
TEST(QColorConversion, QColorToStdString) {
    QColor red(255, 0, 0);
    std::string result = ColorConversion::qColorToStdString(red);
    EXPECT_EQ(result, "rgba(255,0,0,1.0)");
    
    QColor transparent(255, 0, 0, 128);
    result = ColorConversion::qColorToStdString(transparent);
    EXPECT_EQ(result, "rgba(255,0,0,0.5)");
}

// Test QColor to hex string conversion
TEST(QColorConversion, QColorToHexString) {
    QColor red(255, 0, 0);
    std::string result = ColorConversion::qColorToHexString(red);
    EXPECT_EQ(result, "#ff0000");
    
    // With alpha
    result = ColorConversion::qColorToHexString(red, true);
    EXPECT_EQ(result, "#ffff0000");
    
    QColor transparent(255, 0, 0, 128);
    result = ColorConversion::qColorToHexString(transparent, true);
    EXPECT_EQ(result, "#80ff0000");
}

// Test std::string to QColor conversion - hex format
TEST(QColorConversion, StdStringToQColorHex) {
    QColor expected(255, 0, 0);
    QColor result = ColorConversion::stdStringToQColor("#ff0000");
    EXPECT_EQ(result, expected);
    
    // With alpha
    expected = QColor(255, 0, 0, 128);
    result = ColorConversion::stdStringToQColor("#80ff0000");
    EXPECT_EQ(result, expected);
}

// Test std::string to QColor conversion - rgba format
TEST(QColorConversion, StdStringToQColorRgba) {
    QColor expected(255, 0, 0);
    QColor result = ColorConversion::stdStringToQColor("rgb(255,0,0)");
    EXPECT_EQ(result, expected);
    
    // Create a color directly with alpha 128
    QColor color128(255, 0, 0, 128);
    result = ColorConversion::stdStringToQColor("rgba(255,0,0,0.5)");
    
    // Compare RGB values and alpha separately to avoid precision issues
    EXPECT_EQ(result.red(), color128.red());
    EXPECT_EQ(result.green(), color128.green());
    EXPECT_EQ(result.blue(), color128.blue());
    EXPECT_NEAR(result.alpha(), color128.alpha(), 1); // Allow 1 unit difference
}

// Test invalid input handling
TEST(QColorConversion, InvalidInput) {
    QColor result = ColorConversion::stdStringToQColor("not a color");
    EXPECT_FALSE(result.isValid());
}

// Test roundtrip conversion
TEST(QColorConversion, RoundtripConversion) {
    QColor original(42, 84, 126, 168);
    std::string rgbaString = ColorConversion::qColorToStdString(original);
    QColor result = ColorConversion::stdStringToQColor(rgbaString);
    
    EXPECT_EQ(result.red(), original.red());
    EXPECT_EQ(result.green(), original.green());
    EXPECT_EQ(result.blue(), original.blue());
    EXPECT_NEAR(result.alpha(), original.alpha(), 15); // Allow up to 15 units difference due to rounding
}

}  // namespace 