all	:
	gcc -g -O0 -Wall -Wextra -std=gnu99 list.h list.c store.c
run	:	a.out	test.txt
	./a.out test.txt

test	:
	gcc -g -O0 -Wall -Wextra -std=gnu99 list.h list.c listTest.c
runTest	:	a.out
	./a.out
