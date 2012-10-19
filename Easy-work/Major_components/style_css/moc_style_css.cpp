/****************************************************************************
** Meta object code from reading C++ file 'style_css.h'
**
** Created: Fri Oct 19 19:42:32 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "style_css.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'style_css.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StyleCSSclass[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StyleCSSclass[] = {
    "StyleCSSclass\0\0getStyle(QString)\0"
    "slotActivateCSS()\0"
};

void StyleCSSclass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StyleCSSclass *_t = static_cast<StyleCSSclass *>(_o);
        switch (_id) {
        case 0: _t->getStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotActivateCSS(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StyleCSSclass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StyleCSSclass::staticMetaObject = {
    { &StyleCSS::staticMetaObject, qt_meta_stringdata_StyleCSSclass,
      qt_meta_data_StyleCSSclass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StyleCSSclass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StyleCSSclass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StyleCSSclass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StyleCSSclass))
        return static_cast<void*>(const_cast< StyleCSSclass*>(this));
    if (!strcmp(_clname, "style_css.programm/EasyWork/Plagin/1.0.0"))
        return static_cast< StyleCSS*>(const_cast< StyleCSSclass*>(this));
    return StyleCSS::qt_metacast(_clname);
}

int StyleCSSclass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StyleCSS::qt_metacall(_c, _id, _a);
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
void StyleCSSclass::getStyle(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
