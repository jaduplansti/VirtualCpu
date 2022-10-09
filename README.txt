the 0z3Cpu
Registers:
ex, (0x0)
dx, (0x1)
bx, (0x2)
aex,(0x3)
adx,(0x4)
abx,(0x5)
zx1,(0x6)
zx2,(0x7)
zx3,(0x8)

Interrupts:
Still In Progress

Flags:
zf, Zero Flag
nf, NULL Flag

Prefix:
none, None
val, Specifies If An Arguement Is Gonna Be A Constant
addr, Specifies And Address

Instructions:
mov, Moves A Register Or A Constant To A Destination(1st Arg)
movp, Promotes A Register 16 bit to 32 bit
movf, Moves A Float Or A Register To The Destination(1st Arg)
cmp, Compares A Constant Or A Register To A Register
ld,  Links 2 Registers 

Features:
Dual Core (Experimental)
Improved Instructions(I Assure That It Was Not Copy And Paste)
Optimized Source Code(Yes)
Better Arithematic(Not Yet Added)
Built In Assembler
Virtual Hardware (Such As Virtual Ram And Virtual Drive & Vga)
Special Registers And Float Registers

Whats New:
Dual Core:
Basically Seperates Each Instruction And Passes It To One Of The Cores And Then Decode
ld Instruction:
It Links To Registers, For Example ld aex,adx 
This Makes aex == adx If You Try To Change The Value Of Any Of The Linked Registers The Value Will Not Change
so
mov aex,5
ld aex,adx This Makes aex == edx
mov adx,9 Value Of adx Will Still Be 5 Unless You Unlink Them

	







The 0z3Cpu
Registers:
	cdx, (0x0)
	adx, (0x1)
	acx, (0x2)
	a1, Special Register 1 (0x3)
	a2,	Special Register 2 (0x4)
	a3, Switcher(0x5)
	asp, This is The Special Stack Pointer Register (0x6)
Interrupts:
	Not Done
	
Flags:
	zf, The Zero Flag Is Set Conditionally
	nf, This Flag Is Set When A Exception Happens

Prefix:
 val, This Tells The Cpu That A Constant Value Will An Arguement
 addr, Specified Address
 
Instructions:
	mov, Moves A Value Into A Register It Can Be Either A Constant Or A Register(0x0)
	cmp, Compares Either A Register To A Register Or A Register To A Constant Value And Sets The Zero Flag Conditionally(0x1)
	jmp, Not Added Yet
	add, Adds Either cdx,adx,acx,a1 To cdx and Stores The Result To cdx [add adx](0x3)
	sub, Same As Above(0x4)
	mul, (0x5)
	idiv, (0x6)
	
Examples:
[Prefix][Instruction][Register][Register/Constant] 
1004: mov cdx,4
1012: mov adx,2
031:  add,adx
0021  mov adx,cdx (adx = 6)

Whats New:
Better Instructions
Faster And Buggier Registers
No Mode Switching 
Better Arithematic 
More Code
More Easier To Understand
No Input












The 0z2Cpu
Has 4 Registers in Total
4 of them are general purpose which is cx , dx , ax and bx
the other 2 are special registers called
a1 and a2

ax is mostly used for Interrupts such as a Mode Switch or Displaying a Int
a1 is the Memory Pointer that points to the current Position of the Memory
a2 is the Mode Register, Mode Switching Switches Instructions For A Opcode
For example In Mode 0 0x01 Is Move cx,num /15 In Mode 1 0x01 Becomes Move cx,dx

Interrupt List:
0x00 Exits Normal
0x01 Displays A Integer From dx
0x02 Switches To Protected Mode
0x03 Mode Switch 
0x04 Disable Interrupts	
0x05 Use Register bx

Modes:
0x00:Arithemetic
0x01:Moving

All OpCodes:
0x01 Moves A Integer To cx
0x02 Moves A Integer To dx
0x03 Moves A Integer To ax
0x04 Adds cx To dx And Stores The Result in cx
0x05 Subtracts cx To dx And Stores The Result in cx
0x06 Multiplies cx To dx And Stores The Result in cx
0x07 Divides cx To dx And Stores The Result in cx
0x09 Interrupts The Cpu

0x00 Resets a2
0x01 Moves dx To cx
0x02 Moves cx To dx
0x09 Interrupts The Cpu

Whats New?:
0z2Cpu Is Much More Optimized Than The First Counter Part 0z1Cpu.

It Has More Registers But No Flags
Memory Access Is Much More Simplified
More Opcodes And Less Buggy 
Better Input
More Interrupts
Better Arithemetic 
Less Code

