#include <stdio.h>
#include <stdlib.h>

/*
	Linked list related functions and structure definition
*/

// structure definition
struct node {
	// data storage
	int data;
	// address of next node
	struct node *link;
}*start=NULL;

/* ++++++++++++++++++++++ Function Declarations ++++++++++++++++++++++ */

struct node *insertemp(struct node *, int);
struct node *insertend(struct node *, int);
struct node *insertbeg(struct node *, int);
struct node *insertat(struct node *, int, int);
struct node *createlist(struct node *, int);
void traverse(struct node *);
struct node *insertafter(struct node *, int, int);
struct node *insertbefore(struct node *, int, int);

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */



/* ++++++++++++++++++++++ Function Definitions +++++++++++++++++++ */

// Functions to work with the linked list

// function to create a node in an empty linked list
struct node *insertemp(struct node *start, int data){
	// create node and give it size
	struct node *fnode = (struct node *) malloc(sizeof(struct node));

	// give it data and make
	// start point to it
	fnode->data = data;
	fnode->link = NULL;
	start = fnode;

	// return start
	return start;
}

// function to add a node at the end of linked list
struct node *insertend(struct node *start, int data){

	// if start is NULL
	// run insertemp
	if (start == NULL){
		start = insertemp(start, data);
		return start;
	}

	// create node and give it space
	struct node *fnode = (struct node *) malloc(sizeof(struct node));

	// give it data
	fnode->data = data;
	fnode->link = NULL;

	// make previous node point to it
	struct node *p = start;
	while(p!=NULL){
		if (p->link == NULL){
			p->link = fnode;
			break;
		}
		p = p->link;
	}

	// return start
	return start;
}

// function to add node at the beginning
struct node *insertbeg(struct node *start, int data){
	// create a node and give it mem
	struct node *fnode = (struct node *) malloc(sizeof(struct node));

	// make this node point to first node
	fnode->data = data;
	fnode->link = start;

	// make start point to this node
	start = fnode;

	// return start
	return start;
}

// function to add at some index
struct node *insertat(struct node *start, int data, int index){
	// create a node and give it space
	struct node *fnode = (struct node *) malloc(sizeof(struct node));

	// add data to this node 
	fnode->data = data;

	// loop till index-1 and make fnode
	// point to next node
	// and make index-1 node point to fnode
	struct node *temp = start;	// temp pointer to iterate

	for (int i=0;i<index;i++){

		// check if end reached
		if (temp->link != NULL){

			// check if we are at our index
			if (i == index-1){

				// perform the swap
				fnode->link = temp->link;
				temp->link = fnode;

				// return start
				return start;
			}
		}else{
			printf("Invalid Index!\n");
			return start;
		}
	}
}

// function to create linked list with given
// number of terms

struct node *createlist(struct node *start, int total){
	// to store data
	int data;

	// iterate over the nodes and add new node at end
	for (int i=0;i<total;i++){
		printf("Enter Data for %d: ", i);
		scanf("%d", &data);
		start = insertend(start, data);
	}

	// return start
	return start;
}

// function to traverse the linked list
void traverse(struct node *start){
	// create temp node
	struct node *temp = start;
	// iterator
	int i=0;
	system("cls");
	// iterate over all nodes
	while(temp!=NULL){
		printf("Data at index %d: %d\n", i++, temp->data);
		temp = temp->link;
	}
	
}

// function to insert after a given node
struct node *insertafter(struct node *start, int value, int data){
	// create a node and add the data
	struct node *fnode = (struct node *) malloc(sizeof(struct node));
	fnode->data =data;

	// temp node to iterate
	struct node *temp = start;

	while(temp!=NULL){
		if(temp->data == value){
			fnode->link = temp->link;
			temp->link = fnode;
			return start;
		}
		temp = temp->link;
	}
	printf("Value not Found!\n");
	return start;
}

// function to insert a node before a given value
struct node *insertbefore(struct node *start, int value, int data){
	struct node *temp;
	temp = start;
	if (temp == NULL){
		start = insertemp(start, data);
		return start;
	}
	while(temp!=NULL){
		if (temp->link->data == value){
			struct node *fnode = (struct node *) malloc(sizeof(struct node));
			fnode->data = data;
			fnode->link = temp->link;
			temp->link = fnode;
			return start;
		}
		temp = temp->link;
	}
	printf("Value not Found!\n");
	return start;
}

/* +++++++++++++++++++++++ END +++++++++++++++++++++++++ */


/* +++++ Deleting nodes +++++++++++++++++++++++++++++++*/

// function to delete first node
struct node *deletefirst(struct node *start){
	// store the first node in temp
	struct node *temp = start;

	// make start point to 2nd node
	start = start->link;

	// free the space of first node
	free(temp);
}

// function to delete only node in list
struct node *deleteonly(struct node *start){
	// free the space
	free(start);
	// make start point to null
	start = NULL;
}

// function to delete between the list
struct node *deletebetween(struct node *start, int value){
	// store the node to iterate
	struct node *temp = start;

	// iterate over the nodes
	while(temp!=NULL){
		// check if it is desired node
		if (temp->link->data == value){
			// make previous node point to next one
			temp->link = temp->link->link;
			free(temp->link);
			return start;
		}
		temp = temp->link;
	}
	printf("Value not found!\n");
	return start;
}

// function to delete at the end of the list
struct node *deleteatend(struct node *start){
	// store the access node to iterate
	struct node *temp = start;

	// iterate over the nodes
	while(temp!=NULL){
		if(temp->link->link==NULL){
			// free the end node
			free(temp->link);
			// point it to null
			temp->link=NULL;
			return start;
		}
		temp = temp->link;
	}
}

/* +++++++++++++++++++++++++++++ END ++++++++++++++++++++++++++++++++++ */

/*
function to reverse the linked list
*/
struct node *reverse(struct node *start){
	// create 3 pointers
	struct node *prev, *ptr, *next;

	ptr = start;
	prev=NULL;

	while(ptr!=NULL){
		next=ptr->link;
		ptr->link = prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}