/*
 * This is Insruction Set .
 */
package org.cosmo.asmvm;

/**
 *
 * @author Sonu Aryan <cosmo-developer@github.com>
 */
public enum IS {
    IPUSH("push-int(0 to 255)"),
    SIPUSH("push-short(0 to 255)"),
    BIPUSH("push-byte(-128 to 127)"),
    ICONST0("push int-0-on-stack"),
    ICONST1("push int-1-on-stack"),
    ICONST2("push int-2-on-stack"),
    ICONST3("push int-3-on-stack"),
    ICONST4("push int-4-on-stack"),
    ICONST5("push int-5-on-stack"),
    ICONST6("push int-6-on-stack"),
    ICONST7("push int-7-on-stack"),
    ICONST8("push int-8-on-stack"),
    ICONST9("push int-9-on-stack"),
    SCONST0("push short-0-on-stack"),
    SCONST1("push short-1-on-stack"),
    SCONST2("push short-2-on-stack"),
    SCONST3("push short-3-on-stack"),
    SCONST4("push short-4-on-stack"),
    SCONST5("push short-5-on-stack"),
    SCONST6("push short-6-on-stack"),
    SCONST7("push short-7-on-stack"),
    SCONST8("push short-8-on-stack"),
    SCONST9("push short-9-on-stack"),
    FCONST0("push float-0-on-stack"),
    FCONST1("push float-1-on-stack"),
    FCONST2("push float-2-on-stack"),
    FCONST3("push float-3-on-stack"),
    FCONST4("push float-4-on-stack"),
    FCONST5("push float-5-on-stack"),
    FCONST6("push float-6-on-stack"),
    FCONST7("push float-7-on-stack"),
    FCONST8("push float-8-on-stack"),
    FCONST9("push float-9-on-stack"),
    DCONST0("push double-0-on-stack"),
    DCONST1("push double-1-on-stack"),
    DCONST2("push double-2-on-stack"),
    DCONST3("push double-3-on-stack"),
    DCONST4("push double-4-on-stack"),
    DCONST5("push double-5-on-stack"),
    DCONST6("push double-6-on-stack"),
    DCONST7("push double-7-on-stack"),
    DCONST8("push double-8-on-stack"),
    DCONST9("push double-9-on-stack"),
    LCONST0("push long-0-on-stack"),
    LCONST1("push long-1-on-stack"),
    LCONST2("push long-2-on-stack"),
    LCONST3("push long-3-on-stack"),
    LCONST4("push long-4-on-stack"),
    LCONST5("push long-5-on-stack"),
    LCONST6("push long-6-on-stack"),
    LCONST7("push long-7-on-stack"),
    LCONST8("push long-8-on-stack"),
    LCONST9("push long-9-on-stack"),
    LOADI("load-int"),
    LOADF("load-float"),
    LOADD("load-double"),
    LOADS("load-short"),
    LOADL("load-long"),
    ANEW("create-object"),
    CALL("call-function"),
    IRETURN("return-integer"),
    SRETURN("return-short"),
    BRETURN("return-byte"),
    DRETURN("return-double"),
    FRETURN("return-float"),
    LRETURN("return-long"),
    ARETURN("return-object"),
    CIARRAY("create-integer-array"),
    CDARRAY("create-double-array"),
    CFARRAY("create-float-array"),
    CSARRAY("create-short-array"),
    CBARRAY("create-byte-array"),
    CAARRAY("create-object-array"),
    CLARRAY("create-long-array"),
    ARRAY_SIZE("push-array-size-on-stack"),
    ICOMPARE("(integer)push(higher-lower)-on-stack"),
    DCOMPARE("(double)push(higher-lower)-on-stack"),
    FCOMPARE("(float)push(higher-lower)-on-stack"),
    SCOMPARE("(short)push(higher-lower)-on-stack"),
    BCOMPARE("(byte)push(higher-lower)-on-stack"),
    LCOMPARE("(long)push(higher-lower)-on-stack"),
    ACOMPARE("(object)push(higher-lower)-on-stack"),
    //Arithemetic and logical operation
    BADD, BSUB, BMUL, BDIV, BMOD, BAND, BOR, BXOR, BBC, BRSHFT, BLSHFT, BLAND, BLOR, BLNOT, BNE, BET,
    SADD, SSUB, SMUL, SDIV, SMOD, SAND, SOR, SXOR, SBC, SRSHFT, SLSHFT, SLAND, SLOR, SLNOT, SNE, SET,
    IADD, ISUB, IMUL, IDIV, IMOD, IAND, IOR, IXOR, IBC, IRSHFT, ILSHFT, ILAND, ILOR, ILNOT, INE, IET,
    LADD, LSUB, LMUL, LDIV, LMOD, LAND, LOR, LXOR, LBC, LRSHFT, LLSHFT, LLAND, LLOR, LLNOT, LNE, LET,
    DADD, DSUB, DMUL, DDIV, DMOD, DAND, DOR, DXOR, DBC, DRSHFT, DLSHFT, DLAND, DLOR, DLNOT, DNE, DET,
    FADD, FSUB, FMUL, FDIV, FMOD, FAND, FOR, FXOR, FBC, FRSHFT, FLSHFT, FLAND, FLOR, FLNOT, FNE, FET,
    //Branch instructions
    JMPE, JMPNE, JMPGT, JMPLT, JMP;
    public final String dbgStr;

    private IS(String dbgStr) {
        this.dbgStr = dbgStr;
    }

    private IS() {
        this.dbgStr = "nd";
    }
}
