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

void Visual::SetX(float x) {
	m_visual.m_X = x;
}

float Visual::GetY() const {
	return m_visual.m_Y;
}

void Visual::SetY(float y) {
	m_visual.m_Y = y;
}

float Visual::GetWidth() const {
	return m_visual.m_W;
}

void Visual::SetWidth(float width) {
	m_visual.m_W = width;
}

float Visual::GetHeight() const {
	return m_visual.m_H;
}

void Visual::SetHeight(float height) {
	m_visual.m_H = height;
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

bool Visual::HitTest(int x, int y) {
	return m_visual.HitTest(x, y);
}
