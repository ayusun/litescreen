#ifndef x11__H
#define x11__H
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/XWDFile.h>
#include <X11/extensions/Xfixes.h>
#include <X11/extensions/XShm.h>
#include <X11/Xregion.h>
#include <X11/Xutil.h>
#endif

#include <stdio.h>

#include "lz4.h"

#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdint.h>
#include <math.h>

#include <unistd.h>
#include <sys/time.h>

#ifndef thrift__H
#define thrift__H
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#endif

#undef max
#undef min

#include <sstream>

#ifndef litescreen__H
#define litescreen__H
#include "litescreen.h"
#include "litescreen_constants.h"
#endif

#ifndef node__H
#include "node.h"
#define node__H
#endif

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

using namespace  ::thrift::litescreen;


#ifndef clientnode__H
#define clientnode__H
class ClientNode : public Node {
    public:
        litescreenClient *client;
        litescreenConstants constant;
        DeviceData initialData;
        ImageData img;
        
        ClientNode(char *hostname, long port);
        void bootup();
        void initializeHandshake();
        static void captureAndSend(ClientNode *node);
        //void openCommChannel();
};
#endif
