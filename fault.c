#include "fault.h"
#include "logger.h"

#include <stdarg.h>
#include <stdlib.h>

void
fault(const char* format, ...) 
{
	if (format[0] == '!') {
		va_list ap;
		va_start(ap, format);
		LOGV(format+1, ap);
		va_end(ap);
	} else {
		va_list ap;
		va_start(ap, format);
		LOGV(format, ap);
		va_end(ap);
		exit(1);
	}
}
