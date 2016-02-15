#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <iostream>
#include <netdb.h>
#include <cstring>

//binds to an arbritrary return address (client)
void bindSocket (int s, struct sockaddr_in* myaddr) {
    memset((char *)myaddr, 0, sizeof(*myaddr));
    
    *myaddr.sin_family = AF_INET;
    *myaddr.sin_addr = htonl(INADDR_ANY); //IP address
    *myaddr.sin_port = htons(7848); //socket
    if((bind(s, (struct sockaddr *)myaddr, sizeof(*myaddr))) < 0)
        perror("cannot bind");  
}

void send (struct hostent *h, std::string hostname, std::string message, int socket) {
    struct sockaddr_in servaddr;
    char* m = message;

    int server_port; //put in server port

    //put in server address and data
    std::memset((char*)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(server_port);

    //init_hostent here

    std::copy((void *)&servaddr.sin_addr, h->h_addr_list[0], h->h_length);

    if (sendto(socket, m, strlen(m), 0, (struct sockaddr *)&servaddr, sizeof(serveaddr)) < 0) {
        perror("sendto failed");
        return;
    }
}

void init_hostent (
void send_message (std::string hostname, bool ip_address) {
    struct hostent *h;
    char* host = hostname;
    int i;

    h = gethostbyname(host);
    if (!h) {
        cout << "could not get address of " << hostname;
        return;
    } 
   
    for(i=0; h->h_addr_list[i] != 0; i++)
        paddr((unsigned char*) h->h_addr_list[i]);   
}



int main () {


    return 0;
}
