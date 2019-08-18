#include "header.h"

int CPI(info *inf)
{
	bool AC, CF, tmp;
	string hex;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	hex = subtraction(inf->registers['A'], inf->memory[inf->pc], AC, CF, false);
	CF = !CF;
	inf->registers['F'] = setFlags(hex, AC, CF);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
