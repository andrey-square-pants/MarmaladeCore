#include "SceneHelper.hpp"

#include "Error.hpp"

SceneHelper::SceneHelper()
	: m_scene(NULL)
	, m_takeOwnership(false) {
}

SceneHelper::~SceneHelper() {
	Clear();
}

void SceneHelper::Clear() {
	if (m_takeOwnership && (m_scene != NULL)) {
		delete m_scene;
	}
}

void SceneHelper::Render() {
	if (m_scene != NULL) {
		m_scene->Render();
	}
}

void SceneHelper::Update(float delta) {
	if (m_scene != NULL) {
		m_scene->Update(delta);
	}
}

bool SceneHelper::ProcessTouchBegin(const Touch& touch) {
	return (m_scene != NULL ? m_scene->ProcessTouchBegin(touch) : false);
}

bool SceneHelper::ProcessTouchMove(const Touch& touch) {
	return (m_scene != NULL ? m_scene->ProcessTouchMove(touch) : false);
}

bool SceneHelper::ProcessTouchEnd(const Touch& touch) {
	return (m_scene != NULL ? m_scene->ProcessTouchEnd(touch) : false);
}

IScene* SceneHelper::GetCurrentScene() {
	if (m_scene == NULL) {
		throw Error("Null scene pointer");
	}
	return m_scene;
}

void SceneHelper::SetCurrentScene(IScene* scene, bool takeOwnership) {
	if (scene == NULL) {
		throw Error("Null scene pointer");
	}

	Clear();

	m_scene = scene;
	m_takeOwnership = takeOwnership;
}
