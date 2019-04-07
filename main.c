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
    //see UDP hole punching
    Socket sock = {(int) socket(AF_UNSPEC, SOCK_DGRAM, IPPROTO_UDP)};
    return sock; 
}

typedef struct Network {
    Socket socket;
} Network;

Network new_network()
{
    //if it isn't ip4 and ip6
    //checking

    //Network* net = (Network*) calloc(1, sizeof(Network));
    Network net = {new_socket()};
    return net;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_socket();
}



