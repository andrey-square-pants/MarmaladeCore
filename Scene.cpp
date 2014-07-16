#include "Scene.hpp"

#include <algorithm>

#include "Error.hpp"

Scene::Scene() {
}

Scene::~Scene() {
	std::for_each(m_visuals.begin(), m_visuals.end(),
		ClearVisual());
}

void Scene::Render() {
	std::for_each(m_visuals.begin(), m_visuals.end(),
		RenderVisual());
}

void Scene::Update(float delta) {
	std::for_each(m_visuals.begin(), m_visuals.end(),
		UpdateVisual(delta));
}

bool Scene::ProcessTouchBegin(const Touch& touch) {
	return ProcessTouch(touch, TouchEvent::Begin);
}

bool Scene::ProcessTouchMove(const Touch& touch) {
	return ProcessTouch(touch, TouchEvent::Move);
}

bool Scene::ProcessTouchEnd(const Touch& touch) {
	return ProcessTouch(touch, TouchEvent::End);
}

bool Scene::ProcessTouch(const Touch& touch, TouchEvent::E event) {
	VisualVector::reverse_iterator found = std::find_if(m_visuals.rbegin(),
		m_visuals.rend(), TouchVisual(touch, TouchEvent::End));
	return (found != m_visuals.rend());
}

void Scene::AddVisual(IVisual* visual, bool takeOwnership) {
	if (visual == NULL) {
		throw Error("Null visual pointer");
	}

	VisualVector::iterator foundPtr = std::find_if(m_visuals.begin(),
		m_visuals.end(), FindVisual(visual));
	if (foundPtr != m_visuals.end()) {
		throw Error("Visual is already on scene");
	}

	uint32 id = visual->GetId();
	if (id != 0) {
		VisualVector::iterator foundId = std::find_if(m_visuals.begin(),
			m_visuals.end(), FindVisualById(id));
		if (foundId != m_visuals.end()) {
			if (takeOwnership) {
				delete visual;
			}
			throw Error("Visual id is not unique: %u", id);
		}
	}
	m_visuals.push_back(new VisualInfo(visual, takeOwnership));
}

void Scene::RemoveVisual(IVisual* visual) {
	if (visual == NULL) {
		throw Error("Null visual pointer");
	}

	VisualVector::iterator found = std::find_if(m_visuals.begin(),
		m_visuals.end(), FindVisual(visual));
	if (found != m_visuals.end()) {
		delete *found;
		m_visuals.erase(found);
	}
}

void Scene::RemoveVisualById(uint32 id) {
	if (id == 0) {
		throw Error("Can not remove visual by zero id");
	}

	VisualVector::iterator found = std::find_if(m_visuals.begin(),
		m_visuals.end(), FindVisualById(id));
	if (found != m_visuals.end()) {
		delete *found;
		m_visuals.erase(found);
	}
}

uint32 Scene::GetVisualCount() const {
	return m_visuals.size();
}

IVisual* Scene::GetVisual(uint32 number) {
	if (number >= GetVisualCount()) {
		throw Error("Visual number out of bounds: %u", number);
	}
	return m_visuals[number]->visual;
}

IVisual* Scene::GetVisualById(uint32 id) {
	if (id == 0) {
		throw Error("Can not get visual by zero id");
	}

	VisualVector::iterator found = std::find_if(m_visuals.begin(),
		m_visuals.end(), FindVisualById(id));
	if (found == m_visuals.end()) {
		throw Error("Visual not found: %u", id);
	}
	return (*found)->visual;
}
