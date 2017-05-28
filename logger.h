#ifdef __cplusplus
extern "C"
{
#endif

#ifndef logger_h
#define logger_h

#define LOG_TAG "=== logger ==="

#include <stdio.h>

#ifndef NDEBUG

#ifdef __ANDROID__

#include <android/log.h>
#define LOGD(...)		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...)		__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGW(...)		__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGV(fmt, ap)	__android_log_vprint(ANDROID_LOG_INFO, LOG_TAG, (fmt), (ap))

#else

#define LOGD(fmt, ...)	printf("%s [%s] " fmt "\n", LOG_TAG, "debug", __VA_ARGS__)
#define LOGI(fmt, ...)	printf("%s [%s] " fmt "\n", LOG_TAG, "info", __VA_ARGS__)
#define LOGE(fmt, ...)	printf("%s [%s] " fmt "\n", LOG_TAG, "error", __VA_ARGS__)
#define LOGW(fmt, ...)	printf("%s [%s] " fmt "\n", LOG_TAG, "warn", __VA_ARGS__)
#define LOGV			vprintf

#endif // __ANDROID__

#else

#define LOGD(fmt, ...)
#define LOGI(fmt, ...)
#define LOGE(fmt, ...)
#define LOGW(fmt, ...)
#define LOGV

#endif // DEBUG

struct logger {
	FILE* f;
};

void logger_init(struct logger*, FILE* f);
void logger_printf(struct logger*, const char* fmt, ...);

#endif // logger_h

#ifdef __cplusplus
}
#endif