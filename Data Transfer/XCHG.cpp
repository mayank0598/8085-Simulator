#include "header.h"

int XCHG(info *inf)
{
	string temp;
	bool tmp;
	temp = inf->registers['D'];
	inf->registers['D'] = inf->registers['H'];
	inf->registers['H'] = temp;
	temp = inf->registers['E'];
	inf->registers['E'] = inf->registers['L'];
	inf->registers['L'] = temp;
	inf->pc = addition(inf->pc, "0001", tmp, tmp);
	return 0;
}
