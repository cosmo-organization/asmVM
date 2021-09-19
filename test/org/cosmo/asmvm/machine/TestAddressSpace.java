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
        int size=99909989;
        long iarray = AddressSpace.locate_int_array(new int[]{size});
        System.out.println(iarray);
        for (int i=0;i<size*4;i++){
            AddressSpace.put_byte(iarray, i, (byte)0);
        }
        System.out.println(AddressSpace.get_int(iarray,0));
        AddressSpace.free_int_array(iarray);
    }
}
