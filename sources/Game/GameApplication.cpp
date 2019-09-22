#include "GameApplication.h"
#include <Engine/Modules/ECS/ECS.h>

#include <QDebug>
#include <QOpenGLContext>

GameApplication::GameApplication(int argc, char* argv[])
    : BaseGameApplication(argc, argv),
      m_gameWorld(nullptr),
      m_graphicsSystem(nullptr)
{

}

GameApplication::~GameApplication()
{

}

void GameApplication::initialize()
{
    m_gameWorld = new GameWorld();

    m_graphicsSystem = new GraphicsSystem(getMainWindow()->getViewportWidget()->context());
    m_gameWorld->addGameSystem(m_graphicsSystem);
}

void GameApplication::shutdown()
{
    delete m_gameWorld;
    m_gameWorld = nullptr;

    delete m_graphicsSystem;
    m_graphicsSystem = nullptr;
}

void GameApplication::update(float delta)
{
    m_gameWorld->update(delta);
}

void GameApplication::render()
{
    m_gameWorld->render();
}
