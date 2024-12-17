#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setText("Увеличить на 10%");
    ui->radioButton_2->setText("Уменьшить на 10%");
    ui->radioButton->toggle();

    ui->comboBox->addItems({"Элемент 1", "Элемент 2", "Элемент 3", "Элемент 4", "Элемент 5",
                             "Элемент 6", "Элемент 7", "Элемент 8", "Элемент 9", "Элемент 10"});

    ui->pushButton->setText("Увеличить прогресс");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int currentValue = ui->progressBar->value();

    if(ui->radioButton_2->isChecked() && currentValue != 0)
    {
        currentValue--;
    }
    else
    {
        currentValue++;
    }

    if (currentValue > ui->progressBar->maximum()) {
        currentValue = 0;
    }

    ui->progressBar->setValue(currentValue);
}
