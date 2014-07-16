#include "Game.hpp"

#include "Iw2D.h"

Game::Game() {
}

Game::~Game() {
}

void Game::Create() {
	m_touchHelper.SetTouchProcessor(this);
}

void Game::Destroy() {
	m_touchHelper.SetTouchProcessor(NULL);
}

void Game::Run() {
	static const float TicksPerSecond = 1000.0f;

	uint64 currentTicks = 0;
	uint64 previousTicks = 0;
	while (!s3eDeviceCheckQuitRequest()) {
		currentTicks = s3eTimerGetMs();

		Update(previousTicks == 0 ? 0.0f :
			(currentTicks - previousTicks)/TicksPerSecond);

		previousTicks = currentTicks;

		Render();

		Iw2DSurfaceShow();
		s3eDeviceYield(0);
	}
}

void Game::Update(float delta) {
	m_audioHelper.Update(delta);
	m_touchHelper.Update(delta);
	m_sceneHelper.Update(delta);
}

void Game::Render() {
	Iw2DSurfaceClear(0xff000000);
	m_sceneHelper.Render();
}

bool Game::ProcessTouchBegin(const Touch& touch) {
	return m_sceneHelper.ProcessTouchBegin(touch);
}

bool Game::ProcessTouchMove(const Touch& touch) {
	return m_sceneHelper.ProcessTouchMove(touch);
}

bool Game::ProcessTouchEnd(const Touch& touch) {
	return m_sceneHelper.ProcessTouchEnd(touch);
}

void Game::PlayEffect(const std::string& name) {
	m_audioHelper.PlayEffect(name);
}

void Game::PlayMusic(const std::string& name, bool repeat) {
	m_audioHelper.PlayMusic(name, repeat);
}

void Game::StopMusic() {
	m_audioHelper.StopMusic();
}

IScene* Game::GetCurrentScene() {
	return m_sceneHelper.GetCurrentScene();
}

void Game::SetCurrentScene(IScene* scene, bool takeOwnership) {
	m_sceneHelper.SetCurrentScene(scene, takeOwnership);
}

float Game::GetScreenWidth() const {
	return m_screenHelper.GetScreenWidth();
}

float Game::GetScreenHeight() const {
	return m_screenHelper.GetScreenHeight();
}

CIwFVec2 Game::GetScreenSize() const {
	return m_screenHelper.GetScreenSize();
}

CIwFVec2 Game::GetScreenCenter() const {
	return m_screenHelper.GetScreenCenter();
}
