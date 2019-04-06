#include <sys/socket.h>
#include <netinet/in.h>

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

struct Network {
    Socket socket;
};

void new_network()
{
    //if it isn't ip4 and ip6
    //checking

}

Socket new_socket() {
    //see UDP hole punching
    Socket sock = {(int) socket(AF_UNSPEC, SOCK_DGRAM, IPPROTO_UDP)};
    return sock; 
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main() {
    new_socket();
}



