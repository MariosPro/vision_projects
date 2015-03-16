/****************************************************************************
** Meta object code from reading C++ file 'cqtopencvviewergl.h'
**
** Created: Tue Jan 27 06:43:01 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cqtopencvviewergl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cqtopencvviewergl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CQtOpenCVViewerGl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   60,   55,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CQtOpenCVViewerGl[] = {
    "CQtOpenCVViewerGl\0\0outW,outH\0"
    "imageSizeChanged(int,int)\0bool\0image\0"
    "showImage(cv::Mat)\0"
};

void CQtOpenCVViewerGl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CQtOpenCVViewerGl *_t = static_cast<CQtOpenCVViewerGl *>(_o);
        switch (_id) {
        case 0: _t->imageSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: { bool _r = _t->showImage((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CQtOpenCVViewerGl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CQtOpenCVViewerGl::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CQtOpenCVViewerGl,
      qt_meta_data_CQtOpenCVViewerGl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CQtOpenCVViewerGl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CQtOpenCVViewerGl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CQtOpenCVViewerGl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQtOpenCVViewerGl))
        return static_cast<void*>(const_cast< CQtOpenCVViewerGl*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int CQtOpenCVViewerGl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CQtOpenCVViewerGl::imageSizeChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
