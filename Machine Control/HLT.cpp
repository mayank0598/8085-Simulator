#include "header.h"

int HLT(info *inf)
{
	bool tmp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0; 
}
