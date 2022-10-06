#include "CPU_Simulator.h"

OPCODE get_opcode(const std::string &token)
{
	std::map<std::string,OPCODE> map_op{{"add", OPCODE::ADD}, {"sub", OPCODE::SUB}, {"mul", OPCODE::MUL},
                     {"div", OPCODE::DIV}, {"and", OPCODE::AND}, {"or", OPCODE::OR},{"xor", OPCODE::XOR}, 
					 {"inc", OPCODE::INC}, {"dec", OPCODE::DEC}, {"not", OPCODE::NOT},
					 {"jmp", OPCODE::JMP}, {"je", OPCODE::JE}, {"mov", OPCODE::MOV}, {"cmp", OPCODE::CMP},
        				{"jg", OPCODE::JG}, {"jl", OPCODE::JL}};
	if (map_op.count(token))
	{
		return map_op[token];
	}
	return OPCODE::ERROR;
}

mRegister get_register(const std::string &token)
{
	std::map<std::string,mRegister> map_reg{{"r1", mRegister::r1}, {"r2", mRegister::r2}, {"r3", mRegister::r3},
                     {"r4", mRegister::r4}, {"r5", mRegister::r5}, {"r6", mRegister::r6},{"r7", mRegister::r7}, 
					 {"r8", mRegister::r8}, {"r9", mRegister::r9}, {"r10", mRegister::r10}};
	if (map_reg.count(token))
	{
		return map_reg[token];
	}
	return mRegister::ERROR;
}