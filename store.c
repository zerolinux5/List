#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define MAX_LEN 250

int main(int argc, char *argv[]){
        int n, count = 0;
        int j = 0;
        int s = 0;
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

        fgets(line, MAX_LEN, in);
        token = strcat(line, "\n");
        tokenlist[0] = '\0';
        strcat(tokenlist, token);
        int numPurchases = atoi(tokenlist);
        for(j = 0; j < numPurchases; j++){
        	fscanf (in, "%d", &i); 
        	fscanf (in, "%ld", &k); 
        	insertBack(numOfCustomersArray[i-1], k);
        }
        printList(numOfCustomersArray[i]);

        for(s = 0; s < numOfCustomers; s++){
        	freeList(&(numOfCustomersArray[s]));
        }
        fclose(in);
        return(0);
}