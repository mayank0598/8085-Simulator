#include "header.h"

int MOV(info *inf)
{
	bool tmp;
	if(inf->memory[inf->pc][4] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		inf->memory[address] = inf->registers[inf->memory[inf->pc][6]];
	}
	else if(inf->memory[inf->pc][6] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		inf->registers[inf->memory[inf->pc][4]] = inf->memory[address];
	}
	else
		inf->registers[inf->memory[inf->pc][4]] = inf->registers[inf->memory[inf->pc][6]];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
