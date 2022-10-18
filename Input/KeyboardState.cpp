#include "KeyboardState.hpp"

bool KeyboardState::IsKeyDown(Keys key)
{
    if (m_KeyData[key] == KeyState::Pressed)
        return true;

    return false;
}