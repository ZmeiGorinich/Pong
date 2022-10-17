#pragma once
#include <SDL.h>

#include "../SDL_Engine/SDL_GameStateManager.hpp"

#include "Paddle.hpp"
#include "Ball.hpp"
#include "PlayerScore.hpp"
#include "DEFINITIONS.hpp"

class GameState : public IGameState
{
	friend Singleton<GameState>;
	GameState() {};

	Ball ball;
	Paddle paddle;
	Paddle paddleAI;
	PlayerScore score1;
	PlayerScore score2;


public:

	virtual void Update() override
	{

		ball.Update();
		paddle.Update();
		paddleAI.UpdateAI(ball.GetBallLocation());
		score1.Update();
		score2.Update();


		// Collisions
		if (Contact contact = paddle.CheckPaddleCollision(ball.GetBallLocation(), ball.GetBallVelocity());
			contact.type != CollisionType::None)
		{
			ball.CollideWithPaddle(contact);

		}
		else if (contact = paddleAI.CheckPaddleCollision(ball.GetBallLocation(), ball.GetBallVelocity());
			contact.type != CollisionType::None)
		{
			ball.CollideWithPaddle(contact);

		}
		else if (contact = ball.CheckWallCollision();
			contact.type != CollisionType::None)
		{
			ball.CollideWithWall(contact);

			if (contact.type == CollisionType::Left)
			{
				score2.SetScore();

			}
			else if (contact.type == CollisionType::Right)
			{
				score1.SetScore();
			}
		}

	}

	virtual void Draw() override
	{
		ball.Draw();
		paddle.Draw();
		paddleAI.Draw();
		score1.Draw();
		score2.Draw();

	}

	virtual void DeInitialize() override
	{
	}

	virtual void Initialize()
	{
		ball.Initialize();

		paddle.Initialize();
		paddle.SetLocation({ 50.0f, WINDOW_HEIGHT / 2.0f });

		paddleAI.Initialize();
		paddleAI.SetLocation({ WINDOW_WIDTH - 50.0f - PADDLE_WIDTH, WINDOW_HEIGHT / 2.0f });

		score1.Initialize();
		score1.SetPosition({ WINDOW_WIDTH / 4, 20 });

		score2.Initialize();
		score2.SetPosition({ 3 * WINDOW_WIDTH / 4, 20 });

	}

};
typedef Singleton<GameState> TheGameState;