#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;
class Window : public QWidget
{
 public:
  explicit Window(QWidget *parent = 0);
 private:
 QPushButton *m_button;
 QLabel *title;
 QLabel *name;
 QLabel *pass;
 QLineEdit *username;
 QLineEdit *password;
};

#endif // WINDOW_H
