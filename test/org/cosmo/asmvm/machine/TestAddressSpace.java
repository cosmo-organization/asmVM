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
        long iarray = AddressSpace.locate_int_array(new int[]{5,5,5});
        System.out.println(iarray);
        AddressSpace.free_int_array(iarray);
        
    }
}
