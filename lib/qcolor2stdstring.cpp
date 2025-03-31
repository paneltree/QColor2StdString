#include "qcolor2stdstring.h"
#include <QtCore/QRegularExpression>
#include <string>
#include <sstream>

namespace ColorConversion {

std::string qColorToStdString(const QColor& color) {
    std::stringstream ss;
    ss << "rgba(" 
       << color.red() << ","
       << color.green() << ","
       << color.blue() << ","
       << color.alphaF() << ")";
    return ss.str();
}

std::string qColorToHexString(const QColor& color, bool includeAlpha) {
    if (includeAlpha) {
        return color.name(QColor::HexArgb).toStdString();
    } else {
        return color.name(QColor::HexRgb).toStdString();
    }
}

QColor stdStringToQColor(const std::string& colorString) {
    QString qColorStr = QString::fromStdString(colorString);
    
    // Handle hex format (#RRGGBB or #RRGGBBAA)
    if (colorString[0] == '#') {
        return QColor(qColorStr);
    }
    
    // Handle rgb/rgba format
    QRegularExpression rgbRegex(R"(rgba?\(\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)(?:\s*,\s*([0-9.]+))?\s*\))");
    QRegularExpressionMatch match = rgbRegex.match(qColorStr);
    
    if (match.hasMatch()) {
        int r = match.captured(1).toInt();
        int g = match.captured(2).toInt();
        int b = match.captured(3).toInt();
        
        if (match.captured(4).isEmpty()) {
            // rgb format with no alpha
            return QColor(r, g, b);
        } else {
            // rgba format with alpha
            double a = match.captured(4).toDouble();
            return QColor(r, g, b, static_cast<int>(a * 255));
        }
    }
    
    // Return an invalid color if the string couldn't be parsed
    return QColor();
}

} // namespace ColorConversion 