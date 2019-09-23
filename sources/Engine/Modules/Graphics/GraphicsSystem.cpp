#include "GraphicsSystem.h"

#include "Modules/ECS/GameWorld.h"

GraphicsSystem::GraphicsSystem(QOpenGLContext* glContext)
    : GameSystem(),
      m_glContext(glContext),
      m_glFunctions(glContext->functions())
{

}

void GraphicsSystem::render(GameWorld* gameWorld)
{
    ARG_UNUSED(gameWorld);

    m_glFunctions->glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicsSystem::update(GameWorld* gameWorld, float delta)
{
    ARG_UNUSED(gameWorld);
    ARG_UNUSED(delta);
}

void GraphicsSystem::configure(GameWorld* gameWorld)
{
    ARG_UNUSED(gameWorld);

    m_glFunctions->glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
}

void GraphicsSystem::unconfigure(GameWorld* gameWorld)
{
    ARG_UNUSED(gameWorld);
}
