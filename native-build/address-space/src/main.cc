#include <addressspace.h>
#include <stdlib.h>
#include <util.h>
#include <stdio.h>


template<typename T>
static jlong locate(JNIEnv *env, jclass clz, jintArray dims){
	Array<T>* iArray=(Array<T>*)malloc(sizeof(Array<int>));
	iArray->ndim=env->GetArrayLength(dims);
	iArray->type=get_type<T>::type;
	iArray->dims=(int*)malloc(sizeof(int)*iArray->ndim);
	jint* datas=env->GetIntArrayElements(dims,(jboolean*)0);
	unsigned long size_of_array=1;
	for (int i=0;i<iArray->ndim;i++){
		iArray->dims[i]=datas[i];
		size_of_array*=datas[i];
	}
	iArray->pointer=(T*)malloc(sizeof(int)*size_of_array);
	env->ReleaseIntArrayElements(dims,datas,0);
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
static void put(JNIEnv* env,jclass clz,jlong address,jint index,T value){
	Array<T>* array=reinterpret_cast<Array<T>*>(address);
	if (index>=array->size){
		jclass exception_clz=env->FindClass(INDEX_OUT_OF_BOUND_CLASS);
		if (!exception_clz)printf("CAn't find class\n");
		char* msg=(char*)malloc(100);
		sprintf(msg,"Index out of bound size:%d, index:%d (Index must be less than size)",array->size,index);
		env->ThrowNew(exception_clz,msg);
		free(msg);
	}else{
		array->pointer[index]=value;
	}
}

template<typename T>
static T get(JNIEnv* env,jclass clz,jlong address,jint index){
	Array<T>* array=reinterpret_cast<Array<T>*>(address);
	if (index>=array->size){
		jclass exception_clz=env->FindClass(INDEX_OUT_OF_BOUND_CLASS);
		if (!exception_clz)printf("Can't find class\n");
		char* msg=(char*)malloc(100);
		sprintf(msg,"Index out of bound size:%d, index:%d (Index must be less than size)",array->size,index);
		env->ThrowNew(exception_clz,msg);
		free(msg);
	}else{
		return array->pointer[index];
	}
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
	return locate<long long>(env,clz,dims);
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
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1int(JNIEnv *env, jclass clz,jlong address, jint index, jint value){
	put(env,clz,address,index,value);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_short
 * Signature: (IS)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1short(JNIEnv *env, jclass clz,jlong address, jint index, jshort value){
	put(env,clz,address,index,value);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_byte
 * Signature: (IB)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1byte(JNIEnv *env, jclass clz,jlong address, jint index , jbyte value){
	put(env,clz,address,index,value);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_double
 * Signature: (ID)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1double(JNIEnv *env, jclass clz,jlong address, jint index, jdouble value){
	put(env,clz,address,index,value);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_long
 * Signature: (IJ)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1long(JNIEnv *env, jclass clz,jlong address, jint index, jlong value){
	put(env,clz,address,index,value);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_float
 * Signature: (IF)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1float(JNIEnv *env, jclass clz,jlong address, jint index, jfloat value){
	put(env,clz,address,index,value);
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
	release<long long>(env,clz,address);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_float_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1float_1array(JNIEnv *env, jclass clz, jlong address){
	release<float>(env,clz,address);
}

JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1int(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<int>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_short
 * Signature: (JI)S
 */
JNIEXPORT jshort JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1short(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<short>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_byte
 * Signature: (JI)B
 */
JNIEXPORT jbyte JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1byte(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<unsigned char>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_double
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1double(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<double>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_long
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1long(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<jlong>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_float
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1float(JNIEnv *env, jclass clz, jlong address, jint index){
	return get<float>(env,clz,address,index);
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_code
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1code(JNIEnv *env, jclass clz, jlong address){
  	Array<void*>* array=reinterpret_cast<Array<void*>*>(address);
  	return array->type;
}


/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_string
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1string__J(JNIEnv *env, jclass clz, jlong address){
	jint idx=Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1code(env,clz,address);
	jstring str=env->NewStringUTF(TYPE_STRING[idx]);
	return str;
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_string
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1string__I(JNIEnv *env, jclass clz, jint idx){
	jstring str=env->NewStringUTF(TYPE_STRING[idx]);
	return str;
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_size
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1size(JNIEnv *env, jclass clz, jlong address, jint m_sys){
	Array<void>* array=reinterpret_cast<Array<void>*>(address);
	if (m_sys==0){
		int type_code=Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1code(env,clz,address);
		int type_size=get_type_size(type_code);
		return array->size*type_size;
	}else if(m_sys==1){
		return array->size;
	}
	return -1;
}


/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    detect_endian
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_detect_1endian(JNIEnv *, jclass){
	short testByte=0x0001;
	return (((testByte>>8)&0xFF)==1)?0:1;
}

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_byte_stream
 * Signature: (I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1byte_1stream(JNIEnv *env, jclass clz,jlong address, jint flag){
	jint sz=Java_org_cosmo_asmvm_machine_AddressSpace_get_1size(env,clz,address,0);
	jbyteArray byteArray=env->NewByteArray(sz);
	jbyte* ptr=env->GetByteArrayElements(byteArray,(jboolean*)0);
	Array<double>* array=reinterpret_cast<Array<double>*>(address);
	unsigned int prev_size=array->size;
	array->size=sz;
	
	char* buffer=reinterpret_cast<char*>(array->pointer);
	for (unsigned int i=0;i<sz;i++){
		ptr[i]=buffer[i];
	}
	
	array->size=prev_size;
	env->ReleaseByteArrayElements(byteArray,ptr,0);
	return byteArray;
}
