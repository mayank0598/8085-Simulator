#include "header.h"

int SHLD(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	string address = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	address = inf->memory[inf->pc] + address;
	inf->memory[address] = inf->registers['L'];
	address = addition(address, "0001", tmp, tmp);
	inf->memory[address] = inf->registers['H'];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
