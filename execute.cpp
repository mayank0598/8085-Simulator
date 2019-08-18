#include "header.h"

/*	Execute the assembly program from current program counter
*/
int execute(info *inf, map<string, instruc> functionMap, int line)
{
	while(true)
	{
		//	Extracting opcode mnemonic for the instruction
		int len = inf->memory[inf->pc].find(' ');
		if(len == -1)
			len = inf->memory[inf->pc].length();
		string op = inf->memory[inf->pc].substr(0, len);

		//	Execute function corresponding to the opcode
		functionMap[op](inf);

		//	Increment line number
		++line;

		if(op.compare("HLT") == 0)	//	If "HLT" is encountered, stop the execution of assembly program
		{
			cout << "Execution complete!" << endl;
			return INT_MIN;
		}

		//	Return error flag if next instruction is not found in memory
		if(inf->memory.find(inf->pc) == inf->memory.end())
			return -1;

		//	Return current line number if breakpoint is encountered
		if(inf->breaks[line-1])
			return line;
	}
	return line;
}
