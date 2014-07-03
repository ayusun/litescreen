#ifndef litescreen__H
#define litescreen__H
#include "litescreen.h"
#include "litescreen_constants.h"
#endif

#ifndef thrift__H
#define thrift__H
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#endif

#include "lz4.h"
#include <CImg.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace cimg_library;

using namespace  ::thrift::litescreen;

#ifndef node__H
#include "node.h"
#define node__H
#endif

#ifndef servernode__H
#define servernode__H
class ServerNode : virtual public litescreenIf,public Node {
    public:
        DeviceData initialData;
        CImgDisplay *disp;
        ServerNode(char *hostname, long port);
        static void bootup(ServerNode *node);
        void initializeHandshake(const DeviceData& data);
        void sendImage(const ImageData& data);
        
        #define ZINDEX(x, y, byli, bipi) ((y) * byli) + (((x) * bipi) >> 3)
};
#endif
