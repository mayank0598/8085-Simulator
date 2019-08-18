#include "./header/header.h"

/*	Display used memory and registers
*/

int display(info inf)
{
	cout<<"\nRegisters:\n";
	cout<<"A: "<<inf.registers['A']<<"\t";
	cout<<"F: "<<inf.registers['F']<<"\n";
	cout<<"B: "<<inf.registers['B']<<"\t";
	cout<<"C: "<<inf.registers['C']<<"\n";
	cout<<"D: "<<inf.registers['D']<<"\t";
	cout<<"E: "<<inf.registers['E']<<"\n";
	cout<<"H: "<<inf.registers['H']<<"\t";
	cout<<"L: "<<inf.registers['L']<<"\n";
	cout<<"\nMemory:\n";
	map<string, string>::iterator itr = inf.memory.begin();	// Iterate through memory
	while(itr != inf.memory.end())
	{
		cout<<itr->first<<": "<<itr->second<<"\t";
		++itr;
		if(itr != inf.memory.end())
		{
			cout<<itr->first<<": "<<itr->second;
			++itr;
		}
		cout<<endl;
	}
	return 0;
}

/*	Driver function
*/

int main(int argc, char **argv)
{
	info inf;	//	8085 memory, registers, program counter
	map<string, instruc> functionMap;	//	Maps string to the function
	string epc;
	bool status = false	//	status of input
	int line = 0;	//	Line number of input instruction

	//	read.cpp	int initialize(info *inf);
	initialize(&inf);	//	Initialize the registers of 8085 and prog counter

	//	read.cpp	int createFunctionMap(map<string, instruc> &functionMap);
	createFunctionMap(functionMap);	//	Create a map of string to function

	//	set.cpp		bool setData(info *inf);
	status = setData(&inf);	//	Initialize memory before starting the execution



	ifstream fin(argv[1]);	//	Initialize the input file pointer
	if(!fin)
	{
		cout << "File do not exist! Entering command line mode..." << endl;

		//	read.cpp	bool readCmds(info *inf, istream& in, bool file);
		status = readCmds(&inf, cin, false);	//	Scan commands from console if file does not exist
	}
	else
	{
		//	read.cpp	bool readCmds(info *inf, istream& in, bool file);
		status = readCmds(&inf, fin, true);	//	Scan commands from specified input file
		fin.close();	//	Free the file pointer
	}

	if(!status)
	{
		cout << "Error occurred with reading file! Exiting..." << endl;
		exit(1);
	}
	//	execute.cpp		int execute(info *inf, map<string, instruc> functionMap, int line);
	line = execute(&inf, functionMap, line);	//	Execute the assembly program
	if(line == -1)
	{
		cout << "Error occurred! Exiting..." << endl;
		exit(1);
	}
	display(inf);	//	Display the 8085 status
	return 0;
}
