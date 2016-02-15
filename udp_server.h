#include <string>
#include <queue>
#include "string.h"

#define PORT			5789
#define BUFFER_LENGTH   64 //enter bytes

using namespace std;
class UDP_Server {
private:
	//DataContainer object
	char recipientAddr[128];
	int server_socket;
	queue <string> buffer;
	void start();	
	void timestamp(string* data, bool add);
	bool validate(string data); //validates the buffer

public:
	UDP_Server(char recipientAddr[128]);
	void receive();
	string empty(); //empties buffer //use a more intuitive name
};