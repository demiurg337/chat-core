#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

#include "log.h"
#include "network.h"

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
typedef struct Friend {
    //public key
} Friend;
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
typedef struct {
    int size;
    Friend* data;
} FriendsVector;


///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


struct Messenger {
    Network* network;
//net

//dht
//group chats
//friends
//log
//crypto
//options

/*
Saving of friends is in separated way
*/
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

/*api*/
void try_add_friend_with_request(Messenger* messenger, const uint8_t* user_address, const uint8_t* msg) 
{
    //checking of address
    //m_addfriend

    //check address
    // address is id public key
    
    //find user by this id
    // and check is it already 
    // - added
    // - already sent
    // ...


    /// init_new_friend

    //change config for sending the message
    //(it will be in main cicle, in do_friends
}


void init_new_friend() 
{
    //messeger variable with all friends

    /*
    Seems like 
    friendlist is big, big, big pointer !!!!
    */
}

void do_friends() {
    
}

int main() {
    Messenger* messenger = new_messenger();
    char a[5] = {'a', 'v', 'c', 'c', '\0'};
    LOG_TRACE("UEUEUEUE, %s %i", a,  (uint8_t*) a);
    close_messenger(messenger);
}



