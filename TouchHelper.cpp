#include "TouchHelper.hpp"

TouchHelper::TouchHelper()
	: m_processor(NULL) {
	if (s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE) != 0) {
		s3ePointerRegister(S3E_POINTER_TOUCH_EVENT,
			(s3eCallback)MultiTouchCallback, this);
		s3ePointerRegister(S3E_POINTER_TOUCH_MOTION_EVENT,
			(s3eCallback)MultiTouchMoveCallback, this);
	} else {
		s3ePointerRegister(S3E_POINTER_BUTTON_EVENT,
			(s3eCallback)TouchCallback, this);
		s3ePointerRegister(S3E_POINTER_MOTION_EVENT,
			(s3eCallback)TouchMoveCallback, this);
	}
}

TouchHelper::~TouchHelper() {
}

void TouchHelper::SetTouchProcessor(ITouchProcessor* processor) {
	m_processor = processor;
}

void TouchHelper::Update(float delta) {
	s3ePointerUpdate();
}

void TouchHelper::TouchCallback(s3ePointerEvent* event, void* data) {
	TouchHelper* tthis = static_cast<TouchHelper*>(data);
	if (event->m_Pressed) {
		tthis->DoTouchBegin(Touch(0, CIwVec2(event->m_x, event->m_y)));
	} else {
		tthis->DoTouchEnd(Touch(0, CIwVec2(event->m_x, event->m_y)));
	}
}

void TouchHelper::TouchMoveCallback(s3ePointerMotionEvent* event, void* data) {
	TouchHelper* tthis = static_cast<TouchHelper*>(data);
	tthis->DoTouchMove(Touch(0, CIwVec2(event->m_x, event->m_y)));
}

void TouchHelper::MultiTouchCallback(s3ePointerTouchEvent* event, void* data) {
	TouchHelper* tthis = static_cast<TouchHelper*>(data);
	if (event->m_Pressed) {
		tthis->DoTouchBegin(Touch(event->m_TouchID, CIwVec2(event->m_x, event->m_y)));
	} else {
		tthis->DoTouchEnd(Touch(event->m_TouchID, CIwVec2(event->m_x, event->m_y)));
	}
}

void TouchHelper::MultiTouchMoveCallback(s3ePointerTouchMotionEvent* event, void* data) {
	TouchHelper* tthis = static_cast<TouchHelper*>(data);
	tthis->DoTouchMove(Touch(event->m_TouchID, CIwVec2(event->m_x, event->m_y)));
}

void TouchHelper::DoTouchBegin(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		ProcessTouchEnd(found->second);
		m_touches.erase(found);
	} else {
		ProcessTouchBegin(touch);
		m_touches.insert(std::make_pair(touch.id, touch));
	}
}

void TouchHelper::DoTouchMove(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		found->second.point = touch.point;
		ProcessTouchMove(touch);
	}
}

void TouchHelper::DoTouchEnd(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		ProcessTouchEnd(found->second);
		m_touches.erase(found);
	}
}

bool TouchHelper::ProcessTouchBegin(const Touch& touch) {
	return (m_processor != NULL ? m_processor->ProcessTouchBegin(touch) : false);
}

bool TouchHelper::ProcessTouchMove(const Touch& touch) {
	return (m_processor != NULL ? m_processor->ProcessTouchMove(touch) : false);
}

bool TouchHelper::ProcessTouchEnd(const Touch& touch) {
	return (m_processor != NULL ? m_processor->ProcessTouchEnd(touch) : false);
}
