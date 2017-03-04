#include <stdio.h>
#include "Practical.h"
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Port/Service>");

  char *service = argv[1]; // First arg:  local port

  // Create socket for incoming connections
  int servSock = SetupTCPServerSocket(service);
  if (servSock < 0)
    DieWithUserMessage("SetupTCPServerSocket() failed", service);

  for (;;) { // Run forever
    // New connection creates a connected client socket
    int clntSock ; //= AcceptTCPConnection(servSock);

    struct sockaddr_storage clntAddr; // Client address
    // Set length of client address structure (in-out parameter)
    socklen_t clntAddrLen = sizeof(clntAddr);

    // Wait for a client to connect
    clntSock = accept(servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);
    if (clntSock < 0)
      DieWithSystemMessage("accept() failed");

    // clntSock is connected to a client!

    //fputs("Handling client ", stdout);
    //PrintSocketAddress((struct sockaddr *) &clntAddr, stdout);
    //fputc('\n', stdout);

    //HandleTCPClient(clntSock); // Process client

    char buffer[100] = "Connected to server!!! System is On!!!"; // Buffer for echo string


    // Send string and receive again until end of stream
    //while (numBytesRcvd > 0) { // 0 indicates end of stream
      // Echo message back to client
      ssize_t numBytesSent = send(clntSock, buffer, 100*sizeof(char), 0);
      if (numBytesSent < 0)
        DieWithSystemMessage("send() failed");
      else if (numBytesSent != 100*sizeof(char))
        DieWithUserMessage("send()", "sent unexpected number of bytes");
      printf("message to the client: \"%s\" \n", buffer);

      // See if there is more data to receive

    //}

    close(clntSock); // Close client socket

    //close(clntSock);
    break;
  }
  // NOT REACHED
  close(servSock);
}
