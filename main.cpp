#include "CPU_Simulator.h"

int main(int argc, char *argv[])
{
	cpu my_cpu;
	cpu_init(my_cpu);
    std::ifstream input_file;
	open_file(input_file, argv, argc);

	std::map<size_t, instruction> instructions;
	std::multimap<std::string, size_t> labels;
    std::string buffer;
    size_t line = 0;
    while (!input_file.eof())
	{
		std::getline(input_file, buffer);
        if (buffer[0] == '\0')
            continue;
		instructions[line] = parse(buffer, labels, line);
		check_error(instructions[line], line+1);
		++line;
    }
	execute(labels, my_cpu, instructions);
	return 0;
}