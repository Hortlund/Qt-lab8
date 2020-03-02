#include "window.h"
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>

Window::Window(QWidget *parent) :
 QWidget(parent)
 {
 // Set size of the window
 setFixedSize(300, 300);

 title = new QLabel("Logga in", this);
 title->setGeometry(120, 10, 100, 30);

 name = new QLabel("Användarnamn: ", this);
 name->setGeometry(25, 50, 120, 30);

 pass = new QLabel("Lösenord: ", this);
 pass->setGeometry(25, 100, 120, 30);

 username = new QLineEdit(this);
 username->setGeometry(150, 50, 100, 30);

 password = new QLineEdit(this);
 password->setGeometry(150, 100, 100, 30);
 password->setEchoMode(password->Password);

 m_button = new QPushButton("Logga in", this);
 m_button->setGeometry(100, 200, 100, 30);
QMessageBox *box = new QMessageBox(this);

box->setWindowTitle("Error");
box->setText("No connection made");
box->setDetailedText("Simpel app som visar på kunskap inom QT beginners guide");

 connect(m_button, SIGNAL (clicked()), box, SLOT (exec()));

}
