


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



## Further References: 
See [Core Instructions](https://www.felixcloutier.com/x86/) to lookup instruction.
X86-Architecture is a bit explained in [Wiki-Book](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture)


## X86-Register Overview

| Purpose        | 64b | 32b | 16b |
| -------------- | --- | --- | --- |
| Accumulator    | RAX | EAX | AX  |
| Counter        | RCX | ECX | CX  |
| Data           | RDX | EDX | DX  |
| Base           | RBX | EBX | BX  |
| Stack Pnt      | RSP | ESP | SP  |
| Stack Base Pnt | RBP | EBP | BP  |
| Source         | RSI | ESI | SI  |
| Destination    | RDI | EDI | DI  |

Registers
- **AX**: Accumulator: For arithmetic operations
- **CX**: Counter: Shift/Rotate and loops
- **DX**: Data: arithmetic and IO-operations
- **BX**: Base: Pointer to Data-Base (Data-Segment DS, when in segment mode)
- **SP**: StackPointer: Pointer to Top of stack
- **BP**: Stack-Base: Pointer to Base of stack
- **SI**: Source-Index: Points source in stream operations
- **DI**: Destination-Index: Points to destination in stram operations

Segment Registers:
- **SS**: Stack Segment
- **CS**: Code Segment
- **DS**: Data Segment
- **ES**: Extra Segment
- **FS**: F-Segment (next Extra)
- **GS**: G-Segment (next Extra)

Further Register:
- **IP** Instruction Pointer: Pointer to next instruction


EFlags-Register:
- CF: Carry Flag
- PF: Parity Flag
- PF : Parity Flag
- AF : Adjust Flag
- ZF : Zero Flag
- SF : Sign Flag
- TF : Trap Flag
- IF : Interruption Flag
- DF : Direction Flag.
- OF : Overflow Flag. 
- IOPL : I/O Privilege Level field (2 bits).
- NT : Nested Task flag
- RF : Resume Flag
- VM : Virtual-8086 Mode
- AC : Alignment Check
- VIF : Virtual Interrupt Flag
- VIP : Virtual Interrupt Pending flag
- ID : Identification Flag

