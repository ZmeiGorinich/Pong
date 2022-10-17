#include "PlayerScore.hpp"

void PlayerScore::Update()
{
}

void PlayerScore::Draw()
{
	font.DrawString(std::to_string(score), position);
}

void PlayerScore::DeInitialize()
{
}

void PlayerScore::Initialize()
{
	font.Load("Media/DejaVuSansMono.ttf");
	font.SetSize(40);

}

void PlayerScore::SetScore()
{
	score++;
}

void PlayerScore::SetPosition(Vector2F pos)
{
	position = pos;
}
