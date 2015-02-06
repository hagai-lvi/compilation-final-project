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
