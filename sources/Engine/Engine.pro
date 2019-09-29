include(../../Config.pri)

QT += widgets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Engine.cpp \
    Modules/Graphics/GraphicsSystem.cpp \
    Modules/Input/InputSystem.cpp \
    Modules/Math/matrix3.cpp \
    Modules/Math/matrix4.cpp \
    Modules/Math/vector2.cpp \
    Modules/Math/vector3.cpp \
    Modules/Math/vector4.cpp \
    Modules/Platform/ViewportWidget.cpp \
    Modules/ECS/BaseComponentInstance.cpp \
    Modules/ECS/GameObject.cpp \
    Modules/ECS/GameObjectsSequentialIterator.cpp \
    Modules/ECS/GameObjectsSequentialView.cpp \
    Modules/ECS/GameSystem.cpp \
    Modules/ECS/GameWorld.cpp

HEADERS += \
    Engine.h \
    Modules/Graphics/GraphicsSystem.h \
    Modules/Input/InputSystem.h \
    Modules/Math/matrix3.h \
    Modules/Math/matrix4.h \
    Modules/Math/vector2.h \
    Modules/Math/vector3.h \
    Modules/Math/vector4.h \
    Modules/Platform/ViewportWidget.h \
    Modules/ECS/BaseComponentInstance.h \
    Modules/ECS/BaseEventsListener.h \
    Modules/ECS/ComponentHandle.h \
    Modules/ECS/ComponentInstance.h \
    Modules/ECS/ECS.h \
    Modules/ECS/EventsListener.h \
    Modules/ECS/GameObject.h \
    Modules/ECS/GameObjectImpl.h \
    Modules/ECS/GameObjectsComponentsIterator.h \
    Modules/ECS/GameObjectsComponentsIteratorImpl.h \
    Modules/ECS/GameObjectsComponentsView.h \
    Modules/ECS/GameObjectsComponentsViewImpl.h \
    Modules/ECS/GameObjectsSequentialIterator.h \
    Modules/ECS/GameObjectsSequentialView.h \
    Modules/ECS/GameSystem.h \
    Modules/ECS/GameWorld.h \
    Utility/helpers.h

QMAKE_CXXFLAGS += -include $$PWD/Utility/helpers.h
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Werror

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
