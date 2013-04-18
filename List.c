/*Jesus Magana */
/*jmagana7 */
/*pa1 */
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct Node{
	long data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef Node* NodeRef;

typedef struct List{
	NodeRef front;
	NodeRef back;
	NodeRef current;
	int length;
} List;


NodeRef newNode(long node_data){
	NodeRef N = malloc(sizeof(Node));
	N->data = node_data;
	N->next = NULL;
	N->prev = NULL;
	return(N);
}

void freeNode(NodeRef* pN){
	if( pN!=NULL && *pN!=NULL){
		free(*pN);
		*pN = NULL;
	}
}

ListRef newList(void){
	ListRef L;
	L = malloc(sizeof(List));
	L->front = L->back = L->current = NULL;
	L->length = 0;
	return(L);
}

void freeList(ListRef* pL){
	if(pL==NULL && *pL==NULL) {return;}
	while( !isEmpty(*pL)) {
        deleteFront(*pL);
	}
	free(*pL);
	*pL = NULL;
}

/*** Access functions***/
int getFront(ListRef L){
	if(L == NULL){
		printf("List error: calling getFront on NULL ListRef\n");
		exit(1);
	}
	if( isEmpty(L)){
		printf("List error: calling getFront on an empty ListRef\n");
		exit(1);
	}
	return(L->front->data);
}

int getBack(ListRef L){
	if(L == NULL){
		printf("List error: calling getBack on NULL ListRef\n");
		exit(1);
	}
	if( isEmpty(L)){
		printf("List error: calling getFront on an empty ListRef\n");
		exit(1);
	}
	return(L->back->data);
}

int getLength(ListRef L){
	if(L == NULL){
		printf("List error: calling getLength on NULL ListRef\n");
		exit(1);
	}
	return(L->length);
}

int isEmpty(ListRef L){
	if(L==NULL){
		printf("List Error: calling isEmpty on NULL ListRef\n");
		exit(1);
	}
	return(L->length==0);
}

int getIndex(ListRef L){
	if(L == NULL){
		printf("List error: calling getIndex on NULL ListRef\n");
		exit(1);
	}
	if(offEnd(L)){
		printf("List error: calling getIndex when current == NULL;");
		exit(1);
	}
	Node* N = NULL;
	int i = 1;
	for(N = L->front; N != L->current; N=N->next){
		i++;
	}
	return i;
}

int offEnd(ListRef L){
	if(L==NULL){
		printf("List error: callinf offEnd on NULL ListRef\n");
		exit(1);
	}
	return(L->current==NULL);
}

long getCurrent(ListRef L){
	if(L == NULL){
		printf("List error: calling getCurrent on NULL ListRef\n");
		exit(1);
	}
	if( isEmpty(L)){
		printf("List error: calling getCurrent on empty ListRef\n");
		exit(1);
	}
	if( offEnd(L)){
		printf("List error: calling getCurrent when current isnt defined\n");
		exit(1);
	}
	return(L->current->data);
}

int atFirst(ListRef L){
	if (L->current == L->front){
		return 1;
	} else {
		return 0;
	}
}

int atLast(ListRef L){
	if (L->current == L->back){
		return 1;
	} else {
		return 0;
	}

}

/*** Manipulation procedures***/
void makeEmpty(ListRef L){
	NodeRef N = NULL;
	N = L->front;

	while(N != NULL){
		freeNode(&N);
	}	
	L->length = 0;
	L->front = L->back = L->current = NULL;
}

void insertBack(ListRef L, long data)
{
	NodeRef N = newNode(data);

	if(L==NULL){
		printf("List error: calling insertBack on Null ListRef\n");
	exit(1);
	}
	if(isEmpty(L)) {L->front = L->back = N;}
	else { 
		(L->back)->next = N; 
		N->prev = L->back;
		L->back = N;
	}
	L->length++;
}

void insertFront(ListRef L, long data){
	NodeRef N = newNode(data);

	if(L==NULL){
		printf("List error: calling insertFront on NULL listRef\n");
		exit(1);
	}
	if(isEmpty(L)) {L->front = L->back = N;}
	else {	
		(L->front)->prev = N;
		N->next = L->front;
		L->front = N;
	}
	L->length++;
}

void moveFirst(ListRef L){
	L->current = L->front;
}

void moveLast(ListRef L){
	L->current = L->back;
}

void insertAfterCurrent(ListRef L, long data){

	if(L==NULL){
		printf("List error: calling insertAfterCurrent on NULL ListRef\n");
		exit(1);
	} if (offEnd(L)){
		printf("List error: calling insertAfterCurrent on NULL current\n");
		exit(1);
	}
	if(L->back == L->current){
		insertBack(L, data);
	} else {
		NodeRef N = newNode(data);
		N->next = (L->current)->next;
		N->prev = L->current;
		(N->next)->prev = N;
		(L->current)->next = N;
	}
	L->length++;
}

void insertBeforeCurrent(ListRef L, long data){
	if(L==NULL){
		printf("List error: calling insertBeforeCurrent on NULL ListRef\n");
		exit(1);
	} if (offEnd(L)){
		printf("List error: calling insertBeforeCurrent on Null curren\n");
		exit(1);
	}
	NodeRef N = newNode(data);
	if(L->front == L->current){
		insertFront(L, data);
	} else {
		N->next = L->current;
		N->prev = L->current->prev;
		N->prev->next = N;
		L->current->prev = N;
	}
	L->length++;
}

void moveTo(ListRef L, int i){
	if(i < 0 || i > L->length){
		L->current = NULL;
	} else {
		int j = 1;
		L->current = L->front;
		for(j = 1; j < i; j++){
			L->current = L->current->next;
		}
		
		if(i == 0)
			L->front = L->current;
		if(i == L->length)
			L->back = L->current;
	}
}

void movePrev(ListRef L){
	if(L==NULL){
		printf("List error: calling movePrev on NULL ListRef\n");
		exit(1);
	} else if(isEmpty(L)){
		printf("List error: calling movePrev on empty list");
		exit(1);
	} else if(offEnd(L)){
		printf("List error: calling movePrev when current = NULL\n");
		exit(1);
	} else if(L->current == L->front){
		L->current = NULL;
	} else {
		L->current= L->current->prev;
	}
}

void moveNext(ListRef L){
	if(L==NULL){
		printf("List error: calling moveNext on NULL ListRef\n");
		exit(1);
	} else if(isEmpty(L)){
		printf("List error: calling moveNext on empty List\n");
		exit(1);
	} else if(offEnd(L)){
		printf("List error: calling moveNext when current = NULL\n");
		exit(1);
	} else if(L->current == L->back){
		L->current = NULL;
	} else {
		L->current=L->current->next;
	}
}

void deleteFront(ListRef L){
	NodeRef N = NULL;

	if(L == NULL){
		printf("List error: calling deletefront on Null ListRef\n");
		exit(1);
	}
	if( isEmpty(L)){
		printf("List error: calling deletefront on empty queueRef\n");
		exit(1);
	}
	N = L->front;
	if( getLength(L)>1) {
		L->front = L->front->next;
		L->front->prev = NULL;
	}
	else {L->front = L->back =  NULL;}
	L->length--;
	freeNode(&N);
}

void deleteBack(ListRef L){
	NodeRef N = NULL;

	if(L==NULL){
		printf("List error: calling deleteback on Null ListRef\n");
		exit(1);
	}
	if(isEmpty(L)){
		printf("List error: calling deleteBack on empty List\n");
		exit(1);
	}
	N = L->back;
	if( getLength(L)>1){
		L->back = (L->back)->prev;
		(L->back)->next = NULL;
	}
	else {L->front = L->back = NULL;}
	L->length--;
	freeNode(&N);
}

void deleteCurrent(ListRef L){
	NodeRef N = NULL;
	if(L==NULL){
		printf("List error: calling deleteCurrent on NULL ListRef\n");
		exit(1);
	}
	if(isEmpty(L)){
		printf("List error: calling deleteCurrent on empty List\n");
		exit(1);
	}
	if(offEnd(L)){
		printf("List error: calling deleteCurrent when current = NULL\n");
		exit(1);
	}
	N = L->current;
	if(getLength(L)>1){
		L->current->prev->next = L->current->next;
		L->current->next->prev = L->current->prev;
		L->current = NULL;
	} else {
		L->front = L->back = L->current = NULL;
	}
	L->length--;
	freeNode(&N);
}

/***Other ***/
void printList(ListRef L){
	Node* N = NULL;

	if(L==NULL){
		printf("List error: calling printList on empty ListRef\n");
		exit(1);
	}
	for(N = L->front; N != NULL; N = N->next){
		printf("%ld ", N->data);
	}
	printf("\n");
}

int equals(ListRef A, ListRef B){
	int flag = 1;
	Node* N = NULL;
	Node* M = NULL;

	if( A==NULL || B==NULL){
		printf("List error: calling equals on NULL ListRef\n");
	}
	N = A->front;
	M = B->front;
	if(A->length != B->length) {return 0;}
	while( flag && N!=NULL){
		flag =(N->data==M->data);
		N = N->next;
		M = M->next;
	}
	return flag;
}

ListRef copyList(ListRef L){
	NodeRef N = NULL;
	ListRef M = newList();
	for(N = L->front; N != NULL; N=N->next){
		insertBack(M, N->data);	
	}
	return M;
}




