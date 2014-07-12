#include "Label.hpp"

#include "Error.hpp"

CIw2DFont* Label::LoadFont(const std::string& file) {
	CIw2DFont* font = Iw2DCreateFont(file.c_str());
	if (font == NULL) {
		throw Error("Fail to load font: %s", file.c_str());
	}
	return font;
}

Label::Label(const std::string& file)
	: Visual(m_label)
	, m_font(LoadFont(file)) {
	m_label.SetFont(m_font);
}

Label::~Label() {
	delete m_font;
}

std::string Label::GetText() const {
	return m_label.m_Text;
}

void Label::SetText(const std::string& text) {
	m_label.m_Text = text;
}

CIw2DFontAlign Label::GetHorizontalAlign() const {
	return m_label.m_AlignHor;
}

void Label::SetHorizontalAlign(CIw2DFontAlign horizontal) {
	m_label.m_AlignHor = horizontal;
}

CIw2DFontAlign Label::GetVerticalAlign() const {
	return m_label.m_AlignVer;
}

void Label::SetVerticalAlign(CIw2DFontAlign vertical) {
	m_label.m_AlignVer = vertical;
}

void Label::SetCenterAlign() {
	SetHorizontalAlign(IW_2D_FONT_ALIGN_CENTRE);
	SetVerticalAlign(IW_2D_FONT_ALIGN_CENTRE);
}
