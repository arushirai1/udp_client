#include "udp_server.h"
#include "udp_client.h"

class Communication {
private:
	UDP_Client client;
	UDP_Server server;
public:
	Communication ();
};

Communication::Communication() {
	
}

