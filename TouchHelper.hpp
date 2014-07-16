#ifndef TOUCHHELPER_HPP
#define TOUCHHELPER_HPP

#include <map>

#include "s3ePointer.h"

#include "Core.hpp"

class TouchHelper : public ITouchProcessor, public IUpdateable {
public:
	TouchHelper();
	virtual ~TouchHelper();

	void SetTouchProcessor(ITouchProcessor* processor);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual void Update(float delta);

private:
	static void TouchCallback(s3ePointerEvent* event, void* data);
	static void TouchMoveCallback(s3ePointerMotionEvent* event, void* data);
	static void MultiTouchCallback(s3ePointerTouchEvent* event, void* data);
	static void MultiTouchMoveCallback(s3ePointerTouchMotionEvent* event, void* data);

	void DoTouchBegin(const Touch& touch);
	void DoTouchMove(const Touch& touch);
	void DoTouchEnd(const Touch& touch);

private:
	typedef std::map<uint32, Touch> TouchMap;

	TouchMap m_touches;
	ITouchProcessor* m_processor;

	DISABLE_COPY(TouchHelper);
};

#endif
