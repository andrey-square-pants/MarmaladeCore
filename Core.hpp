#ifndef CORE_HPP
#define CORE_HPP

class IRenderable {
public:
	virtual ~IRenderable() {
	}

	virtual void Render() = 0;
};

class IUpdateable {
public:
	virtual ~IUpdateable() {
	}

	virtual void Update(float delta) = 0;
};

#endif
