/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created: Sun Oct 21 01:04:59 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyboardClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      38,   14,   14,   14, 0x0a,
      60,   14,   14,   14, 0x0a,
      68,   14,   14,   14, 0x0a,
      86,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,
     116,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeyboardClass[] = {
    "KeyboardClass\0\0setQPoinParent(QPoint)\0"
    "setQSizeParent(QSize)\0close()\0"
    "fasteningDialog()\0show(bool)\0"
    "actionCheckFalse()\0setKeyLanguage(QStringList)\0"
};

void KeyboardClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyboardClass *_t = static_cast<KeyboardClass *>(_o);
        switch (_id) {
        case 0: _t->setQPoinParent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->setQSizeParent((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 2: _t->close(); break;
        case 3: _t->fasteningDialog(); break;
        case 4: _t->show((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->actionCheckFalse(); break;
        case 6: _t->setKeyLanguage((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KeyboardClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeyboardClass::staticMetaObject = {
    { &Keyboard::staticMetaObject, qt_meta_stringdata_KeyboardClass,
      qt_meta_data_KeyboardClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyboardClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyboardClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyboardClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyboardClass))
        return static_cast<void*>(const_cast< KeyboardClass*>(this));
    if (!strcmp(_clname, "keyboard.for.EasyWork.programm/EasyWork/Plagin/1.0.0"))
        return static_cast< Keyboard*>(const_cast< KeyboardClass*>(this));
    return Keyboard::qt_metacast(_clname);
}

int KeyboardClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Keyboard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
