#pragma once

#define TMB_DEBUG_LOGS 1

#ifdef TMB_DEBUG_LOGS
// YES LOGS
#	ifdef ANDROID
	// LOGS ANDROID
#		include <android/log.h>
#		define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,__VA_ARGS__)
#		define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG,__VA_ARGS__)
#		define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , LOG_TAG,__VA_ARGS__)
#		define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , LOG_TAG,__VA_ARGS__)
#		define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , LOG_TAG,__VA_ARGS__)
#	else
	// LOGS NO ANDROID (fprintf)
		#include <stdio.h>
		#include <time.h>

		//cuidado con esto si en algún momento hacemos multithreading!!!
		static char buff[100];
		static struct tm *sTm;
		static time_t now;
#		define PRINT_TIME {now = time(0); sTm = localtime(&now); strftime(buff, sizeof(buff), "[%Y-%m-%d %H:%M:%M]", sTm); fprintf(stderr, "%s ", buff); }
#		define LOGV(...) {PRINT_TIME fprintf(stderr, "[V][%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");}
#		define LOGD(...) {PRINT_TIME fprintf(stderr, "[D][%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");}
#		define LOGI(...) {PRINT_TIME fprintf(stderr, "[I][%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");}
#		define LOGW(...) {PRINT_TIME fprintf(stderr, "[W][%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");}
#		define LOGE(...) {PRINT_TIME fprintf(stderr, "[E][%s] ", LOG_TAG); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n");}
#	endif // ANDROID
#else
// NO LOGS
#	define LOGV(...)
#	define LOGD(...)
#	define LOGI(...)
#	define LOGW(...)
#	define LOGE(...)
#endif // TMB_DEBUG_LOGS
