# Cpp protobuf events receive server

C++ server listening on predefined port and receiving protobuf messages form client.

## Usage

To start te server application you need a c++ compiler

### On windows

* install cygwin with g++, gdb, cmake, protobuf libraries
* Build project with:  ```<cygwin root>\bin\cmake.exe --build ../cpp_server/cmake-build-debug --target cpp_server -- -j 4 ```
* Run server app by execution:  ``` <project root>\cpp_server\cmake-build-debug\cpp_server.exe ```
* Application will listen on ```port:9999 ``` and logs the data in ```<project root>\eventLogs.txt```

*I have used CLion IDE for developing and executing the service*

### On macOS

Use following calls to start the service:
```
brew install cmake
brew install protobuf
```

From inside *<project root>* execute
```
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
```