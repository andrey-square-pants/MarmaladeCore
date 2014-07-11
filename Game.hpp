#ifndef GAME_HPP
#define GAME_HPP

#include "Core.hpp"
#include "GameRunner.hpp"
#include "TouchManager.hpp"
#include "AudioManager.hpp"

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

	float GetScreenWidth() const;
	float GetScreenHeight() const;
	CIwFVec2 GetScreenSize() const;
	CIwFVec2 GetScreenCenter() const;

private:
	void Run();

private:
	TouchManager m_touchManager;
	AudioManager m_audioManager;

	DISABLE_COPY(Game);

	friend class GameRunner;
};

#define DECLARE_GAME(ClassName)                      \
protected:                                           \
    ClassName();                                     \
    virtual ~ClassName();                            \
                                                     \
    DISABLE_COPY(ClassName);                         \
                                                     \
    friend class GameHolder<ClassName>

#define CONTRUCT_GAME(ClassName) \
    ClassName::ClassName()

#define DESTRUCT_GAME(ClassName) \
    ClassName::~ClassName()

#endif
