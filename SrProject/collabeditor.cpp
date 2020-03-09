#include "collabeditor.h"
#include "ui_collabeditor.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QtDebug>

CollabEditor::CollabEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CollabEditor)
{
    ui->setupUi(this);

    setupEditor();
    //Timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDocument()));
    timer->start(5000);

}

CollabEditor::~CollabEditor()
{
    delete ui;
}


void CollabEditor::setupEditor()
{
    QFont font;
    font.setFamily("Verdana");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->collabTextWidget->setFont(font);

    highlighter = new Highlighter(ui->collabTextWidget->document());

    QFile file("mainwindow.h");
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->collabTextWidget->setPlainText(file.readAll());
}

void CollabEditor::on_actionOpen_triggered()
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
    ui->collabTextWidget->setPlainText(text);
    file.close();
}


void CollabEditor::updateDocument(){

    if(currentFile == "")
        return;

    qDebug() << currentFile;
    QFile file(currentFile);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning!!!", file.errorString());
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->collabTextWidget->setPlainText(text);
    file.close();
}

void CollabEditor::on_collabTextWidget_textChanged()
{
    if(currentFile == "")
        return;
    qDebug() << currentFile;
    QFile file(currentFile);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning!!!", file.errorString());
    }
    QTextStream out(&file);
    QString text = ui->collabTextWidget->toPlainText();
    out << text;
    file.close();
}
