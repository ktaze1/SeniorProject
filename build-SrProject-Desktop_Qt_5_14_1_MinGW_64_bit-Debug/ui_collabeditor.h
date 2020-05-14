/********************************************************************************
** Form generated from reading UI file 'collabeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLLABEDITOR_H
#define UI_COLLABEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CollabEditor
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *collabTextWidget;
    QMenuBar *menubar1;
    QMenu *menuOpen_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CollabEditor)
    {
        if (CollabEditor->objectName().isEmpty())
            CollabEditor->setObjectName(QString::fromUtf8("CollabEditor"));
        CollabEditor->resize(640, 480);
        actionOpen = new QAction(CollabEditor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(CollabEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        collabTextWidget = new QPlainTextEdit(centralwidget);
        collabTextWidget->setObjectName(QString::fromUtf8("collabTextWidget"));

        horizontalLayout->addWidget(collabTextWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        CollabEditor->setCentralWidget(centralwidget);
        menubar1 = new QMenuBar(CollabEditor);
        menubar1->setObjectName(QString::fromUtf8("menubar1"));
        menubar1->setGeometry(QRect(0, 0, 640, 21));
        menuOpen_File = new QMenu(menubar1);
        menuOpen_File->setObjectName(QString::fromUtf8("menuOpen_File"));
        menuOpen_File->setEnabled(true);
        CollabEditor->setMenuBar(menubar1);
        statusbar = new QStatusBar(CollabEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CollabEditor->setStatusBar(statusbar);

        menubar1->addAction(menuOpen_File->menuAction());
        menuOpen_File->addAction(actionOpen);

        retranslateUi(CollabEditor);

        QMetaObject::connectSlotsByName(CollabEditor);
    } // setupUi

    void retranslateUi(QMainWindow *CollabEditor)
    {
        CollabEditor->setWindowTitle(QCoreApplication::translate("CollabEditor", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("CollabEditor", "Open", nullptr));
        menuOpen_File->setTitle(QCoreApplication::translate("CollabEditor", "Open File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CollabEditor: public Ui_CollabEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLLABEDITOR_H
