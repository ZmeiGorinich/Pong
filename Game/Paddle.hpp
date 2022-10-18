#include "../SDL_Engine/SDL_GameStateManager.hpp"
#include "../SDL_Engine/SDL_Image.hpp"
#include "../SDL_Engine/SDL_Timer.hpp"
#include "../Input/Keyboard.hpp"
#include "../DEFINITIONS.hpp"

class Paddle : public IGameState
{
    friend Singleton<Paddle>;

    SDL_Image img;

    Vector2F location;

public:
    void SetLocation(Vector2F loc);

    virtual void Update() override;

    virtual void Draw() override;

    virtual void DeInitialize() override;

    virtual void Initialize() override;

    void UpdateAI(Vector2F ball);

    Contact CheckPaddleCollision(Vector2F const& ball, Vector2F const& velocity);
};
typedef Singleton<Paddle> ThePaddle;