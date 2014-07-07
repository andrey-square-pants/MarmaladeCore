#ifndef GAME_HPP
#define GAME_HPP

#include "Core.hpp"
#include "TouchManager.hpp"
#include "AudioManager.hpp"

class GameRunner;

class Game : public IRenderable, public IUpdateable,
	public ITouchListener, public IAudio {
protected:
	Game();
	virtual ~Game() = 0;

public:
	virtual void Render();
	virtual void Update(float delta);

	virtual void OnTouchBegin(const Touch& touch);
	virtual void OnTouchMove(const Touch& touch);
	virtual void OnTouchEnd(const Touch& touch);

	virtual void PlayEffect(const std::string& file);

	virtual void PlayMusic(const std::string& file, bool repeat);
	virtual void StopMusic();

private:
	void Run();

private:
	TouchManager m_touchManager;
	AudioManager m_audioManager;

	friend class GameRunner;
};

#endif