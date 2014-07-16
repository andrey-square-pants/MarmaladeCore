#include "Visual.hpp"

Visual::Visual(CDrawable& visual)
	: m_id(0)
	, m_touchable(false)
	, m_visual(visual) {
}

Visual::Visual(uint32 id, CDrawable& visual)
	: m_id(id)
	, m_touchable(false)
	, m_visual(visual) {
}

Visual::~Visual() {
}

void Visual::Render() {
	if (!IsVisible()) {
		return;
	}
	m_visual.Render();
}

void Visual::Update(float delta) {
	m_visual.Update(delta, 1.0f);
}

bool Visual::ProcessTouchBegin(const Touch& touch) {
	if (!IsTouchable()) {
		return false;
	}
}

bool Visual::ProcessTouchMove(const Touch& touch) {
	if (!IsTouchable()) {
		return false;
	}
}

bool Visual::ProcessTouchEnd(const Touch& touch) {
	if (!IsTouchable()) {
		return false;
	}
}

uint32 Visual::GetId() const {
	return m_id;
}

float Visual::GetX() const {
	return m_visual.m_X;
}

void Visual::SetX(float x) {
	m_visual.m_X = x;
}

float Visual::GetY() const {
	return m_visual.m_Y;
}

void Visual::SetY(float y) {
	m_visual.m_Y = y;
}

CIwFVec2 Visual::GetPosition() const {
	return CIwFVec2(GetX(), GetY());
}

void Visual::SetPosition(const CIwFVec2& position) {
	SetX(position.x);
	SetY(position.y);
}

float Visual::GetWidth() const {
	return m_visual.m_W;
}

float Visual::GetHeight() const {
	return m_visual.m_H;
}

CIwFVec2 Visual::GetSize() const {
	return CIwFVec2(GetWidth(), GetHeight());
}

float Visual::GetOriginX() const {
	return m_visual.m_AnchorX;
}

void Visual::SetOriginX(float originX) {
	m_visual.m_AnchorX = originX;
}

float Visual::GetOriginY() const {
	return m_visual.m_AnchorY;
}

void Visual::SetOriginY(float originY) {
	m_visual.m_AnchorY = originY;
}

CIwFVec2 Visual::GetOrigin() const {
	return CIwFVec2(GetOriginX(), GetOriginY());
}

void Visual::SetOrigin(const CIwFVec2& origin) {
	SetOriginX(origin.x);
	SetOriginY(origin.y);
}

float Visual::GetScaleX() const {
	return m_visual.m_ScaleX;
}

void Visual::SetScaleX(float scaleX) {
	m_visual.m_ScaleX = scaleX;
}

float Visual::GetScaleY() const {
	return m_visual.m_ScaleY;
}

void Visual::SetScaleY(float scaleY) {
	m_visual.m_ScaleY = scaleY;
}

CIwFVec2 Visual::GetScale() const {
	return CIwFVec2(GetScaleX(), GetScaleY());
}

void Visual::SetScale(const CIwFVec2& scale) {
	SetScaleX(scale.x);
	SetScaleY(scale.y);
}

float Visual::GetAngle() const {
	return m_visual.m_Angle;
}

void Visual::SetAngle(float angle) {
	m_visual.m_Angle = angle;
}

CColor Visual::GetColor() const {
	return m_visual.m_Color;
}

void Visual::SetColor(const CColor& color) {
	m_visual.m_Color = color;
}

float Visual::GetAlpha() const {
	return m_visual.m_Alpha;
}

void Visual::SetAlpha(float alpha) {
	m_visual.m_Alpha = alpha;
}

bool Visual::IsVisible() const {
	return m_visual.m_IsVisible;
}

void Visual::SetVisible(bool visible) {
	m_visual.m_IsVisible = visible;
}

bool Visual::IsTouchable() const {
	return m_touchable;
}

void Visual::SetTouchable(bool touchable) {
	m_touchable = touchable;
}

CColor Visual::GetDebugColor() const {
	return m_visual.m_DebugColor;
}

void Visual::SetDebugColor(const CColor& color) {
	m_visual.m_DebugColor = color;
}

bool Visual::IsDebug() const {
	return m_visual.m_DebugDraw;
}

void Visual::SetDebug(bool debug) {
	m_visual.m_DebugDraw = debug;
}

bool Visual::HitTest(const CIwVec2& point) const {
	return m_visual.HitTest(point.x, point.y);
}
