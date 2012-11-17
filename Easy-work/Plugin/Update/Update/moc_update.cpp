/****************************************************************************
** Meta object code from reading C++ file 'update.h'
**
** Created: Sat Nov 17 13:06:59 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "update.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'update.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UpdateClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   12,   12,   12, 0x0a,
      70,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,
     111,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UpdateClass[] = {
    "UpdateClass\0\0siSaveSetting(QStringList)\0"
    "slSetSaveSetting(QStringList)\0"
    "slCloseEvent()\0dialogExec()\0dialogSave()\0"
    "dialogNotSave()\0"
};

void UpdateClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UpdateClass *_t = static_cast<UpdateClass *>(_o);
        switch (_id) {
        case 0: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->slCloseEvent(); break;
        case 3: _t->dialogExec(); break;
        case 4: _t->dialogSave(); break;
        case 5: _t->dialogNotSave(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UpdateClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UpdateClass::staticMetaObject = {
    { &Update::staticMetaObject, qt_meta_stringdata_UpdateClass,
      qt_meta_data_UpdateClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UpdateClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UpdateClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UpdateClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateClass))
        return static_cast<void*>(const_cast< UpdateClass*>(this));
    if (!strcmp(_clname, "Update/EasyWork/Plagin/1.0.0"))
        return static_cast< Update*>(const_cast< UpdateClass*>(this));
    return Update::qt_metacast(_clname);
}

int UpdateClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Update::qt_metacall(_c, _id, _a);
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
void UpdateClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
