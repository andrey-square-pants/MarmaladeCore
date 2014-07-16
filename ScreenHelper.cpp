#include "ScreenHelper.hpp"

#include "IwGx.h"

ScreenHelper::ScreenHelper() {
}

ScreenHelper::~ScreenHelper() {
}

float ScreenHelper::GetScreenWidth() const {
	return static_cast<float>(IwGxGetScreenWidth());
}

float ScreenHelper::GetScreenHeight() const {
	return static_cast<float>(IwGxGetScreenHeight());
}

CIwFVec2 ScreenHelper::GetScreenSize() const {
	return CIwFVec2(GetScreenWidth(), GetScreenHeight());
}

CIwFVec2 ScreenHelper::GetScreenCenter() const {
	return 0.5f*GetScreenSize();
}
