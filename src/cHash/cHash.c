#include "cHash.h"
#include <stdio.h>
#include <stdlib.h>

/* clears & frees hashTable */
void cHashClear (struct cHashTable *hashTable) {
	int i;
	/* free each linked list in the array, then the array & hash table itself */
	for (i = 0; i < hashTable->arrSize; i++) cHashClearLL(hashTable->arr+i);
	free(hashTable->arr), hashTable->arr = NULL;
	free(hashTable), hashTable = NULL;
}

/* clears a linked list */
void cHashClearLL (struct cHashNode **headPtr) {

	/* temporary node to free memory */
	struct cHashNode *temp;

	/* while the current node is not null */
	while (*headPtr != NULL) {
		temp = *headPtr; /* store current node into temp */
		*headPtr = (*headPtr)->next; /* update pointer */

		free(temp), temp = NULL; /* clear node */
	}

}

/* returns 1 if key is in the hash table, 0 otherwise */
int cHashContainsKey (struct cHashTable *hashTable, int key) {

	/* gets index for the key */
	int index = cHashHC(key) % hashTable->arrSize;

	/* head node to traverse linked list */
	struct cHashNode *head = *(hashTable->arr + index);

	/* traverse until node is not found or until whole list is traversed */
	while (head && key != head->key) head = head->next;
	
	/* return 0 if list is empty or match is not found */
	if (head == NULL) return 0;
	return 1;
}

/* returns 1 if value is in the hash table, 0 otherwise */
int cHashContainsValue (struct cHashTable *hashTable, int data) {

	int i; /* index & node to traverse hashTable */
	struct cHashNode *head;

	for (i = 0; i < hashTable->arrSize; i++) {
		/* head node to traverse linked list */
		struct cHashNode *head = *(hashTable->arr + i);
	
		/* traverse until node is not found or until whole list is traversed */
		while (head && data != head->data) head = head->next;
		
		/* return 0 if list is empty or match is not found */
		if (head != NULL) return 1;
	}
	return 0;
}

/* generates hashCode for int */
int cHashHC (int key) {return key;}

/* initializes hash table */
struct cHashTable *cHashInit(int hashSize) {

	struct cHashTable *hashTable = malloc(sizeof(struct cHashTable)); /* malloc hashTable */
	
	if (hashTable) {

		/* allocating array & initialize to 0 */
		hashTable->arr = calloc(hashSize, sizeof(struct cHashNode*));

		if (hashTable->arr) {
			/* if array allocation succeeds, assign size values */
			hashTable->arrSize = hashSize;
			hashTable->size = 0;
		} else {
			/* if array allocation fails, print message & free hashTable */
			printf("Error allocating memory for hashTable array.\n");
			free(hashTable), hashTable = NULL;
		}

	} else {printf("Error allocating memory for node.\n");} /* if memory allocation fails */

	return hashTable; /* output */
}

/* inserts (key, data) into the hash table */
void cHashInsert (struct cHashTable *hashTable, int key, int data) {

	/* gets index for the key */
	int index = cHashHC(key) % hashTable->arrSize;

	struct cHashNode *node; /* new Node */

	/* if key is already in hash table */
	if (cHashContainsKey(hashTable, key)) return;

	/* generates space for new node */
	node = malloc(sizeof(struct cHashNode));

	/* if memory allocation fails */
	if (!node) {
		printf("Error allocating node memory.\n");
		return;
	}

	/* add data & rearrange pointers to insert node at front */
	node->key = key;
	node->data = data;
	node->next = *(hashTable->arr + index);
	*(hashTable->arr + index) = node;
	hashTable->size++;
}

/* pretty prints hashTable */
void cHashPrettyPrint(struct cHashTable *hashTable) {

	int i; /* iterate & print each linked list */
	for (i = 0; i < hashTable->arrSize; i++ ) {
		printf("[%i]", i);
		cHashLLPrint(*(hashTable->arr + i));
	}
}

/* pretty prints linked list */
void cHashLLPrint(struct cHashNode *head) {

	/* while the current node is not null */
	while (head) {
		printf("-(%i,%i)", head->key, head->data); /* use print func */
		head = head->next; /* update pointer */
	}
	printf("\n"); /* add newline */
}


/* removes key from the hash table & returns its data, if exists */
int cHashRemove (struct cHashTable *hashTable, int key) {

	/* gets index for the key */
	int index = cHashHC(key) % hashTable->arrSize;

	/* temporary storage to free memory */
	struct cHashNode **headPtr = (hashTable->arr + index), *temp;

	/* traverse until node is not found or until whole list is traversed */
	while (*headPtr && key != (*headPtr)->key) headPtr = &(*headPtr)->next;
	
	/* return if list is empty or match is not found */
	if (*headPtr == NULL) return 0;

	/* save value & remove selected node */
	temp = *headPtr;
	index = temp->data;
	*headPtr = (*headPtr)->next;

	/* update hashTable size */
	hashTable->size--;

	/* free the node */
	free(temp), temp = NULL;
	return index;
}

/* replaces data associated with key with newData, returning the original data */
int cHashReplace (struct cHashTable *hashTable, int key, int newData) {

	/* gets index for the key */
	int index = cHashHC(key) % hashTable->arrSize;

	/* head node to traverse linked list */
	struct cHashNode *head = *(hashTable->arr + index);

	/* traverse until node is not found or until whole list is traversed */
	while (head && key != head->key) head = head->next;
	
	/* return if list is empty or match is not found */
	if (head == NULL) return 0;

	/* swap out old value */
	index = head->data;
	head->data = newData;
	return index;
}

/* returns data mapped to key from the hash table */
int cHashRetrieve (struct cHashTable *hashTable, int key) {

	/* gets index for the key */
	int index = cHashHC(key) % hashTable->arrSize;

	/* head node to traverse linked list */
	struct cHashNode *head = *(hashTable->arr + index);

	/* traverse until node is not found or until whole list is traversed */
	while (head && key != head->key) head = head->next;
	
	/* return if list is empty or match is not found */
	if (head == NULL) return 0;

	/* swap out old value */
	return head->data;
}

/* returns size of the hash table */
int cHashSize (struct cHashTable *hashTable) {return hashTable->size;}

