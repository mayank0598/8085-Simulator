#include "header.h"

int CMP(info *inf)
{
	string hex;
	bool AC, CF, tmp;
	if(inf->memory[inf->pc][4] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		hex = subtraction(inf->registers['A'], inf->memory[address], AC, CF, false);
	}
	else
		hex = subtraction(inf->registers['A'], inf->registers[inf->memory[inf->pc][4]], AC, CF, false);
	CF = !CF;
	inf->registers['F'] = setFlags(hex, AC, CF);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
