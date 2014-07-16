#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

#include "Visual.hpp"

class Image : public Visual {
private:
	static CIw2DImage* LoadImage(const std::string& name);

public:
	Image(const std::string& name);
	Image(uint32 id, const std::string& name);
	virtual ~Image();

private:
	void Construct(const std::string& name);
	void Destruct();

protected:
	CSprite m_sprite;
};

#endif
