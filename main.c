#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

struct messenger {
//net

//dht
//group chats
//friends
//log
//crypto
//options
};


struct Ip {
};


/*

tox_iterate

I -> messager
-> friends (list of users) 
-> rooms (list of users) 

user
-> name


*/

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//logger
#include <stdio.h>
#include <time.h>

typedef enum Log_lvl {
    IS_LOG_TRACE,
    IS_LOG_DEBUG,
    IS_LOG_INFO,
    IS_LOG_WARN,
    IS_LOG_ERR
} Log_lvl;

void log(const char* file, int line, const char* func, const char* msg) {
    time_t t_raw;
    struct tm * t_info;

    time(&t_raw);
    t_info = localtime(&t_raw);

    printf("%s   %s:%i;%s: %s\n", asctime(t_info), file, line, func, msg);
}


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



////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Network

typedef struct Socket {
    int f_descriptor;
} Socket;


Socket new_socket() {
    //see UDP hole punching
    int sock_d = (int) socket(AF_UNSPEC, SOCK_DGRAM, IPPROTO_UDP);
    int max_buf = 1024 * 1024 * 2;//2 Megabites
    //set max buffer size
    setsockopt(sock_d, SOL_SOCKET, SO_RCVBUF, &max_buf, sizeof(max_buf)); 
    //max send buffer size
    setsockopt(sock_d, SOL_SOCKET, SO_SNDBUF, &max_buf, sizeof(max_buf)); 

    int is_enabled = 1;
    //enable broadcast (shorokoveshatelniu) address (only for udp)
    setsockopt(sock_d, SOL_SOCKET, SO_BROADCAST, &is_enabled, sizeof(is_enabled)); 

    Socket sock = {sock_d};
    return sock; 
}

typedef struct Network {
    Socket socket;
} Network;

Network* new_network()
{
    //if it isn't ip4 and ip6
    //checking

    //Network* net = (Network*) calloc(1, sizeof(Network));
    Network* net = (Network*) calloc(1, sizeof(Network));
    net->socket = new_socket();
    /*
    !!!!!!!!!!!!!!!!!!!! 
    FREEEE NET !!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!
    */
    

    return net;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_network();
    LOG_TRACE("UEUEUEUE");
}



