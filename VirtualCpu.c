#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *src;
int Memory[255];

int OpCodes[8] = {
    0x00, //Exit
    0x05, //Cmp
    0x09, //Mov
    0x01, //NOP
    0x07, //Jmp
    0x08, //SysCall
    0x03, //Put 
    0x02, //Pull
};

int Register_Code[3] = {
     0x20,
     0x28,
     0x36,
};

struct Registers  {
    int cx;
    int dx;
    int adx;
} Cur_Reg;

struct Flag {
  int rf; //Result Flag
  int of; //Overflow Flag
  int nf; // Null Flag
  int ip; //Instruction Flag
} Cur_Flag;

struct Vm_Status {
    int Comparing;
    int Jumping;
    int DoNothing;
    int SysInterrupt;
    int Move;
    int IsPut;
    int IsPull;
} Cur_Stat;

struct Usage_Info {
    int IsUsingSrc;
    int Volatile;
    int NoLib;
} Cur_UsageInf;

int OpCode_Do(int Opcode)
{
    switch(Opcode)
    {
        case 0x00:
        exit(0);
        break;

        case 0x05:
        Cur_Stat.Comparing = 1;
        break;

        case 0x07:
        Cur_Stat.Jumping = 1;
        break;

	case 0x09:
	Cur_Stat.Move = 1;
	break;
    }
}

int Operand_Do(int Operand1,int Operand2)
{	
    if(Cur_Stat.Comparing == 1)
    {
        if(Operand1 == Operand2)
        {
            Cur_Flag.rf = 1;
            Cur_Stat.Comparing = 0;
            return 0;
        }
    }

    if(Cur_Stat.Comparing == 1)
    {
        if(Cur_UsageInf.IsUsingSrc == 1)
        {
            if(fseek(src,Operand1,SEEK_SET))
            {
                fprintf(stdout,"Jumped To %d",Operand1);
            }
        }
    }
    
    if(Cur_Stat.Move == 1)
    {
	Operand1 = Operand2;
	Cur_Stat.Move = 0;
    }
    Cur_Flag.ip++;
}

int* Initialize_Mem()
{
        Cur_Flag.ip = 0;
        memset(Memory,'0',255);
        return &Memory[0];
}


