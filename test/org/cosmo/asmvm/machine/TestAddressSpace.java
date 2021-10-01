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
        int size=50;
        long darray = AddressSpace.locate_double_array(new int[]{size});
        AddressSpace.put_double(darray, 0, 897);
        AddressSpace.put_double(darray, 1, 897);
        
//        System.out.println(AddressSpace.get_size(darray, 0));
        System.out.println(AddressSpace.detect_endian());
        System.out.println(Arrays.toString(AddressSpace.get_byte_stream(darray, 2)));
        AddressSpace.free_double_array(darray);
        
        
    }
}
