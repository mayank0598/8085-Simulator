#include "header.h"

int ORA(info *inf)
{
	bool tmp;
	if(inf->memory[inf->pc][4] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		inf->registers['A'] = logicor(inf->registers['A'], inf->memory[address]);
	}
	else
	{
		inf->registers['A'] = logicor(inf->registers['A'], inf->registers[inf->memory[inf->pc][4]]);
	}
	inf->registers['F'] = setFlags(inf->registers['A'], false, false);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
