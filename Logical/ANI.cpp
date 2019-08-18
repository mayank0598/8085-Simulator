#include "header.h"

int ANI(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	inf->registers['A'] = logicand(inf->registers['A'], inf->memory[inf->pc]);
	inf->registers['F'] = setFlags(inf->registers['A'], false, false);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
