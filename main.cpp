#include "Iw2D.h"

#include "Game.hpp"
#include "VisualImage.hpp"

class FirstGame : public Game {
public:
	virtual void Render() {
		Game::Render();
		m_image.Render();
	}

	virtual void Update(float delta) {
		Game::Update(delta);
		m_image.Update(delta);
	}

	virtual void OnTouchBegin(const Touch& touch) {
		m_image.SetX(static_cast<float>(touch.x));
		m_image.SetY(static_cast<float>(touch.y));
	}

	virtual void OnTouchMove(const Touch& touch) {
		m_image.SetX(static_cast<float>(touch.x));
		m_image.SetY(static_cast<float>(touch.y));
	}

	virtual void OnTouchEnd(const Touch& touch) {
		m_image.SetX(static_cast<float>(touch.x));
		m_image.SetY(static_cast<float>(touch.y));

		GameHolder<FirstGame>::GetInstance().PlayEffect("audio/gem_destroyed.wav");
	}

private:
	VisualImage m_image;

	DECLARE_GAME(FirstGame);
};

CONTRUCT_GAME(FirstGame)
	: m_image("textures/gem1.png") {
	m_image.SetOriginX(0.5f);
	m_image.SetOriginY(0.5f);

	m_image.SetScaleX(3.0f);
	m_image.SetScaleY(3.0f);

	PlayMusic("audio/frontend.mp3", true);
}

DESTRUCT_GAME(FirstGame) {
}

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
