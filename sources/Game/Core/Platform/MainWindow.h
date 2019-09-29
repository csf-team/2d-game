#pragma once

#include <QMainWindow>
#include <Engine/Modules/Platform/ViewportWidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    ViewportWidget* getViewportWidget() const;

protected:
    void keyPressEvent(QKeyEvent* ev) override;
    void keyReleaseEvent(QKeyEvent* ev) override;

    void mousePressEvent(QMouseEvent* ev) override;
    void mouseReleaseEvent(QMouseEvent* ev) override;

    void mouseMoveEvent(QMouseEvent* ev) override;
private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void close();

    void keyDown(Qt::Key key);
    void keyUp(Qt::Key key);

    void mouseButtonDown(Qt::MouseButton button);
    void mouseButtonUp(Qt::MouseButton button);

    void mouseMove(QPoint position);

private:
    ViewportWidget* m_viewportWidget;
};
