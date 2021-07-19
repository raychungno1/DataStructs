#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void sllAddFirst (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* rearrange pointers to insert node at front */
	node->data = data;
	node->next = *headPtr;
	*headPtr = node;
}

void sllAddLast (struct sllNode **headPtr, int data) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}
	
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

void sllSort (struct sllNode **headPtr) {

	/* get a pointer to the tail node */
	struct sllNode *tail = sllFindTail(*headPtr);

	/* calls quicksort w/ head & tail pointer */
	sllQuickSort(headPtr, &tail);
}

void sllQuickSort(struct sllNode **headPtr, struct sllNode **tailPtr) {

	/* initialize pivot node */
	struct sllNode *pivot, *temp;

	/* if list is length 0 or 1 */
	if (*headPtr == NULL || *headPtr == *tailPtr) return;

	/* partitions list around tail node */
	pivot = partition(headPtr, tailPtr);

	/* recursive call to first half if its length > 1 */
	if (*headPtr != pivot) {
		temp = *headPtr; /* traverse to the node before the pivot */
		while (temp->next != pivot) temp = temp->next;

		temp->next = NULL; /* temporarily set that node to be the tail */
		sllQuickSort(headPtr, &temp); /* recursive call */
		temp->next = pivot; /* restore original list */
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

struct sllNode *partition(struct sllNode **headPtr, struct sllNode **tailPtr) {

	/* storinv pivot node */
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

