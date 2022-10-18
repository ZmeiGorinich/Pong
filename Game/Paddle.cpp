#include "Paddle.hpp"


void Paddle::SetLocation(Vector2F loc)
{
    location = loc;
}

void Paddle::Update()
{
    KeyboardState state = Keyboard::GetState();

    if (state.IsKeyDown(Keys::w))
    {
        location.Y -= SDL_Timer::GetDT() * 1000;
    }

    if (state.IsKeyDown(Keys::s))
    {
        location.Y += SDL_Timer::GetDT() * 1000;
    }

    if (location.Y < 0)
    {
        location.Y = 0;
    }
    else if (location.Y > (WINDOW_HEIGHT - PADDLE_HEIGHT))
    {
        location.Y = WINDOW_HEIGHT - PADDLE_HEIGHT;
    }
}

void Paddle::Draw()
{
    img.Draw(location);
}

void Paddle::DeInitialize()
{
}

void Paddle::Initialize()
{
    img.Load("Media/yellow_button03.png");
}

void Paddle::UpdateAI(Vector2F ball)
{
    if (location.Y < 0)
    {
        location.Y = 0;
    }
    else if (location.Y > (WINDOW_HEIGHT - PADDLE_HEIGHT))
    {
        location.Y = WINDOW_HEIGHT - PADDLE_HEIGHT;
    }

    if (ball.X > WINDOW_WIDTH / 2)
    {
        if (ball.Y < location.Y + PADDLE_HEIGHT / 2)
        {
            location.Y += -0.25;
        }
        if (ball.Y + BALL_HEIGHT > location.Y + PADDLE_HEIGHT / 2)
        {
            location.Y += 0.25;
        }

    }
}

Contact Paddle::CheckPaddleCollision(Vector2F const& ball, Vector2F const& velocity)
{
    float ballLeft = ball.X;
    float ballRight = ball.X + BALL_WIDTH;
    float ballTop = ball.Y;
    float ballBottom = ball.Y + BALL_HEIGHT;

    float paddleLeft = this->location.X;
    float paddleRight = this->location.X + PADDLE_WIDTH;
    float paddleTop = this->location.Y;
    float paddleBottom = this->location.Y + PADDLE_HEIGHT;

    Contact contact{};

    if (ballLeft >= paddleRight)
    {
        return contact;
    }

    if (ballRight <= paddleLeft)
    {
        return contact;
    }

    if (ballTop >= paddleBottom)
    {
        return contact;
    }

    if (ballBottom <= paddleTop)
    {
        return contact;
    }

    float paddleRangeUpper = paddleBottom - (2.0f * PADDLE_HEIGHT / 3.0f);
    float paddleRangeMiddle = paddleBottom - (PADDLE_HEIGHT / 3.0f);

    if (velocity.X < 0)
    {
        // Left paddle
        contact.penetration = paddleRight - ballLeft;
    }
    else if (velocity.X > 0)
    {
        // Right paddle
        contact.penetration = paddleLeft - ballRight;
    }

    if ((ballBottom > paddleTop)
        && (ballBottom < paddleRangeUpper))
    {
        contact.type = CollisionType::Top;
    }
    else if ((ballBottom > paddleRangeUpper)
        && (ballBottom < paddleRangeMiddle))
    {
        contact.type = CollisionType::Middle;
    }
    else
    {
        contact.type = CollisionType::Bottom;
    }

    return contact;
    return Contact();
}
