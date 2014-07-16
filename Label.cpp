#include "Label.hpp"

#include "Error.hpp"

CIw2DFont* Label::LoadFont(const std::string& name) {
	CIw2DFont* font = Iw2DCreateFont(name.c_str());
	if (font == NULL) {
		throw Error("Fail to load font: %s", name.c_str());
	}
	return font;
}

Label::Label(const std::string& name)
	: Visual(m_label) {
	Construct(name);
}

Label::Label(uint32 id, const std::string& name)
	: Visual(id, m_label) {
	Construct(name);
}

Label::~Label() {
	Destruct();
}

void Label::Construct(const std::string& name) {
	m_label.SetFont(LoadFont(name));
	m_label.m_H = static_cast<float>(m_label.m_Font->GetHeight());
}

void Label::Destruct() {
	delete m_label.m_Font;
}

bool Label::IsEmpty() const {
	return m_label.m_Text.empty();
}

std::string Label::GetText() const {
	return m_label.m_Text;
}

void Label::SetText(const std::string& text) {
	m_label.m_Text = text;

	if (!text.empty()) {
		CIw2DFont* oldFont = Iw2DGetFont();

		Iw2DSetFont(m_label.m_Font);
		m_label.m_W = static_cast<float>(Iw2DGetStringWidth(text.c_str()));

		Iw2DSetFont(oldFont);
	} else {
		m_label.m_W = 0.0f;
	}
}
