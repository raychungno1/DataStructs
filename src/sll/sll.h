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

/* reverses the order of the linked list */
void sllFlip (struct sllNode ** headPtr);

/* returns the first index of data in a linked list */
int sllIndexOf (struct sllNode **headPtr, int data);

/* returns the data in the first node of the linked list */
int sllPeekFirst (struct sllNode **headPtr);

/* returns the data in the last node of the linked list */
int sllPeekLast (struct sllNode **headPtr);

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

/* sorts the linked list in increasing order */
void sllSortMS (struct sllNode **headPtr);

	/* returns a pointer to the middle node */
	struct sllNode *sllSplit (struct sllNode *head);

	/* merges the two sorted linked list halves */
	struct sllNode *sllMerge (struct sllNode *front, struct sllNode *back);

/* sorts the linked list in increasing order */
void sllSortQS (struct sllNode **headPtr);

	/* quicksort method for linked list */
	void sllQuickSort (struct sllNode **headPtr, struct sllNode **tailPtr);

	/* finds the tail node of a linked list */
	struct sllNode *sllFindTail (struct sllNode* head);

	/* partitions the array around tail node */
	struct sllNode *partition (struct sllNode **headPtr, struct sllNode **tailPtr);

#endif
