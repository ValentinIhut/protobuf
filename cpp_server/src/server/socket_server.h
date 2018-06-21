//
// Created by valentin.ihut on 6/20/2018.
//

#ifndef CPP_SERVER_SOCKET_SERVER_H
#define CPP_SERVER_SOCKET_SERVER_H

#include "event.pb.h"
#include <thread>
#include <vector>
#include <fstream>

using namespace std;

class socket_server {

    int port;
    int socketId = 0;
    static const int QUEUE_SIZE = 5;
    static const int BUFFER_SIZE = 4096;
    char buf[BUFFER_SIZE];
    ofstream outfile;
    // resolve type, auth, dispatch
    void listenLoop();

public:
    socket_server();
    void run(int port, string filename);
    void closeSocket();
    ~socket_server();
};


#endif //CPP_SERVER_SOCKET_SERVER_H
