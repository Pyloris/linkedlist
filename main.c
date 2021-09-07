#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void main() {
	// main code for linked list
	// get user choice
	int choice;
	while(1){
		printf("\n1. Create a LinkedList\n2. Insert a Node at beginning\n3. Insert a Node at End\n4. Insert a Node in Empty List\n5. Insert after a node\n6. Insert before a node\n7. Traverse the List\n8. Reverse the linkedlist\n");
		printf("\nYour Choice: ");
		scanf("%d", &choice);
		// to store data
		int data;
		// to store total terms
		int n;
		switch (choice){
			case 1:
				printf("Enter number of Nodes: ");
				scanf("%d", &n);
				start = createlist(start, n);
				break;
			case 2:
				printf("\nEnter data: \n");
				scanf("%d", &data);
				start = insertbeg(start, data);
				break;
			case 3:
				printf("\nEnter data: \n");
				scanf("%d", &data);
				start = insertend(start, data);
				break;
			case 4:
				printf("\nEnter data: \n");
				scanf("%d", &data);
				start = insertemp(start, data);
				break;
			case 5:
				printf("\nEnter value after which to insert: ");
				scanf("%d", &n);
				printf("\nEnter data to be inserted: ");
				scanf("%d", &data);
				start = insertafter(start, n, data);
				break;
			case 6:
				printf("\nEnter value before which to insert: ");
				scanf("%d", &n);
				printf("\nEnter data to be inserted: ");
				scanf("%d", &data);
				start = insertbefore(start, n, data);
				break;
			case 7:
				traverse(start);
				break;
			case 8:
				start = reverse(start);
				traverse(start);
				break;
			default:
				printf("Please Choose something!\n");
				break;
		}
	}
}