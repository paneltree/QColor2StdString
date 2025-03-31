#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include "themecolors.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onColorButtonClicked();
    void updateColorDisplay(const QColor& color);
    void updateStringRepresentations(const QColor& color);
    void updateColorValues(const QColor& color);
    void updateAlternateFormats(const QColor& color);
    void onHexStringTextChanged();
    void onRgbaStringTextChanged();
    void onThemeChanged(int themeIndex);
    void updateThemeColorsDisplay();
    void createColorPreviewWidget(QWidget* parent, ColorConversion::ColorRole role, const QString& label);

private:
    Ui::MainWindow *ui;
    QColor currentColor;
    QList<QPair<QFrame*, ColorConversion::ColorRole>> themeColorFrames;
    QList<QLabel*> themeColorLabels;
};

#endif // MAINWINDOW_H 