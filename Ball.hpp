#include "SDL_GameStateManager.hpp"
#include "SDL_Image.hpp"
#include "SDL_Timer.hpp"
#include "DEFINITIONS.hpp"

class Ball : public IGameState
{
	friend Singleton<Ball>;

	SDL_Image img;	
	Vector2F position;
	Vector2F velocity{ BALL_SPEED, 0.0f };


public:
	
	Vector2F GetBallLocation();
	
	Vector2F GetBallVelocity();	

	virtual void Update() override;

	virtual void Draw() override;

	virtual void DeInitialize() override;

	virtual void Initialize();
	
	void CollideWithPaddle(Contact const& contact);

	void CollideWithWall(Contact const& contact);
	
	Contact CheckWallCollision();

};
typedef Singleton<Ball> TheBall;