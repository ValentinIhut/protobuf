# Client/Server protobuf event messages

Project has 2 services:  
    - a java client which opens a http port on 9080. The events posted from http are send over a tcp socket to a server on port 9999.  
    - a cpp server which opens a socket on port 9999 and listen for incoming events. Events are saved to a .txt file.
    
## Preconditions

 - java 8 or higher is need
 - a cpp toolchain is needed. (I have used cygwin)
 
For starting cpp server check:
[cpp README.md](cpp_server/README.md)

For starting java client check:
[java README.md](java_client/README.md)

