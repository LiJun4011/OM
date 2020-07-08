/****************************************************************************
** Meta object code from reading C++ file 'zaoyanC.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../zaoyanC.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zaoyanC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_zaoyanC_t {
    QByteArrayData data[18];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zaoyanC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zaoyanC_t qt_meta_stringdata_zaoyanC = {
    {
QT_MOC_LITERAL(0, 0, 7), // "zaoyanC"
QT_MOC_LITERAL(1, 8, 7), // "snddata"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "array"
QT_MOC_LITERAL(4, 23, 5), // "oksig"
QT_MOC_LITERAL(5, 29, 10), // "Delay_MSec"
QT_MOC_LITERAL(6, 40, 4), // "msec"
QT_MOC_LITERAL(7, 45, 13), // "Relay4Pressed"
QT_MOC_LITERAL(8, 59, 14), // "Relay4Released"
QT_MOC_LITERAL(9, 74, 13), // "Relay5Pressed"
QT_MOC_LITERAL(10, 88, 14), // "Relay5Released"
QT_MOC_LITERAL(11, 103, 13), // "Relay6Pressed"
QT_MOC_LITERAL(12, 117, 14), // "Relay6Released"
QT_MOC_LITERAL(13, 132, 14), // "Relay27Pressed"
QT_MOC_LITERAL(14, 147, 15), // "Relay27Released"
QT_MOC_LITERAL(15, 163, 14), // "Relay28Pressed"
QT_MOC_LITERAL(16, 178, 15), // "Relay28Released"
QT_MOC_LITERAL(17, 194, 8) // "okbutton"

    },
    "zaoyanC\0snddata\0\0array\0oksig\0Delay_MSec\0"
    "msec\0Relay4Pressed\0Relay4Released\0"
    "Relay5Pressed\0Relay5Released\0Relay6Pressed\0"
    "Relay6Released\0Relay27Pressed\0"
    "Relay27Released\0Relay28Pressed\0"
    "Relay28Released\0okbutton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zaoyanC[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   88,    2, 0x08 /* Private */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void zaoyanC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<zaoyanC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->snddata((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->oksig(); break;
        case 2: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->Relay4Pressed(); break;
        case 4: _t->Relay4Released(); break;
        case 5: _t->Relay5Pressed(); break;
        case 6: _t->Relay5Released(); break;
        case 7: _t->Relay6Pressed(); break;
        case 8: _t->Relay6Released(); break;
        case 9: _t->Relay27Pressed(); break;
        case 10: _t->Relay27Released(); break;
        case 11: _t->Relay28Pressed(); break;
        case 12: _t->Relay28Released(); break;
        case 13: _t->okbutton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (zaoyanC::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zaoyanC::snddata)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (zaoyanC::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&zaoyanC::oksig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject zaoyanC::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_zaoyanC.data,
    qt_meta_data_zaoyanC,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *zaoyanC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zaoyanC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zaoyanC.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int zaoyanC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void zaoyanC::snddata(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void zaoyanC::oksig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
