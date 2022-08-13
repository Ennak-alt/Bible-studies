TESTFILES = main.c pointer_versions.c

test:
	cc -I./../../tests ../../tests/test.c $(TESTFILES)
	cat test.txt | ./a.out
	rm -f ./a.out