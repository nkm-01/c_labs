shared.o:
	gcc -c shared.c -o shared.o -g

while.o: clear_while
	gcc -c while.c -o while.o -g

do.o: clear_do
	gcc -c do.c -o do.o -g

while: while.o shared.o
	gcc while.o shared.o -lm -o while

do: clear_do
	gcc shared.o do.o -o do -lm

clear_while:
	rm while 2> /dev/null
	rm while.o 2> /dev/null

clear_do:
	rm do 2> /dev/null
	rm do.o 2> /dev/null
