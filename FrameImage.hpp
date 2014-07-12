#ifndef FRAMEIMAGE_HPP
#define FRAMEIMAGE_HPP

#include <string>

#include "Image.hpp"

class FrameImage : public Image {
public:
	FrameImage(const std::string& file, uint8 count);
	virtual ~FrameImage();

	virtual void Render();

	uint8 GetCount() const;

	uint8 GetFrame() const;
	void SetFrame(uint8 frame);

private:
	uint8 m_frame;
};

#endif
