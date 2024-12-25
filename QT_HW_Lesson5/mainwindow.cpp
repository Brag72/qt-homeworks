#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_stopwatch(new Stopwatch(this)) {
    ui->setupUi(this);

    connect(ui->Start_stop, &QPushButton::clicked, this, &MainWindow::on_start_stop_button_clicked);
    connect(ui->Clear_button, &QPushButton::clicked, this, &MainWindow::on_clear_button_clicked);
    connect(ui->Circle_button, &QPushButton::clicked, this, &MainWindow::on_lap_button_clicked);
    connect(m_stopwatch, &Stopwatch::timeChanged, this, &MainWindow::updateTimeLabel);

    ui->Circle_button->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_start_stop_button_clicked() {
    if (ui->Start_stop->text() == "Старт") {
        ui->Start_stop->setText("Стоп");
        m_stopwatch->start();
        ui->Circle_button->setEnabled(true);
    } else {
        ui->Start_stop->setText("Старт");
        m_stopwatch->stop();
        ui->Circle_button->setEnabled(false);
    }
}

void MainWindow::on_clear_button_clicked() {
    m_stopwatch->reset();
    ui->Circle_Count->clear();
    m_lapNumber = 0;
}

void MainWindow::on_lap_button_clicked() {
    int currentTime = m_stopwatch->getSeconds(); // Текущее общее время
    int lapTime = currentTime - m_lastLapStartTime; // Время круга
    QString lapString = QString("Круг %1, Время: %2 сек").arg(++m_lapNumber).arg(lapTime);
    ui->Circle_Count->append(lapString);
    m_lastLapStartTime = currentTime; // Обновляем время старта следующего круга
}

void MainWindow::updateTimeLabel(int seconds) {
    int minutes = seconds / 60;
    int secs = seconds % 60;
    QString timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(secs, 2, 10, QChar('0'));
    ui->Timer->setText(timeString);
}
