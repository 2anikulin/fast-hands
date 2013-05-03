//============================================================================
// Name        : FastHands.cpp
// Author      : A. Nikulin
// Version     : 1.0 (02.05.2013)
// Description : FastHands Thrift-RPC Server
//============================================================================

#include <stdint.h>
#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>
#include <server/TNonblockingServer.h>
#include <transport/TServerSocket.h>
#include <transport/TTransportUtils.h>


#include <iostream>
#include <stdexcept>
#include <sstream>
#include <stdio.h>

#include "FastHandsHandler.h"
#include "FastHandsService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using namespace apache::thrift::concurrency;

using namespace boost;

#define PORT 9090
#define THREAD_POOL_SIZE 15


int main() {

  printf("FastHands Server started\n");

  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  shared_ptr<FastHandsHandler> handler(new FastHandsHandler());
  shared_ptr<TProcessor> processor(new FastHandsServiceProcessor(handler));

  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(THREAD_POOL_SIZE);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();

  TNonblockingServer server(processor, protocolFactory, PORT, threadManager);
  server.serve();
  printf("done.\n");

  return 0;
}
