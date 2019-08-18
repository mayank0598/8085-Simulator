#include "header.h"

int LHLD(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	string address = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	address = inf->memory[inf->pc] + address;
	inf->registers['L'] = inf->memory[address];
	address = addition(address, "0001", tmp, tmp);
	inf->registers['H'] = inf->memory[address];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
