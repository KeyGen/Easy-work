/****************************************************************************
** Meta object code from reading C++ file 'downloadlanguagekeyboard.h'
**
** Created: Mon Oct 22 16:04:05 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloadlanguagekeyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadlanguagekeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyboardLanguageClass[] = {

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
      25,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeyboardLanguageClass[] = {
    "KeyboardLanguageClass\0\0,\0"
    "getLanguage(QMultiHash<QString,QString>,bool)\0"
    "slotActivateLanguage()\0"
};

void KeyboardLanguageClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyboardLanguageClass *_t = static_cast<KeyboardLanguageClass *>(_o);
        switch (_id) {
        case 0: _t->getLanguage((*reinterpret_cast< QMultiHash<QString,QString>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->slotActivateLanguage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KeyboardLanguageClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeyboardLanguageClass::staticMetaObject = {
    { &KeyboardLanguage::staticMetaObject, qt_meta_stringdata_KeyboardLanguageClass,
      qt_meta_data_KeyboardLanguageClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyboardLanguageClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyboardLanguageClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyboardLanguageClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyboardLanguageClass))
        return static_cast<void*>(const_cast< KeyboardLanguageClass*>(this));
    if (!strcmp(_clname, "keyboard.language.for.keyboardPlugin.programm/EasyWork/Plagin/1.0.0"))
        return static_cast< KeyboardLanguage*>(const_cast< KeyboardLanguageClass*>(this));
    return KeyboardLanguage::qt_metacast(_clname);
}

int KeyboardLanguageClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KeyboardLanguage::qt_metacall(_c, _id, _a);
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
void KeyboardLanguageClass::getLanguage(QMultiHash<QString,QString> _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
