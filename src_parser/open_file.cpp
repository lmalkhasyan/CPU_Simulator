#include <fstream>
#include <iostream>

void open_file(std::ifstream &input_file, char *argv[], int argc)
{
	if (argc != 2)
	{
		std::cout << "Enter ASM File to execute: [filename]" << std::endl;
		exit(EXIT_FAILURE);
	}
    input_file.open(argv[1]);

    if (!input_file.is_open())
	{
		std::cout << "Can't Open File: " << argv[1] << std::endl;  
        exit(EXIT_FAILURE);
	}

}