#ifndef TOUCHMANAGER_HPP
#define TOUCHMANAGER_HPP

#include <vector>
#include <functional>

#include "s3ePointer.h"

#include "Core.hpp"

struct Touch {
	int32 x;
	int32 y;
	uint32 id;

	Touch(int32 x_, int32 y_, uint32 id_ = 0)
		: x(x_)
		, y(y_)
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
		NotifyListener(Event::E event, const Touch& touch)
			: m_event(event)
			, m_touch(touch) {
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
		Event::E m_event;
		Touch m_touch;
	};

private:
	ListenerVector m_listeners;
};

#endif
