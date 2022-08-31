SRC_DIR := src

SRC := $(wildcard $(SRC_DIR)/*.c)

main: 
	gcc -o main -Iinclude $(SRC)

make run : main
	./main

clean:
	rm -f main