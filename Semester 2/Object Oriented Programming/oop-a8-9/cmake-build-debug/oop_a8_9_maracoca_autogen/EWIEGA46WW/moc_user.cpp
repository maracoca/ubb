/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../user.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUserGUIENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserGUIENDCLASS = QtMocHelpers::stringData(
    "UserGUI",
    "CloseUserWindow",
    "",
    "closeButtonClicked",
    "nextButtonClicked",
    "addToWatchListButtonClicked",
    "deleteSelectedMovie",
    "openWatchlistFile",
    "watchlistFileTypeHandler",
    "okButtonClicked",
    "genreInputChanged",
    "updateMovieDisplay",
    "populateWatchlist"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserGUIENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    0,   87,    2, 0x0a,    8 /* Public */,
      10,    0,   88,    2, 0x0a,    9 /* Public */,
      11,    0,   89,    2, 0x0a,   10 /* Public */,
      12,    0,   90,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject UserGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserGUIENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserGUIENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserGUIENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserGUI, std::true_type>,
        // method 'CloseUserWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToWatchListButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteSelectedMovie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openWatchlistFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'watchlistFileTypeHandler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'okButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'genreInputChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMovieDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'populateWatchlist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->CloseUserWindow(); break;
        case 1: _t->closeButtonClicked(); break;
        case 2: _t->nextButtonClicked(); break;
        case 3: _t->addToWatchListButtonClicked(); break;
        case 4: _t->deleteSelectedMovie(); break;
        case 5: _t->openWatchlistFile(); break;
        case 6: _t->watchlistFileTypeHandler(); break;
        case 7: _t->okButtonClicked(); break;
        case 8: _t->genreInputChanged(); break;
        case 9: _t->updateMovieDisplay(); break;
        case 10: _t->populateWatchlist(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserGUI::*)();
            if (_t _q_method = &UserGUI::CloseUserWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *UserGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserGUIENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void UserGUI::CloseUserWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
