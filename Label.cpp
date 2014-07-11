#include "Label.hpp"

#include "Error.hpp"

CIw2DFont* Label::LoadFont(const std::string& file) {
	if (file.empty()) {
		return NULL;
	}

	CIw2DFont* font = Iw2DCreateFont(file.c_str());
	if (font == NULL) {
		throw Error("Fail to load font: %s", file.c_str());
	}
	return font;
}

Label::Label(const std::string& file)
	: Visual(m_label)
	, m_font(LoadFont(file)) {
	if (m_font != NULL) {
		m_label.SetFont(m_font);
	}
}

Label::~Label() {
	delete m_font;
}

std::string Label::GetText() const {
	return m_label.m_Text;
}

Label& Label::SetText(const std::string& text) {
	m_label.m_Text = text;
	return *this;
}

CIw2DFontAlign Label::GetHorizontalAlign() const {
	return m_label.m_AlignHor;
}

Label& Label::SetHorizontalAlign(CIw2DFontAlign horizontal) {
	m_label.m_AlignHor = horizontal;
	return *this;
}

CIw2DFontAlign Label::GetVerticalAlign() const {
	return m_label.m_AlignVer;
}

Label& Label::SetVerticalAlign(CIw2DFontAlign vertical) {
	m_label.m_AlignVer = vertical;
	return *this;
}

Label& Label::SetAlign(CIw2DFontAlign horizontal, CIw2DFontAlign vertical) {
	return SetHorizontalAlign(horizontal).SetVerticalAlign(vertical);
}

Label& Label::CenterAlign() {
	return SetAlign(IW_2D_FONT_ALIGN_CENTRE, IW_2D_FONT_ALIGN_CENTRE);
}
