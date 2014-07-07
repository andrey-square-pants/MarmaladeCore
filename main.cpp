#include "Iw2D.h"

#include "Game.hpp"
#include "GameRunner.hpp"

class FirstGame : public Game {
protected:
	FirstGame()
		: m_position(CIwFVec2::g_Zero)
		, m_image(Iw2DCreateImage("textures/gem1.png")) {
		try {
			PlayMusic("audio/frontend.mp3", true);
		} catch (...) {
			delete m_image;
			throw;
		}
	}

	virtual ~FirstGame() {
		delete m_image;
	}

public:
	virtual void Render() {
		Game::Render();

		Iw2DDrawImage(m_image, m_position);
	}

	virtual void Update(float delta) {
		Game::Update(delta);
	}

	virtual void OnTouchBegin(const Touch& touch) {
		m_position.x = static_cast<float>(touch.x);
		m_position.y = static_cast<float>(touch.y);
	}

	virtual void OnTouchMove(const Touch& touch) {
		m_position.x = static_cast<float>(touch.x);
		m_position.y = static_cast<float>(touch.y);
	}

	virtual void OnTouchEnd(const Touch& touch) {
		m_position.x = static_cast<float>(touch.x);
		m_position.y = static_cast<float>(touch.y);

		GameHolder<FirstGame>::GetInstance().PlayEffect("audio/gem_destroyed.wav");
	}

private:
	CIwFVec2 m_position;
	CIw2DImage* m_image;

	friend class GameHolder<FirstGame>;
};

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
