#define SYM_LIST_LOC 55
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
MOV(R12,IMM(31004));


    JUMP(CONTINUE);
  #include "functions.lib"
   CONTINUE:
ADD(IND(0), 155);
MOV(IND(1) , IMM(T_VOID));
MOV(IND(2) , IMM(T_NIL));
MOV(IND(3) , IMM(T_BOOL));
MOV(IND(4) , IMM(0));
MOV(IND(5) , IMM(T_BOOL));
MOV(IND(6) , IMM(1));
MOV(IND(7) , IMM(T_INTEGER));
MOV(IND(8) , IMM(1));
MOV(IND(9) , IMM(T_INTEGER));
MOV(IND(10) , IMM(100));
MOV(IND(11) , IMM(T_INTEGER));
MOV(IND(12) , IMM(2));
MOV(IND(13) , IMM(T_INTEGER));
MOV(IND(14) , IMM(200));
MOV(IND(15) , IMM(T_INTEGER));
MOV(IND(16) , IMM(123));
//END OF memory allocation 
MAKE_CLOSURE(CONS);
MOV(IND(17) , R0);
MAKE_CLOSURE(CAR);
MOV(IND(18) , R0);
MAKE_CLOSURE(CDR);
MOV(IND(19) , R0);
MAKE_CLOSURE(EQ);
MOV(IND(20) , R0);
MAKE_CLOSURE(IS_NULL);
MOV(IND(21) , R0);
MAKE_CLOSURE(IS_BOOL);
MOV(IND(22) , R0);
MAKE_CLOSURE(IS_INTEGER);
MOV(IND(23) , R0);
MAKE_CLOSURE(IS_NUMBER);
MOV(IND(24) , R0);
MAKE_CLOSURE(IS_STRING);
MOV(IND(25) , R0);
MAKE_CLOSURE(IS_CHAR);
MOV(IND(26) , R0);
MAKE_CLOSURE(IS_VECTOR);
MOV(IND(27) , R0);
MAKE_CLOSURE(IS_SYMBOL);
MOV(IND(28) , R0);
MAKE_CLOSURE(ZERO);
MOV(IND(29) , R0);
MAKE_CLOSURE(IS_PAIR);
MOV(IND(30) , R0);
MAKE_CLOSURE(IS_PROC);
MOV(IND(31) , R0);
MAKE_CLOSURE(MAKE_STRING);
MOV(IND(32) , R0);
MAKE_CLOSURE(CHAR_TO_INTEGER);
MOV(IND(33) , R0);
MAKE_CLOSURE(INTEGER_TO_CHAR);
MOV(IND(34) , R0);
MAKE_CLOSURE(MAKE_VECTOR);
MOV(IND(35) , R0);
MAKE_CLOSURE(VECTOR_LENGTH);
MOV(IND(36) , R0);
MAKE_CLOSURE(VECTOR_REF);
MOV(IND(37) , R0);
MAKE_CLOSURE(VECTOR_SET);
MOV(IND(38) , R0);
MAKE_CLOSURE(STRING_LENGTH);
MOV(IND(39) , R0);
MAKE_CLOSURE(STRING_SET);
MOV(IND(40) , R0);
MAKE_CLOSURE(STRING_REF);
MOV(IND(41) , R0);
MAKE_CLOSURE(SET_CAR);
MOV(IND(42) , R0);
MAKE_CLOSURE(SET_CDR);
MOV(IND(43) , R0);
MAKE_CLOSURE(PLUS);
MOV(IND(44) , R0);
MAKE_CLOSURE(MINUS);
MOV(IND(45) , R0);
MAKE_CLOSURE(MULTIPLY);
MOV(IND(46) , R0);
MAKE_CLOSURE(DIV);
MOV(IND(47) , R0);
MAKE_CLOSURE(BIGGER_THAN);
MOV(IND(48) , R0);
MAKE_CLOSURE(LESS_THAN);
MOV(IND(49) , R0);
MAKE_CLOSURE(NUMBER_EQUALS);
MOV(IND(50) , R0);
MAKE_CLOSURE(APPLY);
MOV(IND(51) , R0);
MAKE_CLOSURE(REMAINDER);
MOV(IND(52) , R0);
MAKE_CLOSURE(SYMBOL_TO_STRING);
MOV(IND(53) , R0);
MAKE_CLOSURE(STRING_TO_SYMBOL);
MOV(IND(54) , R0);
//END OF memory allocation 
MOV(IND(SYM_LIST_LOC),IMM(0));
//************** end of symbol_table **************
MOV(R0,(3));
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
MOV(R0,(7));
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
MOV(R0,(3));
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
MOV(R0,(9));
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
PUSH(IMM(666));
//************************************start of agrument_number1***application_number1***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number1* application_number1*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
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

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-1

POP(FP);
RETURN;
L_lambda_exit1:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
PUSH(IMM(666));
//************************************start of agrument_number1***application_number2***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number1* application_number2*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-2
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

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-2

POP(FP);
RETURN;
L_lambda_exit2:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT1);
MOV(R0,(7));
L_OR_EXIT1:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
PUSH(IMM(666));
//************************************start of agrument_number1***application_number3***************************************
MOV(R0,(5));
PUSH(R0); 
//************************************end of agrument_number1* application_number3*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
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

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-3

POP(FP);
RETURN;
L_lambda_exit3:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
PUSH(IMM(666));
//************************************start of agrument_number1***application_number4***************************************
MOV(R0,(5));
PUSH(R0); 
//************************************end of agrument_number1* application_number4*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-4
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

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-4

POP(FP);
RETURN;
L_lambda_exit4:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT2);
MOV(R0,(7));
L_OR_EXIT2:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT3);
MOV(R0,(7));
L_OR_EXIT3:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT4);
MOV(R0,(5));
L_OR_EXIT4:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT5);
PUSH(IMM(666));
//end of params
PUSH(IMM(0));
//**************proc code**********
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

//************************************start of agrument_number1***application_number6***************************************
MOV(R0,(11));
PUSH(R0); 
//************************************end of agrument_number1* application_number6*****************************************
//************************************start of agrument_number2***application_number6***************************************
MOV(R0,(7));
PUSH(R0); 
//************************************end of agrument_number2* application_number6*****************************************
//end of params
PUSH(IMM(2));
//**************proc code**********
MOV(R0,IND(44));
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(2));//NUMBER OF CURRENT ARGS
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

// Here ends the code of the actual lambda lambda-5

POP(FP);
RETURN;
L_lambda_exit5:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all
L_OR_EXIT5:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
// Starting code-gen for OR
MOV(R0,(7));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT6);
MOV(R0,(5));
L_OR_EXIT6:
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
PUSH(IMM(666));
//************************************start of agrument_number1***application_number7***************************************
MOV(R0,(7));
PUSH(R0); 
//************************************end of agrument_number1* application_number7*****************************************
//************************************start of agrument_number2***application_number7***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number2* application_number7*****************************************
//************************************start of agrument_number3***application_number7***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number3* application_number7*****************************************
//************************************start of agrument_number4***application_number7***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number4* application_number7*****************************************
//end of params
PUSH(IMM(4));
//**************proc code**********
// Starting code-gen for lambda-6
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

// Starting code-gen for OR
MOV_PVAR(0);

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT7);
MOV_PVAR(1);

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT7);
MOV_PVAR(2);

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT7);
MOV(R0,(7));
L_OR_EXIT7:

// Here ends the code of the actual lambda lambda-6

POP(FP);
RETURN;
L_lambda_exit6:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
PUSH(IMM(666));
//************************************start of agrument_number1***application_number8***************************************
// Starting code-gen for lambda-8
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

MOV_PVAR(0);

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_EQ(Lif3else1);
MOV(R0,(9));

JUMP(Lif3exit1);
Lif3else1:
MOV(R0,(13));

Lif3exit1:
// Here ends the code of the actual lambda lambda-8

POP(FP);
RETURN;
L_lambda_exit8:
PUSH(R0); 
//************************************end of agrument_number1* application_number8*****************************************
//************************************start of agrument_number2***application_number8***************************************
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

MOV_PVAR(0);

// Here ends the code of the actual lambda lambda-7

POP(FP);
RETURN;
L_lambda_exit7:
PUSH(R0); 
//************************************end of agrument_number2* application_number8*****************************************
//end of params
PUSH(IMM(2));
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

// Starting code-gen for OR
PUSH(IMM(666));
//************************************start of agrument_number1***application_number10***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number1* application_number10*****************************************
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
ADD(R1,3);
DROP(IMM(R1)); //remove all

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT8);
//************************************start of agrument_number1***application_number9***************************************
MOV(R0,(5));
PUSH(R0); 
//************************************end of agrument_number1* application_number9*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
MOV_PVAR(1);
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
L_OR_EXIT8:

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
ADD(R1,3);
DROP(IMM(R1)); //remove all
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);
//END OF FIRST INPUT********************************************
PUSH(IMM(666));
//************************************start of agrument_number1***application_number11***************************************
MOV(R0,(7));
PUSH(R0); 
//************************************end of agrument_number1* application_number11*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-10
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

// Starting code-gen for OR
PUSH(IMM(666));
//************************************start of agrument_number1***application_number13***************************************
MOV(R0,(7));
PUSH(R0); 
//************************************end of agrument_number1* application_number13*****************************************
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda-12
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

MOV(R0,(3));

// Here ends the code of the actual lambda lambda-12

POP(FP);
RETURN;
L_lambda_exit12:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
DROP(IMM(R1)); //remove all

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT10);
//************************************start of agrument_number1***application_number12***************************************
MOV(R0,(15));
PUSH(R0); 
//************************************end of agrument_number1* application_number12*****************************************
//************************************start of agrument_number2***application_number12***************************************
MOV(R0,(3));
PUSH(R0); 
//************************************end of agrument_number2* application_number12*****************************************
//end of params
PUSH(IMM(2));
//**************proc code**********
// Starting code-gen for lambda-11
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

// Starting code-gen for OR
MOV(R0,(3));

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT9);
MOV_PVAR(0);

CMP(INDD(R0,1), SOB_BOOLEAN_FALSE);
JUMP_NE(L_OR_EXIT9);
MOV_PVAR(1);
L_OR_EXIT9:

// Here ends the code of the actual lambda lambda-11

POP(FP);
RETURN;
L_lambda_exit11:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
MOV(R1,FPARG(-1));PUSH(R1);//push RETURN ADR
MOV(R3,FP);
SUB(R3,FPARG(-2));
MOV(R4,IMM(2));//NUMBER OF CURRENT ARGS
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
L_OR_EXIT10:

// Here ends the code of the actual lambda lambda-10

POP(FP);
RETURN;
L_lambda_exit10:
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,3);
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
