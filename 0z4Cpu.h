#include <stdio.h>
#include <stdlib.h>
#define GB_1 1024
#define GB_4 4024
						//4th Version Of The 0zCpu

enum Registers {
	ex,
	dx,
	bx,
	aex,
	adx,
	abx,
	zx1,
	zx2,
	zx3,
};

enum Instruction  {
	mov,
	movp,
	cmp,
	ld,
};

enum Prefix {
	none,
	val,
	addr,
};
struct Registers_32 { //32 Bit Registers
	 int aex;
	 int adx;
	 int abx;
} Cur_32_Reg;

struct Registers_16 { //16 Bit Registers
	 int ex;
	 int dx;
	 int bx;
} Cur_16_Reg;

struct Spec_Registers { //Special Registers
	 int z1;
	 int z2;
	 int z3;
} Cur_Spec_Reg;

struct Float_Register { //Precise Float Registers 
	 float zx1;
	 float zx2;
	 float zx3;
} Cur_Float_Reg;

struct Cpu { //The Cpu Itself
	 int core1;	//Opcodes
	 int core2; //This Will Handle The Registers
} Cur_Cpu;

struct Flags {
	int zf;
	int nf;
}	Cur_Flag;

struct Hardware {
	 int vga;
	 int ram[GB_4];
	int Harddrive[GB_1];
} Cur_Hardware;

struct Status {
	 int movins;
	 int cmpins;
} Cur_Status;

void Start_Cpu()
{
	Cur_Cpu.core1 = 0;
	Cur_Cpu.core2 = 0;
	
	Cur_Spec_Reg.z1 = 0x1; //Result;
}

int Store_Mem(int Instruction[],int len)
{
	if(len < GB_4) // Checks If Len Exceeds Ram Capacity   	
	{
		for(int i = 0;i<len;i++)
		{
			Cur_Hardware.ram[i] = Instruction[i];
		}
		return 1;
	}
	return 0;
}

void Decode(int Instruction[],int len)
{
	if(Store_Mem(Instruction,len) == 1)
	{
	for(int i = 0;i<len;i++)	//Main Loop
	{
		switch(Instruction[i]) //Checks The Prefix
		{
			case none: //None Prefix
				switch(Instruction[i]) //Checks For The Instruction
				{
					case mov:	//Checks If Instruction Is Cmp 
						switch(Instruction[i++]) //Checks The First Arguement Of Mov
						{
							case aex:
								 switch(Instruction[i++]) //Checks The Second Arguement Of Mov
								 {
									case aex:
										Cur_32_Reg.aex = Cur_32_Reg.aex;
										break;
									case adx:
										Cur_32_Reg.aex = Cur_32_Reg.adx;
										break;
									case abx:
										Cur_32_Reg.aex = Cur_32_Reg.abx;
										break;
									default:
										fprintf(stdout,"Moving A Non Existant Object To A Register Is False\n");
										exit(-1);
								 }
							break;
							case adx:
								 switch(Instruction[i++]) 
								 {
									case aex:
										Cur_32_Reg.adx = Cur_32_Reg.aex;
										break;
									case adx:
										Cur_32_Reg.adx = Cur_32_Reg.adx;
										break;
									case abx:
										Cur_32_Reg.adx = Cur_32_Reg.abx;
										break;
									default:
										fprintf(stdout,"Moving A Non Existant Object To A Register Is False\n");
										exit(-1);
								 }
							 break;
							case abx:
								 switch(Instruction[i++]) 
								 {
									case aex:
										Cur_32_Reg.abx = Cur_32_Reg.aex;
										break;
									case adx:
										Cur_32_Reg.abx = Cur_32_Reg.adx;
										break;
									case abx:
										Cur_32_Reg.abx = Cur_32_Reg.abx;
										break;
									default:
										fprintf(stdout,"Moving A Non Existant Object To A Register Is False\n");
										exit(-1);
								 }
							break;
							default:
								fprintf(stdout,"No Register Was Specified\n");
								exit(-1);
						}
					break;
					case cmp: //Checks If Instruction Is Cmp
						switch(Instruction[i++]) //Checks First Arguement Of Cmp
							{
								case aex:
									switch(Instruction[i++])
									{
										case aex:
											Cur_Flag.zf = ((Cur_32_Reg.aex == Cur_32_Reg.aex)?(1):(0));
											break;
										case adx:
											Cur_Flag.zf = ((Cur_32_Reg.aex == Cur_32_Reg.adx)?(1):(0));
											break;
										case abx:
											Cur_Flag.zf = ((Cur_32_Reg.aex == Cur_32_Reg.abx)?(1):(0));
											break;
										default:
											fprintf(stdout,"Comparing Something To Your Miserable Life Is False\n");
											exit(-1);
									}		
								break;
								case adx:
									switch(Instruction[i++])
									{
										case aex:
											Cur_Flag.zf = ((Cur_32_Reg.adx == Cur_32_Reg.aex)?(1):(0));
											break;
										case adx:
											Cur_Flag.zf = ((Cur_32_Reg.adx == Cur_32_Reg.adx)?(1):(0));
											break;
										case abx:
											Cur_Flag.zf = ((Cur_32_Reg.adx == Cur_32_Reg.abx)?(1):(0));
											break;
										default:
											fprintf(stdout,"Comparing Something To Your Miserable Life Is False\n");
											exit(-1);
									}
								break;
								case abx:
									switch(Instruction[i++])
									{
										case aex:
											Cur_Flag.zf = ((Cur_32_Reg.abx == Cur_32_Reg.aex)?(1):(0));
											break;
										case adx:
											Cur_Flag.zf = ((Cur_32_Reg.abx == Cur_32_Reg.adx)?(1):(0));
											break;
										case abx:
											Cur_Flag.zf = ((Cur_32_Reg.abx == Cur_32_Reg.abx)?(1):(0));
											break;
										default:
											fprintf(stdout,"Comparing Something To Your Miserable Life Is False\n");
											exit(-1);
									}
								break;
								default:
									fprintf(stdout,"No Register Was Specified To Compare\n");
									exit(-1);
							}
						break;
					case movp:	//Checks If Instruction Is Movp
						switch(Instruction[i++])
						{
							case zx1: 

						}
						
						
				}
				
		}
	}
	}
}






