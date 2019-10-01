!MATH_PRI {
CONFIG += MATH_PRI
INCLUDEPATH *= $$clean_path($$PWD/../)

# It's just a helper .pri which brings all data structures together. It can be removed/splitted if it needed

HEADERS += \
    $$PWD/matrix3.h \
    $$PWD/matrix4.h \
    $$PWD/vector2.h \
    $$PWD/vector3.h \
    $$PWD/vector4.h

SOURCES += \
    $$PWD/matrix3.cpp \
    $$PWD/matrix4.cpp \
    $$PWD/vector2.cpp \
    $$PWD/vector3.cpp \
    $$PWD/vector4.cpp
}
