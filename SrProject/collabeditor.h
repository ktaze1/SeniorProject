#ifndef COLLABEDITOR_H
#define COLLABEDITOR_H

#include "highlighter.h"

#include <QMainWindow>
#include <QTimer>

//! [0]
namespace Ui {
class CollabEditor;
}

class CollabEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit CollabEditor(QWidget *parent = nullptr);
    ~CollabEditor();

    void setupEditor();



private slots:
    void on_actionOpen_triggered();

    void on_collabTextWidget_textChanged();

    void updateDocument();

private:
    Ui::CollabEditor *ui;
    QString currentFile = "";

    QTimer *timer;

    Highlighter *highlighter;
};

#endif // COLLABEDITOR_H
