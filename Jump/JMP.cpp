#include "header.h"

int JMP(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	string address = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	address = inf->memory[inf->pc] + address;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	if(inf->memory.find(address) != inf->memory.end())
		inf->pc = address;
	else
		return 1;
	return 0;
}
