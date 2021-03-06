/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef litescreen_H
#define litescreen_H

#include <thrift/TDispatchProcessor.h>
#include "litescreen_types.h"

namespace thrift { namespace litescreen {

class litescreenIf {
 public:
  virtual ~litescreenIf() {}
  virtual void initializeHandshake(const DeviceData& data) = 0;
  virtual void sendImage(const ImageData& data) = 0;
};

class litescreenIfFactory {
 public:
  typedef litescreenIf Handler;

  virtual ~litescreenIfFactory() {}

  virtual litescreenIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(litescreenIf* /* handler */) = 0;
};

class litescreenIfSingletonFactory : virtual public litescreenIfFactory {
 public:
  litescreenIfSingletonFactory(const boost::shared_ptr<litescreenIf>& iface) : iface_(iface) {}
  virtual ~litescreenIfSingletonFactory() {}

  virtual litescreenIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(litescreenIf* /* handler */) {}

 protected:
  boost::shared_ptr<litescreenIf> iface_;
};

class litescreenNull : virtual public litescreenIf {
 public:
  virtual ~litescreenNull() {}
  void initializeHandshake(const DeviceData& /* data */) {
    return;
  }
  void sendImage(const ImageData& /* data */) {
    return;
  }
};

typedef struct _litescreen_initializeHandshake_args__isset {
  _litescreen_initializeHandshake_args__isset() : data(false) {}
  bool data;
} _litescreen_initializeHandshake_args__isset;

class litescreen_initializeHandshake_args {
 public:

  static const char* ascii_fingerprint; // = "E484B97155ACCF7A86515159D956EC59";
  static const uint8_t binary_fingerprint[16]; // = {0xE4,0x84,0xB9,0x71,0x55,0xAC,0xCF,0x7A,0x86,0x51,0x51,0x59,0xD9,0x56,0xEC,0x59};

  litescreen_initializeHandshake_args() {
  }

  virtual ~litescreen_initializeHandshake_args() throw() {}

  DeviceData data;

  _litescreen_initializeHandshake_args__isset __isset;

  void __set_data(const DeviceData& val) {
    data = val;
  }

  bool operator == (const litescreen_initializeHandshake_args & rhs) const
  {
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const litescreen_initializeHandshake_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const litescreen_initializeHandshake_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_initializeHandshake_pargs {
 public:

  static const char* ascii_fingerprint; // = "E484B97155ACCF7A86515159D956EC59";
  static const uint8_t binary_fingerprint[16]; // = {0xE4,0x84,0xB9,0x71,0x55,0xAC,0xCF,0x7A,0x86,0x51,0x51,0x59,0xD9,0x56,0xEC,0x59};


  virtual ~litescreen_initializeHandshake_pargs() throw() {}

  const DeviceData* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_initializeHandshake_result {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  litescreen_initializeHandshake_result() {
  }

  virtual ~litescreen_initializeHandshake_result() throw() {}


  bool operator == (const litescreen_initializeHandshake_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const litescreen_initializeHandshake_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const litescreen_initializeHandshake_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_initializeHandshake_presult {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~litescreen_initializeHandshake_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _litescreen_sendImage_args__isset {
  _litescreen_sendImage_args__isset() : data(false) {}
  bool data;
} _litescreen_sendImage_args__isset;

class litescreen_sendImage_args {
 public:

  static const char* ascii_fingerprint; // = "1C73432DEA07DD0AA65CCCB056297885";
  static const uint8_t binary_fingerprint[16]; // = {0x1C,0x73,0x43,0x2D,0xEA,0x07,0xDD,0x0A,0xA6,0x5C,0xCC,0xB0,0x56,0x29,0x78,0x85};

  litescreen_sendImage_args() {
  }

  virtual ~litescreen_sendImage_args() throw() {}

  ImageData data;

  _litescreen_sendImage_args__isset __isset;

  void __set_data(const ImageData& val) {
    data = val;
  }

  bool operator == (const litescreen_sendImage_args & rhs) const
  {
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const litescreen_sendImage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const litescreen_sendImage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_sendImage_pargs {
 public:

  static const char* ascii_fingerprint; // = "1C73432DEA07DD0AA65CCCB056297885";
  static const uint8_t binary_fingerprint[16]; // = {0x1C,0x73,0x43,0x2D,0xEA,0x07,0xDD,0x0A,0xA6,0x5C,0xCC,0xB0,0x56,0x29,0x78,0x85};


  virtual ~litescreen_sendImage_pargs() throw() {}

  const ImageData* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_sendImage_result {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

  litescreen_sendImage_result() {
  }

  virtual ~litescreen_sendImage_result() throw() {}


  bool operator == (const litescreen_sendImage_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const litescreen_sendImage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const litescreen_sendImage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class litescreen_sendImage_presult {
 public:

  static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
  static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


  virtual ~litescreen_sendImage_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class litescreenClient : virtual public litescreenIf {
 public:
  litescreenClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  litescreenClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void initializeHandshake(const DeviceData& data);
  void send_initializeHandshake(const DeviceData& data);
  void recv_initializeHandshake();
  void sendImage(const ImageData& data);
  void send_sendImage(const ImageData& data);
  void recv_sendImage();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class litescreenProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<litescreenIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (litescreenProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_initializeHandshake(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendImage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  litescreenProcessor(boost::shared_ptr<litescreenIf> iface) :
    iface_(iface) {
    processMap_["initializeHandshake"] = &litescreenProcessor::process_initializeHandshake;
    processMap_["sendImage"] = &litescreenProcessor::process_sendImage;
  }

  virtual ~litescreenProcessor() {}
};

class litescreenProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  litescreenProcessorFactory(const ::boost::shared_ptr< litescreenIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< litescreenIfFactory > handlerFactory_;
};

class litescreenMultiface : virtual public litescreenIf {
 public:
  litescreenMultiface(std::vector<boost::shared_ptr<litescreenIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~litescreenMultiface() {}
 protected:
  std::vector<boost::shared_ptr<litescreenIf> > ifaces_;
  litescreenMultiface() {}
  void add(boost::shared_ptr<litescreenIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void initializeHandshake(const DeviceData& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeHandshake(data);
    }
    ifaces_[i]->initializeHandshake(data);
  }

  void sendImage(const ImageData& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendImage(data);
    }
    ifaces_[i]->sendImage(data);
  }

};

}} // namespace

#endif
