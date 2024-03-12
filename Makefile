##
# Project Title
#
# @file
# @version 0.1

all: install

brainfuckI: ./src/main.c
	clang -o brainfuckI ./src/main.c

install: brainfuckI
	sudo mv brainfuckI /bin
	brainfuckI ./src/test.bf


# end
