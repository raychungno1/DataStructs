#include <stdlib.h>
#include <stdio.h>
#include "cll.h"

void cllAddFirst (struct cllNode **headPtr, int data) {

	/* allocate space for node */
	struct cllNode *node = malloc(sizeof(struct cllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* rearrange pointers to insert node at front */
	node->data = data;

	if (*headPtr == NULL) {
		/* if list is length 0 */
		node->next = node;
		node->prev = node;
	} else {
		/* otherwise */
		node->next = *headPtr;
		node->prev = (*headPtr)->prev;
		((*headPtr)->prev)->next = node;
		(*headPtr)->prev = node;
	}
	/* sets new head ptr */
	*headPtr = node;
}

void cllAddLast (struct cllNode **headPtr, int data) {

	/* allocate space for node */
	struct cllNode *node = malloc(sizeof(struct cllNode));

	/* if memory allocation fails */
	if (node == NULL) {
		printf("Error allocating node memory");
		return;
	}

	/* rearrange pointers to insert node at back */
	node->data = data;

	if (*headPtr == NULL) {
		/* if list is length 0 */
		node->next = node;
		node->prev = node;
		*headPtr = node;
	} else {
		/* otherwise */
		node->next = *headPtr;
		node->prev = (*headPtr)->prev;
		((*headPtr)->prev)->next = node;
		(*headPtr)->prev = node;
	}
}

void cllClear (struct cllNode **headPtr) {

	/* temporary node to free memory */
	struct cllNode *temp;

	/* exit if length is 0 */
	if (*headPtr == NULL) return;

	/* disconnect the last node from the head node */
	((*headPtr)->prev)->next = NULL;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		free(temp), temp = NULL; /* clear node */
	}

}

int cllContains (struct cllNode **headPtr, int data) {

	/* store head node */
	struct cllNode *head = *headPtr;

	/* exit if length is 0 */
	if (*headPtr == NULL) return 0;

	/* while the current node is not null */
	do {
		if (data == (*headPtr)->data) return 1; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
	} while (*headPtr != head);

	/* return 0 if no match found */	
	return 0;
}

void cllFlip (struct cllNode **headPtr) {

	/* store head & tracking node */
	struct cllNode *head = *headPtr, *temp = NULL;

	/* return if list is length 0 */
	if (*headPtr == NULL) return;

	/* while the current node is not null */
	do {
		temp = (*headPtr)->prev;
		(*headPtr)->prev = (*headPtr)->next;
		(*headPtr)->next = temp;
		*headPtr = (*headPtr)->prev;
	} while (*headPtr != head);

	/* set head ptr to last node */
	*headPtr = temp->prev;
}

int cllIndexOf (struct cllNode **headPtr, int data) {

	/* output variable */
	int index = 0;
	/* store head node */
	struct cllNode *head = *headPtr;

	/* exit if length is 0 */
	if (*headPtr == NULL) return 0;

	/* while the current node is not null */
	do {
		if (data == (*headPtr)->data) return index; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
		index++;
	} while (*headPtr != head);

	/* return -1 if no match found */	
	return -1;
}

int cllPeekFirst (struct cllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* return data of first node */
	return (*headPtr)->data;
}

int cllPeekLast (struct cllNode **headPtr) {

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* return data of last node */
	return ((*headPtr)->prev)->data;
}

void cllPrint (struct cllNode **headPtr) {

	/* save tail node */
	struct cllNode *head = *headPtr;

	/* opening bracket */
	printf("{");

	/* exit if length 0*/
	if (*headPtr != NULL) {
		/* while the current node is not null */
		do {
			printf("%i", (*headPtr)->data); /* use print func */
			if ((*headPtr)->next != head) printf(", "); /* print comma if node isn't the last node */
			headPtr = &(*headPtr)->next; /* update pointer */
		} while (*headPtr != head);
	}

	/* ending bracket */
	printf("}\n");	
}

void cllRemove (struct cllNode **headPtr, int data) {

	/* store head node & temporary storage */
	struct cllNode *temp = *headPtr;

	/* return if list is length 0 */
	if (*headPtr == NULL) return;

	while ((*headPtr)->next != temp && data != (*headPtr)->data) headPtr = &(*headPtr)->next;

	/* returns if data was not found */
	if (data != (*headPtr)->data) return;

	/* save selected node */
	temp = *headPtr;

	/* if list is of length 1 */
	if ((*headPtr)->next == *headPtr && (*headPtr)->prev == *headPtr) {
		*headPtr = NULL;
	} else {
		/* rearrange pointers over temp node */
		*headPtr = (*headPtr)->next;
		(*headPtr)->prev = ((*headPtr)->prev)->prev;
		((*headPtr)->prev)->next = *headPtr; /* ensures that last node points to the first */
	}					     /* required when removing first node of the list */

	/* free the node */
	free(temp), temp = NULL;
}

int cllRemoveFirst (struct cllNode **headPtr) {

	int data; /* output var */
	struct cllNode *temp = *headPtr; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* if list is of length 1 */
	if ((*headPtr)->next == *headPtr) {
		*headPtr = NULL;
	} else {
		/* rearrange pointers over temp node */
		*headPtr = (*headPtr)->next;
		(temp->prev)->next = *headPtr;
		(*headPtr)->prev = temp->prev;
	}

	/* save data for output */
	data = temp->data;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int cllRemoveLast (struct cllNode **headPtr) {

	int data; /* output var */
	struct cllNode *temp; /* temp node storage */

	/* return if list is empty */
	if (*headPtr == NULL) return 0;

	/* if list is of length 1 */
	if ((*headPtr)->next == *headPtr) {
		*headPtr = NULL;
	} else {
		/* rearrange pointers over temp node */
		temp = (*headPtr)->prev;
		(temp->prev)->next = *headPtr;
		(*headPtr)->prev = temp->prev;
	}

	/* save data for output */
	data = temp->data;

	/* free the node */
	free(temp), temp = NULL;

	/* output */
	return data;
}

int cllSize (struct cllNode **headPtr) {

	/* initialize output */
	int size = 0;
	struct cllNode *head = *headPtr;

	/* exit if length 0*/
	if (*headPtr == NULL) return size;

	/* while the current node is not null */
	do {
		size++; /* update size & pointer */
		headPtr = &(*headPtr)->next;
	} while (*headPtr != head);

	/* output */
	return size;
}

void cllSortMS (struct cllNode **headPtr) {

	/* initialize second linked list for back node */
	struct cllNode *back;

	/* if the list is length 0 or 1 */
	if (*headPtr == NULL || (*headPtr)->next == *headPtr) return;

	/* split linked list into two halves */
	back = cllSplit(*headPtr);

	/* recursively sort two halves */
	cllSortMS(headPtr);
	cllSortMS(&back);

	/* merge the two sorted halves */
	*headPtr = cllMerge(*headPtr, back);
}

struct cllNode *cllSplit (struct cllNode *head) {

	/* split will only be called on lists w/ at least two elements */
	struct cllNode *midPtr = head, *fast = head->next;

	/* traverse to end of list */
	while (fast != head) {
		/* increment head twice while incrementing midPtr once */
		fast = fast->next;
		if (fast != head) {
			midPtr = midPtr->next;
			fast = fast->next;
		}
	}

	/*-----		a -> b -> c -> d -> e			----- */
	/*-----                   ^ midPtr now points here	----- */

	/* start of second list */
	fast = midPtr->next;

	/* connect second half into a loop */
	(head->prev)->next = fast;
	fast->prev = head->prev;

	/* connect first half into a loop */
	midPtr->next = head;
	head->prev = midPtr;

	/* output */
	return fast;

}

struct cllNode *cllMerge (struct cllNode *front, struct cllNode *back) {

	/* initialize index node to merge list */
	struct cllNode *head, *index;

	/* break the cyclic connection between had & tail nodes */
	(front->prev)->next = NULL;
	(back->prev)->next = NULL;

	/* cllMerge will not be called w/ empty lists */
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

	/* complete the cycle of the merged list */
	head->prev = index;
	index->next = head;

	/* output */
	return head;
}

void cllSortQS (struct cllNode **headPtr) {

	/* initialize pivot node & the node before the pivot node */
	struct cllNode *pivot, *tail;

	/* if list is length 0 or 1 */
	if (*headPtr == NULL || (*headPtr)->next == *headPtr) return;

	/* partitions list around tail node */
	pivot = partition(headPtr);

	/* recursive call to first half if its length > 1 */
	if (*headPtr != pivot) {
		tail = (*headPtr)->prev;
	
		/* connect first half into a loop */
		(pivot->prev)->next = *headPtr;
		(*headPtr)->prev = pivot->prev;

		cllSortQS(headPtr); /* recursive call */

		/* restore list  */
		pivot->prev = (*headPtr)->prev;
		(pivot->prev)->next = pivot;
		tail->next = (*headPtr);
		(*headPtr)->prev = tail; 
	}

	/* recursive call to second half is pivot isnt last node */
	if ((*headPtr)->prev != pivot) {
		/* connect second half into a loop */
		((*headPtr)->prev)->next = pivot->next;
		(pivot->next)->prev = (*headPtr)->prev;
	
		/* recursive call to second half */
		cllSortQS(&(pivot->next));
	
		/* restore list */
		(*headPtr)->prev = (pivot->next)->prev;
		((*headPtr)->prev)->next = *headPtr;
		(pivot->next)->prev = pivot;
	}
}

struct cllNode *partition (struct cllNode **headPtr) {

	/* storing pivot node */
	struct cllNode *pivot = (*headPtr)->prev;
	/* nodes to traverse through linked list */
	struct cllNode *curr = *headPtr, *prev = NULL;

	/* loops until tailPtr */
	while (curr != pivot) {

		/* if the node is greater than the tail data, move it to the end of the list */
		if (curr->data > pivot->data) {

			if (curr == *headPtr) {
				/* update headPtr if we're moving the head node */
				*headPtr = (*headPtr)->next;
			} else {
				/* remove curr from the linked list */
				prev->next = curr->next;
				(prev->next)->prev = prev;

				/* move curr to the end */
				((*headPtr)->prev)->next = curr;
				curr->prev = (*headPtr)->prev;
				(*headPtr)->prev = curr;
			}

			/* update curr node & point tail to head */
			curr = curr->next;
			((*headPtr)->prev)->next = *headPtr;

		/* if node is less than or equal, continue traversing through the list */
		} else {
			prev = curr;
			curr = curr->next;
		}
	}

	/* output */
	return pivot;
}

