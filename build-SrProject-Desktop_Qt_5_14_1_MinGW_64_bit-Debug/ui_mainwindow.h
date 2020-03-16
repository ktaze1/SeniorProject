/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_File;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionUndo;
    QAction *actionCompile_Code;
    QAction *actionPython_Compile;
    QAction *actionCommit;
    QAction *actionPush;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *messageLine;
    QListWidget *onlineUsers;
    QTextEdit *chatMessages;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_3;
    QPlainTextEdit *codeSpace;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *OpenCollabEditor;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *CallButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCompile;
    QMenu *menuG_thub;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1580, 650);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QString::fromUtf8("actionNew_File"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionCompile_Code = new QAction(MainWindow);
        actionCompile_Code->setObjectName(QString::fromUtf8("actionCompile_Code"));
        actionPython_Compile = new QAction(MainWindow);
        actionPython_Compile->setObjectName(QString::fromUtf8("actionPython_Compile"));
        actionCommit = new QAction(MainWindow);
        actionCommit->setObjectName(QString::fromUtf8("actionCommit"));
        actionPush = new QAction(MainWindow);
        actionPush->setObjectName(QString::fromUtf8("actionPush"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label, 1, 3, 1, 1);

        messageLine = new QLineEdit(centralWidget);
        messageLine->setObjectName(QString::fromUtf8("messageLine"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(messageLine->sizePolicy().hasHeightForWidth());
        messageLine->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(messageLine, 1, 4, 1, 2);

        onlineUsers = new QListWidget(centralWidget);
        onlineUsers->setObjectName(QString::fromUtf8("onlineUsers"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(onlineUsers->sizePolicy().hasHeightForWidth());
        onlineUsers->setSizePolicy(sizePolicy3);
        onlineUsers->setMinimumSize(QSize(140, 0));

        gridLayout->addWidget(onlineUsers, 0, 5, 1, 1, Qt::AlignRight);

        chatMessages = new QTextEdit(centralWidget);
        chatMessages->setObjectName(QString::fromUtf8("chatMessages"));
        sizePolicy.setHeightForWidth(chatMessages->sizePolicy().hasHeightForWidth());
        chatMessages->setSizePolicy(sizePolicy);
        chatMessages->setMinimumSize(QSize(400, 0));

        gridLayout->addWidget(chatMessages, 0, 3, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy4);
        textEdit_3->setMinimumSize(QSize(0, 100));

        gridLayout_2->addWidget(textEdit_3, 1, 0, 1, 1);

        codeSpace = new QPlainTextEdit(centralWidget);
        codeSpace->setObjectName(QString::fromUtf8("codeSpace"));
        sizePolicy.setHeightForWidth(codeSpace->sizePolicy().hasHeightForWidth());
        codeSpace->setSizePolicy(sizePolicy);
        codeSpace->setMinimumSize(QSize(1000, 0));

        gridLayout_2->addWidget(codeSpace, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        OpenCollabEditor = new QPushButton(centralWidget);
        OpenCollabEditor->setObjectName(QString::fromUtf8("OpenCollabEditor"));
        OpenCollabEditor->setCheckable(false);

        horizontalLayout_2->addWidget(OpenCollabEditor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        CallButton = new QPushButton(centralWidget);
        CallButton->setObjectName(QString::fromUtf8("CallButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(CallButton->sizePolicy().hasHeightForWidth());
        CallButton->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(CallButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1580, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuCompile = new QMenu(menuBar);
        menuCompile->setObjectName(QString::fromUtf8("menuCompile"));
        menuG_thub = new QMenu(menuBar);
        menuG_thub->setObjectName(QString::fromUtf8("menuG_thub"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuCompile->menuAction());
        menuBar->addAction(menuG_thub->menuAction());
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionUndo);
        menuCompile->addAction(actionCompile_Code);
        menuCompile->addAction(actionPython_Compile);
        menuG_thub->addAction(actionCommit);
        menuG_thub->addAction(actionPush);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_File->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionCompile_Code->setText(QCoreApplication::translate("MainWindow", "C++ Compile", nullptr));
        actionPython_Compile->setText(QCoreApplication::translate("MainWindow", "Python Compile", nullptr));
        actionCommit->setText(QCoreApplication::translate("MainWindow", "Commit", nullptr));
        actionPush->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        OpenCollabEditor->setText(QCoreApplication::translate("MainWindow", "Select User to Open Collab Edit", nullptr));
        CallButton->setText(QCoreApplication::translate("MainWindow", "Select User to Call", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuCompile->setTitle(QCoreApplication::translate("MainWindow", "Compile", nullptr));
        menuG_thub->setTitle(QCoreApplication::translate("MainWindow", "Github", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
