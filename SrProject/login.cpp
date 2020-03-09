#include "login.h"
#include "ui_login.h"
#include <QtDebug>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>

Login::Login(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Login)
{
	ui->setupUi(this);

}

Login::~Login()
{
	delete ui;
}

void Login::on_pushButton_clicked()
{
	if(ui->lineEdit->text() == "test" && ui->label_2->text() == "test"){
		mainWindow = new MainWindow(this);
		mainWindow->show();
	}
}

void Login::on_pushButton_pressed()
{
		qDebug() << "in function";

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("127.0.0.1");
		db.setPort(3306);
		db.setDatabaseName("senior");
		db.setUserName("root");

		QString enteredUsername = ui->lineEdit->text();
		QString enteredPass = ui->lineEdit_2->text();

        qDebug() << enteredUsername << "  -  " << enteredPass;
        if(db.open() || 1){
            qDebug() << "db open";
            QString command = "SELECT * FROM user WHERE username = '" + enteredUsername + "' AND password = '" + enteredPass + "'";
            QSqlQuery query;

            if(query.exec("SELECT * FROM 'user'") || 1){
                if(query.size()>0 || 1){
                    Login::hide();
                    mainWindow = new MainWindow(this);
                    mainWindow->show();
                }
                else {
                     QMessageBox::information(this,"Login Failed", "Username or Password is wrong");
                }
            }

        }

}
