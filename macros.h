#define SCMARG(n) FPARG(IMM(n + 2))
#define SCMENV FPARG(IMM(0))
#define SCMNARGS FPARG(IMM(1))
#define SOB_BOOLEAN_FALSE 0
#define SOB_BOOLEAN_TRUE 1
#define MAKE_NUMBER(i) PUSH(IMM(i));  CALL(MAKE_SOB_NUMBER);DROP(1)

#define MAKE_INTEGER(i) PUSH(IMM(i));  CALL(MAKE_SOB_INTEGER);DROP(1)
#define MAKE_BOOL(i) PUSH(IMM(i));  CALL(MAKE_SOB_BOOL); DROP(1)
#define MAKE_CHAR(i) PUSH(IMM(i));  CALL(MAKE_SOB_CHAR);DROP(1)
#define MAKE_VECTOR(i) PUSH(IMM(i));  CALL(MAKE_SOB_VECTOR);DROP(1)
#define MAKE_SYMBOL(i) PUSH(IMM(i));  CALL(MAKE_SOB_SYMBOL);DROP(1)
#define MAKE_STRING(i) PUSH(IMM(i)); PUSH(IMM(1));  CALL(MAKE_SOB_STRING); DROP(2)
#define MOV_PVAR(j) MOV(R0, SCMARG(j+1))
#define MOV_BVAR(i, j) MOV(R0, FPARG(1)); MOV(R0, INDD(R0, i)); MOV(R0, INDD(R0, j))
#define MAKE_CLOSURE(FUNC) PUSH(LABEL(FUNC));PUSH(R12);CALL(MAKE_SOB_CLOSURE); DROP(2);
#define T_NUMBER	101555


