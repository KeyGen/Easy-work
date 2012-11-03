/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created: Sat Nov 3 14:02:58 2012
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   14,   14,   14, 0x08,
      60,   14,   14,   14, 0x08,
      82,   14,   14,   14, 0x08,
     111,  105,   14,   14, 0x0a,
     139,  105,   14,   14, 0x0a,
     169,  105,   14,   14, 0x0a,
     198,  105,   14,   14, 0x0a,
     223,  105,   14,   14, 0x0a,
     250,  105,   14,   14, 0x0a,
     279,   14,   14,   14, 0x0a,
     305,   14,   14,   14, 0x0a,
     326,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KeyboardClass[] = {
    "KeyboardClass\0\0siKeyboardLanguageChange()\0"
    "slMoveEvent(bool)\0setKeyboardLanguage()\0"
    "findKeyAndPressTimer()\0event\0"
    "slKeyPressEvent(QKeyEvent*)\0"
    "slKeyReleaseEvent(QKeyEvent*)\0"
    "slResizeEvent(QResizeEvent*)\0"
    "slMoveEvent(QMoveEvent*)\0"
    "slCloseEvent(QCloseEvent*)\0"
    "slFocusInEvent(QFocusEvent*)\0"
    "slAnimatePressWord(QChar)\0"
    "pressDownOffAllKey()\0show()\0"
};

void KeyboardClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyboardClass *_t = static_cast<KeyboardClass *>(_o);
        switch (_id) {
        case 0: _t->siKeyboardLanguageChange(); break;
        case 1: _t->slMoveEvent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setKeyboardLanguage(); break;
        case 3: _t->findKeyAndPressTimer(); break;
        case 4: _t->slKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->slKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 7: _t->slMoveEvent((*reinterpret_cast< QMoveEvent*(*)>(_a[1]))); break;
        case 8: _t->slCloseEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: _t->slFocusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 10: _t->slAnimatePressWord((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 11: _t->pressDownOffAllKey(); break;
        case 12: _t->show(); break;
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
    if (!strcmp(_clname, "Keyboard/EasyWork/Plagin/1.0.0"))
        return static_cast< Keyboard*>(const_cast< KeyboardClass*>(this));
    return Keyboard::qt_metacast(_clname);
}

int KeyboardClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Keyboard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void KeyboardClass::siKeyboardLanguageChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
