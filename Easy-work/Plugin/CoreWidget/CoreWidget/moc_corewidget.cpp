/****************************************************************************
** Meta object code from reading C++ file 'corewidget.h'
**
** Created: Sat Nov 3 00:06:04 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "corewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'corewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoreWidgetClass[] = {

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
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CoreWidgetClass[] = {
    "CoreWidgetClass\0\0siGetWidget(QWidget*)\0"
    "slGetWidget()\0"
};

void CoreWidgetClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoreWidgetClass *_t = static_cast<CoreWidgetClass *>(_o);
        switch (_id) {
        case 0: _t->siGetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->slGetWidget(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CoreWidgetClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CoreWidgetClass::staticMetaObject = {
    { &CoreWidget::staticMetaObject, qt_meta_stringdata_CoreWidgetClass,
      qt_meta_data_CoreWidgetClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CoreWidgetClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CoreWidgetClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CoreWidgetClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoreWidgetClass))
        return static_cast<void*>(const_cast< CoreWidgetClass*>(this));
    if (!strcmp(_clname, "CoreWidget/EasyWork/Plagin/1.0.0"))
        return static_cast< CoreWidget*>(const_cast< CoreWidgetClass*>(this));
    return CoreWidget::qt_metacast(_clname);
}

int CoreWidgetClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CoreWidget::qt_metacall(_c, _id, _a);
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
void CoreWidgetClass::siGetWidget(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
