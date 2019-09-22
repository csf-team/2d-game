#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class ViewportWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    ViewportWidget(QWidget *parent);
    ~ViewportWidget() override;

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

signals:
    void initialize();
    void resize(int width, int height);
    void render();
};
