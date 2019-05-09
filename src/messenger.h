
#include "friends.h"
#include "network.h"


struct Messenger* new_messenger();
void close_messenger(struct Messenger* messenger);
void send_packet(int from_socket, int port);
