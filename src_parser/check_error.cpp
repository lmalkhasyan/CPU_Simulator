#include "CPU_Simulator.h"

void check_error(instruction &curr, int line)
{
	if (curr.dest_reg == mRegister::ERROR)
	{
		std::cout << "Error in Line: " << line << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (curr.src_reg == mRegister::ERROR)
	{
		std::cout << "Error in Line: " << line << std::endl;
		exit(EXIT_FAILURE);
	}
	else if (curr.opcode == OPCODE::ERROR)
	{
		std::cout << "Error in Line: " << line << std::endl;
		exit(EXIT_FAILURE);
	}
}