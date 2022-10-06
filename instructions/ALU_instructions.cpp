#include "CPU_Simulator.h"
#include <iostream>

void add(int &dst, int &src)
{
    dst += src;
}

void sub(int &dst, int &src)
{
    dst -= src;
}

void mul(int &dst, int &src)
{
    dst *= src;
}

void div(int &dst, int &src)
{
    if (src == 0)
    {
        std::cout << "Exeption::Division by 0" << std::endl;
        exit(EXIT_FAILURE);
    }
    dst /= src;
}

void inc(int &reg, int&)
{
    ++reg;
}

void dec(int &reg, int&)
{
    --reg;
}

void m_and(int &dst, int &src)
{
    dst &= src;
}

void m_or(int &dst, int &src)
{
    dst |= src;
}

void m_xor(int &dst, int &src)
{
    dst ^= src;
}

void m_not(int &reg, int&)
{
    reg = ~reg;
}


void mov(int &dst, int &src)
{
    dst = src;
}

void cmp(int &dst, int src, j &flag)
{
    int temp = dst;
    temp -= src;
    if(temp == 0)
        flag = j::e;
    else if(temp < 0)
        flag = j::l;
    else 
        flag = j::g;
}