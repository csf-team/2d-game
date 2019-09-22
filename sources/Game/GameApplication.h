#pragma once

#include <memory>

#include <Engine/Modules/ECS/ECS.h>
#include <Engine/Modules/Graphics/GraphicsSystem.h>

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
    GameWorld* m_gameWorld;
    GraphicsSystem* m_graphicsSystem;
};
