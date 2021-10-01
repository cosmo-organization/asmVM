#ifndef __Include_util_H
#define __Include_util_H
#include <defs.h>
template<typename T>
struct get_type{
	static const int type;
};
template<>
struct get_type<int>{
	static const int type=INT;
};
template<>
struct get_type<short>{
	static const int type=SHORT;
};
template<>
struct get_type<unsigned char>{
	static const int type=BYTE;
};
template<>
struct get_type<float>{
	static const int type=FLOAT;
};
template<>
struct get_type<double>{
	static const int type=DOUBLE;
};
template<>
struct get_type<long long>{
	static const int type=LONG;
};

static int get_type_size(unsigned char type){
	switch(type){
		case INT:
			return sizeof(int);
		case LONG:
			return sizeof(long long);
		case SHORT:
			return sizeof(short);
		case DOUBLE:
			return sizeof(double);
		case FLOAT:
			return sizeof(float);
		case BYTE:
			return sizeof(char);
		case OBJECT:
			return sizeof(void*);
	}
}

#endif
