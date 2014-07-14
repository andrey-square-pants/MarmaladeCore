#ifndef TOUCHMANAGER_HPP
#define TOUCHMANAGER_HPP

#include <map>
#include <vector>
#include <functional>

#include "s3ePointer.h"
#include "IwGeomVec2.h"

#include "Core.hpp"

struct Touch {
	CIwVec2 point;
	uint32 id;

	Touch(const CIwVec2& point_, uint32 id_ = 0)
		: point(point_)
		, id(id_) {
	}
};

class ITouchListener {
public:
	virtual ~ITouchListener() {
	}

	virtual void OnTouchBegin(const Touch& touch) = 0;
	virtual void OnTouchMove(const Touch& touch) = 0;
	virtual void OnTouchEnd(const Touch& touch) = 0;
};

class TouchManager : public IUpdateable {
public:
	TouchManager();
	virtual ~TouchManager();

	void AddListener(ITouchListener& listener);
	void RemoveListener(ITouchListener& listener);

	virtual void Update(float delta);

private:
	static void TouchCallback(s3ePointerEvent* event, void* data);
	static void TouchMotionCallback(s3ePointerMotionEvent* event, void* data);
	static void MultiTouchCallback(s3ePointerTouchEvent* event, void* data);
	static void MultiTouchMotionCallback(s3ePointerTouchMotionEvent* event, void* data);

	void TouchBegin(const Touch& touch);
	void TouchMove(const Touch& touch);
	void TouchEnd(const Touch& touch);

private:
	typedef std::map<uint32, Touch> TouchMap;
	typedef std::vector<ITouchListener*> ListenerVector;

	struct Event {
		enum E {
			Begin,
			Move,
			End
		};
	};

	class NotifyListener : public std::unary_function<ITouchListener*, void> {
	public:
		NotifyListener(const Touch& touch, Event::E event)
			: m_touch(touch)
			, m_event(event) {
		}

		void operator()(ITouchListener* listener) const {
			switch (m_event) {
			case Event::Begin:
				listener->OnTouchBegin(m_touch);
				break;

			case Event::Move:
				listener->OnTouchMove(m_touch);
				break;

			case Event::End:
				listener->OnTouchEnd(m_touch);
				break;
			}
		}

	private:
		Touch m_touch;
		Event::E m_event;
	};

	void NotifyBegin(const Touch& touch);
	void NotifyMove(TouchMap::iterator it, const Touch& touch);
	void NotifyEnd(TouchMap::iterator it);

	void NotifyEvent(const Touch& touch, Event::E event);

private:
	TouchMap m_touches;
	ListenerVector m_listeners;

	DISABLE_COPY(TouchManager);
};

#endif
