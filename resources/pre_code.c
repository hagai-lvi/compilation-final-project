#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 1
#include "arch/cisc.h"
#define SOB_FALSE IMM(3)
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
