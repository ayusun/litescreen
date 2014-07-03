/**
 * File     : node.cpp
 * Purpose  : The File contains the implementation of the class Node. It basically implements
 *            all the function to store and retrieve Ipaddress and port number.
 *
 *            The class ServerNode and ClientNode Extend this class
 *
 *
 * @author : Ayush Choubey(ayush.choubey@gmail.com)
 * @version: 1.0
 */

#include "node.h"
#include <string.h>

/** Constructor for the Node class. It initializes the hostname and port
 *  @param hostname IP of the Host/Remote Computer
 *  @param port     Port number of the Host/Remote Computer
 */
Node ::Node(char *hostname, long port) {
	strcpy(this->hostname,hostname);
	this->port = port;
}

/** Hostname Getter
 *
 *  @return char *(Pointer to character array)
 */
char * Node :: getHostName(){
    return this->hostname;
}

/** Port Number Getter
 *
 *  @return Long
 */
long Node :: getPort(){
    return this->port;
}

// Blank implementation
void Node :: bootup(){
}
