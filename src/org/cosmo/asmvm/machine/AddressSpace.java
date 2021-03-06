/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm.machine;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public final class AddressSpace {
    static{
        System.loadLibrary("address-space");
       
    }
    public static native long locate_int_array(int dim[]);
    public static native long locate_short_array(int dim[]);
    public static native long locate_byte_array(int dim[]);
    public static native long locate_double_array(int dim[]);
    public static native long locate_long_array(int dim[]);
    public static native long locate_float_array(int dim[]);
    
    public static native void free_int_array(long address);
    public static native void free_short_array(long address);
    public static native void free_byte_array(long address);
    public static native void free_double_array(long address);
    public static native void free_long_array(long address);
    public static native void free_float_array(long address);
    
    public static native void put_int(long address,int idx,int value);
    public static native void put_short(long address,int idx,short value);
    public static native void put_byte(long address,int idx,byte value);
    public static native void put_double(long address,int idx,double value);
    public static native void put_long(long address,int idx,long value);
    public static native void put_float(long address,int idx,float value);
    
    public static native int get_int(long address,int idx);
    public static native short get_short(long address,int idx);
    public static native byte get_byte(long address,int idx);
    public static native double get_double(long address,int idx);
    public static native long get_long(long address,int idx);
    public static native float get_float(long address,int idx);
    
    public static native int get_type_code(long address);
    public static native String get_type_string(long address);
    public static native String get_type_string(int type_code);
    /***
     * 
     * @param address address of array
     * @param m_sys 0 means get size in bytes of any array type 1 means return the size for specific type.
     * @return 
     */
    public static native long get_size(long address,int m_sys);
    /***
     * 
     * @return 0 if host machine is little endian and 1 means big endian
     */
    public static native int detect_endian();
    /**
     * @param address
     * @param flag 0 means little endian and 1 means big endian 2 means as it is
     * @return byte stream of specific type of array 
     * if flag set to {0,1} then endian formating apply on byte_stream otherwise not
     */
    public static native byte[] get_byte_stream(long address,int flag);
}
