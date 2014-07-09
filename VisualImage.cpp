#include "VisualImage.hpp"

VisualImage::VisualImage(const std::string& file)
	: Visual(m_sprite)
	, m_image(Iw2DCreateImage(file.c_str())) {
		m_sprite.SetImage(m_image);
}

VisualImage::~VisualImage() {
	delete m_image;
}
