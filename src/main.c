#include <errno.h>
#include <stdlib.h>

#include "log.h"
#include "network.h"

struct Messenger {
    Network* network;
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

Messenger* new_messenger()
{
    Messenger* messenger = (Messenger*) calloc(1, sizeof(Messenger));

    if (!messenger) {
        return NULL;
    }

    messenger->network = new_network();

    return messenger;
}

void close_messenger(Messenger* messenger)
{
    close_network(messenger->network);
    free(messenger);
}

void add_new_friend() 
{

}

void do_friends() {
    
}

int main() {
    Messenger* messenger = new_messenger();
    LOG_TRACE("UEUEUEUE, %i", 20);
    close_messenger(messenger);
}



