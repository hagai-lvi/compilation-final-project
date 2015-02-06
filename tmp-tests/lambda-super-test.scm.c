#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 1
#include "arch/cisc.h"
#define SOB_FALSE IMM(3)
#define SOB_NIL IMM(2)
int main()
{
  START_MACHINE;

ADD(IND(0),1000);
//empty env
PUSH(IMM(1));
CALL(MALLOC);
MOV(R12,R0)
DROP(1);
//***


    JUMP(CONTINUE);
  #include "functions.lib"
   CONTINUE:
MOV(IND(1) , IMM(T_VOID));
MOV(IND(2) , IMM(T_NIL));
MOV(IND(3) , IMM(T_BOOL));
MOV(IND(4) , IMM(0));
MOV(IND(5) , IMM(T_BOOL));
MOV(IND(6) , IMM(1));
//END OF memory allocation 
MAKE_CLOSURE(CONS);
MOV(IND(7) , R0);
MAKE_CLOSURE(CAR);
MOV(IND(8) , R0);
MAKE_CLOSURE(CDR);
MOV(IND(9) , R0);
MAKE_CLOSURE(EQ);
MOV(IND(10) , R0);
MAKE_CLOSURE(IS_NULL);
MOV(IND(11) , R0);
MAKE_CLOSURE(IS_BOOL);
MOV(IND(12) , R0);
MAKE_CLOSURE(IS_INTEGER);
MOV(IND(13) , R0);
MAKE_CLOSURE(IS_NUMBER);
MOV(IND(14) , R0);
MAKE_CLOSURE(IS_STRING);
MOV(IND(15) , R0);
MAKE_CLOSURE(IS_CHAR);
MOV(IND(16) , R0);
MAKE_CLOSURE(IS_VECTOR);
MOV(IND(17) , R0);
MAKE_CLOSURE(IS_SYMBOL);
MOV(IND(18) , R0);
MAKE_CLOSURE(ZERO);
MOV(IND(19) , R0);
MAKE_CLOSURE(IS_PAIR);
MOV(IND(20) , R0);
MAKE_CLOSURE(IS_PROC);
MOV(IND(21) , R0);
MAKE_CLOSURE(MAKE_STRING);
MOV(IND(22) , R0);
MAKE_CLOSURE(CHAR_TO_INTEGER);
MOV(IND(23) , R0);
MAKE_CLOSURE(INTEGER_TO_CHAR);
MOV(IND(24) , R0);
MAKE_CLOSURE(MAKE_VECTOR);
MOV(IND(25) , R0);
MAKE_CLOSURE(VECTOR_LENGTH);
MOV(IND(26) , R0);
MAKE_CLOSURE(VECTOR_REF);
MOV(IND(27) , R0);
MAKE_CLOSURE(VECTOR_SET);
MOV(IND(28) , R0);
MAKE_CLOSURE(STRING_LENGTH);
MOV(IND(29) , R0);
MAKE_CLOSURE(STRING_SET);
MOV(IND(30) , R0);
MAKE_CLOSURE(STRING_REF);
MOV(IND(31) , R0);
MAKE_CLOSURE(SET_CAR);
MOV(IND(32) , R0);
MAKE_CLOSURE(SET_CDR);
MOV(IND(33) , R0);
MAKE_CLOSURE(PLUS);
MOV(IND(34) , R0);
MAKE_CLOSURE(MINUS);
MOV(IND(35) , R0);
MAKE_CLOSURE(MULTIPLY);
MOV(IND(36) , R0);
MAKE_CLOSURE(DIV);
MOV(IND(37) , R0);
MAKE_CLOSURE(BIGGER_THAN);
MOV(IND(38) , R0);
MAKE_CLOSURE(LESS_THAN);
MOV(IND(39) , R0);
MAKE_CLOSURE(NUMBER_EQUALS);
MOV(IND(40) , R0);
MAKE_CLOSURE(APPLY);
MOV(IND(41) , R0);
//END OF memory allocation 
//************************************start of agrument_number1***application_number1***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number1* application_number1*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number2***************************************
MOV(R0,(5));
PUSH(R0); 
//************************************end of agrument_number1* application_number2*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number3***************************************
//************************************start of agrument_number1***application_number4***************************************
// Starting code-gen for lambda-1
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env1:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop1);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env1); // another iteration
L_lambda_exit_loop1: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env1: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop2);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env1); // another iteration
L_lambda_exit_loop2: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code1)); // pointer to the code
JUMP(L_lambda_exit1);
L_lambda_code1: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-1

// Starting code-gen for lambda-2
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env2:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop3);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env2); // another iteration
L_lambda_exit_loop3: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env2: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop4);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env2); // another iteration
L_lambda_exit_loop4: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code2)); // pointer to the code
JUMP(L_lambda_exit2);
L_lambda_code2: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-2

//************************************start of agrument_number1***application_number5***************************************
//************************************start of agrument_number1***application_number6***************************************
//************************************start of agrument_number1***application_number7***************************************
//************************************start of agrument_number1***application_number8***************************************
//************************************start of agrument_number1***application_number9***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number9*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number8*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number7*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number6*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number5*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop1:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop1);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop1);
L_tp_applic_exit_loop1:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-2

POP(FP);
RETURN;
L_lambda_exit2:

// Here ends the code of the actual lambda lambda-1

POP(FP);
RETURN;
L_lambda_exit1:
PUSH(R0); 
//************************************end of agrument_number1* application_number4*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number10***************************************
//************************************start of agrument_number1***application_number11***************************************
// Starting code-gen for lambda-3
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env3:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop5);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env3); // another iteration
L_lambda_exit_loop5: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env3: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop6);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env3); // another iteration
L_lambda_exit_loop6: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code3)); // pointer to the code
JUMP(L_lambda_exit3);
L_lambda_code3: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-3

// Starting code-gen for lambda-4
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env4:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop7);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env4); // another iteration
L_lambda_exit_loop7: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env4: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop8);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env4); // another iteration
L_lambda_exit_loop8: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code4)); // pointer to the code
JUMP(L_lambda_exit4);
L_lambda_code4: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-4

//************************************start of agrument_number1***application_number12***************************************
//************************************start of agrument_number1***application_number13***************************************
//************************************start of agrument_number1***application_number14***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number14*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number13*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number12*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop2:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop2);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop2);
L_tp_applic_exit_loop2:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-4

POP(FP);
RETURN;
L_lambda_exit4:

// Here ends the code of the actual lambda lambda-3

POP(FP);
RETURN;
L_lambda_exit3:
PUSH(R0); 
//************************************end of agrument_number1* application_number11*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number15***************************************
//************************************start of agrument_number1***application_number16***************************************
// Starting code-gen for lambda-5
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env5:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop9);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env5); // another iteration
L_lambda_exit_loop9: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env5: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop10);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env5); // another iteration
L_lambda_exit_loop10: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code5)); // pointer to the code
JUMP(L_lambda_exit5);
L_lambda_code5: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-5

// Starting code-gen for lambda-6
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env6:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop11);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env6); // another iteration
L_lambda_exit_loop11: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env6: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop12);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env6); // another iteration
L_lambda_exit_loop12: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code6)); // pointer to the code
JUMP(L_lambda_exit6);
L_lambda_code6: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-6

//************************************start of agrument_number1***application_number17***************************************
//************************************start of agrument_number1***application_number18***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number18*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number17*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop3:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop3);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop3);
L_tp_applic_exit_loop3:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-6

POP(FP);
RETURN;
L_lambda_exit6:

// Here ends the code of the actual lambda lambda-5

POP(FP);
RETURN;
L_lambda_exit5:
PUSH(R0); 
//************************************end of agrument_number1* application_number16*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-7
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env7:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop13);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env7); // another iteration
L_lambda_exit_loop13: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env7: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop14);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env7); // another iteration
L_lambda_exit_loop14: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code7)); // pointer to the code
JUMP(L_lambda_exit7);
L_lambda_code7: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-7

// Starting code-gen for lambda-8
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env8:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop15);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env8); // another iteration
L_lambda_exit_loop15: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env8: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop16);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env8); // another iteration
L_lambda_exit_loop16: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code8)); // pointer to the code
JUMP(L_lambda_exit8);
L_lambda_code8: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-8

//************************************start of agrument_number1***application_number19***************************************
//************************************start of agrument_number1***application_number20***************************************
//************************************start of agrument_number1***application_number21***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number21*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number20*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number19*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop4:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop4);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop4);
L_tp_applic_exit_loop4:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-8

POP(FP);
RETURN;
L_lambda_exit8:

// Here ends the code of the actual lambda lambda-7

POP(FP);
RETURN;
L_lambda_exit7:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number15*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-9
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env9:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop17);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env9); // another iteration
L_lambda_exit_loop17: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env9: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop18);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env9); // another iteration
L_lambda_exit_loop18: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code9)); // pointer to the code
JUMP(L_lambda_exit9);
L_lambda_code9: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-9

// Starting code-gen for lambda-10
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env10:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop19);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env10); // another iteration
L_lambda_exit_loop19: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env10: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop20);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env10); // another iteration
L_lambda_exit_loop20: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code10)); // pointer to the code
JUMP(L_lambda_exit10);
L_lambda_code10: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-10

//************************************start of agrument_number1***application_number22***************************************
// Starting code-gen for lambda-11
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env11:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop21);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env11); // another iteration
L_lambda_exit_loop21: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env11: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop22);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env11); // another iteration
L_lambda_exit_loop22: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code11)); // pointer to the code
JUMP(L_lambda_exit11);
L_lambda_code11: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-11

// Starting code-gen for lambda-12
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env12:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop23);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env12); // another iteration
L_lambda_exit_loop23: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env12: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop24);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env12); // another iteration
L_lambda_exit_loop24: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code12)); // pointer to the code
JUMP(L_lambda_exit12);
L_lambda_code12: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-12

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-12

POP(FP);
RETURN;
L_lambda_exit12:

// Here ends the code of the actual lambda lambda-11

POP(FP);
RETURN;
L_lambda_exit11:
PUSH(R0); 
//************************************end of agrument_number1* application_number22*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number23***************************************
//************************************start of agrument_number1***application_number24***************************************
// Starting code-gen for lambda-13
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env13:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop25);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env13); // another iteration
L_lambda_exit_loop25: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env13: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop26);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env13); // another iteration
L_lambda_exit_loop26: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code13)); // pointer to the code
JUMP(L_lambda_exit13);
L_lambda_code13: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-13

// Starting code-gen for lambda-14
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env14:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop27);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env14); // another iteration
L_lambda_exit_loop27: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env14: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop28);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env14); // another iteration
L_lambda_exit_loop28: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code14)); // pointer to the code
JUMP(L_lambda_exit14);
L_lambda_code14: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-14

//************************************start of agrument_number1***application_number25***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number25*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number26***************************************
// Starting code-gen for lambda-15
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env15:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop29);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env15); // another iteration
L_lambda_exit_loop29: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env15: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop30);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env15); // another iteration
L_lambda_exit_loop30: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code15)); // pointer to the code
JUMP(L_lambda_exit15);
L_lambda_code15: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-15

// Starting code-gen for lambda-16
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env16:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop31);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env16); // another iteration
L_lambda_exit_loop31: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env16: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop32);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env16); // another iteration
L_lambda_exit_loop32: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code16)); // pointer to the code
JUMP(L_lambda_exit16);
L_lambda_code16: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-16

// Starting code-gen for lambda-17
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env17:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop33);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env17); // another iteration
L_lambda_exit_loop33: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env17: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop34);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env17); // another iteration
L_lambda_exit_loop34: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code17)); // pointer to the code
JUMP(L_lambda_exit17);
L_lambda_code17: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-17

//************************************start of agrument_number1***application_number27***************************************
//************************************start of agrument_number1***application_number28***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number28*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number29***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number29*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number27*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop5:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop5);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop5);
L_tp_applic_exit_loop5:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-17

POP(FP);
RETURN;
L_lambda_exit17:

// Here ends the code of the actual lambda lambda-16

POP(FP);
RETURN;
L_lambda_exit16:

// Here ends the code of the actual lambda lambda-15

POP(FP);
RETURN;
L_lambda_exit15:
PUSH(R0); 
//************************************end of agrument_number1* application_number26*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop6:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop6);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop6);
L_tp_applic_exit_loop6:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-14

POP(FP);
RETURN;
L_lambda_exit14:

// Here ends the code of the actual lambda lambda-13

POP(FP);
RETURN;
L_lambda_exit13:
PUSH(R0); 
//************************************end of agrument_number1* application_number24*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number23*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop7:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop7);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop7);
L_tp_applic_exit_loop7:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-10

POP(FP);
RETURN;
L_lambda_exit10:

// Here ends the code of the actual lambda lambda-9

POP(FP);
RETURN;
L_lambda_exit9:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number10*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-18
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env18:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop35);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env18); // another iteration
L_lambda_exit_loop35: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env18: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop36);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env18); // another iteration
L_lambda_exit_loop36: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code18)); // pointer to the code
JUMP(L_lambda_exit18);
L_lambda_code18: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-18

// Starting code-gen for lambda-19
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env19:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop37);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env19); // another iteration
L_lambda_exit_loop37: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env19: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop38);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env19); // another iteration
L_lambda_exit_loop38: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code19)); // pointer to the code
JUMP(L_lambda_exit19);
L_lambda_code19: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-19

//************************************start of agrument_number1***application_number30***************************************
// Starting code-gen for lambda-20
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env20:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop39);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env20); // another iteration
L_lambda_exit_loop39: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env20: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop40);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env20); // another iteration
L_lambda_exit_loop40: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code20)); // pointer to the code
JUMP(L_lambda_exit20);
L_lambda_code20: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-20

// Starting code-gen for lambda-21
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env21:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop41);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env21); // another iteration
L_lambda_exit_loop41: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env21: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop42);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env21); // another iteration
L_lambda_exit_loop42: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code21)); // pointer to the code
JUMP(L_lambda_exit21);
L_lambda_code21: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-21

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-21

POP(FP);
RETURN;
L_lambda_exit21:

// Here ends the code of the actual lambda lambda-20

POP(FP);
RETURN;
L_lambda_exit20:
PUSH(R0); 
//************************************end of agrument_number1* application_number30*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number31***************************************
//************************************start of agrument_number1***application_number32***************************************
// Starting code-gen for lambda-22
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env22:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop43);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env22); // another iteration
L_lambda_exit_loop43: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env22: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop44);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env22); // another iteration
L_lambda_exit_loop44: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code22)); // pointer to the code
JUMP(L_lambda_exit22);
L_lambda_code22: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-22

// Starting code-gen for lambda-23
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env23:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop45);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env23); // another iteration
L_lambda_exit_loop45: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env23: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop46);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env23); // another iteration
L_lambda_exit_loop46: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code23)); // pointer to the code
JUMP(L_lambda_exit23);
L_lambda_code23: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-23

//************************************start of agrument_number1***application_number33***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number33*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number34***************************************
// Starting code-gen for lambda-24
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env24:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop47);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env24); // another iteration
L_lambda_exit_loop47: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env24: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop48);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env24); // another iteration
L_lambda_exit_loop48: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code24)); // pointer to the code
JUMP(L_lambda_exit24);
L_lambda_code24: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-24

// Starting code-gen for lambda-25
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env25:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop49);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env25); // another iteration
L_lambda_exit_loop49: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env25: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop50);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env25); // another iteration
L_lambda_exit_loop50: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code25)); // pointer to the code
JUMP(L_lambda_exit25);
L_lambda_code25: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-25

// Starting code-gen for lambda-26
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env26:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop51);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env26); // another iteration
L_lambda_exit_loop51: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env26: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop52);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env26); // another iteration
L_lambda_exit_loop52: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code26)); // pointer to the code
JUMP(L_lambda_exit26);
L_lambda_code26: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-26

//************************************start of agrument_number1***application_number35***************************************
//************************************start of agrument_number1***application_number36***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number36*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number37***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number37*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number35*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop8:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop8);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop8);
L_tp_applic_exit_loop8:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-26

POP(FP);
RETURN;
L_lambda_exit26:

// Here ends the code of the actual lambda lambda-25

POP(FP);
RETURN;
L_lambda_exit25:

// Here ends the code of the actual lambda lambda-24

POP(FP);
RETURN;
L_lambda_exit24:
PUSH(R0); 
//************************************end of agrument_number1* application_number34*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop9:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop9);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop9);
L_tp_applic_exit_loop9:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-23

POP(FP);
RETURN;
L_lambda_exit23:

// Here ends the code of the actual lambda lambda-22

POP(FP);
RETURN;
L_lambda_exit22:
PUSH(R0); 
//************************************end of agrument_number1* application_number32*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number31*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop10:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop10);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop10);
L_tp_applic_exit_loop10:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-19

POP(FP);
RETURN;
L_lambda_exit19:

// Here ends the code of the actual lambda lambda-18

POP(FP);
RETURN;
L_lambda_exit18:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number3*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number38***************************************
//************************************start of agrument_number1***application_number39***************************************
// Starting code-gen for lambda-27
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env27:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop53);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env27); // another iteration
L_lambda_exit_loop53: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env27: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop54);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env27); // another iteration
L_lambda_exit_loop54: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code27)); // pointer to the code
JUMP(L_lambda_exit27);
L_lambda_code27: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-27

// Starting code-gen for lambda-28
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env28:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop55);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env28); // another iteration
L_lambda_exit_loop55: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env28: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop56);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env28); // another iteration
L_lambda_exit_loop56: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code28)); // pointer to the code
JUMP(L_lambda_exit28);
L_lambda_code28: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-28

//************************************start of agrument_number1***application_number40***************************************
//************************************start of agrument_number1***application_number41***************************************
//************************************start of agrument_number1***application_number42***************************************
//************************************start of agrument_number1***application_number43***************************************
//************************************start of agrument_number1***application_number44***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number44*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number43*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number42*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number41*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number40*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop11:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop11);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop11);
L_tp_applic_exit_loop11:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-28

POP(FP);
RETURN;
L_lambda_exit28:

// Here ends the code of the actual lambda lambda-27

POP(FP);
RETURN;
L_lambda_exit27:
PUSH(R0); 
//************************************end of agrument_number1* application_number39*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-29
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env29:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop57);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env29); // another iteration
L_lambda_exit_loop57: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env29: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop58);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env29); // another iteration
L_lambda_exit_loop58: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code29)); // pointer to the code
JUMP(L_lambda_exit29);
L_lambda_code29: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-29

//************************************start of agrument_number1***application_number45***************************************
//************************************start of agrument_number1***application_number46***************************************
//************************************start of agrument_number1***application_number47***************************************
// Starting code-gen for lambda-30
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env30:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop59);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env30); // another iteration
L_lambda_exit_loop59: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env30: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop60);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env30); // another iteration
L_lambda_exit_loop60: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code30)); // pointer to the code
JUMP(L_lambda_exit30);
L_lambda_code30: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-30

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-30

POP(FP);
RETURN;
L_lambda_exit30:
PUSH(R0); 
//************************************end of agrument_number1* application_number47*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number48***************************************
// Starting code-gen for lambda-31
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env31:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop61);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env31); // another iteration
L_lambda_exit_loop61: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env31: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop62);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env31); // another iteration
L_lambda_exit_loop62: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code31)); // pointer to the code
JUMP(L_lambda_exit31);
L_lambda_code31: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-31

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-31

POP(FP);
RETURN;
L_lambda_exit31:
PUSH(R0); 
//************************************end of agrument_number1* application_number48*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-32
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env32:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop63);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env32); // another iteration
L_lambda_exit_loop63: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env32: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop64);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env32); // another iteration
L_lambda_exit_loop64: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code32)); // pointer to the code
JUMP(L_lambda_exit32);
L_lambda_code32: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-32

// Starting code-gen for lambda-33
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env33:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop65);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env33); // another iteration
L_lambda_exit_loop65: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env33: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop66);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env33); // another iteration
L_lambda_exit_loop66: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code33)); // pointer to the code
JUMP(L_lambda_exit33);
L_lambda_code33: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-33

// Starting code-gen for lambda-34
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env34:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop67);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env34); // another iteration
L_lambda_exit_loop67: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env34: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop68);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env34); // another iteration
L_lambda_exit_loop68: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code34)); // pointer to the code
JUMP(L_lambda_exit34);
L_lambda_code34: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-34

//************************************start of agrument_number1***application_number49***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number49*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number50***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number50*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop12:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop12);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop12);
L_tp_applic_exit_loop12:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-34

POP(FP);
RETURN;
L_lambda_exit34:

// Here ends the code of the actual lambda lambda-33

POP(FP);
RETURN;
L_lambda_exit33:

// Here ends the code of the actual lambda lambda-32

POP(FP);
RETURN;
L_lambda_exit32:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number46*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number51***************************************
// Starting code-gen for lambda-35
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env35:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop69);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env35); // another iteration
L_lambda_exit_loop69: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env35: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop70);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env35); // another iteration
L_lambda_exit_loop70: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code35)); // pointer to the code
JUMP(L_lambda_exit35);
L_lambda_code35: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-35

//************************************start of agrument_number1***application_number52***************************************
//************************************start of agrument_number1***application_number53***************************************
//************************************start of agrument_number1***application_number54***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number54*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-36
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env36:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop71);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env36); // another iteration
L_lambda_exit_loop71: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env36: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop72);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env36); // another iteration
L_lambda_exit_loop72: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code36)); // pointer to the code
JUMP(L_lambda_exit36);
L_lambda_code36: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-36

//************************************start of agrument_number1***application_number55***************************************
// Starting code-gen for lambda-37
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env37:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop73);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env37); // another iteration
L_lambda_exit_loop73: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env37: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop74);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env37); // another iteration
L_lambda_exit_loop74: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code37)); // pointer to the code
JUMP(L_lambda_exit37);
L_lambda_code37: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-37

// Starting code-gen for lambda-38
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env38:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop75);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env38); // another iteration
L_lambda_exit_loop75: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env38: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop76);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env38); // another iteration
L_lambda_exit_loop76: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code38)); // pointer to the code
JUMP(L_lambda_exit38);
L_lambda_code38: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-38

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-38

POP(FP);
RETURN;
L_lambda_exit38:

// Here ends the code of the actual lambda lambda-37

POP(FP);
RETURN;
L_lambda_exit37:
PUSH(R0); 
//************************************end of agrument_number1* application_number55*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop13:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop13);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop13);
L_tp_applic_exit_loop13:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-36

POP(FP);
RETURN;
L_lambda_exit36:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number53*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number56***************************************
//************************************start of agrument_number1***application_number57***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number57*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-39
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env39:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop77);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env39); // another iteration
L_lambda_exit_loop77: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env39: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop78);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env39); // another iteration
L_lambda_exit_loop78: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code39)); // pointer to the code
JUMP(L_lambda_exit39);
L_lambda_code39: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-39

//************************************start of agrument_number1***application_number58***************************************
// Starting code-gen for lambda-40
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env40:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop79);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env40); // another iteration
L_lambda_exit_loop79: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env40: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop80);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env40); // another iteration
L_lambda_exit_loop80: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code40)); // pointer to the code
JUMP(L_lambda_exit40);
L_lambda_code40: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-40

// Starting code-gen for lambda-41
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env41:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop81);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env41); // another iteration
L_lambda_exit_loop81: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env41: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop82);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env41); // another iteration
L_lambda_exit_loop82: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code41)); // pointer to the code
JUMP(L_lambda_exit41);
L_lambda_code41: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-41

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-41

POP(FP);
RETURN;
L_lambda_exit41:

// Here ends the code of the actual lambda lambda-40

POP(FP);
RETURN;
L_lambda_exit40:
PUSH(R0); 
//************************************end of agrument_number1* application_number58*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop14:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop14);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop14);
L_tp_applic_exit_loop14:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-39

POP(FP);
RETURN;
L_lambda_exit39:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number56*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-42
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env42:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop83);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env42); // another iteration
L_lambda_exit_loop83: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env42: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop84);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env42); // another iteration
L_lambda_exit_loop84: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code42)); // pointer to the code
JUMP(L_lambda_exit42);
L_lambda_code42: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-42

// Starting code-gen for lambda-43
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env43:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop85);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env43); // another iteration
L_lambda_exit_loop85: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env43: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop86);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env43); // another iteration
L_lambda_exit_loop86: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code43)); // pointer to the code
JUMP(L_lambda_exit43);
L_lambda_code43: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-43

//************************************start of agrument_number1***application_number59***************************************
// Starting code-gen for lambda-44
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env44:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop87);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env44); // another iteration
L_lambda_exit_loop87: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env44: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop88);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env44); // another iteration
L_lambda_exit_loop88: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code44)); // pointer to the code
JUMP(L_lambda_exit44);
L_lambda_code44: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-44

// Starting code-gen for lambda-45
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env45:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop89);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env45); // another iteration
L_lambda_exit_loop89: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env45: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop90);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env45); // another iteration
L_lambda_exit_loop90: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code45)); // pointer to the code
JUMP(L_lambda_exit45);
L_lambda_code45: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-45

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-45

POP(FP);
RETURN;
L_lambda_exit45:

// Here ends the code of the actual lambda lambda-44

POP(FP);
RETURN;
L_lambda_exit44:
PUSH(R0); 
//************************************end of agrument_number1* application_number59*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number60***************************************
//************************************start of agrument_number1***application_number61***************************************
// Starting code-gen for lambda-46
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env46:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop91);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env46); // another iteration
L_lambda_exit_loop91: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env46: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop92);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env46); // another iteration
L_lambda_exit_loop92: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code46)); // pointer to the code
JUMP(L_lambda_exit46);
L_lambda_code46: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-46

// Starting code-gen for lambda-47
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env47:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop93);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env47); // another iteration
L_lambda_exit_loop93: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env47: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop94);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env47); // another iteration
L_lambda_exit_loop94: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code47)); // pointer to the code
JUMP(L_lambda_exit47);
L_lambda_code47: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-47

//************************************start of agrument_number1***application_number62***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number62*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number63***************************************
// Starting code-gen for lambda-48
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env48:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop95);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env48); // another iteration
L_lambda_exit_loop95: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env48: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop96);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env48); // another iteration
L_lambda_exit_loop96: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code48)); // pointer to the code
JUMP(L_lambda_exit48);
L_lambda_code48: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-48

// Starting code-gen for lambda-49
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env49:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop97);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env49); // another iteration
L_lambda_exit_loop97: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env49: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop98);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env49); // another iteration
L_lambda_exit_loop98: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code49)); // pointer to the code
JUMP(L_lambda_exit49);
L_lambda_code49: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-49

// Starting code-gen for lambda-50
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env50:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop99);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env50); // another iteration
L_lambda_exit_loop99: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env50: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop100);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env50); // another iteration
L_lambda_exit_loop100: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code50)); // pointer to the code
JUMP(L_lambda_exit50);
L_lambda_code50: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-50

//************************************start of agrument_number1***application_number64***************************************
//************************************start of agrument_number1***application_number65***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number65*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number66***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number66*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number64*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop15:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop15);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop15);
L_tp_applic_exit_loop15:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-50

POP(FP);
RETURN;
L_lambda_exit50:

// Here ends the code of the actual lambda lambda-49

POP(FP);
RETURN;
L_lambda_exit49:

// Here ends the code of the actual lambda lambda-48

POP(FP);
RETURN;
L_lambda_exit48:
PUSH(R0); 
//************************************end of agrument_number1* application_number63*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop16:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop16);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop16);
L_tp_applic_exit_loop16:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-47

POP(FP);
RETURN;
L_lambda_exit47:

// Here ends the code of the actual lambda lambda-46

POP(FP);
RETURN;
L_lambda_exit46:
PUSH(R0); 
//************************************end of agrument_number1* application_number61*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number60*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop17:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop17);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop17);
L_tp_applic_exit_loop17:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-43

POP(FP);
RETURN;
L_lambda_exit43:

// Here ends the code of the actual lambda lambda-42

POP(FP);
RETURN;
L_lambda_exit42:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number52*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number67***************************************
//************************************start of agrument_number1***application_number68***************************************
//************************************start of agrument_number1***application_number69***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number69*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-51
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env51:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop101);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env51); // another iteration
L_lambda_exit_loop101: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env51: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop102);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env51); // another iteration
L_lambda_exit_loop102: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code51)); // pointer to the code
JUMP(L_lambda_exit51);
L_lambda_code51: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-51

//************************************start of agrument_number1***application_number70***************************************
// Starting code-gen for lambda-52
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env52:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop103);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env52); // another iteration
L_lambda_exit_loop103: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env52: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop104);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env52); // another iteration
L_lambda_exit_loop104: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code52)); // pointer to the code
JUMP(L_lambda_exit52);
L_lambda_code52: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-52

// Starting code-gen for lambda-53
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env53:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop105);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env53); // another iteration
L_lambda_exit_loop105: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env53: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop106);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env53); // another iteration
L_lambda_exit_loop106: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code53)); // pointer to the code
JUMP(L_lambda_exit53);
L_lambda_code53: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-53

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-53

POP(FP);
RETURN;
L_lambda_exit53:

// Here ends the code of the actual lambda lambda-52

POP(FP);
RETURN;
L_lambda_exit52:
PUSH(R0); 
//************************************end of agrument_number1* application_number70*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop18:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop18);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop18);
L_tp_applic_exit_loop18:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-51

POP(FP);
RETURN;
L_lambda_exit51:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number68*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-54
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env54:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop107);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env54); // another iteration
L_lambda_exit_loop107: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env54: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop108);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env54); // another iteration
L_lambda_exit_loop108: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code54)); // pointer to the code
JUMP(L_lambda_exit54);
L_lambda_code54: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-54

// Starting code-gen for lambda-55
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env55:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop109);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env55); // another iteration
L_lambda_exit_loop109: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env55: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop110);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env55); // another iteration
L_lambda_exit_loop110: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code55)); // pointer to the code
JUMP(L_lambda_exit55);
L_lambda_code55: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-55

// Starting code-gen for lambda-56
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env56:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop111);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env56); // another iteration
L_lambda_exit_loop111: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env56: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop112);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env56); // another iteration
L_lambda_exit_loop112: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code56)); // pointer to the code
JUMP(L_lambda_exit56);
L_lambda_code56: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-56

//************************************start of agrument_number1***application_number71***************************************
//************************************start of agrument_number1***application_number72***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number72*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number73***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number73*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number71*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop19:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop19);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop19);
L_tp_applic_exit_loop19:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-56

POP(FP);
RETURN;
L_lambda_exit56:

// Here ends the code of the actual lambda lambda-55

POP(FP);
RETURN;
L_lambda_exit55:

// Here ends the code of the actual lambda lambda-54

POP(FP);
RETURN;
L_lambda_exit54:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number67*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-57
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env57:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop113);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env57); // another iteration
L_lambda_exit_loop113: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env57: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop114);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env57); // another iteration
L_lambda_exit_loop114: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code57)); // pointer to the code
JUMP(L_lambda_exit57);
L_lambda_code57: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-57

// Starting code-gen for lambda-58
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env58:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop115);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env58); // another iteration
L_lambda_exit_loop115: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env58: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop116);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env58); // another iteration
L_lambda_exit_loop116: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code58)); // pointer to the code
JUMP(L_lambda_exit58);
L_lambda_code58: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-58

// Starting code-gen for lambda-59
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env59:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop117);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env59); // another iteration
L_lambda_exit_loop117: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env59: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop118);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env59); // another iteration
L_lambda_exit_loop118: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code59)); // pointer to the code
JUMP(L_lambda_exit59);
L_lambda_code59: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-59

//************************************start of agrument_number1***application_number74***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number74*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number75***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number75*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop20:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop20);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop20);
L_tp_applic_exit_loop20:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-59

POP(FP);
RETURN;
L_lambda_exit59:

// Here ends the code of the actual lambda lambda-58

POP(FP);
RETURN;
L_lambda_exit58:

// Here ends the code of the actual lambda lambda-57

POP(FP);
RETURN;
L_lambda_exit57:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop21:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop21);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop21);
L_tp_applic_exit_loop21:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-35

POP(FP);
RETURN;
L_lambda_exit35:
PUSH(R0); 
//************************************end of agrument_number1* application_number51*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number45*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-60
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env60:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop119);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env60); // another iteration
L_lambda_exit_loop119: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env60: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop120);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env60); // another iteration
L_lambda_exit_loop120: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code60)); // pointer to the code
JUMP(L_lambda_exit60);
L_lambda_code60: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-60

//************************************start of agrument_number1***application_number76***************************************
// Starting code-gen for lambda-61
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env61:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop121);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env61); // another iteration
L_lambda_exit_loop121: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env61: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop122);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env61); // another iteration
L_lambda_exit_loop122: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code61)); // pointer to the code
JUMP(L_lambda_exit61);
L_lambda_code61: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-61

// Starting code-gen for lambda-62
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env62:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop123);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env62); // another iteration
L_lambda_exit_loop123: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env62: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop124);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env62); // another iteration
L_lambda_exit_loop124: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code62)); // pointer to the code
JUMP(L_lambda_exit62);
L_lambda_code62: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-62

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-62

POP(FP);
RETURN;
L_lambda_exit62:

// Here ends the code of the actual lambda lambda-61

POP(FP);
RETURN;
L_lambda_exit61:
PUSH(R0); 
//************************************end of agrument_number1* application_number76*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop22:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop22);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop22);
L_tp_applic_exit_loop22:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-60

POP(FP);
RETURN;
L_lambda_exit60:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop23:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop23);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop23);
L_tp_applic_exit_loop23:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-29

POP(FP);
RETURN;
L_lambda_exit29:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number38*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-63
MOV(R3, IMM(0)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env63:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop125);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env63); // another iteration
L_lambda_exit_loop125: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env63: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop126);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env63); // another iteration
L_lambda_exit_loop126: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code63)); // pointer to the code
JUMP(L_lambda_exit63);
L_lambda_code63: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-63

// Starting code-gen for lambda-64
MOV(R3, IMM(1)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env64:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop127);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env64); // another iteration
L_lambda_exit_loop127: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env64: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop128);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env64); // another iteration
L_lambda_exit_loop128: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code64)); // pointer to the code
JUMP(L_lambda_exit64);
L_lambda_code64: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-64

//************************************start of agrument_number1***application_number77***************************************
//************************************start of agrument_number1***application_number78***************************************
//************************************start of agrument_number1***application_number79***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number79*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number80***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number80*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-65
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env65:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop129);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env65); // another iteration
L_lambda_exit_loop129: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env65: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop130);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env65); // another iteration
L_lambda_exit_loop130: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code65)); // pointer to the code
JUMP(L_lambda_exit65);
L_lambda_code65: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-65

// Starting code-gen for lambda-66
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env66:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop131);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env66); // another iteration
L_lambda_exit_loop131: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env66: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop132);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env66); // another iteration
L_lambda_exit_loop132: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code66)); // pointer to the code
JUMP(L_lambda_exit66);
L_lambda_code66: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-66

//************************************start of agrument_number1***application_number81***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number81*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number82***************************************
// Starting code-gen for lambda-67
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env67:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop133);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env67); // another iteration
L_lambda_exit_loop133: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env67: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop134);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env67); // another iteration
L_lambda_exit_loop134: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code67)); // pointer to the code
JUMP(L_lambda_exit67);
L_lambda_code67: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-67

//************************************start of agrument_number1***application_number83***************************************
//************************************start of agrument_number1***application_number84***************************************
//************************************start of agrument_number1***application_number85***************************************
// Starting code-gen for lambda-68
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env68:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop135);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env68); // another iteration
L_lambda_exit_loop135: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env68: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop136);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env68); // another iteration
L_lambda_exit_loop136: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code68)); // pointer to the code
JUMP(L_lambda_exit68);
L_lambda_code68: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-68

// Starting code-gen for lambda-69
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env69:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop137);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env69); // another iteration
L_lambda_exit_loop137: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env69: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop138);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env69); // another iteration
L_lambda_exit_loop138: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code69)); // pointer to the code
JUMP(L_lambda_exit69);
L_lambda_code69: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-69

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-69

POP(FP);
RETURN;
L_lambda_exit69:

// Here ends the code of the actual lambda lambda-68

POP(FP);
RETURN;
L_lambda_exit68:
PUSH(R0); 
//************************************end of agrument_number1* application_number85*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number86***************************************
// Starting code-gen for lambda-70
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env70:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop139);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env70); // another iteration
L_lambda_exit_loop139: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env70: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop140);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env70); // another iteration
L_lambda_exit_loop140: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code70)); // pointer to the code
JUMP(L_lambda_exit70);
L_lambda_code70: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-70

// Starting code-gen for lambda-71
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env71:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop141);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env71); // another iteration
L_lambda_exit_loop141: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env71: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop142);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env71); // another iteration
L_lambda_exit_loop142: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code71)); // pointer to the code
JUMP(L_lambda_exit71);
L_lambda_code71: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-71

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-71

POP(FP);
RETURN;
L_lambda_exit71:

// Here ends the code of the actual lambda lambda-70

POP(FP);
RETURN;
L_lambda_exit70:
PUSH(R0); 
//************************************end of agrument_number1* application_number86*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-72
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env72:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop143);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env72); // another iteration
L_lambda_exit_loop143: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env72: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop144);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env72); // another iteration
L_lambda_exit_loop144: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code72)); // pointer to the code
JUMP(L_lambda_exit72);
L_lambda_code72: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-72

// Starting code-gen for lambda-73
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env73:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop145);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env73); // another iteration
L_lambda_exit_loop145: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env73: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop146);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env73); // another iteration
L_lambda_exit_loop146: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code73)); // pointer to the code
JUMP(L_lambda_exit73);
L_lambda_code73: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-73

// Starting code-gen for lambda-74
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env74:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop147);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env74); // another iteration
L_lambda_exit_loop147: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env74: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop148);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env74); // another iteration
L_lambda_exit_loop148: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code74)); // pointer to the code
JUMP(L_lambda_exit74);
L_lambda_code74: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-74

//************************************start of agrument_number1***application_number87***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number87*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number88***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number88*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop24:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop24);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop24);
L_tp_applic_exit_loop24:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-74

POP(FP);
RETURN;
L_lambda_exit74:

// Here ends the code of the actual lambda lambda-73

POP(FP);
RETURN;
L_lambda_exit73:

// Here ends the code of the actual lambda lambda-72

POP(FP);
RETURN;
L_lambda_exit72:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number84*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number89***************************************
// Starting code-gen for lambda-75
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env75:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop149);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env75); // another iteration
L_lambda_exit_loop149: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env75: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop150);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env75); // another iteration
L_lambda_exit_loop150: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code75)); // pointer to the code
JUMP(L_lambda_exit75);
L_lambda_code75: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-75

//************************************start of agrument_number1***application_number90***************************************
//************************************start of agrument_number1***application_number91***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number91*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-76
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env76:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop151);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env76); // another iteration
L_lambda_exit_loop151: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env76: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop152);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env76); // another iteration
L_lambda_exit_loop152: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code76)); // pointer to the code
JUMP(L_lambda_exit76);
L_lambda_code76: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-76

//************************************start of agrument_number1***application_number92***************************************
// Starting code-gen for lambda-77
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env77:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop153);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env77); // another iteration
L_lambda_exit_loop153: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env77: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop154);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env77); // another iteration
L_lambda_exit_loop154: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code77)); // pointer to the code
JUMP(L_lambda_exit77);
L_lambda_code77: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-77

// Starting code-gen for lambda-78
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env78:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop155);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env78); // another iteration
L_lambda_exit_loop155: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env78: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop156);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env78); // another iteration
L_lambda_exit_loop156: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code78)); // pointer to the code
JUMP(L_lambda_exit78);
L_lambda_code78: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-78

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-78

POP(FP);
RETURN;
L_lambda_exit78:

// Here ends the code of the actual lambda lambda-77

POP(FP);
RETURN;
L_lambda_exit77:
PUSH(R0); 
//************************************end of agrument_number1* application_number92*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop25:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop25);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop25);
L_tp_applic_exit_loop25:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-76

POP(FP);
RETURN;
L_lambda_exit76:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number90*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number93***************************************
//************************************start of agrument_number1***application_number94***************************************
//************************************start of agrument_number1***application_number95***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number95*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-79
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env79:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop157);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env79); // another iteration
L_lambda_exit_loop157: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env79: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop158);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env79); // another iteration
L_lambda_exit_loop158: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code79)); // pointer to the code
JUMP(L_lambda_exit79);
L_lambda_code79: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-79

//************************************start of agrument_number1***application_number96***************************************
// Starting code-gen for lambda-80
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env80:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop159);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env80); // another iteration
L_lambda_exit_loop159: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env80: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop160);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env80); // another iteration
L_lambda_exit_loop160: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code80)); // pointer to the code
JUMP(L_lambda_exit80);
L_lambda_code80: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-80

// Starting code-gen for lambda-81
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env81:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop161);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env81); // another iteration
L_lambda_exit_loop161: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env81: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop162);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env81); // another iteration
L_lambda_exit_loop162: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code81)); // pointer to the code
JUMP(L_lambda_exit81);
L_lambda_code81: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-81

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-81

POP(FP);
RETURN;
L_lambda_exit81:

// Here ends the code of the actual lambda lambda-80

POP(FP);
RETURN;
L_lambda_exit80:
PUSH(R0); 
//************************************end of agrument_number1* application_number96*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop26:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop26);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop26);
L_tp_applic_exit_loop26:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-79

POP(FP);
RETURN;
L_lambda_exit79:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number94*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-82
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env82:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop163);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env82); // another iteration
L_lambda_exit_loop163: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env82: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop164);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env82); // another iteration
L_lambda_exit_loop164: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code82)); // pointer to the code
JUMP(L_lambda_exit82);
L_lambda_code82: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-82

// Starting code-gen for lambda-83
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env83:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop165);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env83); // another iteration
L_lambda_exit_loop165: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env83: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop166);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env83); // another iteration
L_lambda_exit_loop166: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code83)); // pointer to the code
JUMP(L_lambda_exit83);
L_lambda_code83: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-83

// Starting code-gen for lambda-84
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env84:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop167);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env84); // another iteration
L_lambda_exit_loop167: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env84: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop168);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env84); // another iteration
L_lambda_exit_loop168: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code84)); // pointer to the code
JUMP(L_lambda_exit84);
L_lambda_code84: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-84

//************************************start of agrument_number1***application_number97***************************************
//************************************start of agrument_number1***application_number98***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number98*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number99***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number99*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number97*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop27:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop27);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop27);
L_tp_applic_exit_loop27:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-84

POP(FP);
RETURN;
L_lambda_exit84:

// Here ends the code of the actual lambda lambda-83

POP(FP);
RETURN;
L_lambda_exit83:

// Here ends the code of the actual lambda lambda-82

POP(FP);
RETURN;
L_lambda_exit82:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number93*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-85
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env85:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop169);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env85); // another iteration
L_lambda_exit_loop169: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env85: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop170);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env85); // another iteration
L_lambda_exit_loop170: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code85)); // pointer to the code
JUMP(L_lambda_exit85);
L_lambda_code85: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-85

// Starting code-gen for lambda-86
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env86:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop171);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env86); // another iteration
L_lambda_exit_loop171: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env86: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop172);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env86); // another iteration
L_lambda_exit_loop172: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code86)); // pointer to the code
JUMP(L_lambda_exit86);
L_lambda_code86: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-86

// Starting code-gen for lambda-87
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env87:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop173);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env87); // another iteration
L_lambda_exit_loop173: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env87: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop174);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env87); // another iteration
L_lambda_exit_loop174: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code87)); // pointer to the code
JUMP(L_lambda_exit87);
L_lambda_code87: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-87

//************************************start of agrument_number1***application_number100***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number100*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number101***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number101*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop28:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop28);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop28);
L_tp_applic_exit_loop28:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-87

POP(FP);
RETURN;
L_lambda_exit87:

// Here ends the code of the actual lambda lambda-86

POP(FP);
RETURN;
L_lambda_exit86:

// Here ends the code of the actual lambda lambda-85

POP(FP);
RETURN;
L_lambda_exit85:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop29:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop29);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop29);
L_tp_applic_exit_loop29:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-75

POP(FP);
RETURN;
L_lambda_exit75:
PUSH(R0); 
//************************************end of agrument_number1* application_number89*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number83*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-88
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env88:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop175);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env88); // another iteration
L_lambda_exit_loop175: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env88: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop176);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env88); // another iteration
L_lambda_exit_loop176: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code88)); // pointer to the code
JUMP(L_lambda_exit88);
L_lambda_code88: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-88

//************************************start of agrument_number1***application_number102***************************************
// Starting code-gen for lambda-89
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env89:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop177);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env89); // another iteration
L_lambda_exit_loop177: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env89: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop178);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env89); // another iteration
L_lambda_exit_loop178: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code89)); // pointer to the code
JUMP(L_lambda_exit89);
L_lambda_code89: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-89

// Starting code-gen for lambda-90
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env90:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop179);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env90); // another iteration
L_lambda_exit_loop179: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env90: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop180);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env90); // another iteration
L_lambda_exit_loop180: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code90)); // pointer to the code
JUMP(L_lambda_exit90);
L_lambda_code90: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-90

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-90

POP(FP);
RETURN;
L_lambda_exit90:

// Here ends the code of the actual lambda lambda-89

POP(FP);
RETURN;
L_lambda_exit89:
PUSH(R0); 
//************************************end of agrument_number1* application_number102*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop30:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop30);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop30);
L_tp_applic_exit_loop30:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-88

POP(FP);
RETURN;
L_lambda_exit88:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop31:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop31);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop31);
L_tp_applic_exit_loop31:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-67

POP(FP);
RETURN;
L_lambda_exit67:
PUSH(R0); 
//************************************end of agrument_number1* application_number82*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop32:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop32);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop32);
L_tp_applic_exit_loop32:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-66

POP(FP);
RETURN;
L_lambda_exit66:

// Here ends the code of the actual lambda lambda-65

POP(FP);
RETURN;
L_lambda_exit65:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number78*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-91
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env91:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop181);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env91); // another iteration
L_lambda_exit_loop181: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env91: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop182);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env91); // another iteration
L_lambda_exit_loop182: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code91)); // pointer to the code
JUMP(L_lambda_exit91);
L_lambda_code91: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-91

//************************************start of agrument_number1***application_number103***************************************
// Starting code-gen for lambda-92
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env92:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop183);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env92); // another iteration
L_lambda_exit_loop183: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env92: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop184);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env92); // another iteration
L_lambda_exit_loop184: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code92)); // pointer to the code
JUMP(L_lambda_exit92);
L_lambda_code92: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-92

// Starting code-gen for lambda-93
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env93:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop185);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env93); // another iteration
L_lambda_exit_loop185: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env93: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop186);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env93); // another iteration
L_lambda_exit_loop186: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code93)); // pointer to the code
JUMP(L_lambda_exit93);
L_lambda_code93: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-93

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-93

POP(FP);
RETURN;
L_lambda_exit93:

// Here ends the code of the actual lambda lambda-92

POP(FP);
RETURN;
L_lambda_exit92:
PUSH(R0); 
//************************************end of agrument_number1* application_number103*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number104***************************************
// Starting code-gen for lambda-94
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env94:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop187);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env94); // another iteration
L_lambda_exit_loop187: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env94: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop188);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env94); // another iteration
L_lambda_exit_loop188: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code94)); // pointer to the code
JUMP(L_lambda_exit94);
L_lambda_code94: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-94

// Starting code-gen for lambda-95
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env95:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop189);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env95); // another iteration
L_lambda_exit_loop189: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env95: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop190);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env95); // another iteration
L_lambda_exit_loop190: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code95)); // pointer to the code
JUMP(L_lambda_exit95);
L_lambda_code95: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-95

// Starting code-gen for lambda-96
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env96:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop191);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env96); // another iteration
L_lambda_exit_loop191: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env96: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop192);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env96); // another iteration
L_lambda_exit_loop192: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code96)); // pointer to the code
JUMP(L_lambda_exit96);
L_lambda_code96: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-96

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-96

POP(FP);
RETURN;
L_lambda_exit96:

// Here ends the code of the actual lambda lambda-95

POP(FP);
RETURN;
L_lambda_exit95:

// Here ends the code of the actual lambda lambda-94

POP(FP);
RETURN;
L_lambda_exit94:
PUSH(R0); 
//************************************end of agrument_number1* application_number104*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop33:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop33);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop33);
L_tp_applic_exit_loop33:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-91

POP(FP);
RETURN;
L_lambda_exit91:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number77*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number105***************************************
//************************************start of agrument_number1***application_number106***************************************
//************************************start of agrument_number1***application_number107***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number107*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number108***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number108*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-97
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env97:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop193);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env97); // another iteration
L_lambda_exit_loop193: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env97: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop194);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env97); // another iteration
L_lambda_exit_loop194: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code97)); // pointer to the code
JUMP(L_lambda_exit97);
L_lambda_code97: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-97

// Starting code-gen for lambda-98
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env98:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop195);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env98); // another iteration
L_lambda_exit_loop195: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env98: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop196);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env98); // another iteration
L_lambda_exit_loop196: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code98)); // pointer to the code
JUMP(L_lambda_exit98);
L_lambda_code98: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-98

//************************************start of agrument_number1***application_number109***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number109*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number110***************************************
// Starting code-gen for lambda-99
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env99:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop197);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env99); // another iteration
L_lambda_exit_loop197: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env99: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop198);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env99); // another iteration
L_lambda_exit_loop198: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code99)); // pointer to the code
JUMP(L_lambda_exit99);
L_lambda_code99: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-99

//************************************start of agrument_number1***application_number111***************************************
//************************************start of agrument_number1***application_number112***************************************
//************************************start of agrument_number1***application_number113***************************************
// Starting code-gen for lambda-100
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env100:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop199);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env100); // another iteration
L_lambda_exit_loop199: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env100: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop200);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env100); // another iteration
L_lambda_exit_loop200: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code100)); // pointer to the code
JUMP(L_lambda_exit100);
L_lambda_code100: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-100

// Starting code-gen for lambda-101
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env101:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop201);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env101); // another iteration
L_lambda_exit_loop201: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env101: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop202);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env101); // another iteration
L_lambda_exit_loop202: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code101)); // pointer to the code
JUMP(L_lambda_exit101);
L_lambda_code101: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-101

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-101

POP(FP);
RETURN;
L_lambda_exit101:

// Here ends the code of the actual lambda lambda-100

POP(FP);
RETURN;
L_lambda_exit100:
PUSH(R0); 
//************************************end of agrument_number1* application_number113*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number114***************************************
// Starting code-gen for lambda-102
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env102:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop203);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env102); // another iteration
L_lambda_exit_loop203: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env102: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop204);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env102); // another iteration
L_lambda_exit_loop204: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code102)); // pointer to the code
JUMP(L_lambda_exit102);
L_lambda_code102: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-102

// Starting code-gen for lambda-103
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env103:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop205);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env103); // another iteration
L_lambda_exit_loop205: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env103: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop206);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env103); // another iteration
L_lambda_exit_loop206: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code103)); // pointer to the code
JUMP(L_lambda_exit103);
L_lambda_code103: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-103

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-103

POP(FP);
RETURN;
L_lambda_exit103:

// Here ends the code of the actual lambda lambda-102

POP(FP);
RETURN;
L_lambda_exit102:
PUSH(R0); 
//************************************end of agrument_number1* application_number114*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-104
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env104:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop207);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env104); // another iteration
L_lambda_exit_loop207: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env104: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop208);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env104); // another iteration
L_lambda_exit_loop208: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code104)); // pointer to the code
JUMP(L_lambda_exit104);
L_lambda_code104: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-104

// Starting code-gen for lambda-105
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env105:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop209);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env105); // another iteration
L_lambda_exit_loop209: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env105: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop210);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env105); // another iteration
L_lambda_exit_loop210: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code105)); // pointer to the code
JUMP(L_lambda_exit105);
L_lambda_code105: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-105

// Starting code-gen for lambda-106
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env106:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop211);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env106); // another iteration
L_lambda_exit_loop211: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env106: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop212);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env106); // another iteration
L_lambda_exit_loop212: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code106)); // pointer to the code
JUMP(L_lambda_exit106);
L_lambda_code106: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-106

//************************************start of agrument_number1***application_number115***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number115*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number116***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number116*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop34:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop34);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop34);
L_tp_applic_exit_loop34:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-106

POP(FP);
RETURN;
L_lambda_exit106:

// Here ends the code of the actual lambda lambda-105

POP(FP);
RETURN;
L_lambda_exit105:

// Here ends the code of the actual lambda lambda-104

POP(FP);
RETURN;
L_lambda_exit104:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number112*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number117***************************************
// Starting code-gen for lambda-107
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env107:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop213);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env107); // another iteration
L_lambda_exit_loop213: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env107: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop214);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env107); // another iteration
L_lambda_exit_loop214: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code107)); // pointer to the code
JUMP(L_lambda_exit107);
L_lambda_code107: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-107

//************************************start of agrument_number1***application_number118***************************************
//************************************start of agrument_number1***application_number119***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number119*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-108
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env108:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop215);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env108); // another iteration
L_lambda_exit_loop215: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env108: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop216);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env108); // another iteration
L_lambda_exit_loop216: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code108)); // pointer to the code
JUMP(L_lambda_exit108);
L_lambda_code108: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-108

//************************************start of agrument_number1***application_number120***************************************
// Starting code-gen for lambda-109
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env109:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop217);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env109); // another iteration
L_lambda_exit_loop217: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env109: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop218);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env109); // another iteration
L_lambda_exit_loop218: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code109)); // pointer to the code
JUMP(L_lambda_exit109);
L_lambda_code109: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-109

// Starting code-gen for lambda-110
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env110:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop219);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env110); // another iteration
L_lambda_exit_loop219: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env110: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop220);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env110); // another iteration
L_lambda_exit_loop220: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code110)); // pointer to the code
JUMP(L_lambda_exit110);
L_lambda_code110: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-110

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-110

POP(FP);
RETURN;
L_lambda_exit110:

// Here ends the code of the actual lambda lambda-109

POP(FP);
RETURN;
L_lambda_exit109:
PUSH(R0); 
//************************************end of agrument_number1* application_number120*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop35:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop35);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop35);
L_tp_applic_exit_loop35:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-108

POP(FP);
RETURN;
L_lambda_exit108:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number118*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number121***************************************
//************************************start of agrument_number1***application_number122***************************************
//************************************start of agrument_number1***application_number123***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number123*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-111
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env111:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop221);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env111); // another iteration
L_lambda_exit_loop221: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env111: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop222);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env111); // another iteration
L_lambda_exit_loop222: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code111)); // pointer to the code
JUMP(L_lambda_exit111);
L_lambda_code111: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-111

//************************************start of agrument_number1***application_number124***************************************
// Starting code-gen for lambda-112
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env112:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop223);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env112); // another iteration
L_lambda_exit_loop223: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env112: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop224);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env112); // another iteration
L_lambda_exit_loop224: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code112)); // pointer to the code
JUMP(L_lambda_exit112);
L_lambda_code112: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-112

// Starting code-gen for lambda-113
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env113:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop225);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env113); // another iteration
L_lambda_exit_loop225: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env113: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop226);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env113); // another iteration
L_lambda_exit_loop226: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code113)); // pointer to the code
JUMP(L_lambda_exit113);
L_lambda_code113: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-113

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-113

POP(FP);
RETURN;
L_lambda_exit113:

// Here ends the code of the actual lambda lambda-112

POP(FP);
RETURN;
L_lambda_exit112:
PUSH(R0); 
//************************************end of agrument_number1* application_number124*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop36:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop36);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop36);
L_tp_applic_exit_loop36:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-111

POP(FP);
RETURN;
L_lambda_exit111:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number122*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-114
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env114:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop227);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env114); // another iteration
L_lambda_exit_loop227: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env114: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop228);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env114); // another iteration
L_lambda_exit_loop228: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code114)); // pointer to the code
JUMP(L_lambda_exit114);
L_lambda_code114: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-114

// Starting code-gen for lambda-115
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env115:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop229);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env115); // another iteration
L_lambda_exit_loop229: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env115: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop230);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env115); // another iteration
L_lambda_exit_loop230: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code115)); // pointer to the code
JUMP(L_lambda_exit115);
L_lambda_code115: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-115

// Starting code-gen for lambda-116
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env116:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop231);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env116); // another iteration
L_lambda_exit_loop231: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env116: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop232);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env116); // another iteration
L_lambda_exit_loop232: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code116)); // pointer to the code
JUMP(L_lambda_exit116);
L_lambda_code116: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-116

//************************************start of agrument_number1***application_number125***************************************
//************************************start of agrument_number1***application_number126***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number126*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number127***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number127*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(1,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number125*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop37:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop37);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop37);
L_tp_applic_exit_loop37:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-116

POP(FP);
RETURN;
L_lambda_exit116:

// Here ends the code of the actual lambda lambda-115

POP(FP);
RETURN;
L_lambda_exit115:

// Here ends the code of the actual lambda lambda-114

POP(FP);
RETURN;
L_lambda_exit114:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number121*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-117
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env117:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop233);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env117); // another iteration
L_lambda_exit_loop233: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env117: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop234);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env117); // another iteration
L_lambda_exit_loop234: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code117)); // pointer to the code
JUMP(L_lambda_exit117);
L_lambda_code117: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-117

// Starting code-gen for lambda-118
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env118:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop235);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env118); // another iteration
L_lambda_exit_loop235: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env118: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop236);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env118); // another iteration
L_lambda_exit_loop236: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code118)); // pointer to the code
JUMP(L_lambda_exit118);
L_lambda_code118: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-118

// Starting code-gen for lambda-119
MOV(R3, IMM(8)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env119:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop237);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env119); // another iteration
L_lambda_exit_loop237: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env119: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop238);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env119); // another iteration
L_lambda_exit_loop238: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code119)); // pointer to the code
JUMP(L_lambda_exit119);
L_lambda_code119: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-119

//************************************start of agrument_number1***application_number128***************************************
MOV_BVAR(0,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number128*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number129***************************************
MOV_BVAR(1,0);
PUSH(R0); 
//************************************end of agrument_number1* application_number129*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop38:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop38);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop38);
L_tp_applic_exit_loop38:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-119

POP(FP);
RETURN;
L_lambda_exit119:

// Here ends the code of the actual lambda lambda-118

POP(FP);
RETURN;
L_lambda_exit118:

// Here ends the code of the actual lambda lambda-117

POP(FP);
RETURN;
L_lambda_exit117:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop39:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop39);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop39);
L_tp_applic_exit_loop39:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-107

POP(FP);
RETURN;
L_lambda_exit107:
PUSH(R0); 
//************************************end of agrument_number1* application_number117*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number111*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-120
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env120:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop239);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env120); // another iteration
L_lambda_exit_loop239: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env120: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop240);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env120); // another iteration
L_lambda_exit_loop240: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code120)); // pointer to the code
JUMP(L_lambda_exit120);
L_lambda_code120: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-120

//************************************start of agrument_number1***application_number130***************************************
// Starting code-gen for lambda-121
MOV(R3, IMM(6)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env121:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop241);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env121); // another iteration
L_lambda_exit_loop241: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env121: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop242);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env121); // another iteration
L_lambda_exit_loop242: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code121)); // pointer to the code
JUMP(L_lambda_exit121);
L_lambda_code121: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-121

// Starting code-gen for lambda-122
MOV(R3, IMM(7)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env122:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop243);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env122); // another iteration
L_lambda_exit_loop243: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env122: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop244);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env122); // another iteration
L_lambda_exit_loop244: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code122)); // pointer to the code
JUMP(L_lambda_exit122);
L_lambda_code122: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-122

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-122

POP(FP);
RETURN;
L_lambda_exit122:

// Here ends the code of the actual lambda lambda-121

POP(FP);
RETURN;
L_lambda_exit121:
PUSH(R0); 
//************************************end of agrument_number1* application_number130*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop40:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop40);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop40);
L_tp_applic_exit_loop40:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-120

POP(FP);
RETURN;
L_lambda_exit120:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop41:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop41);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop41);
L_tp_applic_exit_loop41:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-99

POP(FP);
RETURN;
L_lambda_exit99:
PUSH(R0); 
//************************************end of agrument_number1* application_number110*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop42:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop42);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop42);
L_tp_applic_exit_loop42:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-98

POP(FP);
RETURN;
L_lambda_exit98:

// Here ends the code of the actual lambda lambda-97

POP(FP);
RETURN;
L_lambda_exit97:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number106*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-123
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env123:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop245);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env123); // another iteration
L_lambda_exit_loop245: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env123: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop246);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env123); // another iteration
L_lambda_exit_loop246: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code123)); // pointer to the code
JUMP(L_lambda_exit123);
L_lambda_code123: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-123

//************************************start of agrument_number1***application_number131***************************************
// Starting code-gen for lambda-124
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env124:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop247);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env124); // another iteration
L_lambda_exit_loop247: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env124: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop248);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env124); // another iteration
L_lambda_exit_loop248: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code124)); // pointer to the code
JUMP(L_lambda_exit124);
L_lambda_code124: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-124

// Starting code-gen for lambda-125
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env125:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop249);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env125); // another iteration
L_lambda_exit_loop249: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env125: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop250);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env125); // another iteration
L_lambda_exit_loop250: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code125)); // pointer to the code
JUMP(L_lambda_exit125);
L_lambda_code125: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-125

MOV_BVAR(0,0);

// Here ends the code of the actual lambda lambda-125

POP(FP);
RETURN;
L_lambda_exit125:

// Here ends the code of the actual lambda lambda-124

POP(FP);
RETURN;
L_lambda_exit124:
PUSH(R0); 
//************************************end of agrument_number1* application_number131*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number132***************************************
// Starting code-gen for lambda-126
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env126:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop251);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env126); // another iteration
L_lambda_exit_loop251: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env126: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop252);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env126); // another iteration
L_lambda_exit_loop252: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code126)); // pointer to the code
JUMP(L_lambda_exit126);
L_lambda_code126: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-126

// Starting code-gen for lambda-127
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env127:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop253);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env127); // another iteration
L_lambda_exit_loop253: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env127: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop254);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env127); // another iteration
L_lambda_exit_loop254: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code127)); // pointer to the code
JUMP(L_lambda_exit127);
L_lambda_code127: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-127

// Starting code-gen for lambda-128
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env128:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop255);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env128); // another iteration
L_lambda_exit_loop255: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env128: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop256);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env128); // another iteration
L_lambda_exit_loop256: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code128)); // pointer to the code
JUMP(L_lambda_exit128);
L_lambda_code128: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-128

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-128

POP(FP);
RETURN;
L_lambda_exit128:

// Here ends the code of the actual lambda lambda-127

POP(FP);
RETURN;
L_lambda_exit127:

// Here ends the code of the actual lambda lambda-126

POP(FP);
RETURN;
L_lambda_exit126:
PUSH(R0); 
//************************************end of agrument_number1* application_number132*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop43:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop43);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop43);
L_tp_applic_exit_loop43:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-123

POP(FP);
RETURN;
L_lambda_exit123:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0); 
//************************************end of agrument_number1* application_number105*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-129
MOV(R3, IMM(2)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env129:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop257);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env129); // another iteration
L_lambda_exit_loop257: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env129: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop258);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env129); // another iteration
L_lambda_exit_loop258: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code129)); // pointer to the code
JUMP(L_lambda_exit129);
L_lambda_code129: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-129

// Starting code-gen for lambda-130
MOV(R3, IMM(3)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env130:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop259);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env130); // another iteration
L_lambda_exit_loop259: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env130: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop260);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env130); // another iteration
L_lambda_exit_loop260: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code130)); // pointer to the code
JUMP(L_lambda_exit130);
L_lambda_code130: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-130

//************************************start of agrument_number1***application_number133***************************************
// Starting code-gen for lambda-131
MOV(R3, IMM(4)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env131:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop261);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env131); // another iteration
L_lambda_exit_loop261: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env131: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop262);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env131); // another iteration
L_lambda_exit_loop262: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code131)); // pointer to the code
JUMP(L_lambda_exit131);
L_lambda_code131: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-131

// Starting code-gen for lambda-132
MOV(R3, IMM(5)); // env depth
PUSH(R3); // store env size
CALL(MALLOC); // allocate mem for new env
DROP(IMM(1));
MOV(R1,R0); // pointer to the new env;
MOV(R2,FPARG(0)); // pointer to the old env
MOV(R4,IMM(0)); // R4 is i
MOV(R5,IMM(1)); // R5 is j
// iterating to copy the old env
// in to the new one
L_lambda_copy_old_env132:
CMP(R4,R3);
JUMP_EQ(L_lambda_exit_loop263);
MOV( INDD(R1,R5), INDD(R2,R4))
INCR(R4); //++i
INCR(R5); //++j
JUMP(L_lambda_copy_old_env132); // another iteration
L_lambda_exit_loop263: //end of for loop

// Add the current params to the env
PUSH(IMM(SCMNARGS)); // number of variables
CALL(MALLOC);
DROP(IMM(1));
MOV(R3,R0);
MOV(R4, IMM(0)); // i=0
L_lambda_make_new_env132: // 'for' loop
CMP(R4,IMM(SCMNARGS));
JUMP_EQ(L_lambda_exit_loop264);
MOV(R6,R4);
ADD(R6,IMM(2));
MOV(R5, R6);
MOV(INDD(R3, R4), FPARG(R5));
INCR(R4);
JUMP(L_lambda_make_new_env132); // another iteration
L_lambda_exit_loop264: // end of for loop
MOV(IND(R1), R3); // move pointer to the pvars to the new env
PUSH(IMM(3));
CALL(MALLOC); // memory for the closure data struct
DROP(IMM(1));
MOV(INDD(R0, 0), T_CLOSURE);
MOV(INDD(R0, 1), R1); // pointer to the new env
MOV(INDD(R0, 2), LABEL(L_lambda_code132)); // pointer to the code
JUMP(L_lambda_exit132);
L_lambda_code132: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda lambda-132

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-132

POP(FP);
RETURN;
L_lambda_exit132:

// Here ends the code of the actual lambda lambda-131

POP(FP);
RETURN;
L_lambda_exit131:
PUSH(R0); 
//************************************end of agrument_number1* application_number133*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
//************************************start of agrument_number1***application_number134***************************************
MOV_PVAR(0);
PUSH(R0); 
//************************************end of agrument_number1* application_number134*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_BVAR(0,0);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop44:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop44);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop44);
L_tp_applic_exit_loop44:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-130

POP(FP);
RETURN;
L_lambda_exit130:

// Here ends the code of the actual lambda lambda-129

POP(FP);
RETURN;
L_lambda_exit129:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(1));//NUMBER OF CURRENT ARGS
ADD(R4,3);//number of total elemtns on stack
MOV(R5,R4);//save for later 
MOV(R1,IMM(0));//counter
MOV(R6,FP);
MOV(R10,FP);
SUB(R10,SCMNARGS); //new framepointer
SUB(R10,4);
MOV(R11,FPARG(-2));
MOV(FP,R10);
L_tp_applic_loop45:
CMP(R1,R4); 
JUMP_EQ(L_tp_applic_exit_loop45);
MOV(R7,FP);
ADD(R7,R1);
MOV(R8,R6);
ADD(R8,R1);
MOV(STACK(R7),STACK(R8));
INCR(R1);
JUMP(L_tp_applic_loop45);
L_tp_applic_exit_loop45:
MOV(SP,FP);
ADD(SP,R5);
MOV(FP,R11);
JUMPA((INDD(R0 , IMM(2)))); // jump to code label

// Here ends the code of the actual lambda lambda-64

POP(FP);
RETURN;
L_lambda_exit64:

// Here ends the code of the actual lambda lambda-63

POP(FP);
RETURN;
L_lambda_exit63:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// This code is to be appended to the final cisc file created by our compiler
  JUMP(EXIT);
	lnot_proc:
	printf("not proc \n");
 //  INFO;
	JUMP(EXIT);
  l_NOT_VALID_ARGUMENTS:

  // INFO;
	JUMP(EXIT);	
  l_NOT_PAIR:
  printf("not PAIR \n");
  //INFO;
  SHOW("",INDD(R0,0));

	JUMP(EXIT);
  
  
  EXIT:
 
  STOP_MACHINE;

  return 0;
}
