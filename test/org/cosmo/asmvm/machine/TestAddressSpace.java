/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm.machine;

import java.util.Arrays;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class TestAddressSpace {
    public static void main(String[] args){
        int size=1000;
        long darray = AddressSpace.locate_int_array(new int[]{size});
        AddressSpace.put_int(darray, 0, 0xFFFFFFFF);
        AddressSpace.put_int(darray, 1, size);
        AddressSpace.put_int(darray, 2, size);
        AddressSpace.put_int(darray, 3, size);
        
        
//        System.out.println(AddressSpace.get_size(darray, 0));
        System.out.println(AddressSpace.detect_endian());
        System.out.println(Arrays.toString(AddressSpace.get_byte_stream(darray, 2)));
        AddressSpace.free_int_array(darray);   
    }
}
