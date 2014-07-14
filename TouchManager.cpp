#include "TouchManager.hpp"

#include <algorithm>

TouchManager::TouchManager() {
	if (s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE) != 0) {
		s3ePointerRegister(S3E_POINTER_TOUCH_EVENT,
			(s3eCallback)MultiTouchCallback, this);
		s3ePointerRegister(S3E_POINTER_TOUCH_MOTION_EVENT,
			(s3eCallback)MultiTouchMotionCallback, this);
	} else {
		s3ePointerRegister(S3E_POINTER_BUTTON_EVENT,
			(s3eCallback)TouchCallback, this);
		s3ePointerRegister(S3E_POINTER_MOTION_EVENT,
			(s3eCallback)TouchMotionCallback, this);
	}
}

TouchManager::~TouchManager() {
}

void TouchManager::Update(float delta) {
	s3ePointerUpdate();
}

void TouchManager::AddListener(ITouchListener& listener) {
	ListenerVector::iterator found = std::find(m_listeners.begin(),
		m_listeners.end(), &listener);
	if (found == m_listeners.end()) {
		m_listeners.push_back(&listener);
	}
}

void TouchManager::RemoveListener(ITouchListener& listener) {
	ListenerVector::iterator found = std::find(m_listeners.begin(),
		m_listeners.end(), &listener);
	if (found != m_listeners.end()) {
		m_listeners.erase(found);
	}
}

void TouchManager::TouchCallback(s3ePointerEvent* event, void* data) {
	TouchManager* tthis = static_cast<TouchManager*>(data);
	if (event->m_Pressed) {
		tthis->TouchBegin(Touch(CIwVec2(event->m_x, event->m_y)));
	} else {
		tthis->TouchEnd(Touch(CIwVec2(event->m_x, event->m_y)));
	}
}

void TouchManager::TouchMotionCallback(s3ePointerMotionEvent* event, void* data) {
	TouchManager* tthis = static_cast<TouchManager*>(data);
	tthis->TouchMove(Touch(CIwVec2(event->m_x, event->m_y)));
}

void TouchManager::MultiTouchCallback(s3ePointerTouchEvent* event, void* data) {
	TouchManager* tthis = static_cast<TouchManager*>(data);
	if (event->m_Pressed) {
		tthis->TouchBegin(Touch(CIwVec2(event->m_x, event->m_y), event->m_TouchID));
	} else {
		tthis->TouchEnd(Touch(CIwVec2(event->m_x, event->m_y), event->m_TouchID));
	}
}

void TouchManager::MultiTouchMotionCallback(s3ePointerTouchMotionEvent* event, void* data) {
	TouchManager* tthis = static_cast<TouchManager*>(data);
	tthis->TouchMove(Touch(CIwVec2(event->m_x, event->m_y), event->m_TouchID));
}

void TouchManager::TouchBegin(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		NotifyEnd(found);
	} else {
		NotifyBegin(touch);
	}
}

void TouchManager::TouchMove(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		NotifyMove(found, touch);
	}
}

void TouchManager::TouchEnd(const Touch& touch) {
	TouchMap::iterator found = m_touches.find(touch.id);
	if (found != m_touches.end()) {
		NotifyEnd(found);
	}
}

void TouchManager::NotifyBegin(const Touch& touch) {
	NotifyEvent(touch, Event::Begin);
	m_touches.insert(std::make_pair(touch.id, touch));
}

void TouchManager::NotifyMove(TouchMap::iterator it, const Touch& touch) {
	it->second.point = touch.point;
	NotifyEvent(it->second, Event::Move);
}

void TouchManager::NotifyEnd(TouchMap::iterator it) {
	NotifyEvent(it->second, Event::End);
	m_touches.erase(it);
}

void TouchManager::NotifyEvent(const Touch& touch, Event::E event) {
	std::for_each(m_listeners.begin(), m_listeners.end(),
		NotifyListener(touch, event));
}
