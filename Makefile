##
# Project Title
#
# @file
# @version 0.1

all: clean

brainfuckI: src/main.c src/shell.c src/parser.c
	clang -o brainfuckI src/main.c src/shell.c src/parser.c -lSDL2

run: brainfuckI
	./brainfuckI

test: brainfuckI
	./brainfuckI ./src/test.bf

install: brainfuckI
	sudo mv brainfuckI /bin
	brainfuckI ./src/test.bf


clean: run
	rm brainfuckI

# end
