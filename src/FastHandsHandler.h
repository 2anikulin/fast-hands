/*
 * FastHandsHandler.h
 *
 * Created on: Apr 29, 2013
 * 	   Author: anikulin
 */

#ifndef FASTHANDSHANDLER_H_
#define FASTHANDSHANDLER_H_

#include "FastHandsService.h"

using namespace fasthands;

class FastHandsHandler : virtual public FastHandsServiceIf {

 public:

  FastHandsHandler();

  int32_t put(const int32_t key, const std::string& value);

  void get(std::string& _return, const int32_t key);

  void bitAnd(std::vector<int32_t> & _return, const std::vector<int32_t> & keys);

 private:

  void appendBitPositions(std::vector<int32_t> & positions, unsigned char bits, int offset);


 private:

  std::map<int32_t, std::string> m_store;

};


#endif /* FASTHANDSHANDLER_H_ */
