
typedef struct Socket {
    int f_descriptor;
} Socket;

typedef struct Network {
   int socket_d;
} Network;


Network* new_network();
int close_network(Network* net);
