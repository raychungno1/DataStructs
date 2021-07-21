#ifndef CLL_H
#define CLL_H

struct cllNode {
	int data;
	struct cllNode *next;
	struct cllNode *prev;
};

/* adds node to front of linked list */
void cllAddFirst (struct cllNode **headPtr, int data);

/* adds node to end of linked list */
void cllAddLast (struct cllNode **headPtr, int data);

/* clears linked list */
void cllClear (struct cllNode **headPtr);

/* returns 1 if data is in linked list */
int cllContains (struct cllNode **headPtr, int data);

/* reverses the order of the linked list */
void cllFlip (struct cllNode ** headPtr);

/* returns the first index of data in a linked list */
int cllIndexOf (struct cllNode **headPtr, int data);

/* returns the data in the first node of the linked list */
int cllPeekFirst (struct cllNode **headPtr);

/* returns the data in the last node of the linked list */
int cllPeekLast (struct cllNode **headPtr);

/* prints out linked list, must provide a function pointer to a print function for the data type in the linked list */
void cllPrint (struct cllNode **headPtr);

/* removes data from the linked list */
void cllRemove (struct cllNode **headPtr, int data);

/* removes first node of linked list */
int cllRemoveFirst (struct cllNode **headPtr);

/* remove last node of linked list */
int cllRemoveLast (struct cllNode **headPtr);

/* returns size of linked lise */
int cllSize (struct cllNode **headPtr);

/* sorts the linked list in increasing order */
void cllSortMS (struct cllNode **headPtr);

	/* returns a pointer to the middle node */
	struct cllNode *cllSplit (struct cllNode *head);

	/* merges the two sorted linked list halves */
	struct cllNode *cllMerge (struct cllNode *front, struct cllNode *back);

/* sorts the linked list in increasing order */
void cllSortQS (struct cllNode **headPtr);

	/* partitions the array around tail node */
	struct cllNode *partition (struct cllNode **headPtr);

#endif
