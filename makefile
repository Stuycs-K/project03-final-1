.PHONY: clean run compile
run: prog
	@./prog
clean:
	rm -f *.o prog
compile prog: main.o
	@gcc -g -o prog main.o -lm -lncurses
main.o: main.c
	@gcc -g -c main.c
