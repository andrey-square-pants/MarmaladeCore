#ifndef VISUALIMAGE_HPP
#define VISUALIMAGE_HPP

#include <string>

#include "Visual.hpp"

class VisualImage : public Visual {
public:
	VisualImage(const std::string& file);
	virtual ~VisualImage();

private:
	CSprite m_sprite;
	CIw2DImage* m_image;
};

#endif
