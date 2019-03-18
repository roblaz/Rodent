QT += core
QT -= gui

CONFIG += c++11

TARGET = Rodent
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rodent.cpp

HEADERS += \
    rodent.h
