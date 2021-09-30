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
public class TestAddressSpace {
    public static void main(String[] args){
        int size=50;
        long iarray = AddressSpace.locate_long_array(new int[]{size});
        System.out.println("Array Type code:"+AddressSpace.get_type_code(iarray));
        System.out.println("Array Type String:"+AddressSpace.get_type_string(iarray));
        System.out.println("Array Type String:"+AddressSpace.get_type_string(AddressSpace.get_type_code(iarray)));
        AddressSpace.free_int_array(iarray);
    }
}
