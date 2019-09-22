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

    virtual void initialize();
    virtual void shutdown();

    virtual void update(float delta);
    virtual void render();

protected:
    MainWindow* getMainWindow() const;

private:
    void onTimerTick();
    void performUpdate(float delta);

private:
    QApplication m_qtApp;

    MainWindow* m_mainWindow;
    QTimer* m_gameLoopTimer;

    QElapsedTimer m_updateTimer;
};

