.SUFFIXES: .c

%: %.c
	gcc -x c -o $@ $<