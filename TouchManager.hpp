#ifndef TOUCHMANAGER_HPP
#define TOUCHMANAGER_HPP

#include <vector>
#include <functional>

#include "s3ePointer.h"
#include "IwGeomVec2.h"

#include "Core.hpp"

struct Touch {
	uint32 id;
	CIwVec2 point;

	Touch(int32 x_, int32 y_, uint32 id_ = 0)
		: id(id_)
		, point(x_, y_) {
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

private:
	ListenerVector m_listeners;

	DISABLE_COPY(TouchManager);
};

#endif
