#include "friends.h"
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

struct Messenger* new_messenger()
{
    struct Messenger* messenger = (struct Messenger*) calloc(1, sizeof(struct Messenger));

    if (!messenger) {
        return NULL;
    }

    messenger->network = new_network();
    init_friends_list(&messenger->friends); 

    return messenger;
}

void close_messenger(struct Messenger* messenger)
{
    close_network(messenger->network);
    free_friends_list(&messenger->friends);
    free(messenger);
}


void send_packet(int from_socket, int port, const char* msg) 
{
    int length = 6;
    size_t address_size = sizeof(struct sockaddr_in6);

    //ipv6
    struct sockaddr_in6 addr6;
    addr6.sin6_family = AF_INET6; 
    addr6.sin6_port = htons(port); 
    addr6.sin6_flowinfo = 0;
    addr6.sin6_scope_id = 0;
    
    //addr6->sin6_addr.s6_addr = htonl( "::");
    addr6.sin6_addr = in6addr_any;
    printf("=============\n\n\n");
    //127.0.0.1
    //addr6->sin6_addr.s6_addr = 5c:f9:dd:53:80:e3;
    int res = sendto(from_socket, msg, 6, 0, (struct sockaddr*) &addr6, sizeof(addr6));
    printf("\n\nres=%i", res);

    //sendto(from_socket,  
}
