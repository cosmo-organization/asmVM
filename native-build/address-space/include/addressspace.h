/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_cosmo_asmvm_machine_AddressSpace */

#ifndef _Included_org_cosmo_asmvm_machine_AddressSpace
#define _Included_org_cosmo_asmvm_machine_AddressSpace
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_int_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1int_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_short_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1short_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_byte_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1byte_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_double_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1double_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_long_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1long_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    locate_float_array
 * Signature: ([I)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_locate_1float_1array
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_int_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1int_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_short_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1short_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_byte_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1byte_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_double_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1double_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_long_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1long_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    free_float_array
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_free_1float_1array
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_int
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1int
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_short
 * Signature: (JIS)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1short
  (JNIEnv *, jclass, jlong, jint, jshort);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_byte
 * Signature: (JIB)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1byte
  (JNIEnv *, jclass, jlong, jint, jbyte);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_double
 * Signature: (JID)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1double
  (JNIEnv *, jclass, jlong, jint, jdouble);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_long
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1long
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    put_float
 * Signature: (JIF)V
 */
JNIEXPORT void JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_put_1float
  (JNIEnv *, jclass, jlong, jint, jfloat);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_int
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1int
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_short
 * Signature: (JI)S
 */
JNIEXPORT jshort JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1short
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_byte
 * Signature: (JI)B
 */
JNIEXPORT jbyte JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1byte
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_double
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1double
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_long
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1long
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_float
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1float
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_code
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1code
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_string
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1string__J
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_type_string
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1type_1string__I
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_size
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1size
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    detect_endian
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_detect_1endian
  (JNIEnv *, jclass);

/*
 * Class:     org_cosmo_asmvm_machine_AddressSpace
 * Method:    get_byte_stream
 * Signature: (I)[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_cosmo_asmvm_machine_AddressSpace_get_1byte_1stream
  (JNIEnv *, jclass,jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
