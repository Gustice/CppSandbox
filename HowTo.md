


# Understading symbol files 
Printout looks somwhat like the following:
```
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T Eval_GlobalFun(int)
000000000000002b t Eval_LocalStaticFun(int)
0000000000000070 r Eval_GlobalFun(int)::__PRETTY_FUNCTION__
0000000000000056 T main
                 U printf
```

These files are created by `nm -C <objFile.o>` commands

Meaning of common symbols:
- T|t: Text (code) section
- R|r: ReadOnly data section
- U: Symbol is undefined => Symbol must be referenced somewhere else

# Understading oject dumps
Printout looks somwhat like the following:
```
build/main.o:     file format elf64-x86-64
...
Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         000000a2  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  0000000000000000  0000000000000000  000000e2  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  000000e2  2**0
                  ALLOC
  3 .rodata       000000cc  0000000000000000  0000000000000000  000000f0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
...
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.c
0000000000000070 l     O .rodata	0000000000000019 Eval_GlobalFun(int)::__PRETTY_FUNCTION__
000000000000002b l     F .text	000000000000002b Eval_LocalStaticFun(int)
0000000000000000 g     F .text	000000000000002b Eval_GlobalFun(int)
0000000000000056 g     F .text	000000000000004c main
0000000000000000         *UND*	0000000000000000 Eval_Module_ExternalGlobal(int)
...
RELOCATION RECORDS FOR [.text]:
OFFSET           TYPE              VALUE 
0000000000000013 R_X86_64_PC32     .rodata+0x000000000000006c
0000000000000083 R_X86_64_PC32     Eval_GlobalFun(int)-0x0000000000000004
0000000000000097 R_X86_64_PLT32    Eval_Module_ExternalGlobal(int)-0x0000000000000004
```

The section table shows an overview of defined sections:
- `.text`: executable code section (this is readonly and executable)
- `.rodata`: ReadOnly-data section for constants
- `.interp`: filename and dynamic linker
This section are used during linking time, segments are used during execution
