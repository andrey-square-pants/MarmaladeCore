#ifndef GAME_HPP
#define GAME_HPP

#include "Core.hpp"
#include "GameRunner.hpp"
#include "AudioHelper.hpp"
#include "TouchHelper.hpp"
#include "SceneHelper.hpp"

class Game : public IRenderable, public IUpdateable,
	public ITouchProcessor, public IAudioPlayer, public ISceneManager {
protected:
	Game();
	virtual ~Game();

	virtual void Create() = 0;
	virtual void Destroy() = 0;

public:
	virtual void Render();
	virtual void Update(float delta);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual void PlayEffect(const std::string& file);

	virtual void PlayMusic(const std::string& file, bool repeat);
	virtual void StopMusic();

	virtual void SwitchToScene(IScene* scene, bool takeOwnership);

	float GetScreenWidth() const;
	float GetScreenHeight() const;

	CIwFVec2 GetScreenSize() const;

	CIwFVec2 GetScreenCenter() const;

private:
	void Run();

private:
	AudioHelper m_audioHelper;
	TouchHelper m_touchHelper;
	SceneHelper m_sceneHelper;

	DISABLE_COPY(Game);

	friend class GameRunner;
};

#define DECLARE_GAME(ClassName) \
protected:                      \
    ClassName();                \
    virtual ~ClassName();       \
                                \
    DISABLE_COPY(ClassName);    \
                                \
    friend class GameHolder<ClassName>

#define IMPLEMENT_GAME(ClassName) \
    ClassName::ClassName() {      \
    }                             \
                                  \
    ClassName::~ClassName() {     \
    }

#endif
