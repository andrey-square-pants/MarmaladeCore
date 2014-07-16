#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <functional>

#include "Core.hpp"

class Scene : public IScene {
public:
	Scene();
	virtual ~Scene();

	virtual void Render();
	virtual void Update(float delta);

	virtual bool ProcessTouchBegin(const Touch& touch);
	virtual bool ProcessTouchMove(const Touch& touch);
	virtual bool ProcessTouchEnd(const Touch& touch);

	virtual void AddVisual(IVisual* visual, bool takeOwnership);

	virtual void RemoveVisual(IVisual* visual);
	virtual void RemoveVisualById(uint32 id);

	virtual uint32 GetVisualCount() const;

	virtual IVisual* GetVisual(uint32 number);
	virtual IVisual* GetVisualById(uint32 id);

private:
	struct VisualInfo {
		IVisual* visual;
		bool takeOwnership;

		VisualInfo(IVisual* visual_, bool takeOwnership_)
			: visual(visual_)
			, takeOwnership(takeOwnership_) {
		}

		~VisualInfo() {
			if (takeOwnership) {
				delete visual;
			}
		}
	};

	typedef std::vector<VisualInfo*> VisualVector;

	class FindVisual : public std::unary_function<const VisualInfo*, bool> {
	public:
		FindVisual(IVisual* visual)
			: m_visual(visual) {
		}

		bool operator()(const VisualInfo* info) const {
			return (info->visual == m_visual);
		}

	private:
		IVisual* m_visual;
	};

	class FindVisualById : public std::unary_function<const VisualInfo*, bool> {
	public:
		FindVisualById(uint32 id)
			: m_id(id) {
		}

		bool operator()(const VisualInfo* info) const {
			return (info->visual->GetId() == m_id);
		}

	private:
		uint32 m_id;
	};

	class ClearVisual : public std::unary_function<VisualInfo*, void> {
	public:
		void operator()(VisualInfo* info) const {
			delete info;
		}
	};

	class RenderVisual : public std::unary_function<VisualInfo*, void> {
	public:
		void operator()(VisualInfo* info) const {
			if (info->visual->IsVisible()) {
				info->visual->Render();
			}
		}
	};

	class UpdateVisual : public std::unary_function<VisualInfo*, void> {
	public:
		UpdateVisual(float delta)
			: m_delta(delta) {
		}

		void operator()(VisualInfo* info) const {
			info->visual->Update(m_delta);
		}

	private:
		float m_delta;
	};

	struct TouchEvent {
		enum E {
			Begin,
			Move,
			End
		};
	};

	class TouchVisual : public std::unary_function<VisualInfo*, bool> {
	public:
		TouchVisual(const Touch& touch, TouchEvent::E event)
			: m_touch(touch)
			, m_event(event) {
		}

		bool operator()(VisualInfo* info) const {
			if (!info->visual->IsTouchable() ||
				!info->visual->HitTest(m_touch.point)) {
				return false;
			}

			switch (m_event) {
			case TouchEvent::Begin:
				return info->visual->ProcessTouchBegin(m_touch);

			case TouchEvent::Move:
				return info->visual->ProcessTouchMove(m_touch);

			case TouchEvent::End:
				return info->visual->ProcessTouchEnd(m_touch);
			}
			return false;
		}

	private:
		Touch m_touch;
		TouchEvent::E m_event;
	};

	bool ProcessTouch(const Touch& touch, TouchEvent::E event);

private:
	VisualVector m_visuals;

	DISABLE_COPY(Scene);
};

#endif
