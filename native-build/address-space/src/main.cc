#include <addressspace.h>
#include <defs.h>
#include <stdlib.h>

template<typename T>
static jlong locate(JNIEnv *env, jclass clz, jintArray dims){
	Array<int>* iArray=(Array<int>*)malloc(sizeof(Array<int>));
	iArray->ndim=env->GetArrayLength(dims);
	iArray->dims=(int*)malloc(sizeof(int)*iArray->ndim);
	jint* datas=env->GetIntArrayElements(dims,(jboolean*)0);
	unsigned long size_of_array=1;
	for (int i=0;i<iArray->ndim;i++){
		iArray->dims[i]=datas[i];
		size_of_array*=datas[i];
	}
	iArray->pointer=(int*)malloc(sizeof(int)*size_of_array);
	env->ReleaseIntArrayElements(dims,datas,0);//may be crash point
  	iArray->size=size_of_array;
  	return (jlong)iArray;
}

template<typename T>
static void release(JNIEnv* env,jclass clz,jlong address){
	Array<T>* array=reinterpret_cast<Array<T>*>(address);
	free(array->pointer);
	free(array->dims);
	free(array);
}

template<typename T>
static void put(JNIEnv* env,jclass clz,jint index,T value){
	
}

JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1int_1array(JNIEnv *env, jclass clz, jintArray dims){
  	return locate<int>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_short_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1short_1array(JNIEnv *env, jclass clz, jintArray dims){
	return locate<short>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_byte_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1byte_1array(JNIEnv *env, jclass clz, jintArray dims){
	return locate<unsigned char>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_double_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1double_1array(JNIEnv *env, jclass clz, jintArray dims){
	return locate<double>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_long_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1long_1array(JNIEnv *env, jclass clz, jintArray dims){
	return locate<long>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_float_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1float_1array(JNIEnv *env, jclass clz, jintArray dims){
	return locate<float>(env,clz,dims);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_int
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1int(JNIEnv *, jclass, jint, jint){
	
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_short
 * Signature: (IS)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1short(JNIEnv *, jclass, jint, jshort){
	
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_byte
 * Signature: (IB)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1byte(JNIEnv *, jclass, jint, jbyte){
	
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_double
 * Signature: (ID)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1double(JNIEnv *, jclass, jint, jdouble){
	
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_long
 * Signature: (IJ)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1long(JNIEnv *, jclass, jint, jlong){
	
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_float
 * Signature: (IF)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1float(JNIEnv *, jclass, jint, jfloat){
	
}




/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_int_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1int_1array(JNIEnv *env, jclass clz, jlong address){
	release<int>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_short_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1short_1array(JNIEnv *env, jclass clz, jlong address){
	release<short>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_byte_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1byte_1array(JNIEnv *env, jclass clz, jlong address){
	release<unsigned char>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_double_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1double_1array(JNIEnv *env, jclass clz, jlong address){
	release<double>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_long_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1long_1array(JNIEnv *env, jclass clz, jlong address){
	release<long>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_float_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1float_1array(JNIEnv *env, jclass clz, jlong address){
	release<float>(env,clz,address);
}
