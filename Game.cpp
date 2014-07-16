#include "Game.hpp"

#include "Iw2D.h"
#include "IwGx.h"

Game::Game() {
	m_touchHelper.SetTouchProcessor(this);
}

Game::~Game() {
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

void Game::PlayEffect(const std::string& file) {
	m_audioHelper.PlayEffect(file);
}

void Game::PlayMusic(const std::string& file, bool repeat) {
	m_audioHelper.PlayMusic(file, repeat);
}

void Game::StopMusic() {
	m_audioHelper.StopMusic();
}

void Game::SwitchToScene(IScene* scene, bool takeOwnership) {
	m_sceneHelper.SwitchToScene(scene, takeOwnership);
}

float Game::GetScreenWidth() const {
	return static_cast<float>(IwGxGetScreenWidth());
}

float Game::GetScreenHeight() const {
	return static_cast<float>(IwGxGetScreenHeight());
}

CIwFVec2 Game::GetScreenSize() const {
	return CIwFVec2(GetScreenWidth(), GetScreenHeight());
}

CIwFVec2 Game::GetScreenCenter() const {
	return 0.5f*GetScreenSize();
}
