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

public:
	virtual float GetX() const = 0;
	virtual void SetX(float x) = 0;

	virtual float GetY() const = 0;
	virtual void SetY(float y) = 0;

	virtual float GetWidth() const = 0;
	virtual void SetWidth(float width) = 0;

	virtual float GetHeight() const = 0;
	virtual void SetHeight(float height) = 0;

	virtual float GetOriginX() const = 0;
	virtual void SetOriginX(float originX) = 0;

	virtual float GetOriginY() const = 0;
	virtual void SetOriginY(float originY) = 0;

	virtual float GetScaleX() const = 0;
	virtual void SetScaleX(float scaleX) = 0;

	virtual float GetScaleY() const = 0;
	virtual void SetScaleY(float scaleY) = 0;

	virtual float GetAngle() const = 0;
	virtual void SetAngle(float angle) = 0;

	virtual CColor GetColor() const = 0;
	virtual void SetColor(const CColor& color) = 0;

	virtual float GetAlpha() const = 0;
	virtual void SetAlpha(float alpha) = 0;

	virtual bool IsVisible() const = 0;
	virtual void SetVisible(bool visible) = 0;

	virtual bool IsTouchable() const = 0;
	virtual void SetTouchable(bool touchable) = 0;

	virtual bool HitTest(int x, int y) = 0;
};

class Visual : public IVisual {
protected:
	Visual(CDrawable& visual);

public:
	virtual ~Visual();

public:
	virtual void Render();
	virtual void Update(float delta);

	virtual void OnTouchBegin(const Touch& touch);
	virtual void OnTouchMove(const Touch& touch);
	virtual void OnTouchEnd(const Touch& touch);

	virtual float GetX() const;
	virtual void SetX(float x);

	virtual float GetY() const;
	virtual void SetY(float y);

	virtual float GetWidth() const;
	virtual void SetWidth(float width);

	virtual float GetHeight() const;
	virtual void SetHeight(float height);

	virtual float GetOriginX() const;
	virtual void SetOriginX(float originX);

	virtual float GetOriginY() const;
	virtual void SetOriginY(float originY);

	virtual float GetScaleX() const;
	virtual void SetScaleX(float scaleX);

	virtual float GetScaleY() const;
	virtual void SetScaleY(float scaleY);

	virtual float GetAngle() const;
	virtual void SetAngle(float angle);

	virtual CColor GetColor() const;
	virtual void SetColor(const CColor& color);

	virtual float GetAlpha() const;
	virtual void SetAlpha(float alpha);

	virtual bool IsVisible() const;
	virtual void SetVisible(bool visible);

	virtual bool IsTouchable() const;
	virtual void SetTouchable(bool touchable);

	virtual bool HitTest(int x, int y);

private:
	bool m_touchable;
	CDrawable& m_visual;
};

#endif
