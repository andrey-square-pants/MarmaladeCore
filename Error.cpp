#include "Error.hpp"

#include <cstdio>
#include <cstring>

Error::Error(const char* format, ...) {
	if (format == NULL) {
		return;
	}

	static const int MessageSize = 1024;

	char message[MessageSize];
	memset(message, 0, MessageSize);

	va_list args;
	va_start(args, format);

	vsprintf(message, format, args);

	va_end(args);

	m_message = message;
}

Error::~Error() {
}

std::string Error::GetMessage() const {
	return m_message;
}
