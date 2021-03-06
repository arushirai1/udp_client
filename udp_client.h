#ifndef __INTERCHANGE_UDP_CLIENT_H
#define __INTERCHANGE_UDP_CLIENT_H

#include <queue>
#include <string>
#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h> //used for fprintf
#include <netdb.h>
#include <iostream>

//#include "..\Buffer.h"
//#include "..\Datum.h"

#define BUFFER_SIZE 64 //needs to be changed

using namespace std;

/*
* @author Arushi Rai
*/

class UDP_Client {
private:
	char recipientAddr[32];
	queue<string> buffer; 

	int udp_socket;
	int PORT;
	struct sockaddr_in servaddr;
	struct sockaddr_in myaddr;

   	void setup();
   	void bindSocket();	
	//void timestamp(Datum* data, bool add);
	bool validate(string data); //validates the buffer
	//string empty(); //empties buffer 

public:
	UDP_Client(string address, int port);
	void send(); //sends the next item in the buffer,  empties it as well
	void addToSendBuffer(string message);
	void end();
};

#endif