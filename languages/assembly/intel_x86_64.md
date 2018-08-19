
# Intel assembly

ATT calling convention is "src, dest". Intel is reverse.  

## Registers 

registers are overload in Intel 80x86 arch:

* EAX (Extended AX) is 32-bit, but overlaid on 16-bit AX, which can be further addressed as 8-bit AH and AL.
* EFLAGS register has overflow, direction, intr-disable, sign, zero, parity, carry-flags.
* SP/ESP is stack ptr
* BP/EBP is also special purpose
* Accumulator - AL, AX, EAX

```
x86-64 has 16 64-bit registers
Eight new registers added - (r8 to r15).  
Their 32 bit equiv are r8d-r15d
and 16 bit equiv are r8w-r15w
and 8 bit equiv r8b-r15b
```

previous registers were eax, ebx, ecx, edx, esi, edi, esp, ebp

```
rax : result reg
rbx : misc
rcx : 4th arg
rdx : 3rd arg - also used in imul, idiv
rsp : stack ptr
rbp : frame ptr
rsi : 2nd arg
rdi : 1st arg
r8  : 5th arg
r9  : 6th arg
r10 : misc 
r11 : misc
r12-r15 : misc
```

```
their 32-bit equiv are eax, etc
the 16-bit equiv are ax, 
and 8-bit equiv are {ah, al}
```

rax > eax > ax > ah, al

```
eax stores return value
rsp, rbp are stack frame ptrs
rip (or pc) is instruction ptr - always contains next instr
```


## Instructions

In 64-bit instructions, suffixes are as follows
* b for 8 bits
* w for 16 bits
* l for 32 bits
* q is for quadword (64bit)
* s for floating pt
* d for double
* t for extended precision

```
i.e. movl %edi, -4
or movq %rsp, %rbp
or popq %rbp
or imull

movb, movs, movw, movl(long), movq(quad), movt(ten)
```

## Memory Addressing modes:

1. register indirect for ptrs
2. indexed addressing for arrays
3. scaled indexed addressing for arrays of sizeof(elem) > 2,4,8

get addr of mem using "lea"

## Procedure call

Three instructions for procedure calls (put param into %edi)
1. call f2 : (push addr of next instr into stack and jump to addr specified by its operand)
2. leave : (restore frame and stack ptr; sets stack ptr %rsp to frame ptr %rbp and then sets frame ptr to saved frame ptr, which is popped from stack)
3. ret : pops addr off stack and jumps to it

```
First 6 regs are passed in regs; addtl args passed in mem-arg area
rax is used to return first result
rdx is used to return 2nd result

stack frame grows from higher to lower addr
rbp points to base of frame
rsp points to top of frame
stack frames are aligned to 16-byte boundaries
```

Calls
1. direct
2. indirect
3. indirect using dword ptr


Operands
1. Immediate (numbers preceded by $ sign)
2. register 
3. memory 


### Entry into function
```
    push (ebp) - save old 
    mov esp, ebp : mvoe ptr to base activation into EBP
    sub numvars, esp : alloc storage for local vars
    and $FFFFFFFFC, esp : do stack dword alignment
```

### Exit from func
```
    mov ebp, esp : dealloc locals and clean stack
    pop ebp : restore ptr to caller's activation record
    ret - params : return to caller
```

## Misc

* lea instruction : to take addr of memory location (&a)
* for dereferencing, use [%register] mode
* various addressing modes are defined to enable easy access to arrays
* Faster to multiply by reciprocal than divide
* Xlat instr for table lookup
* Flags : carry, direction, overflow
* instr to scan for set bit : bsf, bsr


## To resolve

what is
.file
.ident
.globl
.text
.type
.size
.section
.cfi_startproc
.cfi_def_cfa
.cfi_def_cfa_offset
.cfi_def_cfa_register

