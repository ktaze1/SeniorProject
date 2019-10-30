/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SrProject/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "appendMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "from"
QT_MOC_LITERAL(4, 31, 7), // "message"
QT_MOC_LITERAL(5, 39, 27), // "on_actionNew_File_triggered"
QT_MOC_LITERAL(6, 67, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 91, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(8, 115, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(9, 140, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(10, 167, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(11, 191, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(12, 215, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(13, 239, 31), // "on_actionCompile_Code_triggered"
QT_MOC_LITERAL(14, 271, 36), // "on_actionOnCompileFinished_tr..."
QT_MOC_LITERAL(15, 308, 33), // "on_actionPython_Compile_trigg..."
QT_MOC_LITERAL(16, 342, 13), // "returnPressed"
QT_MOC_LITERAL(17, 356, 14), // "newParticipant"
QT_MOC_LITERAL(18, 371, 4), // "nick"
QT_MOC_LITERAL(19, 376, 15) // "participantLeft"

    },
    "MainWindow\0appendMessage\0\0from\0message\0"
    "on_actionNew_File_triggered\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionExit_triggered\0on_actionCopy_triggered\0"
    "on_actionUndo_triggered\0"
    "on_actionCompile_Code_triggered\0"
    "on_actionOnCompileFinished_triggered\0"
    "on_actionPython_Compile_triggered\0"
    "returnPressed\0newParticipant\0nick\0"
    "participantLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x0a /* Public */,
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->on_actionNew_File_triggered(); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionSave_triggered(); break;
        case 4: _t->on_actionPaste_triggered(); break;
        case 5: _t->on_actionSave_As_triggered(); break;
        case 6: _t->on_actionExit_triggered(); break;
        case 7: _t->on_actionCopy_triggered(); break;
        case 8: _t->on_actionUndo_triggered(); break;
        case 9: _t->on_actionCompile_Code_triggered(); break;
        case 10: _t->on_actionOnCompileFinished_triggered(); break;
        case 11: _t->on_actionPython_Compile_triggered(); break;
        case 12: _t->returnPressed(); break;
        case 13: _t->newParticipant((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->participantLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
