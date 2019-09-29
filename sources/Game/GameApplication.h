#pragma once

#include <memory>

#include "Core/Platform/BaseGameApplication.h"

class GameApplication : public BaseGameApplication
{
public:
    GameApplication(int argc, char* argv[]);
    virtual ~GameApplication() override;

    void initialize() override;
    void shutdown() override;

    void update(float delta) override;
    void render() override;

private:
};
