#include "Visual.hpp"

Visual::Visual(CDrawable& visual)
	: m_touchable(false)
	, m_visual(visual) {
}

Visual::~Visual() {
}

void Visual::Render() {
	m_visual.Render();
}

void Visual::Update(float delta) {
	m_visual.Update(delta, 1.0f);
}

void Visual::OnTouchBegin(const Touch& touch) {
}

void Visual::OnTouchMove(const Touch& touch) {
}

void Visual::OnTouchEnd(const Touch& touch) {
}

float Visual::GetX() const {
	return m_visual.m_X;
}

Visual& Visual::SetX(float x) {
	m_visual.m_X = x;
	return *this;
}

float Visual::GetY() const {
	return m_visual.m_Y;
}

Visual& Visual::SetY(float y) {
	m_visual.m_Y = y;
	return *this;
}

CIwFVec2 Visual::GetPosition() const {
	return CIwFVec2(GetX(), GetY());
}

Visual& Visual::SetPosition(const CIwFVec2& position) {
	return SetPosition(position.x, position.y);
}

Visual& Visual::SetPosition(float x, float y) {
	return SetX(x).SetY(y);
}

float Visual::GetWidth() const {
	return m_visual.m_W;
}

Visual& Visual::SetWidth(float width) {
	m_visual.m_W = width;
	return *this;
}

float Visual::GetHeight() const {
	return m_visual.m_H;
}

Visual& Visual::SetHeight(float height) {
	m_visual.m_H = height;
	return *this;
}

CIwFVec2 Visual::GetSize() const {
	return CIwFVec2(GetWidth(), GetHeight());
}

Visual& Visual::SetSize(const CIwFVec2& size) {
	return SetSize(size.x, size.y);
}

Visual& Visual::SetSize(float width, float height) {
	return SetWidth(width).SetHeight(height);
}

float Visual::GetOriginX() const {
	return m_visual.m_AnchorX;
}

Visual& Visual::SetOriginX(float originX) {
	m_visual.m_AnchorX = originX;
	return *this;
}

float Visual::GetOriginY() const {
	return m_visual.m_AnchorY;
}

Visual& Visual::SetOriginY(float originY) {
	m_visual.m_AnchorY = originY;
	return *this;
}

CIwFVec2 Visual::GetOrigin() const {
	return CIwFVec2(GetOriginX(), GetOriginY());
}

Visual& Visual::SetOrigin(const CIwFVec2& origin) {
	return SetOrigin(origin.x, origin.y);
}

Visual& Visual::SetOrigin(float origin) {
	return SetOrigin(origin, origin);
}

Visual& Visual::SetOrigin(float originX, float originY) {
	return SetOriginX(originX).SetOriginY(originY);
}

float Visual::GetScaleX() const {
	return m_visual.m_ScaleX;
}

Visual& Visual::SetScaleX(float scaleX) {
	m_visual.m_ScaleX = scaleX;
	return *this;
}

float Visual::GetScaleY() const {
	return m_visual.m_ScaleY;
}

Visual& Visual::SetScaleY(float scaleY) {
	m_visual.m_ScaleY = scaleY;
	return *this;
}

CIwFVec2 Visual::GetScale() const {
	return CIwFVec2(GetScaleX(), GetScaleY());
}

Visual& Visual::SetScale(const CIwFVec2& scale) {
	return SetScale(scale.x, scale.y);
}

Visual& Visual::SetScale(float scale) {
	return SetScale(scale, scale);
}

Visual& Visual::SetScale(float scaleX, float scaleY) {
	return SetScaleX(scaleX).SetScaleY(scaleY);
}

float Visual::GetAngle() const {
	return m_visual.m_Angle;
}

Visual& Visual::SetAngle(float angle) {
	m_visual.m_Angle = angle;
	return *this;
}

CColor Visual::GetColor() const {
	return m_visual.m_Color;
}

Visual& Visual::SetColor(const CColor& color) {
	return SetColor(color.r, color.g, color.b);
}

Visual& Visual::SetColor(uint8 red, uint8 green, uint8 blue) {
	m_visual.m_Color.r = red;
	m_visual.m_Color.g = green;
	m_visual.m_Color.b = blue;
	return *this;
}

uint8 Visual::GetRed() const {
	return m_visual.m_Color.r;
}

Visual& Visual::SetRed(uint8 red) {
	m_visual.m_Color.r = red;
	return *this;
}

uint8 Visual::GetGreen() const {
	return m_visual.m_Color.g;
}

Visual& Visual::SetGreen(uint8 green) {
	m_visual.m_Color.g = green;
	return *this;
}

uint8 Visual::GetBlue() const {
	return m_visual.m_Color.b;
}

Visual& Visual::SetBlue(uint8 blue) {
	m_visual.m_Color.b = blue;
	return *this;
}

float Visual::GetAlpha() const {
	return m_visual.m_Alpha;
}

Visual& Visual::SetAlpha(float alpha) {
	m_visual.m_Alpha = alpha;
	return *this;
}

bool Visual::IsVisible() const {
	return m_visual.m_IsVisible;
}

Visual& Visual::SetVisible(bool visible) {
	m_visual.m_IsVisible = visible;
	return *this;
}

bool Visual::IsTouchable() const {
	return m_touchable;
}

Visual& Visual::SetTouchable(bool touchable) {
	m_touchable = touchable;
	return *this;
}

bool Visual::HitTest(const CIwVec2& point) {
	return HitTest(point.x, point.y);
}

bool Visual::HitTest(int pointX, int pointY) {
	return m_visual.HitTest(pointX, pointY);
}
