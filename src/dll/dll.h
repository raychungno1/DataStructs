#ifndef DLL_H
#define DLL_H

struct dllNode {
	int data;
	struct dllNode *next;
	struct dllNode *prev;
};

/* adds node to front of linked list */
void dllAddFirst (struct dllNode **headPtr, int data);

/* adds node to end of linked list */
void dllAddLast (struct dllNode **headPtr, int data);

/* clears linked list */
void dllClear (struct dllNode **headPtr);

/* returns 1 if data is in linked list */
int dllContains (struct dllNode **headPtr, int data);

/* reverses the order of the linked list */
void dllFlip (struct dllNode ** headPtr);

/* returns the first index of data in a linked list */
int dllIndexOf (struct dllNode **headPtr, int data);

/* returns the data in the first node of the linked list */
int dllPeekFirst (struct dllNode **headPtr);

/* returns the data in the last node of the linked list */
int dllPeekLast (struct dllNode **headPtr);

/* prints out linked list, must provide a function pointer to a print function for the data type in the linked list */
void dllPrint (struct dllNode **headPtr);

/* removes data from the linked list */
void dllRemove (struct dllNode **headPtr, int data);

/* removes first node of linked list */
int dllRemoveFirst (struct dllNode **headPtr);

/* remove last node of linked list */
int dllRemoveLast (struct dllNode **headPtr);

/* returns size of linked lise */
int dllSize (struct dllNode **headPtr);

/* sorts the linked list in increasing order */
void dllSortMS (struct dllNode **headPtr);

	/* returns a pointer to the middle node */
	struct dllNode *dllSplit (struct dllNode *head);

	/* merges the two sorted linked list halves */
	struct dllNode *dllMerge (struct dllNode *front, struct dllNode *back);

/* sorts the linked list in increasing order */
void dllSortQS (struct dllNode **headPtr);

	/* quicksort method for linked list */
	void dllQuickSort (struct dllNode **headPtr, struct dllNode **tailPtr);

	/* finds the tail node of a linked list */
	struct dllNode *dllFindTail (struct dllNode* head);

	/* partitions the array around tail node */
	struct dllNode *partition (struct dllNode **headPtr, struct dllNode **tailPtr);

#endif
