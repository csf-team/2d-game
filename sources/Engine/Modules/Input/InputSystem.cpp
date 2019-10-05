#include "InputSystem.h"

#include <QDebug>

InputSystem::InputSystem()
{

}

InputSystem::~InputSystem()
{

}

void InputSystem::configure(GameWorld* gameWorld)
{
    ARG_UNUSED(gameWorld);
}

void InputSystem::unconfigure(GameWorld* gameWorld)
{
    ARG_UNUSED(gameWorld);
}

void InputSystem::notifyKeyDown(Qt::Key key)
{ 
    m_keyboardKeysState[key] = KeyboardKeyState::Pressed;
}

void InputSystem::notifyKeyUp(Qt::Key key)
{
    m_keyboardKeysState[key] = KeyboardKeyState::Released;
}

void InputSystem::notifyMouseButtonDown(Qt::MouseButton button)
{
    m_mouseButtonsState[button] = MouseButtonState::Pressed;
}

void InputSystem::notifyMouseButtonUp(Qt::MouseButton button)
{   
    m_mouseButtonsState[button] = MouseButtonState::Released;
}

void InputSystem::notifyMouseMove(QPoint position)
{
    m_cursorPosition.setX(position.x());
    m_cursorPosition.setY(position.y());
}

bool InputSystem::isKeyDown(Qt::Key key) const
{
    if(m_keyboardKeysState.contains(key) == true && m_keyboardKeysState[key] == KeyboardKeyState::Pressed) {
        return true;
    } else {
        return false;
    }
}

bool InputSystem::isKeyUp(Qt::Key key) const
{
    if(m_keyboardKeysState.contains(key) == true && m_keyboardKeysState[key] == KeyboardKeyState::Released) {
        return true;
    } else {
        return false;
    }
}

bool InputSystem::isMouseButtonDown(Qt::MouseButton button) const
{
    if(m_mouseButtonsState[button] == MouseButtonState::Pressed && m_mouseButtonsState.contains(button) == true) {
        return true;
    } else {
        return false;
    }
}

bool InputSystem::isMouseButtonUp(Qt::MouseButton button) const
{
    if(m_mouseButtonsState[button] == MouseButtonState::Released && m_mouseButtonsState.contains(button) == true) {
        return true;
    } else {
        return false;
    }
}

vector2 InputSystem::getCursorPosition() const
{
    return vector2(m_cursorPosition);
}

