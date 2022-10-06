#include <CPU_Simulator.h>

void init_alu_map(std::map<OPCODE,void(*)(int&, int&)> &map)
{
	map = {{OPCODE::ADD, add}, {OPCODE::SUB, sub}, 
			{OPCODE::MUL, mul}, {OPCODE::DIV, div},
			{OPCODE::AND, m_and}, {OPCODE::OR, m_or},
			{OPCODE::XOR, m_xor}, {OPCODE::INC, inc},
			{OPCODE::DEC, dec}, {OPCODE::NOT, m_not}, 
			{OPCODE::MOV, mov}};
}

void init_jxx_map(std::map<OPCODE, void(*)(int&, int, j&)> &map)
{
	map = {{OPCODE::JMP, jmp}, {OPCODE::JE, je}, 
			{OPCODE::JG, jg}, {OPCODE::JL, jl}, 
			{OPCODE::CMP, cmp}};
}

void init_regs_map(std::map<mRegister,int*> &map, cpu &my_cpu)
{
	map = {{mRegister::r1, &my_cpu.registers.r1}, {mRegister::r2, &my_cpu.registers.r2},
			{mRegister::r3, &my_cpu.registers.r3}, {mRegister::r4, &my_cpu.registers.r4},
			{mRegister::r5, &my_cpu.registers.r5}, {mRegister::r6, &my_cpu.registers.r6},
			{mRegister::r7, &my_cpu.registers.r7}, {mRegister::r8, &my_cpu.registers.r8},
			{mRegister::r9, &my_cpu.registers.r9}, {mRegister::r10, &my_cpu.registers.r10}};
}