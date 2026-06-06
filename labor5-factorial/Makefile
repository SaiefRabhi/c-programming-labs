CC = gcc -Wall
PRG = ueb05
OBJ = ueb05.o

all: clean $(PRG) run

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb05.o: ueb05.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run:
	./$(PRG)
