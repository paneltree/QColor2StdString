#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>

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
    void onHexStringTextChanged();
    void onRgbaStringTextChanged();

private:
    Ui::MainWindow *ui;
    QColor currentColor;
};

#endif // MAINWINDOW_H 