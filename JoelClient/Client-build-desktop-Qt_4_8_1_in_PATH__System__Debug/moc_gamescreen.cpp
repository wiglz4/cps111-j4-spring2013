/****************************************************************************
** Meta object code from reading C++ file 'gamescreen.h'
**
** Created: Mon Mar 11 10:44:55 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/gamescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_gameScreen[] = {
    "gameScreen\0\0onTimerHit()\0return_to_menu()\0"
    "serverDisconnected()\0unPause()\0"
    "readCommand()\0"
};

void gameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gameScreen *_t = static_cast<gameScreen *>(_o);
        switch (_id) {
        case 0: _t->onTimerHit(); break;
        case 1: _t->return_to_menu(); break;
        case 2: _t->serverDisconnected(); break;
        case 3: _t->unPause(); break;
        case 4: _t->readCommand(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData gameScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gameScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameScreen,
      qt_meta_data_gameScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameScreen))
        return static_cast<void*>(const_cast< gameScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
