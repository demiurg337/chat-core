#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

#include "log.h"
#include "network.h"



typedef struct Friend {
    uint8_t public_key;
} Friend;

typedef struct {
    int size;
    Friend* data;
} FriendsVector;


struct Messenger {
    Network* network;
    FriendsVector friends;


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
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


void appenid_to_friends_list() {
    //set_new_size_friends_list
}

void set_new_size_friends_list(int new_size)
{
    /*
    if (friends->size <= 0) {
        if (new_size > 0) {
            init_friends_list(1);
            friends.size++;
        }

        return friends.size;
    } else {
        
    }
    */
}

void init_friends_list(FriendsVector* friends)
{
    friends->size = 0;
    //friends->data = (Friend*) calloc(1, sizeof(Friend));  
    /*
    if (!friends) {
        LOG_FATAL("Can't init friends list !"); 
    }

    */
}


void free_friends_list(FriendsVector* friends)
{
    free(friends->data);
}
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

Messenger* new_messenger()
{
    Messenger* messenger = (Messenger*) calloc(1, sizeof(Messenger));

    if (!messenger) {
        return NULL;
    }

    messenger->network = new_network();
    init_friends_list(&messenger->friends); 

    return messenger;
}

void close_messenger(Messenger* messenger)
{
    close_network(messenger->network);
    free_friends_list(&messenger->friends);
    free(messenger);
}



void init_new_friend() 
{
    //messeger variable with all friends


    /*
    Seems like 
    friendlist is big, big, big pointer !!!!
    */


    //friends->data[friends-size - 1].public_key = "zzzzzzzzzzzzz";
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
    init_new_friend();

    //change config for sending the message
    //(it will be in main cicle, in do_friends
}



void do_friends() {
    
}

int main() {
    Messenger* messenger = new_messenger();
    char a[5] = {'a', 'v', 'c', 'c', '\0'};
    LOG_TRACE("UEUEUEUE, %s %i", a,  (uint8_t*) a);
    close_messenger(messenger);
}



