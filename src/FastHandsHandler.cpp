/*
 * FastHandsHandler.cpp
 *
 *  Created on: Apr 29, 2013
 *      Author: anikulin
 */

#include "FastHandsHandler.h"

//===================================
FastHandsHandler::FastHandsHandler() {

}

//===================================
int32_t FastHandsHandler::put(const int32_t key, const std::string& value) {
	m_store[key] = value;
	return 0;
}

//===================================
void FastHandsHandler::get(std::string& _return, const int32_t key) {
	_return = m_store.count(key) == 0 ? NULL : m_store[key];
}

//===================================
void FastHandsHandler::bitAnd(std::vector<int32_t> & _return, const std::vector<int32_t> & keys) {

	if (keys.size() < 2) {
		InvalidOperation io;
		io.__set_why("keys size < 2");
		throw io;
	}

	int keysCount = keys.size() - 1;
	std::string *masksArray = new (std::nothrow) std::string[keysCount];
	for (int i = 1; i < (int)keys.size(); i++) {
		if (m_store.count(keys[i]) == 0) {
			delete[] masksArray;

			InvalidOperation io;
			io.__set_why("unknown key");
			throw io;
		}
		masksArray[i - 1] = m_store[keys[i]];
	}

	std::string mask0 = m_store[keys[0]];

	for (int i =0 ; i < (int)mask0.size(); i++) {
		unsigned char res = (unsigned char)mask0[i];
		for (int j = 0; j < keysCount; j++) {
			res &= (unsigned char)masksArray[j][i];
			if (res == 0) {
				break;
			}
		}

		if (res > 0) {
			appendBitPositions(_return, res, i);
		}
	}

	delete[] masksArray;

}

//===================================
void FastHandsHandler::appendBitPositions(std::vector<int32_t> & positions, unsigned char bits, int offset) {
	unsigned char mask = 128;
	for (int i = 0; i < 8; i++) {
	  if (mask & bits) {
		  positions.push_back(offset * 8 + i);
	  }
	  mask = mask >> 1;
	}
}





