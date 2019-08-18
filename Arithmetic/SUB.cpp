#include "header.h"
int SUB(info *inf){
	bool AC=0,CF=0;
	if(inf->memory[inf->PC][4]=='M'){
		string address = inf->registers['H'] + inf->registers['L'];
		inf->registers['A'] = subtraction(inf->registers['A'],inf->memory[addres],AC,CF,false); //generaloperations
	}
	else
		inf->registers['A'] = subtraction(inf->registers['A'],inf->registers[inf->memory[inf->PC][4]],AC,CF,false); //generaloperations
	CF=!CF;	
	inf->registers['F'] = setflags(inf->registers['A'],AC,CF); //generaloperations
	inf->pc = addition(inf-pc,"0001",AC,CF); //generaloperations
	return 0;
}
