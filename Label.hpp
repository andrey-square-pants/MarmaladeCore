#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>

#include "Visual.hpp"

class Label : public Visual {
private:
	static CIw2DFont* LoadFont(const std::string& file);

public:
	Label(const std::string& file = "");
	virtual ~Label();

	std::string GetText() const;
	Label& SetText(const std::string& text);

	CIw2DFontAlign GetHorizontalAlign() const;
	Label& SetHorizontalAlign(CIw2DFontAlign horizontal);

	CIw2DFontAlign GetVerticalAlign() const;
	Label& SetVerticalAlign(CIw2DFontAlign vertical);

	Label& SetAlign(CIw2DFontAlign horizontal, CIw2DFontAlign vertical);

	Label& CenterAlign();

protected:
	CLabel m_label;
	CIw2DFont* m_font;
};

#endif
