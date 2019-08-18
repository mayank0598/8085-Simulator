#include "header.h"

int LXI(info *inf)
{
	bool tmp;
	char low, high;
	if(inf->memory[inf->pc][4] == 'B')
	{
		low = 'C';
		high = 'B';
	}
	else if(inf->memory[inf->pc][4] == 'D')
	{
		low = 'E';
		high = 'D';
	}
	else if(inf->memory[inf->pc][4] == 'H')
	{
		low = 'L';
		high = 'H';
	}
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	inf->registers[low] = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	inf->registers[high] = inf->memory[inf->pc];
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
