#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <log.h>
#include <fcntl.h>
#include <string.h>

struct messenger {
//net

//dht
//group chats
//friends
//log
//crypto
//options
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
////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
//Network
struct Ip {
};

typedef struct Socket {
    int f_descriptor;
} Socket;


int new_socket() {
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

    //make socket not blocking
    if (fcntl(sock_d, F_SETFL, O_NONBLOCK, 1) < 0) {
        return -1;
    }
    
    return sock_d; 
}

typedef struct Network {
   int socket_d;
} Network;

Network* new_network()
{
    //if it isn't ip4 and ip6
    //checking

    //Network* net = (Network*) calloc(1, sizeof(Network));
    Network* net = (Network*) calloc(1, sizeof(Network));
    net->socket_d = new_socket();
    if (net->socket_d < 0) {
        LOG_FATAL("Cant create socket !");
    }
    /*
    !!!!!!!!!!!!!!!!!!!! 
    FREEEE NET !!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!
    */
    struct sockaddr_storage addr;
    memset(&addr, 0, sizeof(sockaddr_storage));
    
    //bind socket to some address and port 
    //will use ip6
    struct sockaddr_in6* addr6 = (struct sockaddr_in6*) &addr;
    addr6->sin6_family = AF_INET6;
    // can be without htonl and htons, 
    // but they were added for understanding process
    // all need to convert to "network" format (by for "0" it can be without it)
    addr6->sin6_port = htons(0);
    // for ipv4 can be
    // sin6.sin6_addr = INADDR_ANY_INIT 
    //servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr6->sin6_addr = in6addr_any; 
    //???
    addr6->sin6_flowinfo = 0;
    addr6->sin6_scope_id = 0;

    int 
        v6only_need_val = 0,
        v6only_val = 0;
        socklen_t v6only_optsize = sizeof (v6only_val);
    if (
        getsockopt(net->socket_d, IPPROTO_IPV6, IPV6_V6ONLY, &v6only_val, &v6only_optsize) == 0
        &&
        v6only_val != v6only_need_val
    ) {
        v6only_val = v6only_need_val;
        setsockopt(net->socket_d, IPPROTO_IPV6, IPV6_V6ONLY, &v6only_need_val, sizeof(v6only_need_val));
    }



    return net;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_network();
    LOG_TRACE("UEUEUEUE");
}



