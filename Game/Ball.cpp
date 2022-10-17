#include "Ball.hpp"

Vector2F Ball::GetBallLocation()
{
	return position;;
}

Vector2F Ball::GetBallVelocity()
{
	return velocity;
}

void Ball::Update()
{
	position.X += velocity.X * SDL_Timer::GetDT() * 1000;
	position.Y += velocity.Y * SDL_Timer::GetDT() * 1000;
}

void Ball::Draw()
{
	img.Draw(position);
}

void Ball::DeInitialize()
{
}

void Ball::Initialize()
{
	img.Load("Media/64-Breakout-Tiles.png");

	position = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
}

void Ball::CollideWithPaddle(Contact const& contact)
{
	position.X += contact.penetration;
	velocity.X = -velocity.X;

	if (contact.type == CollisionType::Top)
	{
		velocity.Y = -.75f * BALL_SPEED;
	}
	else if (contact.type == CollisionType::Bottom)
	{
		velocity.Y = 0.75f * BALL_SPEED;
	}
}
void Ball::CollideWithWall(Contact const& contact)
{
	if ((contact.type == CollisionType::Top)
		|| (contact.type == CollisionType::Bottom))
	{
		position.Y += contact.penetration;
		velocity.Y = -velocity.Y;
	}
	else if (contact.type == CollisionType::Left)
	{
		position.X = WINDOW_WIDTH / 2.0f;
		position.Y = WINDOW_HEIGHT / 2.0f;
		velocity.X = BALL_SPEED;
		velocity.Y = 0.75f * BALL_SPEED;
	}
	else if (contact.type == CollisionType::Right)
	{
		position.X = WINDOW_WIDTH / 2.0f;
		position.Y = WINDOW_HEIGHT / 2.0f;
		velocity.X = -BALL_SPEED;
		velocity.Y = 0.75f * BALL_SPEED;
	}
}
Contact Ball::CheckWallCollision()
{
	float ballLeft = this->position.X;
	float ballRight = this->position.X + BALL_WIDTH;
	float ballTop = this->position.Y;
	float ballBottom = this->position.Y + BALL_HEIGHT;

	Contact contact{};

	if (ballLeft < 0.0f)
	{
		contact.type = CollisionType::Left;
	}
	else if (ballRight > WINDOW_WIDTH)
	{
		contact.type = CollisionType::Right;
	}
	else if (ballTop < 0.0f)
	{
		contact.type = CollisionType::Top;
		contact.penetration = -ballTop;
	}
	else if (ballBottom > WINDOW_HEIGHT)
	{
		contact.type = CollisionType::Bottom;
		contact.penetration = WINDOW_HEIGHT - ballBottom;
	}

	return contact;
}
