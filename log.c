#include <stdio.h>
#include <time.h>
#include <log.h>


void log(const char* file, int line, const char* func, const char* msg) {
    time_t t_raw;
    struct tm * t_info;

    time(&t_raw);
    t_info = localtime(&t_raw);

    printf("%s   %s:%i;%s: %s\n", asctime(t_info), file, line, func, msg);
}


////////////////////////////////////
