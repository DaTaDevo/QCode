/****************************************************************************
** Meta object code from reading C++ file 'trianglewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trianglewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trianglewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TriangleWidget_t {
    QByteArrayData data[10];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TriangleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TriangleWidget_t qt_meta_stringdata_TriangleWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TriangleWidget"
QT_MOC_LITERAL(1, 15, 9), // "startTask"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "numTask"
QT_MOC_LITERAL(4, 34, 4), // "upAB"
QT_MOC_LITERAL(5, 39, 2), // "ab"
QT_MOC_LITERAL(6, 42, 4), // "upBC"
QT_MOC_LITERAL(7, 47, 2), // "bc"
QT_MOC_LITERAL(8, 50, 4), // "upAC"
QT_MOC_LITERAL(9, 55, 2) // "ac"

    },
    "TriangleWidget\0startTask\0\0numTask\0"
    "upAB\0ab\0upBC\0bc\0upAC\0ac"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TriangleWidget[] = {

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
       1,    1,   34,    2, 0x09 /* Protected */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,

       0        // eod
};

void TriangleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TriangleWidget *_t = static_cast<TriangleWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->upAB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->upBC((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->upAC((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TriangleWidget::staticMetaObject = {
    { &BaseWidget::staticMetaObject, qt_meta_stringdata_TriangleWidget.data,
      qt_meta_data_TriangleWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TriangleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TriangleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TriangleWidget.stringdata0))
        return static_cast<void*>(this);
    return BaseWidget::qt_metacast(_clname);
}

int TriangleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseWidget::qt_metacall(_c, _id, _a);
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
