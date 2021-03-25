fast-hands
==========

FastHands Thrift RPC Server
C++ implementation

build:
g++ -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -Wall -I/usr/local/include/thrift *.cpp -L/usr/local/lib -lthrift -lthriftnb -levent -o something

don't forget to install Thrift

A.Nikulin
2anikulin@gmail.com

http://habrahabr.ru/post/179235/

