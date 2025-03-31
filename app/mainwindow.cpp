#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcolor2stdstring.h"
#include "themecolors.h"

#include <QColorDialog>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QLocale>
#include <QGridLayout>
#include <QHBoxLayout>

using namespace ColorConversion;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(Qt::red)
{
    ui->setupUi(this);
    
    // Connect signals/slots for color converter tab
    connect(ui->colorButton, &QPushButton::clicked, this, &MainWindow::onColorButtonClicked);
    connect(ui->hexStringEdit, &QLineEdit::textChanged, this, &MainWindow::onHexStringTextChanged);
    connect(ui->rgbaStringEdit, &QLineEdit::textChanged, this, &MainWindow::onRgbaStringTextChanged);
    
    // Connect theme combobox
    connect(ui->themeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &MainWindow::onThemeChanged);
    
    // Initialize with default color
    updateColorDisplay(currentColor);
    updateStringRepresentations(currentColor);
    updateColorValues(currentColor);
    updateAlternateFormats(currentColor);
    
    // Initialize theme colors display
    updateThemeColorsDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onColorButtonClicked()
{
    QColor newColor = QColorDialog::getColor(currentColor, this, "Select Color", QColorDialog::ShowAlphaChannel);
    
    if (newColor.isValid()) {
        currentColor = newColor;
        updateColorDisplay(currentColor);
        updateStringRepresentations(currentColor);
        updateColorValues(currentColor);
        updateAlternateFormats(currentColor);
    }
}

void MainWindow::updateColorDisplay(const QColor& color)
{
    // Set stylesheet for the color display frame
    QString styleSheet = QString("background-color: %1;").arg(color.name(QColor::HexArgb));
    ui->colorDisplayFrame->setStyleSheet(styleSheet);
}

void MainWindow::updateStringRepresentations(const QColor& color)
{
    // Temporarily block signals to prevent recursive calls
    ui->hexStringEdit->blockSignals(true);
    ui->rgbaStringEdit->blockSignals(true);
    
    // Update the text fields
    ui->hexStringEdit->setText(QString::fromStdString(ColorConversion::qColorToHexString(color, true)));
    ui->rgbaStringEdit->setText(QString::fromStdString(ColorConversion::qColorToStdString(color)));
    
    // CSS color string - in proper CSS format
    QString cssString;
    if (color.alpha() < 255) {
        cssString = QString("rgba(%1, %2, %3, %4)")
                      .arg(color.red())
                      .arg(color.green())
                      .arg(color.blue())
                      .arg(QString::number(color.alphaF(), 'f', 2));
    } else {
        cssString = color.name(QColor::HexRgb);
    }
    ui->cssStringEdit->setText(cssString);
    
    // Unblock signals
    ui->hexStringEdit->blockSignals(false);
    ui->rgbaStringEdit->blockSignals(false);
}

void MainWindow::updateColorValues(const QColor& color)
{
    QLocale locale = QLocale::system();
    
    // RGB integer values (0-255)
    ui->redEdit->setText(QString::number(color.red()));
    ui->greenEdit->setText(QString::number(color.green()));
    ui->blueEdit->setText(QString::number(color.blue()));
    ui->alphaEdit->setText(QString::number(color.alpha()));
    
    // RGB float values (0.0-1.0)
    ui->redFEdit->setText(locale.toString(color.redF(), 'f', 3));
    ui->greenFEdit->setText(locale.toString(color.greenF(), 'f', 3));
    ui->blueFEdit->setText(locale.toString(color.blueF(), 'f', 3));
    ui->alphaFEdit->setText(locale.toString(color.alphaF(), 'f', 3));
    
    // RGB hex values
    ui->redHexEdit->setText(QString("0x%1").arg(color.red(), 2, 16, QChar('0')).toUpper());
    ui->greenHexEdit->setText(QString("0x%1").arg(color.green(), 2, 16, QChar('0')).toUpper());
    ui->blueHexEdit->setText(QString("0x%1").arg(color.blue(), 2, 16, QChar('0')).toUpper());
    ui->alphaHexEdit->setText(QString("0x%1").arg(color.alpha(), 2, 16, QChar('0')).toUpper());
}

void MainWindow::updateAlternateFormats(const QColor& color)
{
    QLocale locale = QLocale::system();
    
    // HSV format
    int h, s, v;
    color.getHsv(&h, &s, &v);
    ui->hsvEdit->setText(QString("hsv(%1, %2%, %3%)")
                           .arg(h)
                           .arg(qRound(s / 2.55))
                           .arg(qRound(v / 2.55)));
    
    // HSL format
    int hsl_h, hsl_s, hsl_l;
    color.getHsl(&hsl_h, &hsl_s, &hsl_l);
    ui->hslEdit->setText(QString("hsl(%1, %2%, %3%)")
                           .arg(hsl_h)
                           .arg(qRound(hsl_s / 2.55))
                           .arg(qRound(hsl_l / 2.55)));
    
    // CMYK format
    int c, m, y, k;
    color.getCmyk(&c, &m, &y, &k);
    ui->cmykEdit->setText(QString("cmyk(%1%, %2%, %3%, %4%)")
                           .arg(qRound(c / 2.55))
                           .arg(qRound(m / 2.55))
                           .arg(qRound(y / 2.55))
                           .arg(qRound(k / 2.55)));
}

void MainWindow::onHexStringTextChanged()
{
    QString hexString = ui->hexStringEdit->text();
    QColor newColor = ColorConversion::stdStringToQColor(hexString.toStdString());
    
    if (newColor.isValid()) {
        currentColor = newColor;
        updateColorDisplay(currentColor);
        updateColorValues(currentColor);
        updateAlternateFormats(currentColor);
        
        // Update only the rgba string to avoid recursion
        ui->rgbaStringEdit->blockSignals(true);
        ui->rgbaStringEdit->setText(QString::fromStdString(ColorConversion::qColorToStdString(currentColor)));
        ui->rgbaStringEdit->blockSignals(false);
        
        // Update CSS string
        QString cssString;
        if (currentColor.alpha() < 255) {
            cssString = QString("rgba(%1, %2, %3, %4)")
                          .arg(currentColor.red())
                          .arg(currentColor.green())
                          .arg(currentColor.blue())
                          .arg(QString::number(currentColor.alphaF(), 'f', 2));
        } else {
            cssString = currentColor.name(QColor::HexRgb);
        }
        ui->cssStringEdit->setText(cssString);
    }
}

void MainWindow::onRgbaStringTextChanged()
{
    QString rgbaString = ui->rgbaStringEdit->text();
    QColor newColor = ColorConversion::stdStringToQColor(rgbaString.toStdString());
    
    if (newColor.isValid()) {
        currentColor = newColor;
        updateColorDisplay(currentColor);
        updateColorValues(currentColor);
        updateAlternateFormats(currentColor);
        
        // Update only the hex string to avoid recursion
        ui->hexStringEdit->blockSignals(true);
        ui->hexStringEdit->setText(QString::fromStdString(ColorConversion::qColorToHexString(currentColor, true)));
        ui->hexStringEdit->blockSignals(false);
        
        // Update CSS string
        QString cssString;
        if (currentColor.alpha() < 255) {
            cssString = QString("rgba(%1, %2, %3, %4)")
                          .arg(currentColor.red())
                          .arg(currentColor.green())
                          .arg(currentColor.blue())
                          .arg(QString::number(currentColor.alphaF(), 'f', 2));
        } else {
            cssString = currentColor.name(QColor::HexRgb);
        }
        ui->cssStringEdit->setText(cssString);
    }
}

void MainWindow::onThemeChanged(int themeIndex)
{
    // Convert combobox index to ThemeColors::ColorTheme
    ColorTheme theme;
    switch(themeIndex) {
        case 0: theme = ColorTheme::System; break;
        case 1: theme = ColorTheme::Light; break;
        case 2: theme = ColorTheme::Dark; break;
        default: theme = ColorTheme::System;
    }
    
    // Set the theme in our singleton
    ThemeColors::getInstance().setTheme(theme);
    
    // Update the displayed theme colors
    updateThemeColorsDisplay();
}

void MainWindow::createColorPreviewWidget(QWidget* parent, ColorRole role, const QString& label)
{
    // Get the color for this role
    QColor color = ThemeColors::getInstance().getColor(role);
    
    // Create a container widget
    QWidget* container = new QWidget(parent);
    QHBoxLayout* layout = new QHBoxLayout(container);
    layout->setContentsMargins(4, 4, 4, 4);
    
    // Create color preview frame
    QFrame* colorFrame = new QFrame(container);
    colorFrame->setMinimumSize(40, 40);
    colorFrame->setMaximumSize(40, 40);
    colorFrame->setFrameShape(QFrame::StyledPanel);
    colorFrame->setFrameShadow(QFrame::Raised);
    colorFrame->setStyleSheet(QString("background-color: %1;").arg(color.name(QColor::HexArgb)));
    
    // Create color info labels
    QLabel* nameLabel = new QLabel(label, container);
    nameLabel->setMinimumWidth(150);
    
    QLabel* hexValueLabel = new QLabel(color.name(QColor::HexArgb), container);
    hexValueLabel->setMinimumWidth(100);
    
    QLabel* rgbValueLabel = new QLabel(QString("rgb(%1,%2,%3)").arg(color.red()).arg(color.green()).arg(color.blue()), container);
    
    // Add widgets to layout
    layout->addWidget(colorFrame);
    layout->addWidget(nameLabel);
    layout->addWidget(hexValueLabel);
    layout->addWidget(rgbValueLabel);
    layout->addStretch();
    
    // Remember these for later updates
    themeColorFrames.append(qMakePair(colorFrame, role));
    themeColorLabels.append(hexValueLabel);
    themeColorLabels.append(rgbValueLabel);
    
    // Add to the parent's layout
    ui->themeColorsLayout->addWidget(container);
}

void MainWindow::updateThemeColorsDisplay()
{
    // Clear existing display
    while (QLayoutItem* item = ui->themeColorsLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    themeColorFrames.clear();
    themeColorLabels.clear();
    
    // Add a header for basic UI colors
    QLabel* basicHeader = new QLabel("<b>Basic UI Colors</b>", ui->themeColorsContainer);
    basicHeader->setAlignment(Qt::AlignLeft);
    ui->themeColorsLayout->addWidget(basicHeader);
    
    // Add basic UI colors
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Primary, "Primary");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Secondary, "Secondary");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Accent, "Accent");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Success, "Success");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Warning, "Warning");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Error, "Error");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Info, "Info");
    
    // Add a header for background colors
    QLabel* bgHeader = new QLabel("<b>Background Colors</b>", ui->themeColorsContainer);
    bgHeader->setAlignment(Qt::AlignLeft);
    ui->themeColorsLayout->addWidget(bgHeader);
    
    // Add background colors
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Background, "Background");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Surface, "Surface");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Card, "Card");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::Dialog, "Dialog");
    
    // Add a header for text colors
    QLabel* textHeader = new QLabel("<b>Text Colors</b>", ui->themeColorsContainer);
    textHeader->setAlignment(Qt::AlignLeft);
    ui->themeColorsLayout->addWidget(textHeader);
    
    // Add text colors
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::TextPrimary, "Text Primary");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::TextSecondary, "Text Secondary");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::TextDisabled, "Text Disabled");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::TextOnPrimary, "Text On Primary");
    createColorPreviewWidget(ui->themeColorsContainer, ColorRole::TextOnAccent, "Text On Accent");
    
    // Add a header for palette colors
    QLabel* paletteHeader = new QLabel("<b>Palette Colors</b>", ui->themeColorsContainer);
    paletteHeader->setAlignment(Qt::AlignLeft);
    ui->themeColorsLayout->addWidget(paletteHeader);
    
    // Create a grid layout for the palette colors
    QWidget* paletteContainer = new QWidget(ui->themeColorsContainer);
    QGridLayout* paletteLayout = new QGridLayout(paletteContainer);
    paletteLayout->setContentsMargins(0, 0, 0, 0);
    
    // Add palette colors in a grid
    for (int i = 0; i < 20; i++) {
        ColorRole role = static_cast<ColorRole>(static_cast<int>(ColorRole::Palette1) + i);
        QColor color = ThemeColors::getInstance().getColor(role);
        
        // Create color preview frame
        QFrame* colorFrame = new QFrame(paletteContainer);
        colorFrame->setMinimumSize(60, 40);
        colorFrame->setFrameShape(QFrame::StyledPanel);
        colorFrame->setFrameShadow(QFrame::Raised);
        colorFrame->setStyleSheet(QString("background-color: %1;").arg(color.name(QColor::HexArgb)));
        
        // Create color info label
        QLabel* colorLabel = new QLabel(QString("Palette%1\n%2").arg(i+1).arg(color.name(QColor::HexArgb)), paletteContainer);
        colorLabel->setAlignment(Qt::AlignCenter);
        
        // Add to grid layout
        int row = i / 5;
        int col = i % 5;
        paletteLayout->addWidget(colorFrame, row*2, col);
        paletteLayout->addWidget(colorLabel, row*2+1, col);
        
        // Remember these for later updates
        themeColorFrames.append(qMakePair(colorFrame, role));
        themeColorLabels.append(colorLabel);
    }
    
    ui->themeColorsLayout->addWidget(paletteContainer);
    
    // Add a spacer at the end
    ui->themeColorsLayout->addStretch();
} 