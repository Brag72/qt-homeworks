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
    void on_start_stop_button_clicked();
    void on_clear_button_clicked();
    void on_lap_button_clicked();
    void updateTimeLabel(int seconds);

private:
    Ui::MainWindow *ui;
    Stopwatch *m_stopwatch;
    int m_lapNumber = 0;
    int m_lastLapStartTime = 0; // Время старта последнего круга
};

#endif // MAINWINDOW_H
