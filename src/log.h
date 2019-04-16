#ifndef C_CHAT_CORE_LOG
#define C_CHAT_CORE_LOG

#include <stdio.h>
#include <time.h>
typedef enum Log_lvl {
    IS_LOG_TRACE,
    IS_LOG_DEBUG,
    IS_LOG_INFO,
    IS_LOG_WARN,
    IS_LOG_ERR
} Log_lvl;

void log(const char* file, int line, const char* func, const char* msg_template, ...);

#define MIN_LOG_LVL IS_LOG_TRACE
#define LOG(level, ...) \
    do { \
        if (level >= MIN_LOG_LVL) {\
            log(__FILE__, __LINE__, __func__, __VA_ARGS__);\
        }\
    } while(0)

#define LOG_TRACE(...) LOG(IS_LOG_TRACE, __VA_ARGS__)
#define LOG_DEBUG(...) LOG(IS_LOG_DEBUG, __VA_ARGS__)
#define LOG_INFO(...)  LOG(IS_LOG_INFO, __VA_ARGS__)
#define LOG_WARN(...)  LOG(IS_LOG_WARN, __VA_ARGS__)
#define LOG_ERR(...)   LOG(IS_LOG_ERR, __VA_ARGS__)

#define LOG_FATAL(...) \
    do {\
        LOG_ERR(__VA_ARGS__); \
        abort();\
    } while(0)



#endif //C_CHAT_CORE_LOG
