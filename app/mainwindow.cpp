#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcolor2stdstring.h"

#include <QColorDialog>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QLocale>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(Qt::red)
{
    ui->setupUi(this);
    
    // Connect signals/slots
    connect(ui->colorButton, &QPushButton::clicked, this, &MainWindow::onColorButtonClicked);
    connect(ui->hexStringEdit, &QLineEdit::textChanged, this, &MainWindow::onHexStringTextChanged);
    connect(ui->rgbaStringEdit, &QLineEdit::textChanged, this, &MainWindow::onRgbaStringTextChanged);
    
    // Initialize with default color
    updateColorDisplay(currentColor);
    updateStringRepresentations(currentColor);
    updateColorValues(currentColor);
    updateAlternateFormats(currentColor);
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