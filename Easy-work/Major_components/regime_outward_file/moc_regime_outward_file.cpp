/****************************************************************************
** Meta object code from reading C++ file 'regime_outward_file.h'
**
** Created: Fri Oct 19 20:56:54 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regime_outward_file.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regime_outward_file.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegimeFileClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_RegimeFileClass[] = {
    "RegimeFileClass\0"
};

void RegimeFileClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RegimeFileClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegimeFileClass::staticMetaObject = {
    { &RegimeFile::staticMetaObject, qt_meta_stringdata_RegimeFileClass,
      qt_meta_data_RegimeFileClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegimeFileClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegimeFileClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegimeFileClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegimeFileClass))
        return static_cast<void*>(const_cast< RegimeFileClass*>(this));
    if (!strcmp(_clname, "regime.outward.file.programm/EasyWork/Plagin/1.0.0"))
        return static_cast< RegimeFile*>(const_cast< RegimeFileClass*>(this));
    return RegimeFile::qt_metacast(_clname);
}

int RegimeFileClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RegimeFile::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
