/****************************************************************************
** Meta object code from reading C++ file 'scorewindow.h'
**
** Created: Tue Mar 5 20:04:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Client/scorewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scorewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScoreWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScoreWindow[] = {
    "ScoreWindow\0\0start_main()\0close_window()\0"
};

void ScoreWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScoreWindow *_t = static_cast<ScoreWindow *>(_o);
        switch (_id) {
        case 0: _t->start_main(); break;
        case 1: _t->close_window(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ScoreWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScoreWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScoreWindow,
      qt_meta_data_ScoreWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScoreWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScoreWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScoreWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScoreWindow))
        return static_cast<void*>(const_cast< ScoreWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScoreWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ScoreWindow::start_main()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
