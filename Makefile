all	:
	gcc -g -O0 -Wall -Wextra -std=gnu99 list.h list.c listTest.c
run	:	a.out
	./a.out
