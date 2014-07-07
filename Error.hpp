#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

class Error {
public:
	Error(const char* format, ...);
	virtual ~Error();

	std::string GetMessage() const;

private:
	std::string m_message;
};

#endif
