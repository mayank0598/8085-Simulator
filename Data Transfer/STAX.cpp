#include "header.h"

int STAX(info *inf)
{
	string address;
	bool tmp;
	if(inf->memory[inf->pc][5] == 'B')
		address = inf->registers['B'] + inf->registers['C'];
	else if(inf->memory[inf->pc][5] == 'D')
		address = inf->registers['D'] + inf->registers['E'];
	else if(inf->memory[inf->pc][5] == 'H')
		address = inf->registers['H'] + inf->registers['L'];
	inf->memory[address] = inf->registers['A'];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
