#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 1
#define SCMARG(n) (FPARG(n + 2))
#define SCMENV (FPARG(0))
#define SCMNARGS (FPARGS(1))
#define SOB_BOOLEAN_FALSE 0
#define SOB_BOOLEAN_TRUE 1

#define MOVE_PVAR(j) (MOVE(R0, SCMARG(j)))
#define MOVE_BVAR(i, j) (MOVE(R0, FPARG(0));MOVE(R0, R0[i]);MOVE(R0, R0[j]))

#include "arch/cisc.h"

int main()
{
  START_MACHINE;

  JUMP(CONTINUE);

#include "arch/char.lib"
#include "arch/io.lib"
#include "arch/math.lib"
#include "arch/string.lib"
#include "arch/system.lib"

 CONTINUE:
