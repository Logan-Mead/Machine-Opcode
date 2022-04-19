/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   assembler.h
 * Author: loganmead
 *
 * Created on March 3, 2021, 5:25 PM
 */

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#ifdef __cplusplus
extern "C" {
#endif
int findRType(Instruction instruction);
int findIType(Instruction instruction);
int findDType(Instruction instruction);


#ifdef __cplusplus
}
#endif

#endif /* ASSEMBLER_H */

