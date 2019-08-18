#include "header.h"

int MVI(info *inf)
{
	bool tmp;
	if(inf->memory[inf->pc][4] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		inf->pc = addition(inf->pc, "0001", tmp, tmp);
		inf->memory[address] = inf->memory[inf->pc];
	}
	else
	{
		char reg = inf->memory[inf->pc][4];
		inf->pc = addition(inf->pc, "0001", tmp, tmp);
		inf->registers[reg] = inf->memory[inf->pc];
	}
	inf->pc = addition(inf->pc, "0001", tmp, tmp);	
	return 0;
}
