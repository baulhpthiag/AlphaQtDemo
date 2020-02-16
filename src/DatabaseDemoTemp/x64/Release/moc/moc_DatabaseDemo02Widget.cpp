/****************************************************************************
** Meta object code from reading C++ file 'DatabaseDemo02Widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DatabaseDemo02Widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DatabaseDemo02Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseDemo02Widget_t {
    QByteArrayData data[6];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseDemo02Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseDemo02Widget_t qt_meta_stringdata_DatabaseDemo02Widget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DatabaseDemo02Widget"
QT_MOC_LITERAL(1, 21, 17), // "findButtonClicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "addButtonClicked"
QT_MOC_LITERAL(4, 57, 19), // "updateButtonClicked"
QT_MOC_LITERAL(5, 77, 19) // "deleteButtonClicked"

    },
    "DatabaseDemo02Widget\0findButtonClicked\0"
    "\0addButtonClicked\0updateButtonClicked\0"
    "deleteButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseDemo02Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatabaseDemo02Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseDemo02Widget *_t = static_cast<DatabaseDemo02Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findButtonClicked(); break;
        case 1: _t->addButtonClicked(); break;
        case 2: _t->updateButtonClicked(); break;
        case 3: _t->deleteButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DatabaseDemo02Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatabaseDemo02Widget.data,
      qt_meta_data_DatabaseDemo02Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseDemo02Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseDemo02Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseDemo02Widget.stringdata0))
        return static_cast<void*>(const_cast< DatabaseDemo02Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DatabaseDemo02Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
