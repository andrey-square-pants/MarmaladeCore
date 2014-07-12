#include "FrameImage.hpp"

#include "Error.hpp"

FrameImage::FrameImage(const std::string& file, uint8 count)
	: Image(file)
	, m_frame(0) {
	m_sprite.SetAnimRepeat(0);
	m_sprite.SetAnimDuration(0.0f);

	CIw2DImage* image = m_sprite.GetImage();
	if (count == 0) {
		delete image;
		throw Error("Frame count should be > 0");
	}

	int width = static_cast<int>(image->GetWidth())/count;
	int height = static_cast<int>(image->GetHeight());

	m_sprite.SetAtlas(new CAtlas(width, height, count, image));

	m_sprite.m_W = static_cast<float>(width);
	m_sprite.m_H = static_cast<float>(height);
}

FrameImage::~FrameImage() {
	delete m_sprite.GetAtlas();
}

uint8 FrameImage::GetCount() const {
	CSprite& sprite = const_cast<CSprite&>(m_sprite);
	return static_cast<uint8>(sprite.GetAtlas()->GetNumFrames());
}

uint8 FrameImage::GetFrame() const {
	return m_frame;
}

void FrameImage::SetFrame(uint8 frame) {
	if (frame >= GetCount()) {
		throw Error("Frame out of bounds: %d", frame);
	}
	m_frame = frame;
}

void FrameImage::Render() {
	if (!IsVisible()) {
		return;
	}

	m_sprite.PreRender();

	const CIwRect& region = m_sprite.GetAtlas()->GetFrame(m_frame);
	Iw2DDrawImageRegion(m_sprite.GetImage(), CIwFVec2(0, 0),
		CIwFVec2(region.x, region.y), CIwFVec2(region.w, region.h));

	if (IsDebug()) {
		CColor color = GetDebugColor();
		Iw2DSetColour(*(uint32*)&color);
		Iw2DDrawRect(CIwFVec2::g_Zero, GetSize());
	}
}
