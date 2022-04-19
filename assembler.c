/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "parser.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

int findRType(Instruction instruction){
    unsigned int machineCode = 0;
    int opCode = 0;
    unsigned int Rm = instruction.Rm;
    Rm = Rm << 16;
    unsigned int shmant = 0;
    shmant = shmant << 10;
    unsigned int Rn = instruction.Rn;
    Rn = Rn << 5;
    unsigned int Rd = instruction.Rd;

    if(instruction.opcode == ADD){
        opCode = 0b10001011000;
        opCode = opCode << 21;
    }
    else if(instruction.opcode == SUB){
        opCode = 0b11001011000;
        opCode = opCode << 21;
    }
    machineCode = machineCode | opCode;
    machineCode = machineCode | Rm;
    machineCode = machineCode | shmant;
    machineCode = machineCode | Rn;
    machineCode = machineCode | Rd;
    return machineCode;
}

int findIType(Instruction instruction){
    unsigned int machineCode = 0;
    int opCode = 0;
    unsigned int ALU = 0;
    ALU = instruction.immediate;
    ALU = ALU << 10;
    unsigned int Rn = 0;
    Rn = instruction.Rn;
    Rn = Rn << 5;
    unsigned int Rd = 0;
    Rd = instruction.Rd;
    
    if(instruction.opcode == ADDI){
        opCode = 0b1001000100;
        opCode = opCode << 22;
    }
    else if(instruction.opcode == SUBI){
        opCode = 0b1101000100;
        opCode = opCode << 22;
    }
    machineCode = machineCode | opCode;
    machineCode = machineCode | ALU;
    machineCode = machineCode | Rn;
    machineCode = machineCode| Rd;
    return machineCode;
}

int findDType(Instruction instruction){
   unsigned int machineCode = 0;
   int opCode = 0;
   unsigned int DT_Address = 0;
   DT_Address = instruction.immediate;
   DT_Address = DT_Address << 12;
   unsigned int op = 0;
   op = op << 10;
   unsigned int Rn = 0;
   Rn = instruction.Rn;
   Rn = Rn << 5;
   unsigned int Rt = 0;
   Rt = instruction.Rd;
   
   if(instruction.opcode == LDUR){
      opCode = 0b11111000010;
      opCode = opCode << 21; 
   }
   else if(instruction.opcode == STUR){
      opCode = 0b11111000000;
      opCode = opCode << 21; 
   }
   machineCode = machineCode | opCode;
   machineCode = machineCode | DT_Address;
   machineCode = machineCode | op;
   machineCode = machineCode | Rn;
   machineCode = machineCode | Rt;
   return machineCode;
}
