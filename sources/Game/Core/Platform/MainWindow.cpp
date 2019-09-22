#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_viewportWidget = new ViewportWidget(this);

    setCentralWidget(m_viewportWidget);
}

MainWindow::~MainWindow()
{
}

ViewportWidget* MainWindow::getViewportWidget() const
{
    return m_viewportWidget;
}

