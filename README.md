Linked List Implementation in **C**
===================================

This repo contains Code for **Linked List** Data structure in C language
--------------------------------------------------------------------

* main.c file
It contains **C** code to let users interact with the linked list. The data structure is not created when
*main.c* is ran, rather it gets created when user chooses so. At the start, Linkedlist is just **NULL**.
Only after user creates it can we do things with it.
All the function's that deal with creation and modification/interaction with the data structure are in 
**linkedlist.h** header file. Next we will discuss that.

* linkedlist.h file
It contains all the function's that deal with creation as well as modification of the linkedlist.
The structure used for a *node* in the linkedlist is defined at the top, then you will see all the
function declarations and after that come function definitions.
Here are all the functions defined in the *linkedlist.h* file:

  * struct node *insertemp(struct node *, int);
  * struct node *insertend(struct node *, int);
  * struct node *insertbeg(struct node *, int);
  * struct node *insertat(struct node *, int, int);
  * struct node *createlist(struct node *, int);
  * void traverse(struct node *);
  * struct node *insertafter(struct node *, int, int);
  * struct node *insertbefore(struct node *, int, int);
  * struct node *deletefirst(struct node *start);
  * struct node *deleteonly(struct node *start);
  * struct node *deletebetween(struct node *start, int value);
  * struct node *deleteatend(struct node *start);
  * struct node *reverse(struct node *start);

Note:
----
In the main.c file all the methods/functions defined in the *linkedlist.h* header file are not used. Rather only
a bunch of them are. You may play with it and modify it as you like.
