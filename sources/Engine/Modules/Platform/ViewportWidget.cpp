#include "ViewportWidget.h"

ViewportWidget::ViewportWidget(QWidget *parent)
    : QOpenGLWidget(parent)

{
}

ViewportWidget::~ViewportWidget()
{

}

void ViewportWidget::initializeGL()
{
    emit initialize();
}

void ViewportWidget::resizeGL(int width, int height)
{
    emit resize(width, height);
}

void ViewportWidget::paintGL()
{
    emit render();
}
