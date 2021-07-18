#ifndef SLL_H
#define SLL_H

struct sllNode {
	int data;
	struct sllNode *next;
};

/* adds node to front of linked list */
void sllAddFirst (struct sllNode **headPtr, int data);

/* adds node to end of linked list */
void sllAddLast (struct sllNode **headPtr, int data);

/* clears linked list */
void sllClear (struct sllNode **headPtr);

/* returns 1 if data is in linked list */
int sllContains (struct sllNode **headPtr, int data);

/* prints out linked list, must provide a function pointer to a print function for the data type in the linked list */
void sllPrint (struct sllNode **headPtr);

/* removes data from the linked list */
void sllRemove (struct sllNode **headPtr, int data);

/* removes first node of linked list */
int sllRemoveFirst (struct sllNode **headPtr);

/* remove last node of linked list */
int sllRemoveLast (struct sllNode **headPtr);

/* returns size of linked lise */
int sllSize (struct sllNode **headPtr);

#endif