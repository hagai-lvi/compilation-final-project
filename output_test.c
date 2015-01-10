#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 1
#include "arch/cisc.h"

int main()
{
  START_MACHINE;

  
//empty env
PUSH(IMM(1));
CALL(MALLOC);
MOV(R12,R0)
DROP(1);
//***


    JUMP(CONTINUE);

  #include "functions.lib"

   CONTINUE:
MAKE_INTEGER(2);
PUSH(R0); 
//end of params
PUSH(IMM(1));
//**************proc code**********
MAKE_INTEGER(1);
PUSH(R0); 
//end of params
PUSH(IMM(1));
//**************proc code**********
// Starting code-gen for lambda
// TODO code-for-env-size
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
JUMP(L_lambda_exit1);L_lambda_code1: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda

// Starting code-gen for lambda
// TODO code-for-env-size
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
JUMP(L_lambda_exit2);L_lambda_code2: // the begining of the actual code of the lambda
PUSH(FP);
MOV(FP, SP);
// TODO need to check arguments here

// Here starts the code of the actual lambda

MOV_PVAR(0);
PUSH(R0); 
MOV_BVAR(0,0);
PUSH(R0); 
//end of params
PUSH(IMM(2));
//**************proc code**********
MAKE_CLOSURE(CONS);
//**************proc code**********
CMP(IND(R0),T_CLOSURE);
JUMP_NE(lnot_proc);
MOV(R1,INDD(R0 , IMM(1))); //push env
PUSH(R1);
CALLA((INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,STARG(0));
ADD(R1,2);
DROP(IMM(R1)); //remove all

// Here ends the code of the actual lambda

POP(FP);
RETURN;
L_lambda_exit2:

// Here ends the code of the actual lambda

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
// This code is to be appended to the final cisc file created by our compiler
PUSH(R0);
CALL(WRITE_SOB);
CALL(NEWLINE);

	lnot_proc:
  l_NOT_VALID_ARGUMENTS:	
  l_NOT_PAIR:
  STOP_MACHINE;

  return 0;
}
