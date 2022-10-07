#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Peek_O scanf("%1x",&Opcode)
#define Max_Mem 500
int Memory[Max_Mem];
int Opcode;
struct Registers {
		int cx;
		int dx;
		int ax;
		int a1;
		int a2;
} Cur_Reg;

struct Cpu {
	int RealMode;
	int ProtectedMode;
	int DisableIns;
} Cur_Cpu;

int Interrupt() //Interrupts
{
	switch(Cur_Reg.ax)
	{
		case 0x00:
				exit(0);
		
		case 0x01:
				printf("%d",Cur_Reg.dx);
				break;
		
		case 0x02:
				Cur_Cpu.ProtectedMode = 1;
				Cur_Cpu.RealMode = 0;
				break;
		case 0x03:
				Cur_Reg.a2 = Cur_Reg.cx;
				break;
		case 0x04:
				Cur_Cpu.DisableIns = 1;
				break;
}

}
int Com_Cpu() 
{
	for(Cur_Reg.a1 = 0;Cur_Cpu.DisableIns != 1; Cur_Reg.a1++)
	{
		Peek_O;
		Memory[Cur_Reg.a1] = Opcode;
	if(Cur_Reg.a2 == 0)
	{
	switch(Opcode) //Arithemetic
	{
		case 0x01: 
			Peek_O;
		    Cur_Reg.cx = Opcode;
			break;
		
		case 0x02:
			Peek_O;
			Cur_Reg.dx = Opcode;
			break;
			
		case 0x03:
			Peek_O;
			Cur_Reg.ax = Opcode;
			break;
			
		case 0x09:
			Interrupt();
			break;
		
		case 0x04:
			Cur_Reg.cx = Cur_Reg.cx + Cur_Reg.dx;
			break;
		case 0x05:
			Cur_Reg.cx = Cur_Reg.cx - Cur_Reg.dx;
			break;
			
		case 0x6:
			Cur_Reg.cx = Cur_Reg.cx * Cur_Reg.dx;
			break;
			
		case 0x7:
			Cur_Reg.cx = Cur_Reg.cx / Cur_Reg.dx;
			break;
		
	}
	}
	else if(Cur_Reg.a2 == 1)
	{
		switch(Opcode) //Moving
		{
			case 0x00:
				Cur_Reg.a2 = 0;
				break;
				
			case 0x01:
				Cur_Reg.cx = Cur_Reg.dx;
				break;
			
			case 0x02:
				Cur_Reg.dx = Cur_Reg.cx;
				break;	
				
			case 0x09:
				Interrupt();
				break;
			
			
				
		}
		
	}
	
	}
}

