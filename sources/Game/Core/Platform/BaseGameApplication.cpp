#include "BaseGameApplication.h"

BaseGameApplication::BaseGameApplication(int argc, char* argv[])
    : m_qtApp(argc, argv),
      m_mainWindow(nullptr),
      m_gameLoopTimer(nullptr)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4, 5);
    format.setProfile(QSurfaceFormat::CoreProfile);

    QSurfaceFormat::setDefaultFormat(format);

    m_mainWindow = new MainWindow();
    m_gameLoopTimer = new QTimer(m_mainWindow);

    QObject::connect(m_gameLoopTimer, &QTimer::timeout, [=]() {
        this->onTimerTick();
    });

    QObject::connect(m_mainWindow, &MainWindow::close, [=]() {
        this->m_gameLoopTimer->stop();
        this->shutdown();
    });

    QObject::connect(m_mainWindow->getViewportWidget(), &ViewportWidget::initialize, [=]() {
        this->initialize();
    });

    QObject::connect(m_mainWindow->getViewportWidget(), &ViewportWidget::render, [=]() {
        this->render();
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

void BaseGameApplication::initialize()
{

}

void BaseGameApplication::shutdown()
{

}

void BaseGameApplication::update(float delta)
{
    m_mainWindow->getViewportWidget()->makeCurrent();
}

void BaseGameApplication::render()
{

}

MainWindow* BaseGameApplication::getMainWindow() const
{
    return m_mainWindow;
}

void BaseGameApplication::onTimerTick()
{
    float delta = m_updateTimer.restart() / 1000.0f;
    performUpdate(delta);

    m_mainWindow->getViewportWidget()->update();
}

void BaseGameApplication::performUpdate(float delta)
{
    m_mainWindow->getViewportWidget()->makeCurrent();
    update(delta);
    m_mainWindow->getViewportWidget()->doneCurrent();
}
