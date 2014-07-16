#ifndef CORE_HPP
#define CORE_HPP

#include <string>

#include "s3eTypes.h"
#include "Iw2DSceneGraph.h"
using namespace Iw2DSceneGraph;

#define DISABLE_COPY(ClassName)  \
private:                         \
    ClassName(const ClassName&); \
    ClassName& operator=(const ClassName&)

#define DISABLE_CREATE(ClassName) \
private:                          \
    ClassName();                  \
    ~ClassName()

inline CIwFVec2 p2v(const CIwVec2& point) {
	return CIwFVec2(static_cast<float>(point.x),
		static_cast<float>(point.y));
}

inline CIwVec2 v2p(const CIwFVec2& vector) {
	return CIwVec2(static_cast<int32>(vector.x),
		static_cast<int32>(vector.y));
}

inline CColor rgb(uint8 red, uint8 green, uint8 blue) {
	return CColor(red, green, blue, 0xff);
}

inline CColor rgba(uint8 red, uint8 green, uint8 blue, uint8 alpha) {
	return CColor(red, green, blue, alpha);
}

inline CIwFVec2 both(float value) {
	return CIwFVec2(value, value);
}

inline CIwVec2 both(int32 value) {
	return CIwVec2(value, value);
}

struct Touch {
	uint32 id;
	CIwVec2 point;

	Touch(uint32 id_, const CIwVec2& point_)
		: id(id_)
		, point(point_) {
	}
};

class ITouchProcessor {
public:
	virtual ~ITouchProcessor() {
	}

	virtual bool ProcessTouchBegin(const Touch& touch) = 0;
	virtual bool ProcessTouchMove(const Touch& touch) = 0;
	virtual bool ProcessTouchEnd(const Touch& touch) = 0;
};

class IAudioPlayer {
public:
	virtual ~IAudioPlayer() {
	}

	virtual void PlayEffect(const std::string& name) = 0;

	virtual void PlayMusic(const std::string& name, bool repeat) = 0;
	virtual void StopMusic() = 0;
};

class IRenderable {
public:
	virtual ~IRenderable() {
	}

	virtual void Render() = 0;
};

class IUpdateable {
public:
	virtual ~IUpdateable() {
	}

	virtual void Update(float delta) = 0;
};

class ICreateable {
public:
	virtual ~ICreateable() {
	}

	virtual void Create() = 0;
	virtual void Destroy() = 0;
};

class IVisual : public IRenderable, public IUpdateable,
	public ITouchProcessor {
public:
	virtual ~IVisual() {
	}

	virtual uint32 GetId() const = 0;

	virtual float GetX() const = 0;
	virtual void SetX(float x) = 0;

	virtual float GetY() const = 0;
	virtual void SetY(float y) = 0;

	virtual CIwFVec2 GetPosition() const = 0;
	virtual void SetPosition(const CIwFVec2& position) = 0;

	virtual float GetWidth() const = 0;
	virtual float GetHeight() const = 0;
	virtual CIwFVec2 GetSize() const = 0;

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

	virtual bool HitTest(const CIwVec2& point) const = 0;
};

class IScene : public IRenderable, public IUpdateable,
	public ITouchProcessor {
public:
	virtual ~IScene() {
	}

	virtual void AddVisual(IVisual* visual, bool takeOwnership) = 0;

	virtual void RemoveVisual(IVisual* visual) = 0;
	virtual void RemoveVisualById(uint32 id) = 0;

	virtual uint32 GetVisualCount() const = 0;

	virtual IVisual* GetVisual(uint32 number) = 0;
	virtual IVisual* GetVisualById(uint32 id) = 0;
};

class ISceneManager {
public:
	virtual ~ISceneManager() {
	}

	virtual IScene* GetCurrentScene() = 0;
	virtual void SetCurrentScene(IScene* scene, bool takeOwnership) = 0;
};

class IScreenData {
public:
	virtual ~IScreenData() {
	}

	virtual float GetScreenWidth() const = 0;
	virtual float GetScreenHeight() const = 0;

	virtual CIwFVec2 GetScreenSize() const = 0;

	virtual CIwFVec2 GetScreenCenter() const = 0;
};

class ITouchListener {
public:
	virtual ~ITouchListener() {
	}

	virtual void OnTouchCancel(IVisual& visual, const Touch& touch) = 0;

	virtual bool OnTouchBegin(IVisual& visual, const Touch& touch) = 0;
	virtual bool OnTouchMove(IVisual& visual, const Touch& touch) = 0;
	virtual bool OnTouchEnd(IVisual& visual, const Touch& touch) = 0;

	virtual bool OnClick(IVisual& visual, const Touch& touch) = 0;
};

#endif
