#include "Image.hpp"

#include "Error.hpp"

CIw2DImage* Image::LoadImage(const std::string& fileImage) {
	CIw2DImage* image = Iw2DCreateImage(fileImage.c_str());
	if (image == NULL) {
		throw Error("Fail to load image: %s", fileImage.c_str());
	}
	return image;
}

Image::Image(const std::string& fileImage)
	: Visual(m_sprite) {
	Construct(fileImage);
}

Image::Image(uint32 id, const std::string& fileImage)
	: Visual(id, m_sprite) {
	Construct(fileImage);
}

Image::~Image() {
	Destruct();
}

void Image::Construct(const std::string& fileImage) {
	m_sprite.SetImage(LoadImage(fileImage));
}

void Image::Destruct() {
	delete m_sprite.GetImage();
}
