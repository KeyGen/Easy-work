/****************************************************************************
** Meta object code from reading C++ file 'what_is.h'
**
** Created: Sat Nov 3 14:03:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "what_is.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'what_is.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WhatIsClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WhatIsClass[] = {
    "WhatIsClass\0\0exec()\0"
};

void WhatIsClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WhatIsClass *_t = static_cast<WhatIsClass *>(_o);
        switch (_id) {
        case 0: _t->exec(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WhatIsClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WhatIsClass::staticMetaObject = {
    { &WhatIs::staticMetaObject, qt_meta_stringdata_WhatIsClass,
      qt_meta_data_WhatIsClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WhatIsClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WhatIsClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WhatIsClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WhatIsClass))
        return static_cast<void*>(const_cast< WhatIsClass*>(this));
    if (!strcmp(_clname, "info.programm/EasyWork/Plagin/1.0.0"))
        return static_cast< WhatIs*>(const_cast< WhatIsClass*>(this));
    return WhatIs::qt_metacast(_clname);
}

int WhatIsClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WhatIs::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE