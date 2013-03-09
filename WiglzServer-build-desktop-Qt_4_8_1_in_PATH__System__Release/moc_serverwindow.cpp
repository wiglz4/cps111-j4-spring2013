/****************************************************************************
** Meta object code from reading C++ file 'serverwindow.h'
**
** Created: Sat Mar 9 08:56:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Server/serverwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_serverWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,
      53,   13,   13,   13, 0x08,
      68,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_serverWindow[] = {
    "serverWindow\0\0clientConnected()\0"
    "clientDisconnected()\0dataReceived()\0"
    "timerHit()\0"
};

void serverWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        serverWindow *_t = static_cast<serverWindow *>(_o);
        switch (_id) {
        case 0: _t->clientConnected(); break;
        case 1: _t->clientDisconnected(); break;
        case 2: _t->dataReceived(); break;
        case 3: _t->timerHit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData serverWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject serverWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_serverWindow,
      qt_meta_data_serverWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &serverWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *serverWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *serverWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_serverWindow))
        return static_cast<void*>(const_cast< serverWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int serverWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
