#ifndef FRAMEIMAGE_HPP
#define FRAMEIMAGE_HPP

#include <string>

#include "Image.hpp"

class FrameImage : public Image {
public:
	FrameImage(const std::string& fileImage, uint8 frameCount);
	FrameImage(uint32 id, const std::string& fileImage, uint8 frameCount);
	virtual ~FrameImage();

	virtual void Render();

	uint8 GetFrameCount() const;

	uint8 GetCurrentFrame() const;
	void SetCurrentFrame(uint8 number);

private:
	void Construct(uint8 frameCount);
	void Destruct();

private:
	uint8 m_currentFrame;
};

#endif
