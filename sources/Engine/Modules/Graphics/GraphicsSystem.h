#pragma once

#include "Modules/ECS/GameSystem.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>

class GraphicsSystem : public GameSystem
{
public:
    GraphicsSystem(QOpenGLContext* glContext);

    void render(GameWorld *gameWorld) override;
    void update(GameWorld *gameWorld, float delta) override;

    void configure(GameWorld *gameWorld) override;
    void unconfigure(GameWorld *gameWorld) override;

private:
    QOpenGLContext* m_glContext;
    QOpenGLFunctions* m_glFunctions;
};

