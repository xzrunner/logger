#ifndef logger_h
#define logger_h

#define LOG_TAG "=== logger ==="

#ifdef __ANDROID__

	#include <android/log.h>
	#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
	#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
	#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#else

	#include <stdio.h>
	#define LOGD(...) printf(LOG_TAG, __VA_ARGS__)
	#define LOGI(...) printf(LOG_TAG, __VA_ARGS__)
	#define LOGE(...) printf(LOG_TAG, __VA_ARGS__)

#endif // __ANDROID__

#endif // logger_h