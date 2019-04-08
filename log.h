
#include <stdio.h>
#include <time.h>
typedef enum Log_lvl {
    IS_LOG_TRACE,
    IS_LOG_DEBUG,
    IS_LOG_INFO,
    IS_LOG_WARN,
    IS_LOG_ERR
} Log_lvl;

void log(const char* file, int line, const char* func, const char* msg);

#define MIN_LOG_LVL IS_LOG_TRACE
#define LOG(level, msg) \
    do { \
        if (level >= MIN_LOG_LVL) {\
            log(__FILE__, __LINE__, __func__, msg);\
        }\
    } while(0)

#define LOG_TRACE(msg) LOG(IS_LOG_TRACE, msg)
#define LOG_DEBUG(msg) LOG(IS_LOG_DEBUG, msg)
#define LOG_INFO(msg)  LOG(IS_LOG_INFO, msg)
#define LOG_WARN(msg)  LOG(IS_LOG_WARN, msg)
#define LOG_ERR(msg)   LOG(IS_LOG_ERR, msg)

#define LOG_FATAL(msg) \
    do {\
        LOG_ERR(msg);\
        abort();\
    } while(0)



