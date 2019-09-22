#pragma once

#include <QMainWindow>
#include <Engine/Modules/Platform/ViewportWidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ViewportWidget* getViewportWidget() const;

private:
    ViewportWidget* m_viewportWidget;
};
