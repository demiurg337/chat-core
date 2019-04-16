#ifndef C_CHAT_CORE_NETWORK
#define C_CHAT_CORE_NETWORK

typedef struct Socket {
    int f_descriptor;
} Socket;

typedef struct Network {
   int socket_d;
} Network;


Network* new_network();
void close_network(Network* net);



#endif //C_CHAT_CORE_NETWORK
