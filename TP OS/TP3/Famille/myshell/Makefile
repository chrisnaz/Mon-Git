CC=gcc
CFLAGS=-g -Wall
SRC=myshell.c read_commands.c
OBJS=${SRC:.c=.o}
BIN=myshell

.PHONY: all

all: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${BIN}


%.o: %.c Makefile
	${CC} ${CFLAGS} -c $<

.PHONY: clean
clean:
	rm -f *.o ${BIN} a.out
