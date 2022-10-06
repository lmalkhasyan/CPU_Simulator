#include "CPU_Simulator.h"

void print_registers(const cpu &my_cpu)
{
	std::cout <<"[R1] = " << my_cpu.registers.r1 << ' ';
	std::cout <<"[R2] = " << my_cpu.registers.r2 << ' ';
	std::cout <<"[R3] = " << my_cpu.registers.r3 << ' ';
	std::cout <<"[R4] = " << my_cpu.registers.r4 << ' ';
	std::cout <<"[R5] = " << my_cpu.registers.r5 << ' ';
	std::cout <<"[R6] = " << my_cpu.registers.r6 << ' ';
	std::cout <<"[R7] = " << my_cpu.registers.r7 << ' ';
	std::cout <<"[R8] = " << my_cpu.registers.r8 << ' ';
	std::cout <<"[R9] = " << my_cpu.registers.r9 << ' ';
	std::cout <<"[R10] = " << my_cpu.registers.r10 << ' ';
	std::cout << std::endl;

}