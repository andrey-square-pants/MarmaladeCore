#include "Error.hpp"

#include <cstdio>
#include <cstring>

#include "s3eTypes.h"

Error::Error(const char* format, ...) {
	if (format == NULL) {
		return;
	}

	static const uint32 MessageSize = 1024;

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
