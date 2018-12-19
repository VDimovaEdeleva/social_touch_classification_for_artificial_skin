/****************************************************************************
** Meta object code from reading C++ file 'MainConsole.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkinTemplate/src/Applications/MainConsole.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainConsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainConsole[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   24,   12,   12, 0x08,
      43,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainConsole[] = {
    "MainConsole\0\0finished()\0s\0message(QString)\0"
    "quit()\0"
};

void MainConsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainConsole *_t = static_cast<MainConsole *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->quit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainConsole::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainConsole::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainConsole,
      qt_meta_data_MainConsole, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainConsole::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainConsole))
        return static_cast<void*>(const_cast< MainConsole*>(this));
    return QObject::qt_metacast(_clname);
}

int MainConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MainConsole::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
