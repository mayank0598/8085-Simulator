#include "header.h"

int STA(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	string address = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	address = inf->memory[inf->pc] + address;
	inf->memory[address] = inf->registers['A'];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
