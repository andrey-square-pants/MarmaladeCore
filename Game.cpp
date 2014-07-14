#include "Game.hpp"

#include "Iw2D.h"
#include "IwGx.h"

Game::Game() {
	m_touchManager.AddListener(*this);
}

Game::~Game() {
	m_touchManager.RemoveListener(*this);
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
	m_touchManager.Update(delta);
	m_audioManager.Update(delta);
}

void Game::Render() {
	Iw2DSurfaceClear(0xff000000);
}

void Game::OnTouchBegin(const Touch& touch) {
}

void Game::OnTouchMove(const Touch& touch) {
}

void Game::OnTouchEnd(const Touch& touch) {
}

void Game::PlayEffect(const std::string& file) {
	m_audioManager.PlayEffect(file);
}

void Game::PlayMusic(const std::string& file, bool repeat) {
	m_audioManager.PlayMusic(file, repeat);
}

void Game::StopMusic() {
	m_audioManager.StopMusic();
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
