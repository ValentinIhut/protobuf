#include <iostream>
#include <socket_server.h>

int main() {
    int port = 9999;
    string lofFile = "../eventLogs.txt";
    socket_server* sr = new socket_server();
    sr->run(port, lofFile);
    delete sr;
    return 0;
}