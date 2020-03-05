#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Declaring external c functions thats was written as a part of an earlier assignment.
extern "C" float calc_resistance(int count, char conn, float *array);
extern "C" float calc_power_r(float volt, float resistance);
extern "C" int e_resistance(float orig_resistance, float *res_array );

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
