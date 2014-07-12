#include "Iw2D.h"

#include "Game.hpp"
#include "Image.hpp"
#include "Label.hpp"

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
		m_image.SetPosition(p2v(touch.point));
	}

	virtual void OnTouchMove(const Touch& touch) {
		m_image.SetPosition(p2v(touch.point));
	}

	virtual void OnTouchEnd(const Touch& touch) {
		PlayEffect("audio/gem_destroyed.wav");
		m_image.SetPosition(p2v(touch.point));
	}

private:
	Image m_image;
	//Label m_label;

	DECLARE_GAME(FirstGame);
};

CONTRUCT_GAME(FirstGame)
	: m_image("textures/gem1.png") {
	PlayMusic("audio/frontend.mp3", true);

	m_image.SetOrigin(both(0.5f));
	m_image.SetScale(both(1.3f));
	m_image.SetAlpha(0.8f);
	m_image.SetPosition(GetScreenCenter());

	//m_label.SetText("Pomidor test").CenterAlign().SetOrigin(0.5f).
	//	SetScale(2.5f).SetPosition(GetScreenCenter()).SetColor(CColor(255, 255, 255, 255));
}

DESTRUCT_GAME(FirstGame) {
}

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
