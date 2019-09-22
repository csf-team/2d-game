#include "BaseGameApplication.h"

BaseGameApplication::BaseGameApplication(int argc, char* argv[])
    : m_qtApp(argc, argv),
      m_mainWindow(nullptr),
      m_gameLoopTimer(nullptr)
{
    m_mainWindow = new MainWindow();
    m_gameLoopTimer = new QTimer(m_mainWindow);

    QObject::connect(m_gameLoopTimer, &QTimer::timeout, [=]() {
        this->onTimerTick();
    });
}

BaseGameApplication::~BaseGameApplication()
{
    delete m_mainWindow;
}

int BaseGameApplication::execute()
{
    m_mainWindow->show();
    m_gameLoopTimer->start(30);

    m_updateTimer.start();

    return m_qtApp.exec();
}

void BaseGameApplication::update(float delta)
{

}

void BaseGameApplication::render()
{

}

void BaseGameApplication::onTimerTick()
{
    float delta = m_updateTimer.restart() / 1000.0f;
    this->update(delta);

    this->render();
}
