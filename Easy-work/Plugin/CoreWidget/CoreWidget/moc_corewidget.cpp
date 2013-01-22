/****************************************************************************
** Meta object code from reading C++ file 'corewidget.h'
**
** Created: Tue Jan 22 14:31:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "corewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'corewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoreWidgetClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      44,   16,   16,   16, 0x05,
      66,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      82,   76,   16,   16, 0x0a,
     111,   16,   16,   16, 0x08,
     125,   16,   16,   16, 0x08,
     143,   16,   16,   16, 0x08,
     161,   16,   16,   16, 0x0a,
     191,   16,   16,   16, 0x0a,

 // methods: signature, parameters, type, tag, flags
     206,   16,   16,   16, 0x02,
     222,   16,   16,   16, 0x02,
     238,   16,   16,   16, 0x02,
     258,   16,   16,   16, 0x02,
     269,   16,   16,   16, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_CoreWidgetClass[] = {
    "CoreWidgetClass\0\0siSaveSetting(QStringList)\0"
    "siGetWidget(QWidget*)\0siFocus()\0event\0"
    "slResizeEvent(QResizeEvent*)\0slGetWidget()\0"
    "destroyedWidget()\0timerChangeText()\0"
    "slSetSaveSetting(QStringList)\0"
    "slCloseEvent()\0followingText()\0"
    "precedingText()\0setStopChangeText()\0"
    "getFocus()\0goToSite(QString)\0"
};

void CoreWidgetClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoreWidgetClass *_t = static_cast<CoreWidgetClass *>(_o);
        switch (_id) {
        case 0: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->siGetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->siFocus(); break;
        case 3: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->slGetWidget(); break;
        case 5: _t->destroyedWidget(); break;
        case 6: _t->timerChangeText(); break;
        case 7: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->slCloseEvent(); break;
        case 9: _t->followingText(); break;
        case 10: _t->precedingText(); break;
        case 11: _t->setStopChangeText(); break;
        case 12: _t->getFocus(); break;
        case 13: _t->goToSite((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CoreWidgetClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CoreWidgetClass::siGetWidget(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CoreWidgetClass::siFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
