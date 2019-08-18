#include "header.h"
int DCR(info *inf){
	bool AC=0,CF=0,tmp;
	if(inf->memory[inf->pc][4] == 'M')
	{
		string address = inf->registers['H'] + inf->registers['L'];
		inf->memory[address] = subtraction(inf->memory[address], "01", AC, CF, false);
		CF = !CF;
		inf->registers['F'] = setFlags(inf->memory[address], AC, CF);
	}
	else
	{
		inf->registers[inf->memory[inf->pc][4]] = subtraction(inf->registers[inf->memory[inf->pc][4]], "01", AC, CF, false);
		CF = !CF;
		inf->registers['F'] = setFlags(inf->registers[inf->memory[inf->pc][4]], AC, CF);
	}
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
