//
// Created by valentin.ihut on 6/20/2018.
//

#ifndef CPP_SERVER_SOCKET_SERVER_H
#define CPP_SERVER_SOCKET_SERVER_H

#include "event.pb.h"
#include <thread>
#include <vector>

class socket_server {

    int port;
    int socketId = 0;
    static const int QUEUE_SIZE = 5;
    static const int BUFFER_SIZE = 1024;
    char buf[BUFFER_SIZE];
    // resolve type, auth, dispatch
    void listenLoop();

public:
    socket_server();
    void run(int port);
    void closeSocket();
    ~socket_server();
};


#endif //CPP_SERVER_SOCKET_SERVER_H
