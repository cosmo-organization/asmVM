/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class BssSegment {
    int growth;
    byte[] bss;
    public BssSegment(byte bss[]){
        this.growth=0;
        this.bss=bss;
    }
    public byte[] reserveBytes(int nBytes){
        byte[] address=ProgramStructure.toBytes(growth);
        growth+=nBytes;
        return address;
    }
    public void writeInt(byte[] variable,int data){
        int index=ProgramStructure.toInteger(variable, 0);
        byte[] bytes=ProgramStructure.toBytes(data);
        System.arraycopy(bytes, index, bss, index, 4+index - index);
    }
}
