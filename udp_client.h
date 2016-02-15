#include <string>
#include <queue>
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h> //used for fprintf

#define PORT			5789
#define BUFFER_LENGTH   64 //enter bytes // never used?

using namespace std;
class UDP_Client {
private:
	//DataContainer object
	char recipientAddr[128];
	queue <string> buffer; 
	int udp_socket;
    struct sockaddr_in servaddr;
   	void setup();
   	void bindSocket(int s, struct sockaddr_in* myaddr);	
	void timestamp(string* data, bool add);
	bool validate(string data); //validates the buffer
	string empty(); //empties buffer 

public:
	UDP_Client();
	void send(); //sends the next item in the buffer,  empties it as well
	void addToSendBuffer(string message);
};