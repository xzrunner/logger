#ifdef __cplusplus
extern "C"
{
#endif

#ifndef logger_h
#define logger_h

#define LOG_TAG "=== logger ==="

#include <stdio.h>

#ifdef __ANDROID__

#include <android/log.h>
#define LOGD(...)		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...)		__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGW(...)		__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGV(fmt, ap)	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, (fmt), (ap))

#else

#define LOGD(...)		printf(LOG_TAG, __VA_ARGS__)
#define LOGI(...)		printf(LOG_TAG, __VA_ARGS__)
#define LOGE(...)		printf(LOG_TAG, __VA_ARGS__)
#define LOGW(...)		printf(LOG_TAG, __VA_ARGS__)
#define LOGV			vprintf

#endif // __ANDROID__

struct logger {
	FILE* f;
};

void logger_init(struct logger*, FILE* f);
void logger_printf(struct logger*, const char* fmt, ...);

#endif // logger_h

#ifdef __cplusplus
}
#endif