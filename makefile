rand.c:
	gcc -o test rand.o
rand.o:
	gcc -c rand.c
run:
	./test
clean:
	rm *~
	rm *.o
