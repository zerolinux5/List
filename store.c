#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define MAX_LEN 250

int main(int argc, char *argv[]){
        int n, count = 0;
        int j = 0;
        int s = 0;
        int t = 0;
        int i = 0;
        long k = 0;
        FILE *in;
        char line[MAX_LEN];
        char tokenlist[MAX_LEN];
        char *token;

        in = fopen(argv[1], "r");
        if(in==NULL){
                printf("unable to open file %s for reading\n", argv[1]);
                exit(1);
        }

        fgets(line, MAX_LEN, in);
        token = strcat(line, "\n");
        tokenlist[0] = '\0';
        strcat(tokenlist, token);
        int numOfCustomers = atoi(tokenlist);

        ListRef numOfCustomersArray[numOfCustomers];
        for(s = 0; s < numOfCustomers; s++){
        	numOfCustomersArray[s] = newList();
        }
        int numPurchases;
        fscanf (in, "%d", &numPurchases); 
        for(j = 0; j < numPurchases; j++){
        	fscanf (in, "%d", &i); 
        	fscanf (in, "%ld", &k); 
        	if(isEmpty(numOfCustomersArray[i-1])){
        		insertBack(numOfCustomersArray[i-1], k);
        	} else {
        		moveFirst(numOfCustomersArray[i-1]);
        		for(s = 0; s < getLength(numOfCustomersArray[i-1]);s++){
        			if(k >= getCurrent(numOfCustomersArray[i-1])){
        				moveNext(numOfCustomersArray[i-1]);
        				if(offEnd(numOfCustomersArray[i-1])){
        					insertBack(numOfCustomersArray[i-1], k);
        					break;
        				}
        			} else if(k < getCurrent(numOfCustomersArray[i-1])){
        				insertBeforeCurrent(numOfCustomersArray[i-1], k);
        				break;
        			}
        		}
        	}
        	
        }

        /*print out the results*/
        printf("Customer Number		:		Book ID \n");
        for(s = 0; s < numOfCustomers; s++){
        	printf("%d : ", s+1);
        	printList(numOfCustomersArray[s]);
        }

        for(s = 0; s < numOfCustomers; s++){
        	printf("hello\n");
        	freeList(&(numOfCustomersArray[s]));
        }
        fclose(in);
        return(0);
}