all: clean install
	./game_of_life examples/diamond/diamond.txt examples/diamond/output/

install: program

clean:
	rm -rf *.o program

program: game_of_life.o
	gcc -o game_of_life game_of_life.o

game_of_life.o:
	gcc -c game_of_life.c
