CC = gcc
CFLAGS = -g 
OBJ = lab26.o dec.o sort.o
PROG = program

build: lab26.o dec.o sort.o
		$(CC) $(CFLAGS) -o $(PROG) $(OBJ)
        
lab26.o: lab26.c
		$(CC) $(CFLAGS) -c lab26.c
        
dec.o: dec.c dec.h
		$(CC) $(CFLAGS) -c dec.c

sort.o: sort.c sort.h
	    $(CC) $(CFLAGS) -c sort.c

clean:
	rm $(PROG) $(OBJ)
	
