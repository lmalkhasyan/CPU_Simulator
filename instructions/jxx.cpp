#include "CPU_Simulator.h"

void jmp(int &IP, int line_num, j &flag)
{
    IP = line_num;
}

void je(int &IP, int line_num, j &flag)
{
    if(flag == j::e)
        IP = line_num;
}

void jg(int &IP, int line_num, j &flag)
{
    if(flag == j::g)
        IP = line_num;
    
}

void jl(int &IP, int line_num, j &flag)
{
    if(flag == j::l)
        IP = line_num;
}