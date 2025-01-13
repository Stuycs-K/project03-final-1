.PHONY: clean run compile
run: prog
	@./prog
clean:
	rm -f *.o prog
compile prog: test.o
	@gcc -o prog test.o -lm -lncurses
main.o: test.c
	@gcc -c test.c
