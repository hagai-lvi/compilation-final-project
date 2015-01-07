#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 1

#include "arch/cisc.h"
#include "macros.h"
int main()
{
  START_MACHINE;

  JUMP(CONTINUE);

#include "arch/char.lib"
#include "arch/io.lib"
#include "arch/math.lib"
#include "arch/string.lib"
#include "arch/system.lib"
#include "arch/scheme.lib"

 CONTINUE:
MAKE_INTEGER(2);
PUSH(R0); 
//end of params
PUSH(IMM(1));
MOVE_PVAR(0);
PUSH(R0);
CMP(IND(R0),T_CLOSURE);
JUMP_NE(Lnot_proc);
MOV(R1,INDD(R0 , IMM(1)));
PUSH(R1);
CALL(*(INDD(R0 , IMM(2))));
DROP(IMM(2+SCMNARGS));
// This code is to be appended to the final cisc file created by our compiler
Lnot_proc:
  STOP_MACHINE;

  return 0;
}
