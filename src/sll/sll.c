#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void sllAddFirst (struct sllNode **headPtr, void *data, int dataSize) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* rearrange pointers to insert node at front */
	node->data = malloc(dataSize);
	node->next = *headPtr;
	*headPtr = node;

	/* copy data into node 1 byte at a time */
	while (--dataSize >= 0) {
		*((char *)node->data + dataSize) = *((char *)data + dataSize);
	}
}

void sllAddLast (struct sllNode **headPtr, void *data, int dataSize) {

	/* allocate space for node */
	struct sllNode *node = malloc(sizeof(struct sllNode));

	/* while the current node is not null */
	while (*headPtr != NULL) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* rearrange pointers to insert node at front */
	node->data = malloc(dataSize);
	node->next = *headPtr;
	*headPtr = node;

	/* copy data into node 1 byte at a time */
	while (--dataSize >= 0) {
		*((char *)node->data + dataSize) = *((char *)data + dataSize);
	}
}

void sllClear (struct sllNode **headPtr) {

	/* temporary node to free memory */
	struct sllNode *temp;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		/* clear(temp->data); */ /* clear data */
		free(temp->data), temp->data = NULL; /* clear data pointer */
		free(temp), temp = NULL; /* clear node */
	}

}

int sllContains (struct sllNode **headPtr, void *data, int (*compare)(void*, void*)) {

	/* while the current node is not null */
	while (*headPtr != NULL) {
		if (!compare(data, (*headPtr)->data)) return 1; /* return 1 if match found */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* return 0 if no match found */	
	return 0;
}

void sllPrint (struct sllNode **headPtr, void (*print)(void*)) {

	/* opening bracket */
	printf("{");

	/* while the current node is not null */
	while (*headPtr != NULL) {
		print((*headPtr)->data); /* use print func */
		if ((*headPtr)->next != NULL) printf(", "); /* print comma if node isn't the last node */
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* ending bracket */
	printf("}\n");	
}

void sllRemove (struct sllNode **headPtr, void *data, int (*compare)(void*, void*)) {

	/* temporary storage to free memory */
	struct sllNode *temp;

	/* while the current node is not null or a match is not found */
	while (*headPtr != NULL && compare(data, (*headPtr)->data)) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}
	
	/* return if list is empty or match is not found */
	if (*headPtr == NULL) return;

	/* remove selected node */
	temp = *headPtr;
	*headPtr = (*headPtr)->next;

	/* free the node */
	free(temp->data), temp->data = NULL;
	free(temp), temp = NULL;
}

void sllRemoveFirst (struct sllNode **headPtr, void *data, int dataSize) {

	/* temporary storage to free memory */
	struct sllNode *temp = *headPtr;

	/* return if list is empty */
	if (*headPtr == NULL) return;

	/* shift head pointer to second node */
	*headPtr = (*headPtr)->next;

	/* copy data into node 1 byte at a time */
	while (--dataSize >= 0) {
		*((char *)data + dataSize) = *((char *)temp->data + dataSize);
	}

	/* free the node */
	free(temp->data), temp->data = NULL;
	free(temp), temp = NULL;
}

void sllRemoveLast (struct sllNode **headPtr, void *data, int dataSize) {

	/* temporary storage to free memory */
	struct sllNode *temp;

	/* return if list is empty */
	if (*headPtr == NULL) return;

	/* locate second-to-last node */
	while ((*headPtr)->next != NULL) {
		headPtr = &(*headPtr)->next; /* update pointer */
	}

	/* remove last node */
	temp = *headPtr;
	*headPtr = NULL;

	/* copy data into node 1 byte at a time */
	while (--dataSize >= 0) {
		*((char *)data + dataSize) = *((char *)temp->data + dataSize);
	}

	/* free the node */
	free(temp->data), temp->data = NULL;
	free(temp), temp = NULL;
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

