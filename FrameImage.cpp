#include "FrameImage.hpp"

#include "Error.hpp"

FrameImage::FrameImage(const std::string& name, uint8 count)
	: Image(name)
	, m_currentFrame(0) {
	Construct(count);
}

FrameImage::FrameImage(uint32 id, const std::string& name, uint8 count)
	: Image(id, name)
	, m_currentFrame(0) {
	Construct(count);
}

FrameImage::~FrameImage() {
	Destruct();
}

void FrameImage::Construct(uint8 count) {
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

void FrameImage::Destruct() {
	delete m_sprite.GetAtlas();
}

uint8 FrameImage::GetFrameCount() const {
	CSprite& sprite = const_cast<CSprite&>(m_sprite);
	return static_cast<uint8>(sprite.GetAtlas()->GetNumFrames());
}

uint8 FrameImage::GetCurrentFrame() const {
	return m_currentFrame;
}

void FrameImage::SetCurrentFrame(uint8 number) {
	if (number >= GetFrameCount()) {
		throw Error("Frame number out of bounds: %u", number);
	}
	m_currentFrame = number;
}

void FrameImage::Render() {
	if (!IsVisible()) {
		return;
	}

	m_sprite.PreRender();

	const CIwRect& region = m_sprite.GetAtlas()->GetFrame(m_currentFrame);
	Iw2DDrawImageRegion(m_sprite.GetImage(), CIwFVec2(0, 0),
		CIwFVec2(region.x, region.y), CIwFVec2(region.w, region.h));

	if (IsDebug()) {
		CColor color = GetDebugColor();
		Iw2DSetColour(*(uint32*)&color);
		Iw2DDrawRect(CIwFVec2::g_Zero, GetSize());
	}
}
