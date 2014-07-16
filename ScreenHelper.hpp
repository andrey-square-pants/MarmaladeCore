#ifndef SCREENHELPER_HPP
#define SCREENHELPER_HPP

#include "Core.hpp"

class ScreenHelper : public IScreenData {
public:
	ScreenHelper();
	virtual ~ScreenHelper();

	virtual float GetScreenWidth() const;
	virtual float GetScreenHeight() const;

	virtual CIwFVec2 GetScreenSize() const;

	virtual CIwFVec2 GetScreenCenter() const;

	DISABLE_COPY(ScreenHelper);
};

#endif
