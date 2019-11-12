all: rand.o
	gcc -o program rand.o

rand.o: rand.c
	gcc -c rand.c

run:
	./program

clean:
	rm *.o
	rm *~
