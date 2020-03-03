#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    qApp->exit();
}

void MainWindow::on_pushButton_clicked()
{
    int stepValue = 1;
    int userStep = ui->lineEdit->text().toInt();
    if(userStep > 1 && userStep < 255){
        stepValue = userStep;
    }
    else{
        ui->lineEdit->clear();
    }

    int tmp = ui->verticalSlider->value();
    ui->verticalSlider->setValue(tmp+stepValue);

    int tmp2 = ui->verticalSlider_2->value();
    ui->verticalSlider_2->setValue(tmp2+stepValue);

    int tmp3 = ui->verticalSlider_3->value();
    ui->verticalSlider_3->setValue(tmp3+stepValue);

    if(tmp == 255 || tmp2 == 255 || tmp3 == 255){
        QMessageBox msgBox;
        msgBox.setText("Max värde nått!");
        msgBox.exec();
    }



}

void MainWindow::on_pushButton_3_clicked()
{
    int stepValue = 1;
    int userStep = ui->lineEdit->text().toInt();
    if(userStep > 1 && userStep < 255){
        stepValue = userStep;
    }
    else{
        ui->lineEdit->clear();
    }

    int tmp = ui->verticalSlider->value();
    ui->verticalSlider->setValue(tmp-stepValue);

    int tmp2 = ui->verticalSlider_2->value();
    ui->verticalSlider_2->setValue(tmp2-stepValue);

    int tmp3 = ui->verticalSlider_3->value();
    ui->verticalSlider_3->setValue(tmp3-stepValue);

    if(tmp == 0 || tmp2 == 0 || tmp3 == 0){
        QMessageBox msgBox;
        msgBox.setText("Min värde nått!");
        msgBox.exec();
    }
}
