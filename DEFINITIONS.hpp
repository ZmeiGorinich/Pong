#pragma once
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PADDLE_SPEED = 1.0f;
const int PADDLE_WIDTH = 45;
const int PADDLE_HEIGHT = 190;
const float BALL_SPEED = 0.5f;
const int BALL_WIDTH = 16;
const int BALL_HEIGHT = 16;

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
