#include "oaHash.h"
#include <stdio.h>
#include <stdlib.h>

/* clears & frees hashTable */
void oaHashClear (struct oaHashTable **hashTable) {
	int i;

	/* return if hashTable is NULL */
	if (!*hashTable) return;

	/* free array of nodes */
	free((*hashTable)->arr), (*hashTable)->arr = NULL;
	free(*hashTable), *hashTable = NULL;
}

/* returns 1 if key is in the hash table, 0 otherwise */
int oaHashContainsKey (struct oaHashTable *hashTable, int key) {

	/* vars to get key index */
	int j = 0, index;
	struct oaHashNode *node;

	/* return if hashtable is empty */
	if (hashTable->size == 0) return 0;

	do { /* repeat until item has been found */
		index = oaHashHC(key, j) % hashTable->arrSize; /* calculate index */
		node = (hashTable->arr + index);
	
		/* if index exists & key matches, remove it */
		if (node->collisionFlag == 1 && node->key == key) return 1;
		j++;
	} while (j != hashTable->arrSize);
	return 0;
}

/* returns 1 if value is in the hash table, 0 otherwise */
int oaHashContainsValue (struct oaHashTable *hashTable, int data) {

	int i; /* index */

	for (i = 0; i < hashTable->arrSize; i++) {
		/* return 1 if key is found */
		if ((hashTable->arr + i)->collisionFlag == 1 && (hashTable->arr + i)->data == data) return 1;
	}
	return 0;
}

/* generates hashCode for int */
int oaHashHC (int key, int j) {return key + j;}

/* initializes hash table */
struct oaHashTable *oaHashInit(int hashSize) {

	struct oaHashTable *hashTable = malloc(sizeof(struct oaHashTable)); /* malloc hashTable */
	
	if (hashTable) {

		/* allocating array & initialize to 0 */
		hashTable->arr = calloc(hashSize, sizeof(struct oaHashNode));

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
void oaHashInsert (struct oaHashTable *hashTable, int key, int data) {

	/* vars to get key index */
	int j = 0, index;
	struct oaHashNode *node;

	do { /* repeat until hashtable has overflowed */
		index = oaHashHC(key, j) % hashTable->arrSize; /* calculate index */
		node = (hashTable->arr + index);

		/* if an empty spot appears at the index */
		if (node->collisionFlag == 0) {
			node->key = key;
			node->data = data;
			node->collisionFlag = 1;
			hashTable->size++;
			return;
		/* if the same key is found */
		} else if (node->key == key) {
			printf("Key %i already exists.\n", key);
			return;
		/* otherwise, a collision has occurred*/
		} else {
			j++;
		}
	} while (j != hashTable->arrSize);
	printf("Hash Table Overflow.\n");
}

/* pretty prints hashTable */
void oaHashPrettyPrint(struct oaHashTable *hashTable) {

	int i; /* iterate & print each linked list */
	for (i = 0; i < hashTable->arrSize; i++ ) {
		printf("[%i]", i);
		if ((hashTable->arr+i)->collisionFlag == 1) printf("-(%i, %i)", (hashTable->arr+i)->key, (hashTable->arr+i)->data);
		printf("\n");
	}
}

/* removes key from the hash table & returns its data, if exists */
int oaHashRemove (struct oaHashTable *hashTable, int key) {

	/* vars to get key index */
	int j = 0, index;
	struct oaHashNode *node;

	/* return if hashtable is empty */
	if (hashTable->size == 0) return 0;

	do { /* repeat until item has been found */
		index = oaHashHC(key, j) % hashTable->arrSize; /* calculate index */
		node = (hashTable->arr + index);
	
		/* if index exists & key matches, remove it */
		if (node->collisionFlag == 1 && node->key == key) {
			node->collisionFlag = 0;
			hashTable->size--;
			return node->data;
		}
		j++;
	} while (j != hashTable->arrSize);
	
	/* if value is not found */
	printf("Key %i does not exist.\n", key);
	return 0;
}

/* replaces data associated with key with newData, returning the original data */
int oaHashReplace (struct oaHashTable *hashTable, int key, int newData) {

	/* vars to get key index */
	int j = 0, index;
	struct oaHashNode *node;

	/* return if hashtable is empty */
	if (hashTable->size == 0) return 0;

	do { /* repeat until item has been found */
		index = oaHashHC(key, j) % hashTable->arrSize; /* calculate index */
		node = (hashTable->arr + index);
	
		/* if index exists & key matches, replace its value & return the old one */
		if (node->collisionFlag == 1 && node->key == key) {
			index = node->data;
			node->data = newData;
			return index;
		}
		j++;
	} while (j != hashTable->arrSize);
	
	/* if value is not found */
	return 0;
}

/* returns data mapped to key from the hash table */
int oaHashRetrieve (struct oaHashTable *hashTable, int key) {

	/* vars to get key index */
	int j = 0, index;
	struct oaHashNode *node;

	/* return if hashtable is empty */
	if (hashTable->size == 0) return 0;

	do { /* repeat until item has been found */
		index = oaHashHC(key, j) % hashTable->arrSize; /* calculate index */
		node = (hashTable->arr + index);
	
		/* if index exists & key matches, return its value */
		if (node->collisionFlag == 1 && node->key == key) return node->data;
		j++;
	} while (j != hashTable->arrSize);
	
	/* if value is not found */
	return 0;
}

/* returns size of the hash table */
int oaHashSize (struct oaHashTable *hashTable) {return hashTable->size;}

