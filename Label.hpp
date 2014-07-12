#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>

#include "Visual.hpp"

class Label : public Visual {
private:
	static CIw2DFont* LoadFont(const std::string& file);

public:
	Label(const std::string& file);
	virtual ~Label();

	bool IsEmpty() const;

	std::string GetText() const;
	void SetText(const std::string& text);

protected:
	CLabel m_label;
};

#endif
