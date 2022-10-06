#include "CPU_Simulator.h"

instruction parse(std::string &line, std::multimap<std::string, size_t> &labels, size_t line_num)
{
	instruction curr;
	check_labels(line);
    toLowerCase(line);
	auto str_vec = split(line, ", ");
    map_labels(str_vec, line_num, labels);
	if(str_vec.size() > 3)
	{
		curr.opcode = OPCODE::ERROR;
		return curr;
	}

	curr.opcode = get_opcode(str_vec[0]);
	if(curr.opcode == OPCODE::JMP || curr.opcode == OPCODE::JE
	 || curr.opcode == OPCODE::JG || curr.opcode == OPCODE::JL )
	{
		curr.target = str_vec[1];
	}
	else
	{
		curr.dest_reg = get_register(str_vec[1]);
	}
	if (str_vec.size() == 3)
	{
		if(curr.opcode == OPCODE::INC || curr.opcode == OPCODE::NOT || curr.opcode == OPCODE::DEC)
		{
			curr.opcode = OPCODE::ERROR;
		}
		else if(is_number(str_vec[2]))
		{
			curr.src_immdate = std::stoi(str_vec[2]);
			curr.src_reg = mRegister::Number;
		}
		else
		{
			curr.src_reg = get_register(str_vec[2]);
		}
		
	}
	return curr;
}