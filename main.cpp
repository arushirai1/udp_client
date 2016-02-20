#include "udp_client.h"
#include "udp_server.h"
//#include <iostream>

int main () {
    UDP_Client client ("127.0.0.1", 7689);
    UDP_Server server ("127.0.0.1", 7689);

    client.addToSendBuffer("test message");
    client.send();
    
    for (;;) {
        server.receive();
    }

    client.end();
    server.end();

    return 0;
}