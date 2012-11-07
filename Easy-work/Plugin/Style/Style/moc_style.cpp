/****************************************************************************
** Meta object code from reading C++ file 'style.h'
**
** Created: Wed Nov 7 15:51:22 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "style.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'style.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StyleClass[] = {

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
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StyleClass[] = {
    "StyleClass\0\0getStyle(QString)\0"
    "slotActivateCSS()\0slCloseEvent()\0"
};

void StyleClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StyleClass *_t = static_cast<StyleClass *>(_o);
        switch (_id) {
        case 0: _t->getStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotActivateCSS(); break;
        case 2: _t->slCloseEvent(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StyleClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StyleClass::staticMetaObject = {
    { &Style::staticMetaObject, qt_meta_stringdata_StyleClass,
      qt_meta_data_StyleClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StyleClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StyleClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StyleClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StyleClass))
        return static_cast<void*>(const_cast< StyleClass*>(this));
    if (!strcmp(_clname, "Style/EasyWork/Plagin/1.0.0"))
        return static_cast< Style*>(const_cast< StyleClass*>(this));
    return Style::qt_metacast(_clname);
}

int StyleClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Style::qt_metacall(_c, _id, _a);
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
void StyleClass::getStyle(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
