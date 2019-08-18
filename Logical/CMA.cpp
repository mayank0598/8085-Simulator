#include "header.h"

int CMA(info *inf)
{
	bool tmp;
	inf->registers['A'] = complement(inf->registers['A']);
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
