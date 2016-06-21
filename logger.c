#include "logger.h"

#include <stdarg.h>
#include <string.h>

// static char LOG_FILENAME[255] = "_logger";

void 
logger_init(struct logger* logger, FILE* f) {
	logger->f = f;
}

void 
logger_printf(struct logger* logger, const char* fmt, ...) {
	if (logger->f) {
		va_list ap;
		va_start(ap, fmt);
		LOGV(fmt, ap);
		va_end(ap);
	}
}