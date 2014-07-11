#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

#include "Visual.hpp"

class Image : public Visual {
private:
	static CIw2DImage* LoadImage(const std::string& file);

public:
	Image(const std::string& file);
	virtual ~Image();

protected:
	CSprite m_sprite;
	CIw2DImage* m_image;
};

#endif
