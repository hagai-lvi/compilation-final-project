.SUFFIXES: .c
CPP_FILES := $(wildcard *.c)

FILE_NAMES=$(basename $(CPP_FILES))


$(FILE_NAMES): $(FILE_NAMES).c
	gcc -o $@ $^