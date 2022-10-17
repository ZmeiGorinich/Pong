#pragma once
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT  600
#define PADDLE_SPEED  1.0f
#define PADDLE_WIDTH  45
#define PADDLE_HEIGHT  190
#define BALL_SPEED  0.5f
#define BALL_WIDTH  16
#define BALL_HEIGHT  16

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
