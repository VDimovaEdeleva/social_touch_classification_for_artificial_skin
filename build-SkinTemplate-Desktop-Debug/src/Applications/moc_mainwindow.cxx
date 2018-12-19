/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkinTemplate/src/Applications/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      23,   11,   11,   11, 0x05,
      65,   63,   11,   11, 0x05,
     125,  121,   11,   11, 0x05,
     147,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     167,  165,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     289,   11,   11,   11, 0x08,
     310,  121,   11,   11, 0x08,
     332,   11,   11,   11, 0x0a,
     348,  339,   11,   11, 0x0a,
     395,  389,   11,   11, 0x2a,
     436,  432,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0finished()\0"
    "newDataBunch(QVector<Skin::Cell::Data>)\0"
    "d\0sampledData(Skin::Reconstruction::AccDataSampler::Data)\0"
    "num\0startLedFeedback(int)\0stopLedFeedback()\0"
    "s\0message(QString)\0handleEvents()\0"
    "dataSamplerStarted()\0dataSamplerStopped()\0"
    "dataSamplerPoseFinished()\0"
    "dataSamplerFinished()\0dataSamplingFailed()\0"
    "newNumberOfCells(int)\0quit()\0color,id\0"
    "changeLedColor(Skin::Cell::LedColor,int)\0"
    "color\0changeLedColor(Skin::Cell::LedColor)\0"
    "org\0newSkinOrganization(QVector<Skin::Cell::Organization>)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->newDataBunch((*reinterpret_cast< QVector<Skin::Cell::Data>(*)>(_a[1]))); break;
        case 2: _t->sampledData((*reinterpret_cast< Skin::Reconstruction::AccDataSampler::Data(*)>(_a[1]))); break;
        case 3: _t->startLedFeedback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->stopLedFeedback(); break;
        case 5: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->handleEvents(); break;
        case 7: _t->dataSamplerStarted(); break;
        case 8: _t->dataSamplerStopped(); break;
        case 9: _t->dataSamplerPoseFinished(); break;
        case 10: _t->dataSamplerFinished(); break;
        case 11: _t->dataSamplingFailed(); break;
        case 12: _t->newNumberOfCells((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->quit(); break;
        case 14: _t->changeLedColor((*reinterpret_cast< Skin::Cell::LedColor(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->changeLedColor((*reinterpret_cast< Skin::Cell::LedColor(*)>(_a[1]))); break;
        case 16: _t->newSkinOrganization((*reinterpret_cast< QVector<Skin::Cell::Organization>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::newDataBunch(QVector<Skin::Cell::Data> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sampledData(Skin::Reconstruction::AccDataSampler::Data _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::startLedFeedback(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::stopLedFeedback()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
