/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created: Fri Nov 16 19:43:41 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyboardClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      42,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   14,   14,   14, 0x08,
      87,   14,   14,   14, 0x08,
     109,   14,   14,   14, 0x08,
     132,   14,   14,   14, 0x08,
     150,  144,   14,   14, 0x0a,
     178,  144,   14,   14, 0x0a,
     208,  144,   14,   14, 0x0a,
     237,  144,   14,   14, 0x0a,
     262,   14,   14,   14, 0x0a,
     277,  144,   14,   14, 0x0a,
     306,   14,   14,   14, 0x0a,
     332,   14,   14,   14, 0x0a,
     353,   14,   14,   14, 0x0a,
     360,   14,   14,   14, 0x0a,
     369,   14,   14,   14, 0x0a,
     378,   14,   14,   14, 0x0a,
     401,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KeyboardClass[] = {
    "KeyboardClass\0\0siKeyboardLanguageChange()\0"
    "siSaveSetting(QStringList)\0slMoveEvent(bool)\0"
    "setKeyboardLanguage()\0findKeyAndPressTimer()\0"
    "setBLShow()\0event\0slKeyPressEvent(QKeyEvent*)\0"
    "slKeyReleaseEvent(QKeyEvent*)\0"
    "slResizeEvent(QResizeEvent*)\0"
    "slMoveEvent(QMoveEvent*)\0slCloseEvent()\0"
    "slFocusInEvent(QFocusEvent*)\0"
    "slAnimatePressWord(QChar)\0"
    "pressDownOffAllKey()\0show()\0slShow()\0"
    "slHide()\0setStyleSheet(QString)\0"
    "slSetSaveSetting(QStringList)\0"
};

void KeyboardClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyboardClass *_t = static_cast<KeyboardClass *>(_o);
        switch (_id) {
        case 0: _t->siKeyboardLanguageChange(); break;
        case 1: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->slMoveEvent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setKeyboardLanguage(); break;
        case 4: _t->findKeyAndPressTimer(); break;
        case 5: _t->setBLShow(); break;
        case 6: _t->slKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 7: _t->slKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 9: _t->slMoveEvent((*reinterpret_cast< QMoveEvent*(*)>(_a[1]))); break;
        case 10: _t->slCloseEvent(); break;
        case 11: _t->slFocusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 12: _t->slAnimatePressWord((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 13: _t->pressDownOffAllKey(); break;
        case 14: _t->show(); break;
        case 15: _t->slShow(); break;
        case 16: _t->slHide(); break;
        case 17: _t->setStyleSheet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void KeyboardClass::siKeyboardLanguageChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void KeyboardClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
