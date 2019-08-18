#include "header.h"

int DCX(info *inf)
{
	bool AC = 0, CF = 0, tmp;
	if(inf->memory[inf->pc][4] == 'B')
	{
		string data = inf->registers['B'] + inf->registers['C'];
		data = subtraction(data, "0001", AC, CF, true);
		inf->registers['B'] = data.substr(0, 2);
		inf->registers['C'] = data.substr(2, 2);
	}
	else if(inf->memory[para->pc][4] == 'D')
	{
		string data = inf->registers['D'] + inf->registers['E'];
		data = subtraction(data, "0001", AC, CF, true);
		inf->registers['D'] = data.substr(0, 2);
		inf->registers['E'] = data.substr(2, 2);
	}
	else if(inf->memory[para->pc][4] == 'H')
	{
		string data = para->registers['H'] + inf->registers['L'];
		data = subtraction(data, "0001", AC, CF, true);
		inf->registers['H'] = data.substr(0, 2);
		inf->registers['L'] = data.substr(2, 2);
	}
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
