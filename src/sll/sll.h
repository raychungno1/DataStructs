#ifndef SLL_H
#define SLL_H

struct sllNode {
	void *data;
	struct sllNode *next;
};

/* adds node to front of linked list */
void sllAddFirst (struct sllNode **headPtr, void *data, int dataSize);

/* adds node to end of linked list */
void sllAddLast (struct sllNode **headPtr, void *data, int dataSize);

/* clears linked list */
void sllClear (struct sllNode **headPtr);

/* returns 1 if data is in linked list */
int sllContains (struct sllNode **headPtr, void *data, int (*compare)(void*, void*));

/* prints out linked list, must provide a function pointer to a print function for the data type in the linked list */
void sllPrint (struct sllNode **headPtr, void (*print)(void *));

/* removes data from the linked list */
void sllRemove (struct sllNode **headPtr, void *data, int (*compare)(void*, void*));

/* removes first node of linked list */
void sllRemoveFirst (struct sllNode **headPtr, void *data, int dataSize);

/* remove last node of linked list */
void sllRemoveLast (struct sllNode **headPtr, void *data, int dataSize);

/* returns size of linked lise */
int sllSize (struct sllNode **headPtr);

#endif
