#ifndef CORE_HPP
#define CORE_HPP

#include "IwGeomFVec2.h"

#define DISABLE_COPY(ClassName)  \
private:                         \
    ClassName(const ClassName&); \
    ClassName& operator=(const ClassName&)

#define DISABLE_CREATE(ClassName) \
private:                          \
    ClassName();                  \
    ~ClassName()

inline CIwFVec2 PointToPosition(const CIwVec2& point) {
	return CIwFVec2(static_cast<float>(point.x),
		static_cast<float>(point.y));
}

inline CIwVec2 PositionToPoint(const CIwFVec2& position) {
	return CIwVec2(static_cast<int32>(position.x),
		static_cast<int32>(position.y));
}

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

#endif
