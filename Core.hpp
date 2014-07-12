#ifndef CORE_HPP
#define CORE_HPP

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
