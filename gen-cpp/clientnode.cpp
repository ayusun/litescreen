/**
 * File     : clientnode.cpp
 * Purpose  : The File contains the implementation of the class ClientNode. It basically implements
 *            all the function that class is going to use to send data t remote computer.
 *
 *            To use it create an Object of ClientNode and call the functions. For more information
 *            Checkout clientnode.h to view class and the members
 *
 *            It Extends Node Class
 *
 *
 * @author : Ayush Choubey(ayush.choubey@gmail.com)
 * @version: 1.0
 */

#include "clientnode.h"
#include <CImg.h>

using namespace cimg_library;
/**
 *  Constructor. Used to initialize hostname and port
 */
ClientNode :: ClientNode(char *hostname, long port): Node(hostname, port) {
    // Call to the parent constructor
}

/**
 * Boots up the client. Uses hostname and port number of the remote computer and
 * opens a connection. If opened, all is well, else throw an error
 *
 * @return void
 */
void ClientNode :: bootup() {		
  boost::shared_ptr<TTransport> socket(new TSocket(this->getHostName(), this->getPort()));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  client = new litescreenClient(protocol);
  try {
      transport ->open();
  } catch(TException &tx) {
      printf("ERROR: %s\n", tx.what());
  }
}

/**
 * Collects one frame and then send all the data along with the client type to
 * remote machine, so that remote machine can know what kind of data it should expect.
 *
 * @return void
 */
void ClientNode :: initializeHandshake() {
	//DeviceData initialData;
	#ifdef __linux__
	Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);

	XImage *image = XGetImage(display,root, 0,0 , gwa.width,gwa.height,AllPlanes, ZPixmap);
	initialData.width          = gwa.width;
	initialData.height         = gwa.height;
	initialData.depth          = image->depth;
	initialData.bits_per_pixel = image->bits_per_pixel;
	initialData.bytes_per_line = image->bytes_per_line;
	initialData.byteorder      = image->byte_order;
	initialData.fromDevice     = constant.FROM_LINUX;
    client->initializeHandshake(initialData);
	#endif
}

/**
 * Collects frame continously and send it to remote computer after compressing using LZ4
 *
 * @param clientnode Since the function is static type and hence its
                     necessary to know to call this function from which variable.

 * @return void
 */
void ClientNode :: captureAndSend(ClientNode *clientnode) {
    #ifdef __linux__
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    char *destData;


    int i=1;
    while(i<=50) {
        XImage *image    = XGetImage(display,root, 0,0 , clientnode->initialData.width,clientnode->initialData.height,AllPlanes, ZPixmap);
        int originalSize = clientnode->initialData.bytes_per_line * clientnode->initialData.height;
        destData = new char[originalSize];

        // Compressing image data
        int compressedSize =  LZ4_compress(image->data, destData, originalSize);
        ostringstream s;
        s.write(destData, originalSize);

        // Writing to image data
        clientnode->img.orig_size    = originalSize;
        clientnode->img.data = s.str();
        clientnode->img.compressed_size = compressedSize;

        clientnode->client->sendImage(clientnode->img);

        // Code to free some memory
        XDestroyImage(image);
        free(destData);
        s.flush();
        i++;
    }
	#endif
	
}
