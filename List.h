/*Jesus Magana */
/*jmagana7 */
/*pa1 */
#if !defined(_LIST_H_INCLUDE_)
#define _LIST_H_INCLUDE_
#include <stdio.h>
#include <stdlib.h>

typedef struct List * ListRef;

ListRef newList(void);

void freeList(ListRef* pL);

/*** Access Functions  ***/

int getFront(ListRef L);

int getLength(ListRef L);

int isEmpty(ListRef L);

int offEnd(ListRef L);

long getCurrent(ListRef L);

int getIndex(ListRef L);

int atFirst(ListRef L);

int atLast(ListRef L);

/*** Manipulation functions***/
void insertBack(ListRef L, long data);

void insertFront(ListRef L, long data);

void moveTo(ListRef L, int i);

void movePrev(ListRef L);

void moveNext(ListRef L);

void insertAfterCurrent(ListRef L, long data);

void insertBeforeCurrent(ListRef L, long data);

void deleteFront(ListRef L);

void deleteBack(ListRef L);

void deleteCurrent(ListRef L);

/***Other functions ***/
void printList(ListRef L);

int equals(ListRef A, ListRef B);

ListRef copyList(ListRef A);

#endif
