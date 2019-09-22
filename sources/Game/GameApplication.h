#pragma once

#include <QApplication>
#include "Core/Platform/BaseGameApplication.h"

class GameApplication : public BaseGameApplication
{
public:
    GameApplication(int argc, char* argv[]);
    virtual ~GameApplication() override;

    void update(float delta) override;
    void render() override;
};

