/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm;
import java.util.Arrays;
import static org.cosmo.asmvm.IS.*;
/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class Main {
    public static void main(String[] args){
        byte[] codeSegment={(byte)IPUSH.ordinal(),0xA,
            (byte)IPUSH.ordinal(),0xA,
            (byte)IADD.ordinal()
        };
        byte[] stackSegment=new byte[32];
        byte[] bssSegment=new byte[32];
        ProgramStructure ps=new ProgramStructure();
        ps.setSegments(bssSegment, codeSegment, null, stackSegment);
        ps.execute();
        System.out.println("Stack\n"+Arrays.toString(stackSegment));
        System.out.println("Code\n"+Arrays.toString(codeSegment));
        System.out.println("Bss\n"+Arrays.toString(bssSegment));
    }
}
