build: 
	cc -c -o main.o main.c
	cc -c -o maf.o maf.c
	cc -o main main.o maf.o

clean:
	rm -f main.o
	rm -f maf.o

run: 
	./main

buildrc:
	make build
	make clean
	make run
	
	