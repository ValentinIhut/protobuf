//
// Created by valentin.ihut on 6/20/2018.
//

#include "socket_server.h"
#include "event.pb.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>


using std::cerr;
using std::endl;
using std::cout;

using namespace std;


socket_server::socket_server(){
}

socket_server::~socket_server() {
    closeSocket();
}

void socket_server::run(int port) {
    this->port = port;

    socketId = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if(socketId == -1)
        throw std::runtime_error("Failed to open socket");

    auto serverAddr = sockaddr_in{0};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(port);

    int rc = bind(socketId, (sockaddr*)&serverAddr, sizeof(sockaddr));
    if(rc == -1)
        throw std::runtime_error("Failed to bind socket");

    rc = listen(socketId, QUEUE_SIZE);
    if(rc == -1)
        throw std::runtime_error("Failed to listen socket");
    cout << "Start server at " << port << endl;

    listenLoop();
}

void socket_server::listenLoop() {
    sockaddr_in addr;
    socklen_t addrSize;
    while (true) {
        int connectId = accept(socketId, (sockaddr*)(&addr), &addrSize);
        if (connectId == -1) {
            cerr << "Failed to accept a request" << endl;
            continue;
        }
        cerr << "Accept " << connectId << " from " << inet_ntoa(addr.sin_addr) << endl;

        int len = recv(connectId, buf, BUFFER_SIZE, 0);
        buf[len] = '\0';
        string a = buf;
        cout << "You got a message from " << inet_ntoa(addr.sin_addr) << endl;

        // Receive  msg from clients
        event::Event ev;
        ev.ParseFromString(a);
        cout << "Event:\t" << endl;
        cout << "timestamo:\t" << ev.timestamp() << endl;
        cout << "UserId:\t" << ev.user_id() << endl;
        cout << "Message:\t" << ev.event() << endl;
    }
}

void socket_server::closeSocket() {
    if(socketId)
        close(socketId);
    socketId = 0;
}
