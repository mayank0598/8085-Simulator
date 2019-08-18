#include "header.h"

int JC(info *inf)
{
	string flag = to_bin(inf->registers['F']);
	bool t;
	if(flag[7] == '1')
	{
		inf->pc = addition(inf->pc, "0001", t, t);
		string address = inf->memory[inf->pc];
		inf->pc = addition(inf->pc, "0001", t, t);
		address = inf->memory[inf->pc] + address;
		inf->pc = addition(inf->pc, "0001", t, t);
		if(inf->memory.find(address) != inf->memory.end())
			inf->pc = address;
		else
			return 1;
	}
	else
		inf->pc = addition(inf->pc, "0003", t, t);
	return 0;
}
