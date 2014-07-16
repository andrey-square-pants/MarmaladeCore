#include "Image.hpp"

#include "Error.hpp"

CIw2DImage* Image::LoadImage(const std::string& name) {
	CIw2DImage* image = Iw2DCreateImage(name.c_str());
	if (image == NULL) {
		throw Error("Fail to load image: %s", name.c_str());
	}
	return image;
}

Image::Image(const std::string& name)
	: Visual(m_sprite) {
	Construct(name);
}

Image::Image(uint32 id, const std::string& name)
	: Visual(id, m_sprite) {
	Construct(name);
}

Image::~Image() {
	Destruct();
}

void Image::Construct(const std::string& name) {
	m_sprite.SetImage(LoadImage(name));
}

void Image::Destruct() {
	delete m_sprite.GetImage();
}
