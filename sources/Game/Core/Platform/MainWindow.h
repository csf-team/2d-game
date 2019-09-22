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

private:
    void closeEvent(QCloseEvent *event) override;

signals:
    void close();

private:
    ViewportWidget* m_viewportWidget;
};
