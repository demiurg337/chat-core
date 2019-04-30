#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>

#include <netinet/in.h>

#include <ncurses.h>

#include "log.h"
#include "network.h"

////////////////////////////////////////
////////////////////////////////////////
// need to move to some utils
// wrappers

void* safe_calloc(size_t count_els, size_t el_size)
{
    void* p = calloc(count_els,  el_size);
    if (!p) {
        LOG_FATAL("Can't get memory !");
    }

    return p;
}

void* safe_realloc(void* ptr, size_t new_size)
{
    void* p = realloc(ptr, new_size);
    if (!p) {
        LOG_FATAL("Can't realloc memory !");
    }

    return p;
}

////////////////////////////////////////
////////////////////////////////////////

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

/*
Return new size
*/
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


bool static append_place_to_friends_list(FriendsVector* friends) {
    //set_new_size_friends_list
    int size_before = friends->_size;
    set_new_size_friends_list(friends, friends->_size + 1);
    return size_before < friends->_size;
}

void init_friends_list(FriendsVector* friends)
{
    friends->_size = 0;
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



void init_new_friend(FriendsVector* friends) 
{
    //messeger variable with all friends


    /*
    Seems like 
    friendlist is big, big, big pointer !!!!
    */
    append_place_to_friends_list(friends);
    friends->data[friends->_size - 1].public_key = 100;
    friends->data[friends->_size - 1].status = REGULAR_FRIEND;
    
    //friends->data[friends-size - 1].public_key = "zzzzzzzzzzzzz";
}

/*api*/
void try_add_friend_with_request(Messenger* messenger/*, const uint8_t* user_address, const uint8_t* msg*/)
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



void do_friends() {
    
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
    initscr();
    printw("HHH");

    /*
    have to use
    refresh
    and after can be used only wrefresh
    */
    refresh();

    WINDOW* msg_win = newwin(20, 150, 1, 3);
    box(msg_win, 0, 0);
    wrefresh(msg_win);

    WINDOW* input_win = newwin(7, 150, 22, 3);
    box(input_win, 0, 0);
    wrefresh(input_win);

    printw("HHH");
    getch();
    endwin();

    /*
    char str[100];
    int port;
    printf("Enter host for sending message:\n\n");
    //fgets(str, 100, stdin);
    scanf("%i", &port);
    
    Messenger* messenger = new_messenger();
    char a[5] = {'a', 'v', 'c', 'c', '\0'};
    LOG_TRACE("UEUEUEUE, %s %i", a,  (uint8_t*) a);
    try_add_friend_with_request(messenger);

    printf("++++++++++++%i", messenger->friends._size);
    int num_received_bytes = 0;
    char msg[10];
    struct sockaddr_in6 addr6_was_sent;
    socklen_t addr_len = sizeof(addr6_was_sent);
    while(1) {
        do_friends();
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
    */
}


