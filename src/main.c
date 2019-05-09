#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>

#include <netinet/in.h>

#include "log.h"
#include "network.h"
#include "friends.h"



///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

/*
Return new size
*/



///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

/*

tox_iterate

I -> messager
-> friends (list of users) 
-> rooms (list of users) 

user
-> name
*/

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








void send_packet(int from_socket, int port) 
{
    const char* msg = "qwert";
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

void processing_of_request()
{
    
}

int main() {
    char str[100];
    int port;
    printf("Enter host for sending message:\n\n");
    //fgets(str, 100, stdin);
    scanf("%i", &port);
    
    struct Messenger* messenger = new_messenger();
    char a[5] = {'a', 'v', 'c', 'c', '\0'};
    LOG_TRACE("UEUEUEUE, %s %i", a,  (uint8_t*) a);
    try_add_friend_with_request(messenger);

    printf("++++++++++++%i", messenger->friends._size);
    int num_received_bytes = 0;
    char msg[10];
    struct sockaddr_in6 addr6_was_sent;
    socklen_t addr_len = sizeof(addr6_was_sent);
    while(1) {
        printf("\n\n=======\n\n");
        send_packet(messenger->network->socket_d, port);
        //send_packet(m->socket_d);
        //usleep(20000);//0.02
        
        num_received_bytes = recvfrom(messenger->network->socket_d, msg, 10, 0, (struct sockaddr*) &addr6_was_sent, &addr_len);
        if (num_received_bytes > 0) {
            printf("\n\nReceived message: %s", msg);
        } else if(num_received_bytes == -1) {

            printf("Error has been occured: %s", strerror(errno));
        }

        usleep(2000000);
    }

    close_messenger(messenger);
}


