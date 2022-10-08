#include <stdio.h>
#include <stdlib.h>
#define Max_Mem 4000

enum Reg_List {
	cdx,
	adx,
	acx,
	a1,
	a2,
	a3,
	asp,
};
enum Instructions {
	mov,
	cmp,
	jmp,
	add,
	sub,
	mul,
	idiv,
};

enum Prefixes {
	none,
	val,
	addr,
};
struct Registers {
	int cdx;
	int adx;
	int acx;
	int a1;
	int a2;
	int a3;
	int asp;
	int mp;
} Cur_Reg;

struct Flags {
	int zf;
	int nf;
} Cur_Flag;

struct  Status { 
	int ismove;
	int iscompare;
	int isjump;
	int isarithematic;
} Cur_Status;

int Do_Opcode(int Opcode[]);

int Pass_Ins(int Opcode[])
{
	switch(Opcode[1]) //Checks The Instruction
	{
		case mov:
			Cur_Status.ismove = 1;
			Do_Opcode(Opcode);
			Cur_Status.ismove = 0;
			break;
		case cmp:
			Cur_Status.iscompare = 1;
			Do_Opcode(Opcode);
			Cur_Status.iscompare = 0;
			break;
		case add:
			Cur_Status.isarithematic = 1;
			Do_Opcode(Opcode);
			Cur_Status.isarithematic = 0;
			break;
		case sub:
			Cur_Status.isarithematic = 1;
			Do_Opcode(Opcode);
			Cur_Status.isarithematic = 0;
			break;
		case mul:
			Cur_Status.isarithematic = 1;
			Do_Opcode(Opcode);
			Cur_Status.isarithematic = 0;
		case idiv:
			Cur_Status.isarithematic = 1;
			Do_Opcode(Opcode);
			Cur_Status.isarithematic = 0;
			
	}
}

int Do_Opcode(int Opcode[])
{
	
	if(Cur_Status.ismove == 1)
	{		
					switch(Opcode[2]) // Checks For The 1st Arguement
					{
						case cdx: 	
						
							if(Opcode[0] == val)
							{
									Cur_Reg.cdx = Opcode[3];
									break;
							}		
									
							switch(Opcode[3]) //Checks For 2nd Arguement
							{
									
								case cdx:
									fprintf(stdout,"error! cannot move a register to itself\n");
									exit(1);
								
								case adx:
									Cur_Reg.cdx = Cur_Reg.adx;
									break;
									
								case acx:
									Cur_Reg.cdx = Cur_Reg.acx;
									break;
								
								case a1:
									Cur_Reg.cdx = Cur_Reg.a1;
									break;
									
								case asp:
									Cur_Reg.cdx = Cur_Reg.asp;
									break;
									
								default:
									fprintf(stdout,"Missing 2nd Arguement!\n");
									exit(1);
							}
						break;
						
						case adx:
						
							if(Opcode[0] == val)
							{
									Cur_Reg.adx = Opcode[3];
									break;
							}		
							
							switch(Opcode[3])
							{
									
								case cdx:
									Cur_Reg.adx = Cur_Reg.cdx;
									break;
								
								case adx:
									fprintf(stdout,"error! cannot move a register to itself\n");
									exit(1);
									
								case acx:
									Cur_Reg.adx = Cur_Reg.acx;
									break;
								
								case a1:
									Cur_Reg.adx = Cur_Reg.a1;
									break;
									
								case asp:
									Cur_Reg.adx = Cur_Reg.asp;
									break;
								
								default:
									fprintf(stdout,"Missing 2nd Arguement!\n");		
									exit(1);
							}
						break;
						case acx:
						
							if(Opcode[0] == val)
							{
									Cur_Reg.acx = Opcode[3];
									break;
							}		
							
							switch(Opcode[3])
							{
							
								case cdx:
									Cur_Reg.acx = Cur_Reg.cdx;
									break;
								
								case adx:
									Cur_Reg.acx = Cur_Reg.adx;
									break;
									
								case acx:
									fprintf(stdout,"error! cannot move a register to itself\n");
									exit(1);
								
								case a1:
									Cur_Reg.acx = Cur_Reg.a1;
									break;
									
								case asp:
									Cur_Reg.acx = Cur_Reg.asp;
									break;
									
								default:
									fprintf(stdout,"Missing 2nd Arguement!\n");
									exit(1);
							}
					    break;
						case a1:
						
							if(Opcode[0] == val)
							{
									Cur_Reg.a1 = Opcode[3];
									break;
							}		
							
							switch(Opcode[3])
							{
							
								case cdx:
									Cur_Reg.a1 = Cur_Reg.cdx;
									break;
								
								case adx:
									Cur_Reg.a1 = Cur_Reg.adx;
									break;
									
								case acx:
									Cur_Reg.a1 = Cur_Reg.acx;
									break;
								
								case a1:
									fprintf(stdout,"error! cannot move a register to itself\n");
									exit(1);
									
								case asp:
									Cur_Reg.a1 = Cur_Reg.asp;
									break;
									
								default:
									fprintf(stdout,"Missing 2nd Arguement!\n");
									exit(1);
							}
						break;
						default:
							fprintf(stdout,"Arguement Is Not A Register\n");
							exit(1);
								
					}
					
	}	
	
	if(Cur_Status.iscompare == 1)
	{
		switch(Opcode[2]) // Checks For The 1st Arguement Of Cmp
					{
						case cdx: 	
							if(Opcode[0] == val && Cur_Reg.cdx == Opcode[3]) //Checks If Val Prefix Is Present
							{
									Cur_Flag.zf = 1;
									break;
							}		
									
							switch(Opcode[3]) //Checks For 2nd Arguement
							{
									
								case cdx:
									if(Cur_Reg.cdx == Cur_Reg.cdx)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								case adx:
									if(Cur_Reg.cdx == Cur_Reg.adx)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								case acx:
									if(Cur_Reg.cdx == Cur_Reg.acx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case a1:
									if(Cur_Reg.cdx == Cur_Reg.a1)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								default:
									fprintf(stdout,"Error:Cant Compare A Register To Your Imagination\n");
									exit(1);
							}
						break;
						
						case adx:
						
							if(Opcode[0] == val && Cur_Reg.adx == Opcode[3])
							{
									Cur_Flag.zf = 1;
									break;
							}		
							
							switch(Opcode[3])
							{
									
								case cdx:
									if(Cur_Reg.adx == Cur_Reg.cdx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case adx:
									if(Cur_Reg.adx == Cur_Reg.adx)
									{
										Cur_Flag.zf = 1;
									}
									exit(1);
									
								case acx:
									if(Cur_Reg.adx == Cur_Reg.acx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case a1:
									if(Cur_Reg.adx == Cur_Reg.a1)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								default:
									fprintf(stdout,"Error:Cant Compare A Register To Your Imagination\n");
									exit(1);
							}
						break;
						case acx:
						
							if(Opcode[0] == val && Cur_Reg.acx == Opcode[3])
							{
									Cur_Flag.zf = 1;
									break;
							}		
							
							switch(Opcode[3])
							{
						
								case cdx:
									if(Cur_Reg.acx == Cur_Reg.cdx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case adx:
									if(Cur_Reg.acx == Cur_Reg.adx)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								case acx:
									if(Cur_Reg.acx == Cur_Reg.acx)
									{
										Cur_Flag.zf = 1;
									}
									exit(1);
								
								case a1:
									if(Cur_Reg.acx == Cur_Reg.a1)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								default:
									fprintf(stdout,"Error:Cant Compare A Register To Your Imagination\n");
									exit(1);
							}
					    break;
						case a1:
						
							if(Opcode[0] == val && Cur_Reg.a1 == Opcode[3])
							{
									Cur_Flag.zf = 1;
									break;
							}		
							
							switch(Opcode[3])
							{
							
								case cdx:
									if(Cur_Reg.a1 == Cur_Reg.cdx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case adx:
									if(Cur_Reg.a1 == Cur_Reg.adx)
									{
										Cur_Flag.zf = 1;
									}
									break;
									
								case acx:
									if(Cur_Reg.a1 == Cur_Reg.acx)
									{
										Cur_Flag.zf = 1;
									}
									break;
								
								case a1:
									if(Cur_Reg.a1 == Cur_Reg.a1)
									{
										Cur_Flag.zf = 1;
									}
									exit(1);
									
								default:
									fprintf(stdout,"Error:Cant Compare A Register To Your Imagination\n");
									exit(1);
							}
						break;
						default:
							fprintf(stdout,"Your Arguements Are False! Error:No Register Specified\n");
							exit(1);
								
					}
	}
	
	if(Cur_Status.isarithematic == 1)
	{
		switch(Opcode[1])
		{
			case add: //Every Arithematic Instruction Stores The Result In The Source Register
					//cdx = cdx + register 
				switch(Opcode[2])
				{
					case cdx:
						Cur_Reg.cdx = Cur_Reg.cdx + Cur_Reg.cdx;
						break; 
					case adx:
						Cur_Reg.cdx = Cur_Reg.cdx + Cur_Reg.adx;
						break;
					case acx:
						Cur_Reg.cdx = Cur_Reg.cdx + Cur_Reg.acx;
						break;
					case a1: 
						Cur_Reg.cdx = Cur_Reg.cdx + Cur_Reg.a1;
						break;
					default:
						fprintf(stdout,"1+NULL = NULL Error:No Register Was Specified\n");
						exit(1);
				}
			break;
			
			case sub:
				switch(Opcode[2])
				{
					case cdx:
						Cur_Reg.cdx = Cur_Reg.cdx - Cur_Reg.cdx;
						break; 
					case adx:
						Cur_Reg.cdx = Cur_Reg.cdx - Cur_Reg.adx;
						break;
					case acx:
						Cur_Reg.cdx = Cur_Reg.cdx - Cur_Reg.acx;
						break;
					case a1: 
						Cur_Reg.cdx = Cur_Reg.cdx - Cur_Reg.a1;
						break;
					default:
						fprintf(stdout,"1-NULL = NULL Error:No Register Was Specified\n");
						exit(1);
				}
			break;
			
			case mul:
				switch(Opcode[2])
				{
					case cdx:
						Cur_Reg.cdx = Cur_Reg.cdx * Cur_Reg.cdx;
						break; 
					case adx:
						Cur_Reg.cdx = Cur_Reg.cdx * Cur_Reg.adx;
						break;
					case acx:
						Cur_Reg.cdx = Cur_Reg.cdx * Cur_Reg.acx;
						break;
					case a1: 
						Cur_Reg.cdx = Cur_Reg.cdx * Cur_Reg.a1;
						break;
					default:
						fprintf(stdout,"1*NULL = NULL Error:No Register Was Specified\n");
						exit(1);
				}
			break;
			
			case idiv:
				switch(Opcode[2])
				{
					case cdx:
						Cur_Reg.cdx = Cur_Reg.cdx / Cur_Reg.cdx;
						break; 
					case adx:
						Cur_Reg.cdx = Cur_Reg.cdx / Cur_Reg.adx;
						break;
					case acx:
						Cur_Reg.cdx = Cur_Reg.cdx / Cur_Reg.acx;
						break;
					case a1: 
						Cur_Reg.cdx = Cur_Reg.cdx / Cur_Reg.a1;
						break;
					default:
						fprintf(stdout,"1/NULL = Undefined Behavior Error:No Register Was Specified\n");
						exit(1);
				}
		}
	}
}
