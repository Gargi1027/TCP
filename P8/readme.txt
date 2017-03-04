[P8] Using getsockname() and getpeername(), modify TCPEchoServer4.c to print the local and foreign address for the server socket immediately before and after bind() and for the client socket immediately after it’s returned by accept().


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