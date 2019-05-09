#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>


#include <netinet/in.h>

#include "log.h"
#include "network.h"
#include "friends.h"
#include "messenger.h"


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


