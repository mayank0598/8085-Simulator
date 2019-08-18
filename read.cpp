#include "header.h"

int initialize(info *inf)
{
	string pc;
	cout<<"Enter starting address: ";
	while(!valid_address(pc))
		cin>>pc;
	inf->pc = pc;
	inf->registers['A'] = "00";
	inf->registers['F'] = "00";
	inf->registers['B'] = "00";
	inf->registers['C'] = "00";
	inf->registers['D'] = "00";
	inf->registers['E'] = "00";
	inf->registers['H'] = "00";
	inf->registers['L'] = "00";
	return 0;
}

int createFunctionMap(map<string, instruc> &functionMap)
{
	functionMap["MOV"] = MOV;
	functionMap["XCHG"] = XCHG;
	functionMap["ADD"] = ADD;
	functionMap["SUB"] = SUB;
	functionMap["INR"] = INR;
	functionMap["DCR"] = DCR;
	functionMap["INX"] = INX;
	functionMap["DCX"] = DCX;
	functionMap["DAD"] = DAD;
	functionMap["CMA"] = CMA;
	functionMap["CMP"] = CMP;
	functionMap["LDAX"] = LDAX;
	functionMap["STAX"] = STAX;
	functionMap["ANA"] = ANA;
	functionMap["ORA"] = ORA;
	functionMap["XRA"] = XRA;
	functionMap["MVI"] = MVI;
	functionMap["ADI"] = ADI;
	functionMap["SUI"] = SUI;
	functionMap["CPI"] = CPI;
	functionMap["ANI"] = ANI;
	functionMap["ORI"] = ORI;
	functionMap["XRI"] = XRI;
	functionMap["LDA"] = LDA;
	functionMap["STA"] = STA;
	functionMap["LXI"] = LXI;
	functionMap["LHLD"] = LHLD;
	functionMap["SHLD"] = SHLD;
	functionMap["JMP"] = JMP;
	functionMap["JC"] = JC;
	functionMap["JNC"] = JNC;
	functionMap["JZ"] = JZ;
	functionMap["JNZ"] = JNZ;
	functionMap["HLT"] = HLT;
	return 0;
}

info *add_to_memory(info *inf, string cmd, string &pc)
{
	vector<string> parts = getParts(cmd);
	int space = cmd.find(' ');
	string str;
	if(space == -1)
		str = cmd;
	else
		str = cmd.substr(0, space);
	bool tmp;
	switch(instruc_size(str))
	{
		case 1:
			inf->memory[pc] = parts[0];
			pc = addition(pc, "0001", tmp, tmp);
			break;
		case 2:
			inf->memory[pc] = parts[0];
			pc = addition(pc, "0001", tmp, tmp);
			inf->memory[pc] = parts[1];
			pc = addition(pc, "0001", tmp, tmp);
			break;
		case 3:
			inf->memory[pc] = parts[0];
			pc = addition(pc, "0001", tmp, tmp);
			inf->memory[pc] = parts[1].substr(2, 2);
			pc = addition(pc, "0001", tmp, tmp);
			inf->memory[pc] = parts[1].substr(0, 2);
			pc = addition(pc, "0001", tmp, tmp);
			break;
	}
	return inf;
}

/*string convert_upper(string str)
{
	for(int i = 0; i < str.length(); ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	}
	return str;
}*/

bool readCmds(info *inf, istream& in, bool file)
{
	if(!file)
		cout << "Enter the instructions (Enter \'./\' to finish):" << endl;
	while(true)
	{
		string str;
		static string pc = inf->pc;
		if(!file)
			cout << pc << " : ";
		getline(in, str);
		str = convert_upper(str);
		if(str.compare("./") == 0)
			return true;
		if(instruction_check(str))
		{
			inf = add_to_memory(inf, str, pc);
			inf->cmds.push_back(str);
			inf->breaks.push_back(false);
		}
		else if(file)
			return false;
		else
			cout << "Invalid instruction! Enter again." << endl;
	}
	return true;
}
