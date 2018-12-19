/****************************************************************************
** Meta object code from reading C++ file 'LedFeedback.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkinTemplate/include/Tasks/LedFeedback.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LedFeedback.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LedFeedback[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      65,   56,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   12,   12,   12, 0x08,
     119,  115,   12,   12, 0x0a,
     130,   12,   12,   12, 0x0a,
     139,  137,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LedFeedback[] = {
    "LedFeedback\0\0color\0"
    "changeLedColor(Skin::Cell::LedColor)\0"
    "color,id\0changeLedColor(Skin::Cell::LedColor,int)\0"
    "update()\0num\0start(int)\0stop()\0d\0"
    "newDataBunch(QVector<Skin::Cell::Data>)\0"
};

void LedFeedback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LedFeedback *_t = static_cast<LedFeedback *>(_o);
        switch (_id) {
        case 0: _t->changeLedColor((*reinterpret_cast< Skin::Cell::LedColor(*)>(_a[1]))); break;
        case 1: _t->changeLedColor((*reinterpret_cast< Skin::Cell::LedColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->update(); break;
        case 3: _t->start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->stop(); break;
        case 5: _t->newDataBunch((*reinterpret_cast< QVector<Skin::Cell::Data>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LedFeedback::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LedFeedback::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LedFeedback,
      qt_meta_data_LedFeedback, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LedFeedback::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LedFeedback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LedFeedback::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LedFeedback))
        return static_cast<void*>(const_cast< LedFeedback*>(this));
    return QObject::qt_metacast(_clname);
}

int LedFeedback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LedFeedback::changeLedColor(Skin::Cell::LedColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LedFeedback::changeLedColor(Skin::Cell::LedColor _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
