#include "../SDL_Engine/SDL_GameStateManager.hpp"
#include "../SDL_Engine/SDL_TTFFont.hpp"
#include "../DEFINITIONS.hpp"

class PlayerScore : public IGameState
{
	friend Singleton<PlayerScore>;

	Vector2F position;

	SDL_TTFFont font;

	int score = 0;
public:

	void Update() override;

	void Draw() override;

	void DeInitialize() override;

	void Initialize() override;

	void SetScore();

	void SetPosition(Vector2F pos);
};
typedef Singleton<PlayerScore> ThePlayerScore;