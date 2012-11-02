/****************************************************************************
** Meta object code from reading C++ file 'regimefile.h'
**
** Created: Sat Nov 3 00:06:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regimefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regimefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RigimeFileClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      39,   16,   16,   16, 0x05,
      56,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   16,   16,   16, 0x08,
      83,   16,   16,   16, 0x08,
     106,   16,   16,   16, 0x08,
     124,   16,   16,   16, 0x08,
     152,   16,   16,   16, 0x08,
     184,  178,   16,   16, 0x0a,
     212,  178,   16,   16, 0x0a,
     242,  178,   16,   16, 0x0a,
     271,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RigimeFileClass[] = {
    "RigimeFileClass\0\0siGetWidget(QWidget*)\0"
    "siGetWord(QChar)\0stopLesson()\0"
    "slGetWidget()\0setWorkerText(QString)\0"
    "destroyedWidget()\0labelSetStyleSheetDefault()\0"
    "labelSetStyleSheetError()\0event\0"
    "slKeyPressEvent(QKeyEvent*)\0"
    "slKeyReleaseEvent(QKeyEvent*)\0"
    "slResizeEvent(QResizeEvent*)\0"
    "siKeyboardLanguageChange()\0"
};

void RigimeFileClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RigimeFileClass *_t = static_cast<RigimeFileClass *>(_o);
        switch (_id) {
        case 0: _t->siGetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->siGetWord((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 2: _t->stopLesson(); break;
        case 3: _t->slGetWidget(); break;
        case 4: _t->setWorkerText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->destroyedWidget(); break;
        case 6: _t->labelSetStyleSheetDefault(); break;
        case 7: _t->labelSetStyleSheetError(); break;
        case 8: _t->slKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 9: _t->slKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 10: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 11: _t->siKeyboardLanguageChange(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RigimeFileClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RigimeFileClass::staticMetaObject = {
    { &RigimeFile::staticMetaObject, qt_meta_stringdata_RigimeFileClass,
      qt_meta_data_RigimeFileClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RigimeFileClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RigimeFileClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RigimeFileClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RigimeFileClass))
        return static_cast<void*>(const_cast< RigimeFileClass*>(this));
    if (!strcmp(_clname, "RigimeFile/EasyWork/Plagin/1.0.0"))
        return static_cast< RigimeFile*>(const_cast< RigimeFileClass*>(this));
    return RigimeFile::qt_metacast(_clname);
}

int RigimeFileClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RigimeFile::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void RigimeFileClass::siGetWidget(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RigimeFileClass::siGetWord(QChar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RigimeFileClass::stopLesson()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
