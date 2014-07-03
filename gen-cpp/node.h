/**
 * A class Node that act as base class of server and client both
 * It contains hostname and port value as fields
 */
#ifndef node__H
#define node__H 
class Node {
	private:
	    char hostname[16];
	    long port;
	public:
	    Node(char *hostname, long port);
		char *getHostName();
        long getPort();
        virtual void bootup();
};

#endif
