#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
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
