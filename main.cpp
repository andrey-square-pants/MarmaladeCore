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
		struct Id {
			enum E {
				BackgroundLabel = 1,
				StaticImage,
				TouchableImage
			};
		};

	public:
		FirstScene() {
			Label* label = new Label(Id::BackgroundLabel, "fonts/arial8.gxfont");
			label->SetText("Pomidor test");
			label->SetOrigin(both(0.5f));
			label->SetScale(both(1.5f));
			label->SetPosition(FirstGame::I().GetScreenCenter());
			label->SetColor(rgb(0xff, 0xff, 0xff));
			label->SetDebug(true);
			AddVisual(label, true);

			FrameImage* frameImage = new FrameImage(Id::StaticImage, "textures/gem2.png", 2);
			frameImage->SetOrigin(both(0.5f));
			frameImage->SetScale(both(1.8f));
			frameImage->SetPosition(0.5f*FirstGame::I().GetScreenCenter());
			frameImage->SetAngle(30);
			frameImage->SetDebug(true);
			AddVisual(frameImage, true);

			Image* image = new Image(Id::TouchableImage, "textures/gem1.png");
			image->SetOrigin(both(0.5f));
			image->SetScale(both(1.3f));
			image->SetDebug(true);
			AddVisual(image, true);

			FirstGame::I().PlayMusic("audio/frontend.mp3", true);
		}

		virtual ~FirstScene() {
		}

		virtual bool ProcessTouchBegin(const Touch& touch) {
			VisualById<FrameImage>(Id::StaticImage)->SetCurrentFrame(1);
			VisualById<Image>(Id::TouchableImage)->SetPosition(p2v(touch.point));
			return true;
		}

		virtual bool ProcessTouchMove(const Touch& touch) {
			VisualById<Image>(Id::TouchableImage)->SetPosition(p2v(touch.point));
			return true;
		}

		virtual bool ProcessTouchEnd(const Touch& touch) {
			FirstGame::I().PlayEffect("audio/gem_destroyed.wav");

			VisualById<FrameImage>(Id::StaticImage)->SetCurrentFrame(0);
			VisualById<Image>(Id::TouchableImage)->SetPosition(p2v(touch.point));
			return true;
		}
	};

protected:
	virtual void Create() {
		Game::Create();
		SetCurrentScene(new FirstScene(), true);
	}

	DECLARE_GAME(FirstGame);
};

IMPLEMENT_GAME(FirstGame);

int main() {
	return (GameRunner::Run<FirstGame>(), 0);
}
