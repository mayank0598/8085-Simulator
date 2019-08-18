#include "header.h"
int ANA(info *inf){
	bool tmp;
	if(inf->memory[inf->pc][4] == 'M'){
		string address = inf->registers['H'] + inf->registers['L'];
		inf->registers['A'] = logicand(inf->registers['A'], inf->memory[address]);
	}
	else{
		inf->registers['A'] = logicand(inf->registers['A'], inf->registers[inf->memory[inf->pc][4]]);
	}
	inf->registers['F'] = setFlags(inf->registers['A'], false, false);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
