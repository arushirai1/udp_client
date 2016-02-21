#include "udp_client.h"
#include "udp_server.h"
#include <iostream>

int main () {
    std::cout << "Test" << std::endl;

    UDP_Client client ("127.0.0.1", 76668);
    std::cout << "created client" << std::endl;
    UDP_Server server ("127.0.0.1", 76668);

    client.addToSendBuffer("test message");
    client.send();
    
    for (;;) {
        server.receive();
    }

    client.end();
    server.end();
    std::cin.get();
    return 0;
}