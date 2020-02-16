/****************************************************************************
** Meta object code from reading C++ file 'AlphaThread1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AlphaThread1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlphaThread1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlphaThread1_t {
    QByteArrayData data[6];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlphaThread1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlphaThread1_t qt_meta_stringdata_AlphaThread1 = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AlphaThread1"
QT_MOC_LITERAL(1, 13, 10), // "workSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "threadName"
QT_MOC_LITERAL(4, 36, 11), // "pauseSignal"
QT_MOC_LITERAL(5, 48, 12) // "finishSignal"

    },
    "AlphaThread1\0workSignal\0\0threadName\0"
    "pauseSignal\0finishSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlphaThread1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       5,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void AlphaThread1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlphaThread1 *_t = static_cast<AlphaThread1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->pauseSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->finishSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AlphaThread1::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlphaThread1::workSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AlphaThread1::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlphaThread1::pauseSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AlphaThread1::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlphaThread1::finishSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AlphaThread1::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AlphaThread1.data,
      qt_meta_data_AlphaThread1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AlphaThread1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlphaThread1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlphaThread1.stringdata0))
        return static_cast<void*>(const_cast< AlphaThread1*>(this));
    return QThread::qt_metacast(_clname);
}

int AlphaThread1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AlphaThread1::workSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlphaThread1::pauseSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AlphaThread1::finishSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
