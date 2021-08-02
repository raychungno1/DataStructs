#ifndef BHEAP_H
#define BHEAP_H

struct cHashNode {
	int key;
	int data;
	struct cHashNode *next;
};

struct cHashTable {
	struct cHashNode **arr;
	int arrSize; /* number of 'buckets' in hash table */
	int size; /* total number of elements in hash table */
};

/* clears & frees hashTable */
void cHashClear (struct cHashTable **hashTable);

	/* clears a linked list */
	void cHashClearLL (struct cHashNode **headPtr);

/* returns 1 if key is in the hash table, 0 otherwise */
int cHashContainsKey (struct cHashTable *hashTable, int key);

/* returns 1 if value is in the hash table, 0 otherwise */
int cHashContainsValue (struct cHashTable *hashTable, int data);

/* initializes hash table */
struct cHashTable *cHashInit(int hashSize);

/* generates hashCode for int */
int cHashHC (int key);

/* inserts (key, data) into the hash table */
void cHashInsert (struct cHashTable *hashTable, int key, int data);

/* pretty prints hashTable */
void cHashPrettyPrint(struct cHashTable *hashTable);

	/* pretty prints linked list */
	void cHashLLPrint(struct cHashNode *head);

/* removes key from the hash table & returns its data, if exists */
int cHashRemove (struct cHashTable *hashTable, int key);

/* replaces data associated with key with newData, returning the original data */
int cHashReplace (struct cHashTable *hashTable, int key, int newData);

/* returns data mapped to key from the hash table */
int cHashRetrieve (struct cHashTable *hashTable, int key);

/* returns size of the hash table */
int cHashSize (struct cHashTable *hashTable);

#endif
