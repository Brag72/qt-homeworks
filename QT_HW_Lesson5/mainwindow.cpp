#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), lapCount(0), running(false) {
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);
    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTimerDisplay);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateTimerDisplay(qreal seconds) {
    ui->Timer->setText(QString::number(seconds, 'f', 1));
}

void MainWindow::on_Start_stop_clicked()
{
    if (running) {
        stopwatch->stop();
        ui->Start_stop->setText("Старт");
    } else {
        stopwatch->start();
        ui->Start_stop->setText("Стоп");
    }
    running = !running;
}

void MainWindow::on_Clear_button_clicked()
{
    stopwatch->reset();
    ui->Timer->setText("0");
    ui->CircleCount->clear();
    lapCount = 0;
    ui->Start_stop->setText("Старт");
    running = false;
}

void MainWindow::on_Circle_button_clicked()
{
    if (running) {
        lapCount++;
        QString lapInfo = QString("Круг %1, время: %2 сек").arg(lapCount).arg(stopwatch->elapsedTime());
        ui->CircleCount->append(lapInfo);
    }
}

