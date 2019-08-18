#include "header.h"

int XRI(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	inf->registers['A'] = logicxor(inf->registers['A'], inf->memory[inf->pc]);
	inf->registers['F'] = setFlags(inf->registers['A'], false, false);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
