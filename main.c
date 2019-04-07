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
//Network

typedef struct Socket {
    int f_descriptor;
} Socket;


Socket new_socket() {
    int sock_d = (int) socket(AF_UNSPEC, SOCK_DGRAM, IPPROTO_UDP);
    int max_buf = 1024 * 1024 * 2;//2 Megabites
    //set max buffer size
    setsockopt(sock_d, SOL_SOCKET, SO_RCVBUF, &max_buf, sizeof(max_buf)); 
    //max send buffer size
    setsockopt(sock_d, SOL_SOCKET, SO_SNDBUF, &max_buf, sizeof(max_buf)); 

    int is_enabled = 1;
    //enable broadcast (shorokoveshatelniu) address (only for udp)
    setsockopt(sock_d, SOL_SOCKET, SO_BROADCAST, &is_enabled, sizeof(is_enabled)); 

    //see UDP hole punching
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

    

    return net;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_network();
}



