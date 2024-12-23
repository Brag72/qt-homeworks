#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatchclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Start_stop_clicked();
    void on_Clear_button_clicked();
    void on_Circle_button_clicked();
    void updateTimerDisplay(qreal seconds);

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    int lapCount;
    bool running;
};

#endif // MAINWINDOW_H
