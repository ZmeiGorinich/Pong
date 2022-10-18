#pragma once
static constexpr int WINDOW_WIDTH = 800;
static constexpr int WINDOW_HEIGHT = 600;
static constexpr float PADDLE_SPEED = 1.0f;
static constexpr int PADDLE_WIDTH = 45;
static constexpr int PADDLE_HEIGHT = 190;
static constexpr float BALL_SPEED = 0.5f;
static constexpr int BALL_WIDTH = 16;
static constexpr int BALL_HEIGHT = 16;

enum Buttons
{
    PaddleOneUp = 0,
    PaddleOneDown,
    PaddleTwoUp,
    PaddleTwoDown,
};

enum class CollisionType
{
    None,
    Top,
    Middle,
    Bottom,
    Left,
    Right
};

struct Contact
{
    CollisionType type;
    float penetration;
};
