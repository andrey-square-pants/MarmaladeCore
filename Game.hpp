#ifndef GAME_HPP
#define GAME_HPP

#include "Core.hpp"
#include "GameRunner.hpp"
#include "AudioHelper.hpp"
#include "TouchHelper.hpp"
#include "SceneHelper.hpp"
#include "ScreenHelper.hpp"

class Game : public IRenderable, public IUpdateable,
	public ITouchProcessor, public IAudioPlayer,
	public ISceneManager, public IScreenData,
	protected ICreateable {
protected:
	Game();
	virtual ~Game() = 0;

	virtual void Create();
	virtual void Destroy();

public:
	virtual void Render();
	virtual void Update(float delta);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual void PlayEffect(const std::string& name);

	virtual void PlayMusic(const std::string& name, bool repeat);
	virtual void StopMusic();

	virtual IScene* GetCurrentScene();
	virtual void SetCurrentScene(IScene* scene, bool takeOwnership);

	virtual float GetScreenWidth() const;
	virtual float GetScreenHeight() const;

	virtual CIwFVec2 GetScreenSize() const;

	virtual CIwFVec2 GetScreenCenter() const;

private:
	void Run();

private:
	AudioHelper m_audioHelper;
	TouchHelper m_touchHelper;
	SceneHelper m_sceneHelper;
	ScreenHelper m_screenHelper;

	DISABLE_COPY(Game);

	friend class GameRunner;
};

#define DECLARE_GAME(ClassName)            \
public:                                    \
    static ClassName& I() {                \
        return GameHolder<ClassName>::I(); \
    }                                      \
                                           \
protected:                                 \
    ClassName();                           \
    virtual ~ClassName();                  \
                                           \
    DISABLE_COPY(ClassName);               \
                                           \
    friend class GameHolder<ClassName>

#define IMPLEMENT_GAME(ClassName) \
    ClassName::ClassName() {      \
    }                             \
                                  \
    ClassName::~ClassName() {     \
    }

#endif
