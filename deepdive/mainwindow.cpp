#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>

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
    //Setting up variables for  the functions, using the same setup as assignment 6 for electrotest
    int count = ui->spinBox->value();
    //Limited components to 3
    float comp [3];
    float arrayE [3] = {1.0, 1.0, 1.0};
    int raknare = 0;
    //Showing an dialogbox for ohm input for each component and storing in comp array
    for (int i = 0; i < count ; i++) {
        QString str = QString::number(i + 1);
        comp[i] = QInputDialog::getInt(this, "Component Ohm", "Komponent: " + str );
    }
    //Checking which radio button is checked and making koppling to that corrensponding char
    char koppling{};
    if(ui->radioButton->isChecked()){
        koppling = 'S';
    }
    else{
        koppling = 'P';
    }

    //Calling the respective functions with correct parameters as eariler assignment ans setting corresponding line_edit text to that result.
    float resistance = calc_resistance(count, koppling, comp);
    QString res = QString::number(resistance);
    ui->lineEdit_2->setText(res + " ohm");

    float volt = ui->lineEdit->text().toFloat();
    float power = calc_power_r(volt, resistance);
    QString pow = QString::number(power);
    ui->lineEdit_3->setText(pow + " W");

    count = e_resistance(resistance, arrayE);
    QString er;
    while(raknare<count){
        er += QString::number(arrayE[raknare]) + ", ";
        raknare++;
    }
    ui->lineEdit_4->setText(er);

}
