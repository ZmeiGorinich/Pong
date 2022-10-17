#include "SDL_GameStateManager.hpp"
#include "SDL_TTFFont.hpp"
#include "DEFINITIONS.hpp"

class PlayerScore : public IGameState
{
	friend Singleton<PlayerScore>;

	Vector2F position;

	SDL_TTFFont font;

	int score = 0;
public:

	virtual void Update() override;

	virtual void Draw() override;

	virtual void DeInitialize() override;

	virtual void Initialize();

	void SetScore();

	void SetPosition(Vector2F pos);
};
typedef Singleton<PlayerScore> ThePlayerScore;