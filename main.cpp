#include "Iw2D.h"

#include "Game.hpp"
#include "Scene.hpp"
#include "Label.hpp"
#include "Image.hpp"
#include "FrameImage.hpp"

class FirstGame : public Game {
private:
	class FirstScene : public Scene {
	public:
		FirstScene() {
			FirstGame& game = GameHolder<FirstGame>::GetInstance();

			Label* label = new Label(1, "fonts/arial8.gxfont");
			label->SetText("Pomidor test");
			label->SetOrigin(both(0.5f));
			label->SetScale(both(1.5f));
			label->SetPosition(game.GetScreenCenter());
			label->SetColor(rgb(0xff, 0xff, 0xff));
			label->SetDebug(true);
			AddVisual(label, true);

			FrameImage* frameImage = new FrameImage(2, "textures/gem2.png", 2);
			frameImage->SetOrigin(both(0.5f));
			frameImage->SetScale(both(1.8f));
			frameImage->SetPosition(0.5f*game.GetScreenCenter());
			frameImage->SetAngle(30);
			frameImage->SetDebug(true);
			AddVisual(frameImage, true);

			Image* image = new Image(3, "textures/gem1.png");
			image->SetOrigin(both(0.5f));
			image->SetScale(both(1.3f));
			image->SetDebug(true);
			AddVisual(image, true);

			game.PlayMusic("audio/frontend.mp3", true);
		}

		virtual ~FirstScene() {
		}

		virtual bool ProcessTouchBegin(const Touch& touch) {
			((FrameImage*)GetVisualById(2))->SetCurrentFrame(1);
			GetVisualById(3)->SetPosition(p2v(touch.point));

			return true;
		}

		virtual bool ProcessTouchMove(const Touch& touch) {
			GetVisualById(3)->SetPosition(p2v(touch.point));

			return true;
		}

		virtual bool ProcessTouchEnd(const Touch& touch) {
			FirstGame& game = GameHolder<FirstGame>::GetInstance();

			game.PlayEffect("audio/gem_destroyed.wav");

			GetVisualById(3)->SetPosition(p2v(touch.point));
			((FrameImage*)GetVisualById(2))->SetCurrentFrame(0);

			return true;
		}
	};

protected:
	virtual void Create() {
		SwitchToScene(new FirstScene(), true);
	}

	virtual void Destroy() {
	}

	DECLARE_GAME(FirstGame);
};

IMPLEMENT_GAME(FirstGame);

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
