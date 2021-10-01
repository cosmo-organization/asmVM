/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm;

import java.io.Serializable;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class ProgramFile implements Serializable {
    private final int ______bss_Segment_size;
    private final int ______code_Segment_size;
    private final byte[] ______________bss_Segment;
    private final byte[] __________code_Segment______;
    public ProgramFile(byte[] bss,byte[] code){
        this.______________bss_Segment=bss;
        this.__________code_Segment______=code;
        this.______bss_Segment_size=bss.length;
        this.______code_Segment_size=code.length;
    }
    public byte[] getCode(){
        return this.__________code_Segment______;
    }
    public byte[] getBss(){
        return this.______________bss_Segment;
    }
}
