#ifndef VISUAL_HPP
#define VISUAL_HPP

#include "Core.hpp"
#include "TouchManager.hpp"

class IVisual : public IRenderable, public IUpdateable,
	public ITouchListener {
public:
	virtual ~IVisual() {
	}

	virtual float GetX() const = 0;
	virtual void SetX(float x) = 0;

	virtual float GetY() const = 0;
	virtual void SetY(float y) = 0;

	virtual CIwFVec2 GetPosition() const = 0;
	virtual void SetPosition(const CIwFVec2& position) = 0;

	virtual float GetWidth() const = 0;
	virtual void SetWidth(float width) = 0;

	virtual float GetHeight() const = 0;
	virtual void SetHeight(float height) = 0;

	virtual CIwFVec2 GetSize() const = 0;
	virtual void SetSize(const CIwFVec2& size) = 0;

	virtual float GetOriginX() const = 0;
	virtual void SetOriginX(float originX) = 0;

	virtual float GetOriginY() const = 0;
	virtual void SetOriginY(float originY) = 0;

	virtual CIwFVec2 GetOrigin() const = 0;
	virtual void SetOrigin(const CIwFVec2& origin) = 0;

	virtual float GetScaleX() const = 0;
	virtual void SetScaleX(float scaleX) = 0;

	virtual float GetScaleY() const = 0;
	virtual void SetScaleY(float scaleY) = 0;

	virtual CIwFVec2 GetScale() const = 0;
	virtual void SetScale(const CIwFVec2& scale) = 0;

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

	virtual CColor GetDebugColor() const = 0;
	virtual void SetDebugColor(const CColor& color) = 0;

	virtual bool IsDebug() const = 0;
	virtual void SetDebug(bool debug) = 0;

	virtual bool HitTest(const CIwVec2& point) = 0;
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
	virtual void SetX(float x);

	virtual float GetY() const;
	virtual void SetY(float y);

	virtual CIwFVec2 GetPosition() const;
	virtual void SetPosition(const CIwFVec2& position);

	virtual float GetWidth() const;
	virtual void SetWidth(float width);

	virtual float GetHeight() const;
	virtual void SetHeight(float height);

	virtual CIwFVec2 GetSize() const;
	virtual void SetSize(const CIwFVec2& size);

	virtual float GetOriginX() const;
	virtual void SetOriginX(float originX);

	virtual float GetOriginY() const;
	virtual void SetOriginY(float originY);

	virtual CIwFVec2 GetOrigin() const;
	virtual void SetOrigin(const CIwFVec2& origin);

	virtual float GetScaleX() const;
	virtual void SetScaleX(float scaleX);

	virtual float GetScaleY() const;
	virtual void SetScaleY(float scaleY);

	virtual CIwFVec2 GetScale() const;
	virtual void SetScale(const CIwFVec2& scale);

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

	virtual CColor GetDebugColor() const;
	virtual void SetDebugColor(const CColor& color);

	virtual bool IsDebug() const;
	virtual void SetDebug(bool debug);

	virtual bool HitTest(const CIwVec2& point);

private:
	bool m_touchable;
	CDrawable& m_visual;
};

#endif
