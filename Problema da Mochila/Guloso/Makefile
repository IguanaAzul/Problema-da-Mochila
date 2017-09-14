TARGET = main

all: default
    
default: main

main: guloso.c
	gcc -c guloso.o -o guloso

run: guloso
	./guloso

clean:
	-rm -f guloso.o
	-rm -f guloso
	-rm -f Out.txt
