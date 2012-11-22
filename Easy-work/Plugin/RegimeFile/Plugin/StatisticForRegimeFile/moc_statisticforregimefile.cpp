/****************************************************************************
** Meta object code from reading C++ file 'statisticforregimefile.h'
**
** Created: Wed Nov 21 11:24:53 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "statisticforregimefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statisticforregimefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StatisticForRegimeFileClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x0a,
      51,   28,   28,   28, 0x0a,
      63,   28,   28,   28, 0x08,
      70,   28,   28,   28, 0x08,
      95,   28,   28,   28, 0x08,
     116,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StatisticForRegimeFileClass[] = {
    "StatisticForRegimeFileClass\0\0"
    "setValue(QStringList)\0connectDB()\0"
    "exec()\0setActiveItemWidget(int)\0"
    "deleteStatisticAll()\0deleteStatistic()\0"
};

void StatisticForRegimeFileClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StatisticForRegimeFileClass *_t = static_cast<StatisticForRegimeFileClass *>(_o);
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->connectDB(); break;
        case 2: _t->exec(); break;
        case 3: _t->setActiveItemWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->deleteStatisticAll(); break;
        case 5: _t->deleteStatistic(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StatisticForRegimeFileClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StatisticForRegimeFileClass::staticMetaObject = {
    { &StatisticForRegimeFile::staticMetaObject, qt_meta_stringdata_StatisticForRegimeFileClass,
      qt_meta_data_StatisticForRegimeFileClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StatisticForRegimeFileClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StatisticForRegimeFileClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StatisticForRegimeFileClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StatisticForRegimeFileClass))
        return static_cast<void*>(const_cast< StatisticForRegimeFileClass*>(this));
    if (!strcmp(_clname, "StatisticForRegimeFile/RigimeFile/EasyWork/Plagin/1.0.0"))
        return static_cast< StatisticForRegimeFile*>(const_cast< StatisticForRegimeFileClass*>(this));
    return StatisticForRegimeFile::qt_metacast(_clname);
}

int StatisticForRegimeFileClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StatisticForRegimeFile::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
