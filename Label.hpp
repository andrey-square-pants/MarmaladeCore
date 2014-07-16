#ifndef LABEL_HPP
#define LABEL_HPP

#include <string>

#include "Visual.hpp"

class Label : public Visual {
private:
	static CIw2DFont* LoadFont(const std::string& name);

public:
	Label(const std::string& name);
	Label(uint32 id, const std::string& name);
	virtual ~Label();

	bool IsEmpty() const;

	std::string GetText() const;
	void SetText(const std::string& text);

private:
	void Construct(const std::string& name);
	void Destruct();

protected:
	CLabel m_label;
};

#endif
