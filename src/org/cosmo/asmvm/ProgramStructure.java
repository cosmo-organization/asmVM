/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.cosmo.asmvm;

import java.io.File;
import java.nio.ByteBuffer;
import static org.cosmo.asmvm.IS.*;
/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public class ProgramStructure {
    byte[] bssSegment;
    byte[] codeSegment;
    byte[] dataSegment;
    byte[] stackSegment;
    public void setSegments(byte[] bssSegment,byte[] codeSegment,byte[] dataSegment,byte[] stackSegment){
        this.bssSegment=bssSegment;
        this.codeSegment=codeSegment;
        this.dataSegment=dataSegment;
        this.stackSegment=stackSegment;
    }
    public void loadFromFile(File executableFile){
        
    }
    public void execute(){
        int rip=0;
        int rsp=0;
        int rbp=0;
        
        while (rip!=codeSegment.length){
            IS instruction=IS.values()[this.codeSegment[rip++]];
            switch(instruction){
                case IPUSH:{
                    this.stackSegment[rsp+3]=this.codeSegment[rip++];
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST0:{
                    this.stackSegment[rsp+3]=0;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                
                case ICONST1:{
                    this.stackSegment[rsp+3]=1;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                
                case ICONST2:{
                    this.stackSegment[rsp+3]=2;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                
                case ICONST3:{
                    this.stackSegment[rsp+3]=3;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST4:{
                    this.stackSegment[rsp+3]=4;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST5:{
                    this.stackSegment[rsp+3]=5;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST6:{
                    this.stackSegment[rsp+3]=6;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST7:{
                    this.stackSegment[rsp+3]=7;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST8:{
                    this.stackSegment[rsp+3]=8;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                case ICONST9:{
                    this.stackSegment[rsp+3]=9;
                    this.stackSegment[rsp+2]=0;
                    this.stackSegment[rsp+1]=0;
                    this.stackSegment[rsp]=0;
                    rsp+=4;
                    break;
                }
                
                case LOADI:{
                    int index=toInteger(this.codeSegment,rip);
                    rip+=4;
                    writeBuffer(this.bssSegment,index,4,this.stackSegment,rsp);
                    rsp+=4;
                    break;
                }
                case STI:{
                    int index=toInteger(this.codeSegment,rip);
                    rip+=4;
                    writeBuffer(this.stackSegment,rsp-3,4,this.bssSegment,index);
                    rsp-=4;
                    break;
                }
                
                case IADD:{
                    //Fault Here
                    
                    System.out.println(rsp-3);
                    int first=toInteger(this.stackSegment,rsp-3);
                    rsp-=4;
                    System.out.println(rsp);
                    System.out.println(rsp-3);
                    int second=toInteger(this.stackSegment,rsp-3);
                    rsp-=4;
                    System.out.println(rsp);
                    int result=first+second;
                    writeBuffer(toBytes(result),0,4,this.stackSegment,rsp);
                    rsp+=4;
                    break;
                }
                
                default:
                    System.err.println("Invalid Instruction:"+instruction);
                    System.err.printf("Register status rip:%d,rsp:%d,rbp:%d\n",rip,rsp,rbp);
                    rip=codeSegment.length;
                    break;
            
            }
        
        }
    }
    public static int toInteger(byte[] bytes,int offset){
        ByteBuffer buffer=ByteBuffer.allocate(4);
        buffer.put(bytes,offset,4);
        buffer.flip();
        int result= buffer.asIntBuffer().get();
        buffer.clear();
        return result;
    }
    public static byte[] readBuffer(byte[] src,int offset,int length){
        byte[] result=new byte[length];
        int c=0;
        for (int i=offset;i<offset+length;i++){
            result[c++]=src[i];
        }
        return result;
    }
    public static void writeBuffer(byte[] src,int s_offset,int s_length,byte[] dest,int d_offset){
        int d_c=0;
        for (int i=s_offset;i<s_offset+s_length;i++){
            dest[d_offset+d_c++]=src[i];
        }
    }
    public static byte[] toBytes(int integer){
        byte[] result=new byte[4];
        result[0]=(byte) ((byte)(integer>>24)&0xFF);
        result[1]=(byte) ((byte)(integer>>16)&0xFF);
        result[2]=(byte) ((byte)(integer>>8)&0xFF);
        result[3]=(byte) ((byte)(integer)&0xFF);
        return result;
    }
}
