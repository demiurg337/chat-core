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
    if (fcntl(sock_d, F_SETFL, O_NONBLOCK, 1) == 0) {
        return 0;
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
    /*
    !!!!!!!!!!!!!!!!!!!! 
    FREEEE NET !!!!!!!!!!!!!!!!!!!!
    !!!!!!!!!!!
    */
    struct sockaddr_storage addr;
    memset(&addr, 0, sizeof(sockaddr_storage));
    
    //bind socket to some address and port 



    return net;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_network();
    LOG_TRACE("UEUEUEUE");
}



