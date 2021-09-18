#ifndef _Include_DEFS_H
#define _Include_DEFS_H
template<typename T>
struct Array{
	int ndim;
	int* dims;
	int size;
	T* pointer;
};

#endif
