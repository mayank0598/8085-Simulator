#include "header.h"
int ADI(info *inf){
	bool AC=0,CF=0;
	inf->pc = addition(inf-pc,"0001",AC,CF); //generaloperations
	string data = inf->memory[inf->pc];
	inf->registers['A'] = addition(inf->registers['A'],data,AC,CF); //generaloperations
	inf->registers['F'] = setflags(inf->registers['A'],AC,CF); //generaloperations
	inf->pc = addition(inf-pc,"0001",AC,CF); //generaloperations
	return 0;
}
