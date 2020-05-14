#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "collabeditor.h"
#include "server.h"
#include "udpsender.h"
#include "udpreceiver.h"
#include <QtWidgets>
#include <QTimer>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	timer = new QTimer(this);
	QTextCursor cursor(ui->codeSpace->textCursor());
    cursor.setPosition(QTextCursor::End);



	ui->gridLayout->setAlignment(Qt::AlignCenter);
	ui->messageLine->setFocusPolicy(Qt::StrongFocus);
	ui->chatMessages->setReadOnly(true);
	ui->chatMessages->setFocusPolicy(Qt::NoFocus);
	ui->onlineUsers->setFocusPolicy(Qt::NoFocus);

    setupCodeSpace();

	connect(ui->chatMessages, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
	connect(ui->messageLine, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
	connect(&client, SIGNAL(newMessage(QString,QString)),
		  this, SLOT(appendMessage(QString,QString)));
	connect(&client, SIGNAL(newParticipant(QString)),
		  this, SLOT(newParticipant(QString)));
	connect(&client, SIGNAL(participantLeft(QString)),
		  this, SLOT(participantLeft(QString)));


    udpReceiver = new class udpReceiver(this);
	myNickName = client.nickName();
	newParticipant(myNickName);
    tableFormat.setBorder(0);

  //  udpSender = new class udpSender();
    qDebug() << "Test";
    udpReceiver = new class udpReceiver();
}


MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::setupCodeSpace()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->codeSpace->setFont(font);

    highlighter = new Highlighter(ui->codeSpace->document());

        QFile file("mainwindow.h");
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->codeSpace->setPlainText(file.readAll());

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
	ui->codeSpace->setPlainText(QString());
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
    ui->codeSpace->setPlainText(text);
	file.close();
}

void MainWindow::on_actionSave_triggered()
{
	//sql query to fetch if user is permitted
	//if permitted allow in if statement
	if(1){
		//TODO: Edit this function to save the current file
		QString fileName = QFileDialog::getSaveFileName(this, "Save as");
		QFile file(fileName);
		if(!file.open(QIODevice::WriteOnly | QFile::Text)){
			QMessageBox::warning(this, "Warning!!!", file.errorString());
		}
		currentFile = fileName;
		setWindowTitle(fileName);
		QTextStream out(&file);
		QString text = ui->codeSpace->toPlainText();
		out << text;
		file.close();
	}
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
	QString text = ui->codeSpace->toPlainText();
	out << text;
	file.close();
}

void MainWindow::on_actionPaste_triggered()
{
    // TODO:
}

void MainWindow::on_actionExit_triggered()
{
    // TODO:
}

void MainWindow::on_actionCopy_triggered()
{
    // TODO:
}

void MainWindow::on_actionUndo_triggered()
{
    // TODO:
}

void MainWindow::on_actionCompile_Code_triggered()
{
	QProcess compile;
    QString fileNameOutput = QFileInfo(currentFile).fileName().mid(0, QFileInfo(currentFile).fileName().indexOf("."));
    QString path = QFileInfo(currentFile).filePath().mid(0, QFileInfo(currentFile).filePath().indexOf("."));
    qDebug() << path;
    compile.start("powershell", QStringList() << "g++ " + QFileInfo(currentFile).fileName() +" -o " + fileNameOutput);
    if (compile.error()){
        ui->textEdit_3->setText(compile.errorString());
    }
	compile.kill();
    compile.execute("powershell " + path + ".exe | Out-File ./output");
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
}

void MainWindow::on_actionPython_Compile_triggered()
{
	QProcess compile;

	compile.startDetached("powershell", QStringList() << "py Code.py | Out-File ./output");
	compile.kill();
	on_actionOnCompileFinished_triggered();
}

void MainWindow::on_actionCommit_triggered()
{
	QProcess commit;
	QString committedFile = MainWindow::currentFile;
	committedFile.remove(0,123);
	commit.execute("powershell", QStringList() << "ls");
	commit.execute("powershell", QStringList() << "git add * | git commit | Out-File ./output ");
	on_actionOnCompileFinished_triggered();
	qDebug() << MainWindow::currentFile;
	commit.kill();
}

void MainWindow::on_actionPush_triggered()
{
	QProcess commit;

	commit.execute("powershell", QStringList() << "git push | Out-File ./output");
	on_actionOnCompileFinished_triggered();
}

void MainWindow::on_onlineUsers_itemClicked(QListWidgetItem *item)
{
    QString userName = item->text();
    userName = userName.mid(0, userName.indexOf("@"));

    //recepientPort =  client.server.serverPort();
   // qDebug() << recepientPort;
    ui->CallButton->setText("Call " + userName);
    ui->OpenCollabEditor->setText("Open Collaborative Editor With " + userName);

}


void MainWindow::on_OpenCollabEditor_clicked()
{
    CollabEditor = new class CollabEditor(this);
    CollabEditor->show();
}

void MainWindow::on_CallButton_clicked()
{
    AudioRecorder = new class AudioRecorder();
    AudioRecorder->show();

    class udpSender c;
    c.start("192.168.10.23",8888,"C:\\Users\\Kaan\\Desktop");
}
