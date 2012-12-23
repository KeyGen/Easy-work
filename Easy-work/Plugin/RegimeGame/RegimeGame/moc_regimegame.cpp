/****************************************************************************
** Meta object code from reading C++ file 'regimegame.h'
**
** Created: Sat Dec 22 11:44:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regimegame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regimegame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegimeGameClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      44,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   16,   16,   16, 0x0a,
      96,   16,   16,   16, 0x0a,
     117,  111,   16,   16, 0x0a,
     146,   16,   16,   16, 0x08,
     160,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RegimeGameClass[] = {
    "RegimeGameClass\0\0siSaveSetting(QStringList)\0"
    "siGetWidget(QWidget*)\0"
    "slSetSaveSetting(QStringList)\0"
    "slCloseEvent()\0event\0slResizeEvent(QResizeEvent*)\0"
    "slGetWidget()\0destroyedWidget()\0"
};

void RegimeGameClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegimeGameClass *_t = static_cast<RegimeGameClass *>(_o);
        switch (_id) {
        case 0: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->siGetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->slCloseEvent(); break;
        case 4: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 5: _t->slGetWidget(); break;
        case 6: _t->destroyedWidget(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegimeGameClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegimeGameClass::staticMetaObject = {
    { &RegimeGame::staticMetaObject, qt_meta_stringdata_RegimeGameClass,
      qt_meta_data_RegimeGameClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegimeGameClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegimeGameClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegimeGameClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegimeGameClass))
        return static_cast<void*>(const_cast< RegimeGameClass*>(this));
    if (!strcmp(_clname, "RegimeGame/EasyWork/Plagin/1.0.0"))
        return static_cast< RegimeGame*>(const_cast< RegimeGameClass*>(this));
    return RegimeGame::qt_metacast(_clname);
}

int RegimeGameClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RegimeGame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RegimeGameClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegimeGameClass::siGetWidget(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
