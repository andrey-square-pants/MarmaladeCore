#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

#include "Visual.hpp"

class Image : public Visual {
private:
	static CIw2DImage* LoadImage(const std::string& fileImage);

public:
	Image(const std::string& fileImage);
	Image(uint32 id, const std::string& fileImage);
	virtual ~Image();

private:
	void Construct(const std::string& fileImage);
	void Destruct();

protected:
	CSprite m_sprite;
};

#endif
