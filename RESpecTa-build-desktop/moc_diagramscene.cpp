/****************************************************************************
** Meta object code from reading C++ file 'diagramscene.h'
**
** Created: Mon May 23 16:29:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../diagramscene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagramscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DiagramScene[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      54,   49,   44,   13, 0x05,
      80,   14,   13,   13, 0x05,
     113,   14,   13,   13, 0x05,
     142,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     168,  163,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DiagramScene[] = {
    "DiagramScene\0\0item\0itemInserted(BaseState*)\0"
    "bool\0line\0lineInserted(Transition*)\0"
    "textInserted(QGraphicsTextItem*)\0"
    "itemSelected(QGraphicsItem*)\0"
    "reportError(QString)\0mode\0setMode(Mode)\0"
};

const QMetaObject DiagramScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_DiagramScene,
      qt_meta_data_DiagramScene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DiagramScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DiagramScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DiagramScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DiagramScene))
        return static_cast<void*>(const_cast< DiagramScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int DiagramScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: itemInserted((*reinterpret_cast< BaseState*(*)>(_a[1]))); break;
        case 1: { bool _r = lineInserted((*reinterpret_cast< Transition*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: textInserted((*reinterpret_cast< QGraphicsTextItem*(*)>(_a[1]))); break;
        case 3: itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 4: reportError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void DiagramScene::itemInserted(BaseState * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
bool DiagramScene::lineInserted(Transition * _t1)
{
    bool _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void DiagramScene::textInserted(QGraphicsTextItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DiagramScene::itemSelected(QGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DiagramScene::reportError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
