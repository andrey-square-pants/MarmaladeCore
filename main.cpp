#include "Iw2D.h"

#include "Game.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "FrameImage.hpp"

class FirstGame : public Game {
public:
	virtual void Render() {
		Game::Render();

		m_label.Render();
		m_frameImage.Render();
		m_image.Render();
	}

	virtual void Update(float delta) {
		Game::Update(delta);

		m_label.Update(delta);
		m_frameImage.Update(delta);
		m_image.Update(delta);
	}

	virtual void OnTouchBegin(const Touch& touch) {
		m_frameImage.SetFrame(1);
		m_image.SetPosition(p2v(touch.point));
	}

	virtual void OnTouchMove(const Touch& touch) {
		m_image.SetPosition(p2v(touch.point));
	}

	virtual void OnTouchEnd(const Touch& touch) {
		PlayEffect("audio/gem_destroyed.wav");
		m_image.SetPosition(p2v(touch.point));
		m_frameImage.SetFrame(0);
	}

private:
	Label m_label;
	Image m_image;
	FrameImage m_frameImage;

	DECLARE_GAME(FirstGame);
};

CONTRUCT_GAME(FirstGame)
	: m_label("fonts/arial8.gxfont")
	, m_image("textures/gem1.png")
	, m_frameImage("textures/gem2.png", 2) {
	PlayMusic("audio/frontend.mp3", true);

	m_image.SetOrigin(both(0.5f));
	m_image.SetScale(both(1.3f));
	m_image.SetDebug(true);

	m_frameImage.SetOrigin(both(0.5f));
	m_frameImage.SetScale(both(1.8f));
	m_frameImage.SetPosition(0.5f*GetScreenCenter());
	m_frameImage.SetAngle(30);
	m_frameImage.SetDebug(true);

	m_label.SetText("Pomidor test");
	m_label.SetOrigin(both(0.5f));
	m_label.SetScale(both(1.5f));
	m_label.SetPosition(GetScreenCenter());
	m_label.SetColor(rgb(0xff, 0xff, 0xff));
	m_label.SetDebug(true);
}

DESTRUCT_GAME(FirstGame) {
}

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
