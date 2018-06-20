#include <iostream>
#include <socket_server.h>

int main() {
    int port = 6664;
    socket_server* sr = new socket_server();
    sr->run(port);
    delete sr;
    return 0;
}