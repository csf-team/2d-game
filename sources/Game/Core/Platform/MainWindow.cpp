#include "MainWindow.h"

#include <QCloseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_viewportWidget = new ViewportWidget(this);

    setCentralWidget(m_viewportWidget);
    setFocusPolicy(Qt::StrongFocus);

    setMouseTracking(true);
    m_viewportWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
}

ViewportWidget* MainWindow::getViewportWidget() const
{
    return m_viewportWidget;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    emit close();
    event->accept();
}

void MainWindow::keyPressEvent(QKeyEvent* ev)
{
    emit keyDown(static_cast<Qt::Key>(ev->key()));

    QMainWindow::keyPressEvent(ev);
}

void MainWindow::keyReleaseEvent(QKeyEvent* ev)
{
    if (!ev->isAutoRepeat()) {
        emit keyUp(static_cast<Qt::Key>(ev->key()));
    }

    QMainWindow::keyReleaseEvent(ev);
}

void MainWindow::mousePressEvent(QMouseEvent* ev)
{
    emit mouseButtonDown(ev->button());

    QMainWindow::mousePressEvent(ev);
}

void MainWindow::mouseReleaseEvent(QMouseEvent* ev)
{
    emit mouseButtonUp(ev->button());

    QMainWindow::mouseReleaseEvent(ev);
}

void MainWindow::mouseMoveEvent(QMouseEvent* ev)
{
    emit mouseMove(ev->pos());

    QMainWindow::mouseMoveEvent(ev);
}
