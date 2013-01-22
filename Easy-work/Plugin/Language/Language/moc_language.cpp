/****************************************************************************
** Meta object code from reading C++ file 'language.h'
**
** Created: Tue Jan 22 16:16:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "language.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'language.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LanguageClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LanguageClass[] = {
    "LanguageClass\0\0clickAction()\0"
};

void LanguageClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LanguageClass *_t = static_cast<LanguageClass *>(_o);
        switch (_id) {
        case 0: _t->clickAction(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LanguageClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LanguageClass::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguageClass,
      qt_meta_data_LanguageClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LanguageClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LanguageClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LanguageClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageClass))
        return static_cast<void*>(const_cast< LanguageClass*>(this));
    if (!strcmp(_clname, "Language/EasyWork/Plagin/1.0.0"))
        return static_cast< Language*>(const_cast< LanguageClass*>(this));
    return Language::qt_metacast(_clname);
}

int LanguageClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
