/****************************************************************************
** Meta object code from reading C++ file 'regimefile.h'
**
** Created: Thu Dec 6 23:21:42 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regimefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regimefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RigimeFileClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      39,   16,   16,   16, 0x05,
      56,   16,   16,   16, 0x05,
      69,   16,   16,   16, 0x05,
      96,   16,   16,   16, 0x05,
     124,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     135,   16,   16,   16, 0x08,
     149,   16,   16,   16, 0x08,
     172,   16,   16,   16, 0x08,
     190,   16,   16,   16, 0x08,
     218,   16,   16,   16, 0x08,
     244,   16,   16,   16, 0x08,
     258,   16,   16,   16, 0x08,
     276,  270,   16,   16, 0x0a,
     304,  270,   16,   16, 0x0a,
     334,  270,   16,   16, 0x0a,
     363,   16,   16,   16, 0x0a,
     390,   16,   16,   16, 0x0a,
     420,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RigimeFileClass[] = {
    "RigimeFileClass\0\0siGetWidget(QWidget*)\0"
    "siGetWord(QChar)\0stopLesson()\0"
    "siSaveSetting(QStringList)\0"
    "siGetDateValue(QStringList)\0siDBOpen()\0"
    "slGetWidget()\0setWorkerText(QString)\0"
    "destroyedWidget()\0labelSetStyleSheetDefault()\0"
    "labelSetStyleSheetError()\0saveSetting()\0"
    "stopPrint()\0event\0slKeyPressEvent(QKeyEvent*)\0"
    "slKeyReleaseEvent(QKeyEvent*)\0"
    "slResizeEvent(QResizeEvent*)\0"
    "slKeyboardLanguageChange()\0"
    "slSetSaveSetting(QStringList)\0"
    "slCloseEvent()\0"
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
        case 3: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->siGetDateValue((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->siDBOpen(); break;
        case 6: _t->slGetWidget(); break;
        case 7: _t->setWorkerText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->destroyedWidget(); break;
        case 9: _t->labelSetStyleSheetDefault(); break;
        case 10: _t->labelSetStyleSheetError(); break;
        case 11: _t->saveSetting(); break;
        case 12: _t->stopPrint(); break;
        case 13: _t->slKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 14: _t->slKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 15: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 16: _t->slKeyboardLanguageChange(); break;
        case 17: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 18: _t->slCloseEvent(); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
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

// SIGNAL 3
void RigimeFileClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RigimeFileClass::siGetDateValue(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RigimeFileClass::siDBOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
