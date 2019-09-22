include(Config.pri)

TEMPLATE = subdirs

SUBDIRS += \
    sources/Engine \
    sources/Game


CONFIG += ordered

Game.depends = Engine

APP_DIR = ./
