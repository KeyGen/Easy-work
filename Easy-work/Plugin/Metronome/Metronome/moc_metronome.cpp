/****************************************************************************
** Meta object code from reading C++ file 'metronome.h'
**
** Created: Tue Jan 22 14:58:37 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "metronome.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'metronome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MetronomeClass[] = {

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

static const char qt_meta_stringdata_MetronomeClass[] = {
    "MetronomeClass\0"
};

void MetronomeClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MetronomeClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MetronomeClass::staticMetaObject = {
    { &Metronome::staticMetaObject, qt_meta_stringdata_MetronomeClass,
      qt_meta_data_MetronomeClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MetronomeClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MetronomeClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MetronomeClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MetronomeClass))
        return static_cast<void*>(const_cast< MetronomeClass*>(this));
    if (!strcmp(_clname, "Metronome/EasyWork/Plagin/1.0.0"))
        return static_cast< Metronome*>(const_cast< MetronomeClass*>(this));
    return Metronome::qt_metacast(_clname);
}

int MetronomeClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Metronome::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
