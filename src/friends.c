#include "friends.h"
#include "log.h"
#include "utils.h"

static int set_new_size_friends_list(FriendsVector* friends, int new_size)
{
    if (new_size < 0) {
        LOG_FATAL("Size can't be less than 0 !");
    }

    if (new_size > 0) {
        if (friends->_size == 0) {
            friends->data = (Friend*) safe_calloc(new_size, sizeof(Friend)); 
        } else {
            friends->data = (Friend*) safe_realloc(friends->data, new_size * sizeof(Friend)); 
            if (new_size > friends->_size) {
                memset(&friends->data[friends->_size], 0, (new_size - friends->_size) * sizeof(Friend));
            }
        }

    } else {
    }

    friends->_size = new_size;
    return new_size;
}

static int append_place_to_friends_list(FriendsVector* friends) 
{
    //set_new_size_friends_list
    int size_before = friends->_size;
    set_new_size_friends_list(friends, friends->_size + 1);
    return size_before < friends->_size ? 1 : 0;
}

void init_friends_list(FriendsVector* friends)
{
    friends->_size = 0;
}

void free_friends_list(FriendsVector* friends)
{
    free(friends->data);
}


void init_new_friend(FriendsVector* friends) 
{
    append_place_to_friends_list(friends);
    friends->data[friends->_size - 1].public_key = 100;
    friends->data[friends->_size - 1].status = REGULAR_FRIEND;
}


void try_add_friend_with_request(struct Messenger* messenger/*, const uint8_t* user_address, const uint8_t* msg*/)
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
    init_new_friend(&messenger->friends);

    //change config for sending the message
    //(it will be in main cicle, in do_friends
}
