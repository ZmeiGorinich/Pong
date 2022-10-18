#pragma once
#include "../Singleton/Singleton.hpp"

class IGameState
{
public:
    virtual ~IGameState() = 0 {}

    virtual void Initialize() = 0;

    virtual void Update() = 0;

    virtual void Draw() = 0;

    virtual void DeInitialize() = 0;

};

