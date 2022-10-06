#ifndef CPU_SIMULATOR
#define CPU_SIMULATOR

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

// #define DEBUG // Output Registers after cmd 

enum class OPCODE
{
    ADD,SUB,MUL,DIV,INC,DEC,AND,OR,XOR,NOT,
    CMP,MOV,JMP,JE,JG,JL, NAN = 999,
    ERROR = 1000
};

enum class mRegister
{
    r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,
    Number = 999, ERROR = 1000
};

enum class j
{
    e,l,g
};

struct instruction
{
    OPCODE opcode;
    mRegister dest_reg;
    mRegister src_reg;
    int src_immdate;
    std::string target;
};

struct cpu 
{   
    struct regs{int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;}registers;
    j flag;
}; 

// Debug CPU
void print_registers(const cpu &my_cpu);

// Binary Instructions
    void add(int &dst, int &src);
    void sub(int &dst, int &src);
    void mul(int &dst, int &src);
    void div(int &dst, int &src);
    void m_and(int &dst, int &src);
    void m_or(int &dst, int &src);
    void m_xor(int &dst, int &src);
    void mov(int &dst, int &src);
    void cmp(int &dst, int src, j &flag);

// unary Instructions
    void inc(int &reg, int&);
    void dec(int &reg, int&);
    void m_not(int &reg, int&);

// Jxx.cpp
    void jmp(int &IP, int line_num, j &flag);
    void je(int &IP, int line_num, j &flag);
    void jg(int &IP, int line_num, j &flag);
    void jl(int &IP, int line_num, j &flag);

// enum_from_str.cpp
    OPCODE get_opcode(const std::string &token);
    mRegister get_register(const std::string &token);

// open_file.cpp
    void open_file(std::ifstream &input_file, char *argv[], int argc);
// Parser
    instruction parse(std::string &line, std::multimap<std::string, size_t> &labels, size_t line_num);
    void map_labels(std::vector<std::string> &str, size_t line, std::multimap<std::string, size_t> &labels);
    void check_labels(std::string &line);
    void check_error(instruction &curr, int line);
// Helpers
    std::vector<std::string> split(const std::string &str, const char* c);
    void toLowerCase(std::string &str);
    bool is_number(const std::string& s);
// CPU
    void cpu_init(cpu &my_cpu);
    void execute(const std::multimap<std::string, size_t> &labels, cpu &my_cpu, std::map<size_t, instruction> &instructions);
// init_maps
    void init_alu_map(std::map<OPCODE,void(*)(int&, int&)> &map);
    void init_jxx_map(std::map<OPCODE, void(*)(int&, int, j&)> &map);
    void init_regs_map(std::map<mRegister,int*> &map, cpu &my_cpu);


#endif