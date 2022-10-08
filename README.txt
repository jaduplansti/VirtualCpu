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

