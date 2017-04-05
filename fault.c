#include "fault.h"
#include "logger.h"

#include <stdarg.h>
#include <stdlib.h>

#ifdef _DEBUG

static void panic() { int *p = 0; *p = 1; }

#else

static void panic() { exit(1); }

#endif

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
		panic();
	}
}
