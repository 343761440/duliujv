CC=gcc
STD=-std=gnu99
BIN=system.bin
FLAG=-Wall -Werror
OBJ=main.o system.o student.o teacher.o master.o tools.o

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)
main.o:main.c system.h
	$(CC) $(STD) $(FLAG) -c main.c
system.o:system.c system.h student.h teacher.h master.h tools.h
	$(CC) $(STD) $(FLAG) -c system.c
student.o:student.c student.h tools.h
	$(CC) $(STD) $(FLAG) -c student.c
teacher.o:teacher.c teacher.h tools.h
	$(CC) $(STD) $(FLAG) -c teacher.c
master.o:master.c master.h tools.h
	$(CC) $(STD) $(FLAG) -c master.c
tools.o:tools.c tools.h
	$(CC) $(STD) $(FLAG) -c tools.c
clean:
	rm -rf $(BIN) $(OBJ)
