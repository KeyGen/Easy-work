/****************************************************************************
** Meta object code from reading C++ file 'savesetting.h'
**
** Created: Wed Nov 14 16:01:16 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "savesetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savesetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SaveSettingClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      48,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   17,   17,   17, 0x0a,
      92,   17,   17,   17, 0x0a,
     109,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SaveSettingClass[] = {
    "SaveSettingClass\0\0sisetSaveSetting(QStringList)\0"
    "closeApplication()\0saveSetting(QStringList)\0"
    "setSaveSetting()\0deleteSetting()\0"
};

void SaveSettingClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SaveSettingClass *_t = static_cast<SaveSettingClass *>(_o);
        switch (_id) {
        case 0: _t->sisetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->closeApplication(); break;
        case 2: _t->saveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->setSaveSetting(); break;
        case 4: _t->deleteSetting(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SaveSettingClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SaveSettingClass::staticMetaObject = {
    { &SaveSetting::staticMetaObject, qt_meta_stringdata_SaveSettingClass,
      qt_meta_data_SaveSettingClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SaveSettingClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SaveSettingClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SaveSettingClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SaveSettingClass))
        return static_cast<void*>(const_cast< SaveSettingClass*>(this));
    if (!strcmp(_clname, "SaveSetting/EasyWork/Plagin/1.0.0"))
        return static_cast< SaveSetting*>(const_cast< SaveSettingClass*>(this));
    return SaveSetting::qt_metacast(_clname);
}

int SaveSettingClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SaveSetting::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SaveSettingClass::sisetSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SaveSettingClass::closeApplication()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
