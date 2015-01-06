#include <stdio.h>
#include <stdlib.h>

/* change to 1 for debug info to be printed: */
#define DO_SHOW 0


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
// This code is to be appended to the final cisc file created by our compiler

  STOP_MACHINE;

  return 0;
}
