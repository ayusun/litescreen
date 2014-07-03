// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "litescreen.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::thrift::litescreen;

class litescreenHandler : virtual public litescreenIf {
 public:
  litescreenHandler() {
    // Your initialization goes here
  }

  void initializeHandshake(const DeviceData& data) {
    // Your implementation goes here
    printf("initializeHandshake\n");
  }

  void sendImage(const ImageData& data) {
    // Your implementation goes here
    printf("sendImage\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<litescreenHandler> handler(new litescreenHandler());
  shared_ptr<TProcessor> processor(new litescreenProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

