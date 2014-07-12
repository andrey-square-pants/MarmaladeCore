#include "Image.hpp"

#include "Error.hpp"

CIw2DImage* Image::LoadImage(const std::string& file) {
	CIw2DImage* image = Iw2DCreateImage(file.c_str());
	if (image == NULL) {
		throw Error("Fail to load image: %s", file.c_str());
	}
	return image;
}

Image::Image(const std::string& file)
	: Visual(m_sprite) {
	m_sprite.SetImage(LoadImage(file));
}

Image::~Image() {
	delete m_sprite.GetImage();
}
