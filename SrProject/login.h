#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
	Q_OBJECT

public:
	explicit Login(QWidget *parent = nullptr);

	QString currentUser = "";
	~Login();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_pressed();

private:
	Ui::Login *ui;
	MainWindow *mainWindow;
};

#endif // LOGIN_H
