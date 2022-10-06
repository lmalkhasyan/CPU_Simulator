#include "CPU_Simulator.h"

void execute(const std::multimap<std::string, size_t> &labels, cpu &my_cpu, std::map<size_t, instruction> &instructions)
{
	std::map<OPCODE,void(*)(int&, int&)> inst;
	init_alu_map(inst);
	std::map<OPCODE, void(*)(int&, int, j&)> jumps;
	init_jxx_map(jumps);
	std::map<mRegister,int*> reg_map;
	init_regs_map(reg_map, my_cpu);

	int IP = 0;
	while (instructions.find(IP) != instructions.end())
	{
		instruction temp = instructions[IP];

		if (inst.find(temp.opcode) !=  inst.end())
		{
			if (temp.src_reg == mRegister::Number)
				inst[temp.opcode](*reg_map[temp.dest_reg],temp.src_immdate);
			else
				inst[temp.opcode](*reg_map[temp.dest_reg],*reg_map[temp.src_reg]);
		}
		else if (jumps.find(temp.opcode) != jumps.end())
		{
			if (temp.opcode == OPCODE::CMP)
			{
				if (temp.src_reg == mRegister::Number)
					jumps[temp.opcode](*reg_map[temp.dest_reg],temp.src_immdate,my_cpu.flag);
				else
					jumps[temp.opcode](*reg_map[temp.dest_reg],*reg_map[temp.src_reg],my_cpu.flag);
			}
			else if(labels.count(temp.target) == 1)
			{
				jumps[temp.opcode](IP, labels.find(temp.target)->second, my_cpu.flag);
				continue;
			}
		}
	#ifdef DEBUG
		print_registers(my_cpu);
	#endif
	++IP;	
	}
}