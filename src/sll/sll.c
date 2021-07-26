#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void sllAddFirst (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) printf("Error allocating node memory"), return;

	/* rearrange pointers to insert node at front */
	node->data = data;
	node->next = *headPtr;
	*headPtr = node;
}

void sllAddLast (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) printf("Error allocating node memory"), return;
	
	/* traverse to end of list */
	while (*headPtr != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* rearrange pointers to insert node at back */
	node->data = data;
	node->next = *headPtr;
	*headPtr = node;
}

void sllClear (struct sllNode **headPtr) {

	/* temporary node to free memory */
	struct sllNode *temp;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		free(temp), temp = NULL; /* clear node */
	}

}

int sllContains (struct sllNode **headPtr, int data) {

	/* while the current node is not null */
	while (*headPtr != NULL) {
		if (data == (*headPtr)->data) return 1; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* return 0 if no match found */	
	return 0;
}

void sllFlip (struct sllNode **headPtr) {

	/* tracking nodes */
	struct sllNode *prev = NULL;
	struct sllNode *next = NULL;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		next = (*headPtr)->next; /* update next node */
		(*headPtr)->next = prev; /* assign node.next to prev */
		prev = *headPtr; /* update prev node */
		*headPtr = next; /* update current node */
	}

	/* set head ptr to last node */
	*headPtr = prev;
}

int sllIndexOf (struct sllNode **headPtr, int data) {

	/* output variable */
	int index = 0;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		if (data == (*headPtr)->data) return index; /* return index if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
		index++; /* increment index */
	}

	/* return 0 if no match found */	
	return -1;
}

int sllPeekFirst (struct sllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* return data of first node */
	return (*headPtr)->data;
}

int sllPeekLast (struct sllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* traverse to last node */
	while ((*headPtr)->next != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* return data of last node */
	return (*headPtr)->data;
}

void sllPrint (struct sllNode **headPtr) {

	/* opening bracket */
	printf("{");

	/* while the current node is not null */
	while (*headPtr != NULL) {
		printf("%i", (*headPtr)->data); /* use print func */
		if ((*headPtr)->next != NULL) printf(", "); /* print comma if node isn't the last node */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* ending bracket */
	printf("}\n");	
}

void sllRemove (struct sllNode **headPtr, int data) {

	/* temporary storage to free memory */
	struct sllNode *temp;

	/* while the current node is not null or a match is not found */
	while (*headPtr != NULL && data != (*headPtr)->data) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}
	
	/* return if list is empty or match is not found */
	if (*headPtr == NULL) return;

	/* remove selected node */
	temp = *headPtr;
	*headPtr = (*headPtr)->next;

	/* free the node */
	free(temp), temp = NULL;
}

int sllRemoveFirst (struct sllNode **headPtr) {

	int data; /* output var */
	struct sllNode *temp = *headPtr; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* shift head pointer to second node */
	data = temp->data;
	*headPtr = (*headPtr)->next;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int sllRemoveLast (struct sllNode **headPtr) {

	int data; /* output var */
	struct sllNode *temp; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* traverse to end of list */
	while ((*headPtr)->next != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* remove last node */
	temp = *headPtr;
	data = temp->data;
	*headPtr = NULL;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int sllSize (struct sllNode **headPtr) {

	/* initialize output */
	int size = 0;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		size++; /* update size & pointer */
		headPtr = &(*headPtr)->next;
	}

	/* output */
	return size;
}

void sllSortMS (struct sllNode **headPtr) {

	/* initialize second linked list for back node */
	struct sllNode *back;

	/* if the list is length 0 or 1 */
	if (*headPtr == NULL || (*headPtr)->next == NULL) return;

	/* split linked list into two halves */
	back = sllSplit(*headPtr);

	/* recursively sort two halves */
	sllSortMS(headPtr);
	sllSortMS(&back);

	/* merge the two sorted halves */
	*headPtr = sllMerge(*headPtr, back);
}

struct sllNode *sllSplit (struct sllNode *head) {

	/* split will only be called on lists w/ at least two elements */
	struct sllNode *midPtr = head;
	head = head->next;

	/* traverse to end of list */
	while (head != NULL) {
		/* increment head twice while incrementing midPtr once */
		head = head->next;
		if (head != NULL) {
			midPtr = midPtr->next;
			head = head->next;
		}
	}

	/*-----		a -> b -> c -> d -> e			----- */
	/*-----                   ^ midPtr now points here	----- */

	/* store beginning of second half */
	head = midPtr->next;

	/* sever connection between who linked lists */
	midPtr->next = NULL;

	/* output */
	return head;

}

struct sllNode *sllMerge (struct sllNode *front, struct sllNode *back) {

	/* initialize index node to merge list */
	struct sllNode *head, *index;

	/* sllMerge will not be called w/ empty lists */
	if (front->data < back ->data) {
		head = front; /* set first node be first node */
		front = front->next;
	} else {
		head = back; /* set back node to be first node */
		back = back->next;
	}
	index = head;

	/* loop until both lists are empty */
	while (front != NULL || back != NULL) {
		/* if front data is smaller */
		if (back == NULL || (front != NULL && (front->data < back->data))) {
			/* add front to list & increment front */
			index->next = front;
			front = front->next;
		} else {
			/* add back to list & increment back */
			index->next = back;
			back = back->next;
		}
		index = index->next; /* increment index */
	}

	/* output */
	return head;
}

void sllSortQS (struct sllNode **headPtr) {

	/* get a pointer to the tail node */
	struct sllNode *tail = sllFindTail(*headPtr);

	/* calls quicksort w/ head & tail pointer */
	sllQuickSort(headPtr, &tail);
}

void sllQuickSort (struct sllNode **headPtr, struct sllNode **tailPtr) {

	/* initialize pivot node & the node before the pivot node */
	struct sllNode *pivot, *pivotPrev;

	/* if list is length 0 or 1 */
	if (*headPtr == NULL || *headPtr == *tailPtr) return;

	/* partitions list around tail node */
	pivot = partition(headPtr, tailPtr);

	/* recursive call to first half if its length > 1 */
	if (*headPtr != pivot) {
		pivotPrev = *headPtr; /* traverse to the node before the pivot */
		while (pivotPrev->next != pivot) pivotPrev = pivotPrev->next;

		pivotPrev->next = NULL; /* temporarily set that node to be the tail */
		sllQuickSort(headPtr, &pivotPrev); /* recursive call */
		pivotPrev->next = pivot; /* restore original list */
	}
	
	/* recursive call to second half */
	sllQuickSort(&(pivot->next), tailPtr);

}

struct sllNode *sllFindTail (struct sllNode *head) {

	/* traverse to the last node */
	while (head != NULL && head->next != NULL) head = head->next;

	/* output */
	return head;

}

struct sllNode *partition (struct sllNode **headPtr, struct sllNode **tailPtr) {

	/* storing pivot node */
	struct sllNode *pivot = *tailPtr;
	/* nodes to traverse through linked list */
	struct sllNode *curr = *headPtr, *prev = NULL;

	/* loops until tailPtr */
	while (curr != pivot) {

		/* if the node is greater than the tail data, move it to the end of the list */
		if (curr->data > pivot->data) {

			if (curr == *headPtr) {
				/* update headPtr if we're moving the head node */
				*headPtr = (*headPtr)->next;
			} else {
				/* update prev node otherwise */
				prev->next = curr->next;
			}

			/* move curr to the end & update tailPtr */
			(*tailPtr)->next = curr;
			*tailPtr = curr;

			/* update curr & set tail->next to null */
			curr = curr->next;
			(*tailPtr)->next = NULL;

		/* if node is less than or equal, continue traversing through the list */
		} else {
			prev = curr;
			curr = curr->next;
		}
	}

	/* output */
	return pivot;
}

