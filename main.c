#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "assembler.h"

int main(int argc, char** argv){
    //Get Instruction from the user (using standard input)
    printf("Enter an ARM instruction: ");  
    char str[MAX_LIMIT]; 
    fgets(str, MAX_LIMIT, stdin); 
    
    while(!feof(stdin)){
        int n = fscanf(stdin,"%s", str);
        if (n > 0){
        // Create an instruction structure from instruction string
            Instruction instruction = parseInstructionString(str);
            unsigned int machineCode = 0;
    
            if(instruction.instruction_type == R){
                machineCode = findRType(instruction);
            }
            else if(instruction.instruction_type == I){
                machineCode = findIType(instruction);
            }
            else if(instruction.instruction_type == D){
                machineCode = findDType(instruction);
            }
            fprintf(stdout, "%x \n", machineCode);
    
            //Print the contents of the instruction 
            //printInstruction(instruction);
        }
    }
    return (EXIT_SUCCESS);
}

