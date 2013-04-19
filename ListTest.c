/*Jesus Magana */
/*jmagana7 */
/*pa5 */
#include <stdio.h>
#include "List.h"

int main(int argc, char *argv[])
{
	int i;
	ListRef A = newList();
	ListRef B = newList();

	/*Will make two lists: 1 from 1 to 10 the other from 10 to 1*/
	for(i = 1; i<=10; i++){
		insertBack(A, i);
		insertBack(B, 11-i);
	}
	/*Print them both and skip a line so i can read them*/
	printList(A);
	printList(B);
	printf("\n");

	/*Test the moving function,at first function, and at last function*/
	/*Should print out 1,1,0,1,1*/
	moveTo(A, 0);
	printf("%ld\n",getCurrent(A));
	printf("%d\n",atFirst(A));
	
	
	int z = 0;
	for(z = 1; z < 10; z++){
		moveNext(A);
	}
	printf("%d\n",atFirst(A));
	printf("%d\n",atLast(A));
	
	moveTo(A,0);
	printf("%ld\n",getCurrent(A));






	/*will insert the front of b to the front of a and delete the front of b*/
	for(i = 1; i <=6; i++){
		insertFront(A, getFront(B));
		deleteFront(B);
	}

	/*will insert the front of a to the front of b and delete the front of a*/
	for(i = 1; i <=6; i++){
		insertFront(B, getFront(A));
		deleteFront(A);
	}

	printList(A);
	printList(B);
	printf("\n");

	/*Take the first three values of a and paste them to the back of b*/
	for(i = 1; i <= 3; i++){
		insertFront(B, getFront(A));
		deleteFront(A);
	}
	printList(A);
	printList(B);
	printf("\n");

	/*Move to 3, then back, then forward and insert before the 3rd value and after, 5*/
	moveTo(A, 3);
	movePrev(A);
	moveNext(A);
	insertAfterCurrent(A, 5);
	insertBeforeCurrent(A,5);
	printList(A);
	printList(B);
	printf("\n");

	/*Move to different locations and insert more numbers then delete the current value*/
	moveTo(A, 5);
	moveTo(A, 3);
	moveTo(A, 6);
	moveTo(A, 4);
	moveTo(A, 5);
	insertAfterCurrent(A, 8);
	insertBeforeCurrent(A, 5);
	deleteCurrent(A);
	printList(A);
	printList(B);
	printf("\n");
	ListRef C;
	C = copyList(A);
	printList(C);
	printf("\n");

	printf("%s\n", equals(A,B)?"true":"false");
	printf("%s\n", equals(A,A)?"true":"false");
	printf("\n");

	freeList(&A);
	freeList(&B);
	freeList(&C);

	return(0);
}
