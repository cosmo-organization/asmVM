/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Arrays;
import static org.cosmo.asmvm.IS.*;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException {
         byte[] stackSegment = new byte[32];
        byte[] bssSegment = new byte[32];
        BssSegment bss = new BssSegment(bssSegment);
        byte[] var1 = bss.reserveBytes(4);
        byte[] var2 = bss.reserveBytes(4);
        bss.writeInt(var1, -2568);
        
        byte[] codeSegment = {(byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IADD.ordinal(),
            (byte) IPRINT.ordinal(),
            (byte) NEWLINE.ordinal(),
            (byte) LOADI.ordinal(),var1[0],var1[1],
            var1[2],var1[3],
            (byte)IDUP.ordinal(),
            (byte)IPRINT.ordinal(),
            (byte)NEWLINE.ordinal(),
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IADD.ordinal(),
            (byte) IPRINT.ordinal(),
            (byte) NEWLINE.ordinal(),
            (byte) LOADI.ordinal(),var1[0],var1[1],
            var1[2],var1[3],
            (byte)IDUP.ordinal(),
            (byte)IPRINT.ordinal(),
            (byte)NEWLINE.ordinal(),
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IADD.ordinal(),
            (byte) IPRINT.ordinal(),
            (byte) NEWLINE.ordinal(),
            (byte) LOADI.ordinal(),var1[0],var1[1],
            var1[2],var1[3],
            (byte)IDUP.ordinal(),
            (byte)IPRINT.ordinal(),
            (byte)NEWLINE.ordinal(),
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IADD.ordinal(),
            (byte) IPRINT.ordinal(),
            (byte) NEWLINE.ordinal(),
            (byte) LOADI.ordinal(),var1[0],var1[1],
            var1[2],var1[3],
            (byte)IDUP.ordinal(),
            (byte)IPRINT.ordinal(),
            (byte)NEWLINE.ordinal(),
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IPUSH.ordinal(), 0, 0, 0, 0x0A,
            (byte) IADD.ordinal(),
            (byte) IPRINT.ordinal(),
            (byte) NEWLINE.ordinal(),
            (byte) LOADI.ordinal(),var1[0],var1[1],
            var1[2],var1[3],
            (byte)IDUP.ordinal(),
            (byte)IPRINT.ordinal(),
            (byte)NEWLINE.ordinal(),
            (byte)JMP.ordinal(),0,0x0,0x0,0x0
        };
        ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream("example.asmvm"));
        oos.writeObject(new ProgramFile(bssSegment,codeSegment));
        
        ProgramStructure ps = new ProgramStructure();
        ps.setSegments(bssSegment, codeSegment, null, stackSegment);
        ps.execute();
        System.out.println("Stack\n" + Arrays.toString(stackSegment));
        System.out.println("Code\n" + Arrays.toString(codeSegment));
        System.out.println("Bss\n" + Arrays.toString(bssSegment));
        
    }
}
