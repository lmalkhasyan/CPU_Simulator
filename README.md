# CPU_Simulator (Register Machine)
### Registers:
    r1-r10  
### Instructions:
    MOV, ADD, SUB, MUL, DIV, INC, DEC, AND, OR, XOR, NOT  
    JMP, JE, JG, JL
    
### Syntax:
    Same as MASM syntax, but the labels must be on the same line as the instruction.  
    Example: label1: Mov r1,r2:
    Not case sensitive!

### How to compile?
#### In Terminal:
```
make or make all
```
### Usage:  
#### In Terminal:  
```
    ./cpu_simulator [filename]
```
### Clean Object Files and ./cpu_simulator
#### In Terminal:  
```
    make fclean
    make clean (only objs)
```
