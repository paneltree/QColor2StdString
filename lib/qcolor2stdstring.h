#ifndef QCOLOR2STDSTRING_H
#define QCOLOR2STDSTRING_H

#include <QtGui/QColor>
#include <string>

namespace ColorConversion {

/**
 * @brief Convert a QColor to a std::string in the format "rgba(r,g,b,a)"
 * @param color The QColor to convert
 * @return A std::string representation of the color
 */
std::string qColorToStdString(const QColor& color);

/**
 * @brief Convert a QColor to a std::string in hex format "#RRGGBB" or "#RRGGBBAA"
 * @param color The QColor to convert
 * @param includeAlpha Whether to include the alpha channel
 * @return A std::string representation of the color in hex format
 */
std::string qColorToHexString(const QColor& color, bool includeAlpha = false);

/**
 * @brief Convert a std::string to a QColor
 * @param colorString The string to convert in format "rgba(r,g,b,a)" or "rgb(r,g,b)" or "#RRGGBB" or "#RRGGBBAA"
 * @return A QColor object
 */
QColor stdStringToQColor(const std::string& colorString);

} // namespace ColorConversion

#endif // QCOLOR2STDSTRING_H 