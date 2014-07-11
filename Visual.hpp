#ifndef VISUAL_HPP
#define VISUAL_HPP

#include "Iw2DSceneGraph.h"
using namespace Iw2DSceneGraph;

#include "Core.hpp"
#include "TouchManager.hpp"

class IVisual : public IRenderable, public IUpdateable,
	public ITouchListener {
public:
	virtual ~IVisual() {
	}

	virtual float GetX() const = 0;
	virtual IVisual& SetX(float x) = 0;

	virtual float GetY() const = 0;
	virtual IVisual& SetY(float y) = 0;

	virtual CIwFVec2 GetPosition() const = 0;
	virtual IVisual& SetPosition(const CIwFVec2& position) = 0;

	virtual IVisual& SetPosition(float x, float y) = 0;

	virtual float GetWidth() const = 0;
	virtual IVisual& SetWidth(float width) = 0;

	virtual float GetHeight() const = 0;
	virtual IVisual& SetHeight(float height) = 0;

	virtual CIwFVec2 GetSize() const = 0;
	virtual IVisual& SetSize(const CIwFVec2& size) = 0;

	virtual IVisual& SetSize(float width, float height) = 0;

	virtual float GetOriginX() const = 0;
	virtual IVisual& SetOriginX(float originX) = 0;

	virtual float GetOriginY() const = 0;
	virtual IVisual& SetOriginY(float originY) = 0;

	virtual CIwFVec2 GetOrigin() const = 0;
	virtual IVisual& SetOrigin(const CIwFVec2& origin) = 0;

	virtual IVisual& SetOrigin(float origin) = 0;
	virtual IVisual& SetOrigin(float originX, float originY) = 0;

	virtual float GetScaleX() const = 0;
	virtual IVisual& SetScaleX(float scaleX) = 0;

	virtual float GetScaleY() const = 0;
	virtual IVisual& SetScaleY(float scaleY) = 0;

	virtual CIwFVec2 GetScale() const = 0;
	virtual IVisual& SetScale(const CIwFVec2& scale) = 0;

	virtual IVisual& SetScale(float scale) = 0;
	virtual IVisual& SetScale(float scaleX, float scaleY) = 0;

	virtual float GetAngle() const = 0;
	virtual IVisual& SetAngle(float angle) = 0;

	virtual CColor GetColor() const = 0;
	virtual IVisual& SetColor(const CColor& color) = 0;

	virtual IVisual& SetColor(uint8 red, uint8 green, uint8 blue) = 0;

	virtual uint8 GetRed() const = 0;
	virtual IVisual& SetRed(uint8 red) = 0;

	virtual uint8 GetGreen() const = 0;
	virtual IVisual& SetGreen(uint8 green) = 0;

	virtual uint8 GetBlue() const = 0;
	virtual IVisual& SetBlue(uint8 blue) = 0;

	virtual float GetAlpha() const = 0;
	virtual IVisual& SetAlpha(float alpha) = 0;

	virtual bool IsVisible() const = 0;
	virtual IVisual& SetVisible(bool visible) = 0;

	virtual bool IsTouchable() const = 0;
	virtual IVisual& SetTouchable(bool touchable) = 0;

	virtual bool HitTest(const CIwVec2& point) = 0;
	virtual bool HitTest(int pointX, int pointY) = 0;
};

class Visual : public IVisual {
protected:
	Visual(CDrawable& visual);

public:
	virtual ~Visual();

	virtual void Render();
	virtual void Update(float delta);

	virtual void OnTouchBegin(const Touch& touch);
	virtual void OnTouchMove(const Touch& touch);
	virtual void OnTouchEnd(const Touch& touch);

	virtual float GetX() const;
	virtual Visual& SetX(float x);

	virtual float GetY() const;
	virtual Visual& SetY(float y);

	virtual CIwFVec2 GetPosition() const;
	virtual Visual& SetPosition(const CIwFVec2& position);

	virtual Visual& SetPosition(float x, float y);

	virtual float GetWidth() const;
	virtual Visual& SetWidth(float width);

	virtual float GetHeight() const;
	virtual Visual& SetHeight(float height);

	virtual CIwFVec2 GetSize() const;
	virtual Visual& SetSize(const CIwFVec2& size);

	virtual Visual& SetSize(float width, float height);

	virtual float GetOriginX() const;
	virtual Visual& SetOriginX(float originX);

	virtual float GetOriginY() const;
	virtual Visual& SetOriginY(float originY);

	virtual CIwFVec2 GetOrigin() const;
	virtual Visual& SetOrigin(const CIwFVec2& origin);

	virtual Visual& SetOrigin(float origin);
	virtual Visual& SetOrigin(float originX, float originY);

	virtual float GetScaleX() const;
	virtual Visual& SetScaleX(float scaleX);

	virtual float GetScaleY() const;
	virtual Visual& SetScaleY(float scaleY);

	virtual CIwFVec2 GetScale() const;
	virtual Visual& SetScale(const CIwFVec2& scale);

	virtual Visual& SetScale(float scale);
	virtual Visual& SetScale(float scaleX, float scaleY);

	virtual float GetAngle() const;
	virtual Visual& SetAngle(float angle);

	virtual CColor GetColor() const;
	virtual Visual& SetColor(const CColor& color);

	virtual Visual& SetColor(uint8 red, uint8 green, uint8 blue);

	virtual uint8 GetRed() const;
	virtual Visual& SetRed(uint8 red);

	virtual uint8 GetGreen() const;
	virtual Visual& SetGreen(uint8 green);

	virtual uint8 GetBlue() const;
	virtual Visual& SetBlue(uint8 blue);

	virtual float GetAlpha() const;
	virtual Visual& SetAlpha(float alpha);

	virtual bool IsVisible() const;
	virtual Visual& SetVisible(bool visible);

	virtual bool IsTouchable() const;
	virtual Visual& SetTouchable(bool touchable);

	virtual bool HitTest(const CIwVec2& point);
	virtual bool HitTest(int pointX, int pointY);

private:
	bool m_touchable;
	CDrawable& m_visual;
};

#endif
