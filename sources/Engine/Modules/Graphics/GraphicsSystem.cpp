#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(QOpenGLContext* glContext)
    : GameSystem(),
      m_glContext(glContext),
      m_glFunctions(glContext->functions())
{

}

void GraphicsSystem::render(GameWorld* gameWorld)
{
    m_glFunctions->glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicsSystem::update(GameWorld* gameWorld, float delta)
{

}

void GraphicsSystem::configure(GameWorld* gameWorld)
{
    m_glFunctions->glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
}

void GraphicsSystem::unconfigure(GameWorld* gameWorld)
{

}
