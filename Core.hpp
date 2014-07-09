#ifndef CORE_HPP
#define CORE_HPP

#define DISABLE_COPY(ClassName)  \
private:                         \
    ClassName(const ClassName&); \
    ClassName& operator=(const ClassName&)

#define DISABLE_CREATE(ClassName) \
private:                          \
    ClassName();                  \
    ~ClassName()

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
