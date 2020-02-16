/****************************************************************************
** Meta object code from reading C++ file 'DatabaseDemo01Widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DatabaseDemo01Widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DatabaseDemo01Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseDemo01Widget_t {
    QByteArrayData data[7];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseDemo01Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseDemo01Widget_t qt_meta_stringdata_DatabaseDemo01Widget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DatabaseDemo01Widget"
QT_MOC_LITERAL(1, 21, 25), // "initDatabaseButtonClicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 27), // "addProductTypeButtonClicked"
QT_MOC_LITERAL(4, 76, 28), // "findProductTypeButtonClicked"
QT_MOC_LITERAL(5, 105, 25), // "addDetectLogButtonClicked"
QT_MOC_LITERAL(6, 131, 26) // "findDetectLogButtonClicked"

    },
    "DatabaseDemo01Widget\0initDatabaseButtonClicked\0"
    "\0addProductTypeButtonClicked\0"
    "findProductTypeButtonClicked\0"
    "addDetectLogButtonClicked\0"
    "findDetectLogButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseDemo01Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    0,   41,    2, 0x09 /* Protected */,
       5,    0,   42,    2, 0x09 /* Protected */,
       6,    0,   43,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatabaseDemo01Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseDemo01Widget *_t = static_cast<DatabaseDemo01Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initDatabaseButtonClicked(); break;
        case 1: _t->addProductTypeButtonClicked(); break;
        case 2: _t->findProductTypeButtonClicked(); break;
        case 3: _t->addDetectLogButtonClicked(); break;
        case 4: _t->findDetectLogButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DatabaseDemo01Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatabaseDemo01Widget.data,
      qt_meta_data_DatabaseDemo01Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseDemo01Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseDemo01Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseDemo01Widget.stringdata0))
        return static_cast<void*>(const_cast< DatabaseDemo01Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DatabaseDemo01Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
