#include <stdio.h>
#include <time.h>
#include <log.h>
#include <stdarg.h>


void log(const char* file, int line, const char* func, const char* msg_template, ...) {
    time_t t_raw;
    struct tm * t_info;

    time(&t_raw);
    t_info = localtime(&t_raw);

    va_list msg_params;
    va_start(msg_params, msg_template);
    vprintf(msg_template, msg_params);
    va_end(msg_params);

    //printf("%s   %s:%i;%s: %s\n", asctime(t_info), file, line, func, msg);
}
