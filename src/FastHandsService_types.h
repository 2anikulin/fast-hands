/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef FastHandsService_TYPES_H
#define FastHandsService_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace fasthands {

typedef struct _InvalidOperation__isset {
  _InvalidOperation__isset() : what(false), why(false) {}
  bool what;
  bool why;
} _InvalidOperation__isset;

class InvalidOperation : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "3F5FC93B338687BC7235B1AB103F47B3";
  static const uint8_t binary_fingerprint[16]; // = {0x3F,0x5F,0xC9,0x3B,0x33,0x86,0x87,0xBC,0x72,0x35,0xB1,0xAB,0x10,0x3F,0x47,0xB3};

  InvalidOperation() : what(0), why() {
  }

  virtual ~InvalidOperation() throw() {}

  int32_t what;
  std::string why;

  _InvalidOperation__isset __isset;

  void __set_what(const int32_t val) {
    what = val;
  }

  void __set_why(const std::string& val) {
    why = val;
  }

  bool operator == (const InvalidOperation & rhs) const
  {
    if (!(what == rhs.what))
      return false;
    if (!(why == rhs.why))
      return false;
    return true;
  }
  bool operator != (const InvalidOperation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InvalidOperation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(InvalidOperation &a, InvalidOperation &b);

} // namespace

#endif