#include "GameApplication.h"
#include <Engine/Modules/ECS/ECS.h>

#include <QDebug>
#include <QOpenGLContext>

GameApplication::GameApplication(int argc, char* argv[])
    : BaseGameApplication(argc, argv)
{

}

GameApplication::~GameApplication()
{

}

void GameApplication::initialize()
{

}

void GameApplication::shutdown()
{

}

void GameApplication::update(float delta)
{
    ARG_UNUSED(delta);
}

void GameApplication::render()
{
}
