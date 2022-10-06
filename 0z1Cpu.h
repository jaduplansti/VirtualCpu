#include <stdio.h>
#include <stdlib.h>
#define Protected_Mode 1 
#define Real_Mode 0
#define Interrupt_Mode 2
#define Read 3
#define Max_Mem 1000
#define  Get_Op fscanf(fp,"%1x",&Opcode)
#define  Put_Mem Access_Memory(Opcode,Cur_Mem.Cur_Mode)
FILE *fp;
struct Inf_Flag {
	int zf;
	int of;
	int ip;
	int mp;
} Cur_Flag;

struct Inf_Reg {
	int cx; //0x2
	int dx; //0x8
	int a1; //Interrupt Register 0x3
} Cur_Reg;
int Opcode;

struct Mem_Info {
	int Cur_Mode;
	int Cur_Size;

} Cur_Mem;

int Access_Memory(int Val,int Mode)
{
	switch(Mode)
	{
		case Protected_Mode:
			static int Protected_Mem[Max_Mem];
			Protected_Mem[Cur_Flag.mp] = Val;
			break;
		case Real_Mode:
			static int Real_Mem[Max_Mem];
			Real_Mem[Cur_Flag.mp] = Val;
			break;
		case Read:
			return Real_Mem[Val];

	}
	Cur_Flag.mp++;
}

void *Access_Cpu(int Cpu_Mode)
{
	switch(Cpu_Mode)
	{
		case Protected_Mode:
			Cur_Mem.Cur_Mode = Protected_Mode;
			Access_Memory(0,Protected_Mode);
			break;
		case Real_Mode:
			Cur_Mem.Cur_Mode = Real_Mode;
			Access_Memory(0,Real_Mode);
			break;
		case Interrupt_Mode:
			printf("Registers:a1:%d cx:%d dx:%d\n",Cur_Reg.a1,Cur_Reg.cx,Cur_Reg.dx);
			if(Cur_Reg.a1 == 0)
			{
				exit(0);
			}
			if(Cur_Reg.a1 == 1 && Cur_Reg.cx == 9)
			{
				printf("%d",Cur_Reg.dx);
			}
			if(Cur_Reg.a1 == 1 && Cur_Reg.cx == 0)
			{
				scanf("%d",&Cur_Reg.dx);
			}
			if(Cur_Reg.a1 == 0 && Cur_Reg.cx == 1)
			{
				exit(-1);
			}
			if(Cur_Reg.a1 == 1 && Cur_Reg.cx == 1)
			{
				putc('\n',stdout);
			}
	}
}

int Start_Machine(int Mode)
{
	Cur_Flag.mp = 0;
	Cur_Flag.ip = 0;
	Cur_Reg.a1 = -1;
	switch(Mode)
	{
		case 0:			//Starts The Machine In Protected Mode
			
			Access_Cpu(Protected_Mode);
			break;

		case 1:			//Starts The Machine In Real Mode
			Access_Cpu(Real_Mode);
			break;

		case 3:			//Debug Mode
			break;		
	} 
}

int Shutdown_Machine()
{
	Cur_Reg.a1 = 0; // 0 Is The Shutdown Interrupt Int
	Access_Cpu(Interrupt_Mode);
}



int Rec_Ins() {
	while(!feof(fp))
	{	
		Get_Op;
		Put_Mem;
	       if(Opcode == 0x01)
		{
			Get_Op;
			Put_Mem;
			Cur_Reg.cx = Opcode;
			Opcode = 0;
		}
	       	if(Opcode == 0x02)
		{
			Get_Op;
			Put_Mem;
			Cur_Reg.dx = Opcode;
			Opcode = 0;
		}
		if(Opcode == 0x03)
		{
			Cur_Reg.a1 = Cur_Reg.cx;
		}
		if(Opcode == 0x04)
		{
			Cur_Reg.a1 = Cur_Reg.dx;
		}
		if(Opcode == 0x05)
		{
			Access_Cpu(Interrupt_Mode);
		}
		if(Opcode == 0x06)
		{
			Get_Op;
			Put_Mem;
			switch(Opcode)
			{
				case 0x2:
					Get_Op;
					Put_Mem;
					Cur_Reg.cx+=Opcode;
					Opcode = 0;
					break;
				case 0x8:
					Get_Op;
					Put_Mem;
					Cur_Reg.dx+=Opcode;
					Opcode = 0;
					break;
			}
		}
		if(Opcode == 0x07)
		{
			Get_Op;
			Put_Mem;
			switch(Opcode)
			{
				case 0x2:
					Get_Op;
					Put_Mem;
					Cur_Reg.cx-=Opcode;
					Opcode = 0;
					break;
				case  0x8:
					Get_Op;
					Put_Mem;
					Cur_Reg.dx-=Opcode;
					Opcode = 0;
					break;
			}
		}
		if(Opcode == 0x08)
		{	
			if(Cur_Reg.cx == Cur_Reg.dx)
			{
				Cur_Flag.zf = 1;
			}
	                
		}

	}

}


