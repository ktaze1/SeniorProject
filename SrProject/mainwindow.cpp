#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->gridLayout->setAlignment(Qt::AlignCenter);
	ui->messageLine->setFocusPolicy(Qt::StrongFocus);
	ui->chatMessages->setReadOnly(true);
	ui->chatMessages->setFocusPolicy(Qt::NoFocus);
	ui->onlineUsers->setFocusPolicy(Qt::NoFocus);

	connect(ui->chatMessages, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
	connect(ui->messageLine, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
	connect(&client, SIGNAL(newMessage(QString,QString)),
		  this, SLOT(appendMessage(QString,QString)));
	connect(&client, SIGNAL(newParticipant(QString)),
		  this, SLOT(newParticipant(QString)));
	connect(&client, SIGNAL(participantLeft(QString)),
		  this, SLOT(participantLeft(QString)));

	myNickName = client.nickName();
	newParticipant(myNickName);
	tableFormat.setBorder(0);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::appendMessage(const QString &from, const QString &message)
{
	if (from.isEmpty() || message.isEmpty())
		return;

	QTextCursor cursor(ui->chatMessages->textCursor());
	cursor.movePosition(QTextCursor::End);
	QTextTable *table = cursor.insertTable(1, 2, tableFormat);
	table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
	table->cellAt(0, 1).firstCursorPosition().insertText(message);
	QScrollBar *bar = ui->chatMessages->verticalScrollBar();
	bar->setValue(bar->maximum());

}




void MainWindow::returnPressed()
{
	QString text = ui->messageLine->text();
	if (text.isEmpty())
		return;

	if (text.startsWith(QChar('/'))) {
		QColor color = ui->chatMessages->textColor();
		ui->chatMessages->setTextColor(Qt::red);
		ui->chatMessages->append(tr("! Unknown command: %1")
						 .arg(text.left(text.indexOf(' '))));
		ui->chatMessages->setTextColor(color);
	} else {
		client.sendMessage(text);
		appendMessage(myNickName, text);
	}

	ui->messageLine->clear();
}

void MainWindow::newParticipant(const QString &nick)
{
	if (nick.isEmpty())
		return;

	QColor color = ui->chatMessages->textColor();
	ui->chatMessages->setTextColor(Qt::gray);
	ui->chatMessages->append(tr("* %1 has joined").arg(nick));
	ui->chatMessages->setTextColor(color);
	ui->onlineUsers->addItem(nick);
}

void MainWindow::participantLeft(const QString &nick)
{
	if (nick.isEmpty())
		return;

	QList<QListWidgetItem *> items = ui->onlineUsers->findItems(nick,
														   Qt::MatchExactly);
	if (items.isEmpty())
		return;

	delete items.at(0);
	QColor color = ui->chatMessages->textColor();
	ui->chatMessages->setTextColor(Qt::gray);
	ui->chatMessages->append(tr("* %1 has left").arg(nick));
	ui->chatMessages->setTextColor(color);
}


void MainWindow::on_actionNew_File_triggered()
{
	currentFile.clear();
	ui->textEdit->setPlainText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Please open the file");
	QFile file(fileName);
	currentFile = fileName;
	if(!file.open(QIODevice::ReadOnly | QFile::Text)){
		QMessageBox::warning(this, "Warning!!!", file.errorString());
	}
	setWindowTitle(fileName);
	QTextStream in(&file);
	QString text = in.readAll();
	ui->textEdit->setText(text);
	file.close();
}

void MainWindow::on_actionSave_triggered()
{
	//TODO: Edit this function to save the current file
	QString fileName = QFileDialog::getSaveFileName(this, "Save as");
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly | QFile::Text)){
		QMessageBox::warning(this, "Warning!!!", file.errorString());
	}
	currentFile = fileName;
	setWindowTitle(fileName);
	QTextStream out(&file);
	QString text = ui->textEdit->toPlainText();
	out << text;
	file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save as");
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly | QFile::Text)){
		QMessageBox::warning(this, "Warning!!!", file.errorString());
	}
	currentFile = fileName;
	setWindowTitle(fileName);
	QTextStream out(&file);
	QString text = ui->textEdit->toPlainText();
	out << text;
	file.close();
}

void MainWindow::on_actionPaste_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::on_actionCopy_triggered()
{

}

void MainWindow::on_actionUndo_triggered()
{

}

void MainWindow::on_actionCompile_Code_triggered()
{
	QProcess compile;

	compile.startDetached("powershell", QStringList() << "g++ Code.cpp -o a");
	compile.kill();
	compile.execute("powershell ./a.exe | Out-File ./output");
	on_actionOnCompileFinished_triggered();
}

void MainWindow::on_actionOnCompileFinished_triggered()
{
	QFile outputFile("./output");
	if(!outputFile.open(QIODevice::ReadWrite | QFile::Text)){
		QMessageBox::warning(this, "Warning!!!", outputFile.errorString());
	}
	QTextStream in(&outputFile);
	QString text = in.readAll();
	ui->textEdit_3->setPlainText(text);
	outputFile.close();

	QProcess compile;

	compile.execute("a.exe");
}

void MainWindow::on_actionPython_Compile_triggered()
{
	QProcess compile;

	compile.startDetached("powershell", QStringList() << "py Code.py | Out-File ./output");
	compile.kill();
	on_actionOnCompileFinished_triggered();
}

