/* scheme/write_sob_pair.asm
 * Take a pointer to a Scheme pair object, and 
 * prints (to stdout) the character representation
 * of that object.
 * 
 * Programmer: Mayer Goldberg, 2010
 */

 WRITE_SOB_PAIR:
  PUSH(FP);
  MOV(FP, SP);
   PUSH(R1);
  PUSH(R2);
  PUSH(R3);
  PUSH(R4);
  MOV(R0, FPARG(0));
  MOV(R1,INDD(R0,1));
  MOV(R2,INDD(R0,2)); 
  CMP(IND(R1),T_PAIR);
  CMP(IND(R2),T_PAIR);
  MOV(R4,R0);
  OR(R0,R3);
  JUMP_NE(WRITE_REG_PAIR);
  JUMP_EQ(WRITE_REG_BOTH_PAIR);
  WRITE_REG_PAIR:
  PUSH(IMM('('));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(R1);
  CALL(WRITE_SOB);
  DROP(1);
  CMP(IND(R2),T_NIL);
  JUMP_EQ(LIST_PRINT);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(IMM('.'));
  CALL(PUTCHAR);
  DROP(1);

  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(R2);
  CALL(WRITE_SOB);
  DROP(1);
  LIST_PRINT:
  PUSH(IMM(')'));
  CALL(PUTCHAR);
  DROP(1);
  JUMP(PAIR_EXIT);
  WRITE_REG_BOTH_PAIR:
  PUSH(IMM('('));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(R1);
  CALL(WRITE_SOB);
  DROP(1);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(R2);
  CALL(WRITE_SOB_PAIR_WITH_NO_BRACE);
  DROP(1);
  PUSH(IMM(')'));
  CALL(PUTCHAR);
  DROP(1);
  PAIR_EXIT:
  POP(R4);
  POP(R3);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;



WRITE_SOB_PAIR_WITH_NO_BRACE:
  PUSH(FP);
  MOV(FP, SP);
    PUSH(R1);
  PUSH(R2);
  MOV(R0, FPARG(0));
  MOV(R1,INDD(R0,1));
  MOV(R2,INDD(R0,2));
  PUSH(R1);
  CALL(WRITE_SOB);
  DROP(1);
  CMP(IND(R2),T_NIL);
  JUMP_EQ(LIST_PRINT_WITH_NO_BRACE);
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(IMM('.'));
  CALL(PUTCHAR);
  DROP(1);
  LIST_PRINT_WITH_NO_BRACE:
  PUSH(IMM(' '));
  CALL(PUTCHAR);
  DROP(1);
  PUSH(R2);
  CALL(WRITE_SOB);
  DROP(1);
  POP(R2);
  POP(R1);
  POP(FP);
  RETURN;

