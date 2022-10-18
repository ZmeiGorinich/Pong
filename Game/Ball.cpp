#include "Ball.hpp"

Vector2F Ball::GetBallLocation()
{
    return position;
}

Vector2F Ball::GetBallVelocity()
{
    return velocity;
}

void Ball::Update()
{
    position.SetXPlus(velocity.GetX() * SDL_Timer::GetDT() * 1000);
    position.SetYPlus(velocity.GetY() * SDL_Timer::GetDT() * 1000);
}

void Ball::Draw()
{
    img.Draw(position);
}

void Ball::DeInitialize() {}

void Ball::Initialize()
{
    img.Load("Media/64-Breakout-Tiles.png");

    position = {WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f};
}

void Ball::CollideWithPaddle(Contact const& contact)
{
    position.SetXPlus(contact.penetration);
    velocity.SetX(-velocity.GetX());

    if (contact.type == CollisionType::Top)
    {
        velocity.SetY(-.75f * BALL_SPEED);
    }
    else if (contact.type == CollisionType::Bottom)
    {
        velocity.SetY(0.75f * BALL_SPEED);
    }
}
void Ball::CollideWithWall(Contact const& contact)
{
    if ((contact.type == CollisionType::Top) || (contact.type == CollisionType::Bottom))
    {
        position.SetYPlus(contact.penetration);
        velocity.SetY(-velocity.GetY());
    }
    else if (contact.type == CollisionType::Left)
    {
        position.SetX(WINDOW_WIDTH / 2.0f);
        position.SetY(WINDOW_HEIGHT / 2.0f);
        velocity.SetX(BALL_SPEED);
        velocity.SetY(0.75f * BALL_SPEED);
    }
    else if (contact.type == CollisionType::Right)
    {
        position.SetX(WINDOW_WIDTH / 2.0f);
        position.SetY(WINDOW_HEIGHT / 2.0f);
        velocity.SetX(-BALL_SPEED);
        velocity.SetY(0.75f * BALL_SPEED);
    }
}
Contact Ball::CheckWallCollision()
{
    float ballLeft = this->position.GetX();
    float ballRight = this->position.GetX() + BALL_WIDTH;
    float ballTop = this->position.GetY();
    float ballBottom = this->position.GetY() + BALL_HEIGHT;

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
