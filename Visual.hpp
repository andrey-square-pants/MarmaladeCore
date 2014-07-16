#ifndef VISUAL_HPP
#define VISUAL_HPP

#include "Core.hpp"

class Visual : public IVisual {
protected:
	Visual(CDrawable& visual);
	Visual(uint32 id, CDrawable& visual);

public:
	virtual ~Visual();

	virtual void Render();
	virtual void Update(float delta);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual uint32 GetId() const;

	virtual float GetX() const;
	virtual void SetX(float x);

	virtual float GetY() const;
	virtual void SetY(float y);

	virtual CIwFVec2 GetPosition() const;
	virtual void SetPosition(const CIwFVec2& position);

	virtual float GetWidth() const;
	virtual float GetHeight() const;
	virtual CIwFVec2 GetSize() const;

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

	virtual bool HitTest(const CIwVec2& point) const;

private:
	uint32 m_id;
	bool m_touchable;
	mutable CDrawable& m_visual;

	DISABLE_COPY(Visual);
};

#endif
