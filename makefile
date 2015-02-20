.SUFFIXES: .c
C_FILES := $(wildcard *.c)

FILE_NAMES=$(basename $(C_FILES))


$(FILE_NAMES): $(FILE_NAMES).c
	gcc -o $@ $^
