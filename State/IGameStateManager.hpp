#pragma once

#include "GameStateManager.hpp"

class IGameStateManager :public GameStateManager
{
public:

    virtual void Update() = 0;

    virtual void Draw() = 0;
};

