#ifndef C_CHAT_CORE_FRIENDS
#define C_CHAT_CORE_FRIENDS
#include <stdint.h>
#include "network.h"
#include "messenger.h"

typedef enum {
    REGULAR_FRIEND,
    WAITING_CONFIRMATION_OF_FRIENDSHIP
} Friend_Status;

typedef struct {
    uint8_t public_key;
    Friend_Status status;
} Friend;

typedef struct {
    int _size;
    Friend* data;
} FriendsVector;

struct Messenger {
    Network* network;
    FriendsVector friends;
};

static int set_new_size_friends_list(FriendsVector* friends, int new_size);
static int append_place_to_friends_list(FriendsVector* friends); 
void init_friends_list(FriendsVector* friends);
void free_friends_list(FriendsVector* friends);
void init_new_friend(FriendsVector* friends); 
void try_add_friend_with_request(struct Messenger* messenger/*, const uint8_t* user_address, const uint8_t* msg*/);
#endif //C_CHAT_CORE_FRIENDS
