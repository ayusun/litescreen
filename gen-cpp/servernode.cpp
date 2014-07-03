/**
 * File     : servernode.cpp
 * Purpose  : The File contains the implementation of the class ServerNode. It basically implements
 *            all the function that server is going to use to deal with remote computers data.
 *
 *            To use it create an Object of ServerNode and call the functions. For more information
 *            Checkout servernode.h to view class and the members
 *
 *            It extends Class Node
 *
 *
 * @author : Ayush Choubey(ayush.choubey@gmail.com)
 * @version: 1.0
 */

#include "servernode.h"

/**
 * Its a Constructor. It initializes the IP and port that server will work on and initializes the
   the title bar of the window that opens up as 'user@{ipaddress}'.

   @param hostname Keeps hostname of the host computer
   @param port     Keeps port number that the host computer should bind to
 */
ServerNode :: ServerNode(char *hostname, long port): Node(hostname, port) {
    // Call to the parent constructor
    char usermsg[25] = "user@";
    strcat(usermsg,hostname);
    disp = new CImgDisplay(1024,768,usermsg);
}

/**
 * This boots up the server by initialising various shared pointers and thrift's TSimpleServer
 *
 * @param   node As bootup is static in nature hence the instance is passed so that the server can be
 *               bound to correct instance.
 * @return void
 */
void ServerNode :: bootup(ServerNode *node) {
  int port = node->getPort();
  shared_ptr<ServerNode> handler(node);
  shared_ptr<TProcessor> processor(new litescreenProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
}

/**
 * Initial Handshake sends the client information according to which server will handle rest of the frames
 *
 * @param  data It takes various client information and saves it in a variable which can be used later on
 *
 * @return void
 */
void ServerNode :: initializeHandshake(const DeviceData& data) {
    // Your implementation goes here
    initialData = data;
}
/**
  * It calculates and returns the pixel value at a particular position.
  * Code Source: Modified from XGetPixel

  * @param data Pointer to the data from the client
  * @param x    pixel value at location X
  * @param y    Pixel value at location Y
  * @param byli Number of bytes per line
  * @param bipi Number of bytes per pixel

  * @return long
  */

static unsigned long getPixel (register char *data, int x, int y, int byli, int bipi) {
	unsigned long pixel, px;
	register char *src;
	register char *dst;
	register int i, j;
	int bits, nbytes;
	long plane;

	src = &data[ZINDEX(x, y, byli, bipi)];
		dst = (char *)&px;
		px = 0;
		for (i = (32 + 7) >> 3; --i >= 0; )
		    *dst++ = *src++;
		//_znormalizeimagebits((unsigned char *)(&px));
		//ZNORMALIZE(&px);
		pixel = 0;
		for (i=sizeof(unsigned long); --i >= 0; )
		    pixel = (pixel << 8) | ((unsigned char *)&px)[i];
		return pixel;
}

/**
 * All the images sent from client are handled in this function
 *
 * @param img Contains all of the image data(ImageData) from the client machine
 *
 * @return void
 */
void ServerNode :: sendImage(const ImageData& img) {
    // Your implementation goes here
    char *compressedImage   = new char[img.compressed_size];
    memcpy(compressedImage, img.data.data(), img.compressed_size);
      
    char *buffer = new char[img.orig_size];
    int decompress_size = LZ4_decompress_safe (compressedImage, buffer, img.compressed_size, img.orig_size);
      
    unsigned char *array = new unsigned char[img.orig_size];
    CImg<> pic(array,initialData.width,initialData.height,1,4);    
    unsigned long red_mask = 0xFF0000;   // rgb(255,0,0) = 0xFF0000
    unsigned long green_mask = 0xFF00;   // rgb(0,255,0) = 0x00FF00
    unsigned long blue_mask = 0xFF;      // rgb(0,0,255) = 0x0000FF
    
    for (int x = 0; x < initialData.width; x++) {
        for (int y = 0; y < initialData.height ; y++)
        {
            unsigned long pixel = getPixel(buffer,x,y, initialData.bytes_per_line, initialData.bits_per_pixel);
            unsigned char blue = pixel & blue_mask;
            unsigned char green = (pixel & green_mask) >> 8;
            unsigned char red = (pixel & red_mask) >> 16;
            
            pic(x,y,0,0) = red;
            pic(x,y,0,1) = green;
            pic(x,y,0,2) = blue;
        }
    }
    disp->display(pic);
}

