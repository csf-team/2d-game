#pragma once

#include <QApplication>
#include <QTimer>
#include <QElapsedTimer>

#include "MainWindow.h"

class BaseGameApplication
{
public:
    BaseGameApplication(int argc, char* argv[]);
    virtual ~BaseGameApplication();

    virtual int execute();

    virtual void update(float delta);
    virtual void render();

private:
    void onTimerTick();

private:
    QApplication m_qtApp;

    MainWindow* m_mainWindow;
    QTimer* m_gameLoopTimer;

    QElapsedTimer m_updateTimer;
};

