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
MAKE_INTEGER(2);
PUSH(R0); 
MAKE_INTEGER(2);
PUSH(R0); 
MAKE_INTEGER(2);
PUSH(R0); 
MAKE_INTEGER(3);
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
CALL(*(INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,SCMNARGS);
ADD(R1,2);
DROP(IMM(R1)); //remove all
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
CALL(*(INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,SCMNARGS);
ADD(R1,2);
DROP(IMM(R1)); //remove all
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
CALL(*(INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,SCMNARGS);
ADD(R1,2);
DROP(IMM(R1)); //remove all
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
CALL(*(INDD(R0 , IMM(2)))); // jump to code label
MOV(R1,SCMNARGS);
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
