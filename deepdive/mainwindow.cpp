#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
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


void MainWindow::on_pushButton_clicked()
{
    int count = ui->spinBox->value();
    int comp [3];
    for (int i = 0; i < count ; i++) {
        QString str = QString::number(i + 1);
        comp[i] = QInputDialog::getInt(this, "Component Ohm", "Komponent: " + str );
    }
}
