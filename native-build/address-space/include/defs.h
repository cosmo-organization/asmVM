#ifndef _Include_DEFS_H
#define _Include_DEFS_H
#define INDEX_OUT_OF_BOUND_CLASS "Lorg/cosmo/asmvm/machine/IndexOutOfBoundException;"
#define INT 0
#define BYTE 1
#define SHORT 2
#define LONG 3
#define FLOAT 4
#define DOUBLE 5
#define OBJECT 6
template<typename T>
struct Array{
	int type;
	int ndim;
	int* dims;
	int size;
	T* pointer;
};

#endif
