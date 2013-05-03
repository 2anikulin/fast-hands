/*
Thrift FastHands Service declaration

thrift --gen cpp FastHandsService.thrift
*/

namespace cpp fasthands
namespace java fasthands
namespace php fasthands
namespace perl fasthands

exception InvalidOperation {
  1: i32 what,
  2: string why
}

service FastHandsService {

	i32 put(1:i32 key, 2:binary value),
	
	binary get(1:i32 key),
	
	list<i32> bitAnd(1:list<i32> keys) throws (1:InvalidOperation ouch)
}

