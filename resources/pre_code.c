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
