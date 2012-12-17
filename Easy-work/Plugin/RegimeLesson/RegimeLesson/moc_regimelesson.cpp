/****************************************************************************
** Meta object code from reading C++ file 'regimelesson.h'
**
** Created: Fri Dec 7 13:51:43 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "regimelesson.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'regimelesson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegimeLessonClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      41,   18,   18,   18, 0x05,
      68,   18,   18,   18, 0x05,
      85,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   18,   18,   18, 0x0a,
     128,   18,   18,   18, 0x0a,
     149,  143,   18,   18, 0x0a,
     178,  143,   18,   18, 0x0a,
     206,   18,   18,   18, 0x0a,
     233,   18,   18,   18, 0x08,
     247,   18,   18,   18, 0x08,
     265,   18,   18,   18, 0x08,
     289,   18,   18,   18, 0x08,
     317,   18,   18,   18, 0x08,

 // methods: signature, parameters, type, tag, flags
     351,   18,  343,   18, 0x02,
     374,   18,   18,   18, 0x02,
     400,   18,  343,   18, 0x02,
     419,   18,  343,   18, 0x02,
     434,   18,   18,   18, 0x02,
     455,   18,  451,   18, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_RegimeLessonClass[] = {
    "RegimeLessonClass\0\0siGetWidget(QWidget*)\0"
    "siSaveSetting(QStringList)\0siGetWord(QChar)\0"
    "stopLesson()\0slSetSaveSetting(QStringList)\0"
    "slCloseEvent()\0event\0slResizeEvent(QResizeEvent*)\0"
    "slKeyPressEvent(QKeyEvent*)\0"
    "slKeyboardLanguageChange()\0slGetWidget()\0"
    "destroyedWidget()\0on_pushButton_clicked()\0"
    "labelSetStyleSheetDefault()\0"
    "labelSetStyleSheetError()\0QString\0"
    "getLanguageLesson(int)\0readDBNameLesson(QString)\0"
    "getNameLesson(int)\0getAutorName()\0"
    "startLesson(int)\0int\0getLessonAssessment(QString)\0"
};

void RegimeLessonClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegimeLessonClass *_t = static_cast<RegimeLessonClass *>(_o);
        switch (_id) {
        case 0: _t->siGetWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->siSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->siGetWord((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 3: _t->stopLesson(); break;
        case 4: _t->slSetSaveSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->slCloseEvent(); break;
        case 6: _t->slResizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 7: _t->slKeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: _t->slKeyboardLanguageChange(); break;
        case 9: _t->slGetWidget(); break;
        case 10: _t->destroyedWidget(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->labelSetStyleSheetDefault(); break;
        case 13: _t->labelSetStyleSheetError(); break;
        case 14: { QString _r = _t->getLanguageLesson((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: _t->readDBNameLesson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: { QString _r = _t->getNameLesson((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: { QString _r = _t->getAutorName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: _t->startLesson((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: { int _r = _t->getLessonAssessment((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegimeLessonClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegimeLessonClass::staticMetaObject = {
    { &RegimeLesson::staticMetaObject, qt_meta_stringdata_RegimeLessonClass,
      qt_meta_data_RegimeLessonClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegimeLessonClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegimeLessonClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegimeLessonClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegimeLessonClass))
        return static_cast<void*>(const_cast< RegimeLessonClass*>(this));
    if (!strcmp(_clname, "RegimeLesson/EasyWork/Plagin/1.0.0"))
        return static_cast< RegimeLesson*>(const_cast< RegimeLessonClass*>(this));
    return RegimeLesson::qt_metacast(_clname);
}

int RegimeLessonClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RegimeLesson::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void RegimeLessonClass::siGetWidget(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RegimeLessonClass::siSaveSetting(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RegimeLessonClass::siGetWord(QChar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RegimeLessonClass::stopLesson()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
