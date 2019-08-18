#include "header.h"

int DAD(info *inf)
{
	bool AC = 0, CF = 0, tmp;
	string hex1 = inf->registers['H'] + inf->registers['L'], hex2;
	if(inf->memory[inf->pc][4] == 'B')
		hex2 = inf->registers['B'] + inf->registers['C'];
	else if(inf->memory[inf->pc][4] == 'D')
		hex2 = inf->registers['D'] + inf->registers['E'];
	else if(inf->memory[inf->pc][4] == 'H')
		hex2 = inf->registers['H'] + inf->registers['L'];
	hex1 = addition(hex1, hex2, AC, CF);
	inf->registers['H'] = hex1.substr(0, 2);
	inf->registers['L'] = hex1.substr(2, 2);
	inf->registers['F'] = setFlags(inf->registers['H']+inf->registers['L'], AC, CF);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
