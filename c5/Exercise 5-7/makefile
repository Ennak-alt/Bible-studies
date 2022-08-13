TESTFILES1 = testog.c alloc.c readlines.c getline.c
TESTFILES2 = testnew.c alloc.c readlines.c getline.c

test:
	cc -I./../../tests ../../tests/test.c $(TESTFILES1)
	cat hello.txt | ./a.out
	cat alloc.c | ./a.out
	echo Hello | ./a.out
	rm -f ./a.out
	cc -I./../../tests ../../tests/test.c $(TESTFILES2)
	cat hello.txt | ./a.out
	cat alloc.c | ./a.out
	echo Hello | ./a.out
	rm -f ./a.out