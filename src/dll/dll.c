#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

void dllAddFirst (struct dllNode **headPtr, int data) {

	/* allocate space for node */
	struct dllNode *node = malloc(sizeof(struct dllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* rearrange pointers to insert node at front */
	node->data = data;
	node->next = *headPtr;
	node->prev = NULL;
	if (*headPtr != NULL) (*headPtr)->prev = node;
	*headPtr = node;
}

void dllAddLast (struct dllNode **headPtr, int data) {

	/* allocate space for node */
	struct dllNode *node = malloc(sizeof(struct dllNode));
	struct dllNode *prev = NULL;

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* traverse to end of list */
	while (*headPtr != NULL) {
		prev = *headPtr;
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* rearrange pointers to insert node at back */
	node->data = data;
	node->next = *headPtr;
	node->prev = prev;
	*headPtr = node;
}

void dllClear (struct dllNode **headPtr) {

	/* temporary node to free memory */
	struct dllNode *temp;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		free(temp), temp = NULL; /* clear node */
	}

}

int dllContains (struct dllNode **headPtr, int data) {

	/* while the current node is not null */
	while (*headPtr != NULL) {
		if (data == (*headPtr)->data) return 1; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* return 0 if no match found */	
	return 0;
}

void dllFlip (struct dllNode **headPtr) {

	/* tracking nodes */
	struct dllNode *temp = NULL;

	/* return if list is length 0 */
	if (*headPtr == NULL) return;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = (*headPtr)->prev;
		(*headPtr)->prev = (*headPtr)->next;
		(*headPtr)->next = temp;
		*headPtr = (*headPtr)->prev;
	}

	/* set head ptr to last node */
	*headPtr = temp->prev;
}

int dllIndexOf (struct dllNode **headPtr, int data) {

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

int dllPeekFirst (struct dllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* return data of first node */
	return (*headPtr)->data;
}

int dllPeekLast (struct dllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* traverse to last node */
	while ((*headPtr)->next != NULL) headPtr = &(*headPtr)->next; /* update pointer */

	/* return data of last node */
	return (*headPtr)->data;
}

void dllPrint (struct dllNode **headPtr) {

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

void dllRemove (struct dllNode **headPtr, int data) {

	/* temporary storage to free memory */
	struct dllNode *temp;

	/* while the current node is not null or a match is not found */
	while (*headPtr != NULL && data != (*headPtr)->data) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}
	
	/* return if list is empty or match is not found */
	if (*headPtr == NULL) return;

	/* remove selected node */
	temp = *headPtr;
	*headPtr = (*headPtr)->next;

	/* set prev ptr if list length > 1 */
	if (*headPtr != NULL) (*headPtr)->prev = ((*headPtr)->prev)->prev;
	

	/* free the node */
	free(temp), temp = NULL;
}

int dllRemoveFirst (struct dllNode **headPtr) {

	int data; /* output var */
	struct dllNode *temp = *headPtr; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* shift head pointer to second node */
	data = temp->data;
	*headPtr = (*headPtr)->next;

	/* set prev ptr if list length > 1 */
	if (*headPtr != NULL) (*headPtr)->prev = ((*headPtr)->prev)->prev;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int dllRemoveLast (struct dllNode **headPtr) {

	int data; /* output var */
	struct dllNode *temp; /* temp node storage */

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

int dllSize (struct dllNode **headPtr) {

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

void dllSortMS (struct dllNode **headPtr) {

	/* initialize second linked list for back node */
	struct dllNode *back;

	/* if the list is length 0 or 1 */
	if (*headPtr == NULL || (*headPtr)->next == NULL) return;

	/* split linked list into two halves */
	back = dllSplit(*headPtr);

	/* recursively sort two halves */
	dllSortMS(headPtr);
	dllSortMS(&back);

	/* merge the two sorted halves */
	*headPtr = dllMerge(*headPtr, back);
}

struct dllNode *dllSplit (struct dllNode *head) {

	/* split will only be called on lists w/ at least two elements */
	struct dllNode *midPtr = head;
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
	head->prev = NULL;
	midPtr->next = NULL;

	/* output */
	return head;

}

struct dllNode *dllMerge (struct dllNode *front, struct dllNode *back) {

	/* initialize index node to merge list */
	struct dllNode *head, *index;

	/* dllMerge will not be called w/ empty lists */
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
			front->prev = index;
			front = front->next;
		} else {
			/* add back to list & increment back */
			index->next = back;
			back->prev = index;
			back = back->next;
		}
		index = index->next; /* increment index */
		
	}

	/* output */
	return head;
}

void dllSortQS (struct dllNode **headPtr) {

	/* get a pointer to the tail node */
	struct dllNode *tail = dllFindTail(*headPtr);

	/* calls quicksort w/ head & tail pointer */
	dllQuickSort(headPtr, &tail);
}

void dllQuickSort (struct dllNode **headPtr, struct dllNode **tailPtr) {

	/* initialize pivot node & the node before the pivot node */
	struct dllNode *pivot, *pivotPrev;

	/* if list is length 0 or 1 */
	if (*headPtr == NULL || *headPtr == *tailPtr) return;

	/* partitions list around tail node */
	pivot = partition(headPtr, tailPtr);

	/* recursive call to first half if its length > 1 */
	if (*headPtr != pivot) {
		pivotPrev = pivot->prev; /* node before the pivot */

		/* sever connection between two lists */
		pivot->prev = NULL;
		pivotPrev->next = NULL;

		dllQuickSort(headPtr, &pivotPrev); /* recursive call */

		/* reconnect two lists */
		pivot->prev = pivotPrev;
		pivotPrev->next = pivot; /* restore original list */
	}
	
	/* recursive call to second half */
	dllQuickSort(&(pivot->next), tailPtr);

}

struct dllNode *dllFindTail (struct dllNode *head) {

	/* traverse to the last node */
	while (head != NULL && head->next != NULL) head = head->next;

	/* output */
	return head;

}

struct dllNode *partition (struct dllNode **headPtr, struct dllNode **tailPtr) {

	/* storing pivot node */
	struct dllNode *pivot = *tailPtr;
	/* nodes to traverse through linked list */
	struct dllNode *curr = *headPtr, *prev = NULL;

	/* loops until tailPtr */
	while (curr != pivot) {

		/* if the node is greater than the tail data, move it to the end of the list */
		if (curr->data > pivot->data) {

			if (curr == *headPtr) {
				/* update headPtr if we're moving the head node */
				*headPtr = (*headPtr)->next;
				(*headPtr)->prev = NULL;
			} else {
				/* update prev node otherwise */
				prev->next = curr->next;
				(prev->next)->prev = prev;
			}

			/* move curr to the end & update tailPtr */
			(*tailPtr)->next = curr;
			curr->prev = *tailPtr;
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

