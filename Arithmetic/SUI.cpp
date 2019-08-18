#include "header.h"
int ADI(info *inf){
	bool AC=0,CF=0,temp;
	inf->pc = addition(inf-pc,"0001",temp,temp); //generaloperations
	string data = inf->memory[inf->pc];
	inf->registers['A'] = subtraction(inf->registers['A'],data,AC,CF,false); //generaloperations
	CF=!CF;
	inf->registers['F'] = setflags(inf->registers['A'],AC,CF); //generaloperations
	inf->pc = addition(inf-pc,"0001",temp,temp); //generaloperations
	return 0;
}
