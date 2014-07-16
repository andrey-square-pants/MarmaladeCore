#ifndef SCENEHELPER_HPP
#define SCENEHELPER_HPP

#include "Core.hpp"

class SceneHelper : public ISceneManager, public IRenderable,
	public IUpdateable, public ITouchProcessor {
public:
	SceneHelper();
	virtual ~SceneHelper();

	virtual void Render();
	virtual void Update(float delta);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual IScene* GetCurrentScene();
	virtual void SetCurrentScene(IScene* scene, bool takeOwnership);

private:
	void Clear();

private:
	IScene* m_scene;
	bool m_takeOwnership;

	DISABLE_COPY(SceneHelper);
};

#endif
