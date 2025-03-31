#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcolor2stdstring.h"

#include <QColorDialog>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>

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
    
    // Unblock signals
    ui->hexStringEdit->blockSignals(false);
    ui->rgbaStringEdit->blockSignals(false);
}

void MainWindow::onHexStringTextChanged()
{
    QString hexString = ui->hexStringEdit->text();
    QColor newColor = ColorConversion::stdStringToQColor(hexString.toStdString());
    
    if (newColor.isValid()) {
        currentColor = newColor;
        updateColorDisplay(currentColor);
        
        // Update only the rgba string to avoid recursion
        ui->rgbaStringEdit->blockSignals(true);
        ui->rgbaStringEdit->setText(QString::fromStdString(ColorConversion::qColorToStdString(currentColor)));
        ui->rgbaStringEdit->blockSignals(false);
    }
}

void MainWindow::onRgbaStringTextChanged()
{
    QString rgbaString = ui->rgbaStringEdit->text();
    QColor newColor = ColorConversion::stdStringToQColor(rgbaString.toStdString());
    
    if (newColor.isValid()) {
        currentColor = newColor;
        updateColorDisplay(currentColor);
        
        // Update only the hex string to avoid recursion
        ui->hexStringEdit->blockSignals(true);
        ui->hexStringEdit->setText(QString::fromStdString(ColorConversion::qColorToHexString(currentColor, true)));
        ui->hexStringEdit->blockSignals(false);
    }
} 