#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QListWidgetItem>
#include <QTextTableFormat>
#include <QDebug>
#include <QTimer>

#include "collabeditor.h"


#include "highlighter.h"

#include "client.h"
#include "udpreceiver.h"
#include "udpsender.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
   // inline static int recepientPort;
    ~MainWindow();


public slots:
	void appendMessage(const QString &from, const QString &message);

private slots:
	void on_actionNew_File_triggered();

	void on_actionOpen_triggered();

	void on_actionSave_triggered();

	void on_actionPaste_triggered();

	void on_actionSave_As_triggered();

	void on_actionExit_triggered();

	void on_actionCopy_triggered();

	void on_actionUndo_triggered();

	void on_actionCompile_Code_triggered();

	void on_actionOnCompileFinished_triggered();

	void on_actionPython_Compile_triggered();

	void returnPressed();

	void newParticipant(const QString &nick);

    void participantLeft(const QString &nick);

	void on_actionCommit_triggered();

	void on_actionPush_triggered();

    void on_onlineUsers_itemClicked(QListWidgetItem *item);

    void setupCodeSpace();

    void on_OpenCollabEditor_clicked();

    void on_CallButton_clicked();

private:
	Ui::MainWindow *ui;
	QString currentFile = "";
	QString currentUser = "";
	QTimer *timer;


    Highlighter *highlighter;
	QString myNickName;
    QTextTableFormat tableFormat;
    CollabEditor *CollabEditor;
    udpSender *udpSender;
    udpReceiver *udpReceiver;
    Client client;
};

#endif // MAINWINDOW_H
