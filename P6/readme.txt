[P6] Using getsockname() and getpeername(), modify TCPEchoClient4.c to print the local and foreign address immediately after connect().


To compile server:

gcc TCPEchoServer4.c DieWithMessage.c -o server

//creates server outputfil

To comile client:

gcc TCPEcoClient4.c DieWithMessage.c -o client
//creats client outputfile

To Run server:

./server.out 7000 (7000 as a port no)


To Run Client:
./client.out 127.0.0.1 hi 7000

//127.0.0.1 is loopback ip i.e. local ip for server we use same machine as server and host.
//7000 is a port no.