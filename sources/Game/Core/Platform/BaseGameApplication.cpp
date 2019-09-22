#include "BaseGameApplication.h"

#include <QMessageLogger>

BaseGameApplication::BaseGameApplication(int argc, char* argv[])
    : m_qtApp(argc, argv),
      m_mainWindow(nullptr),
      m_gameLoopTimer(nullptr),
      m_glDebugLogger(nullptr)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4, 5);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setOption(QSurfaceFormat::DebugContext);

    QSurfaceFormat::setDefaultFormat(format);

    m_mainWindow = new MainWindow();
    m_gameLoopTimer = new QTimer(m_mainWindow);

    QObject::connect(m_gameLoopTimer, &QTimer::timeout, [=]() {
        this->onTimerTick();
    });

    QObject::connect(m_mainWindow, &MainWindow::close, [=]() {
        this->performShutdown();
    });

    QObject::connect(m_mainWindow->getViewportWidget(), &ViewportWidget::initialize, [=]() {
        this->performInitialize();
    });

    QObject::connect(m_mainWindow->getViewportWidget(), &ViewportWidget::render, [=]() {
        this->performRender();
    });
}

BaseGameApplication::~BaseGameApplication()
{
    delete m_mainWindow;
}

int BaseGameApplication::execute()
{
    m_gameLoopTimer->start(30);

    m_mainWindow->resize(640, 480);
    m_mainWindow->show();

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

void BaseGameApplication::performInitialize()
{
    m_glDebugLogger = new QOpenGLDebugLogger(m_mainWindow);
    m_glDebugLogger->initialize();

    QObject::connect(m_glDebugLogger, &QOpenGLDebugLogger::messageLogged, [=](const QOpenGLDebugMessage &debugMessage) {
        qDebug() << debugMessage;
    });

    m_glDebugLogger->startLogging();

    initialize();
}

void BaseGameApplication::performShutdown()
{
    this->m_gameLoopTimer->stop();
    shutdown();
}

void BaseGameApplication::performUpdate(float delta)
{
    m_mainWindow->getViewportWidget()->makeCurrent();
    update(delta);
    m_mainWindow->getViewportWidget()->doneCurrent();
}

void BaseGameApplication::performRender()
{
    render();
}
