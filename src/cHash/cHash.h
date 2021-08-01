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
vpod cHashClear (cHashTable *hashTable);

/* returns 1 if key is in the hash table, 0 otherwise */
int cHashContainsKey (cHashTable **hashTable, int key);

/* returns 1 if value is in the hash table, 0 otherwise */
int cHashContainsValue (cHashTable **hashTable, int data);

/* initializes hash table */
cHashTable *cHashInit(int hashSize);

/* inserts (key, data) into the hash table */
void cHashInsert (cHashTable **hashTable, int key, int data);

/* removes key from the hash table, if exists */
void cHashRemove (cHashTable **hashTable, int key);

/* replaces data associated with key with newData */
void cHashReplace (cHashTable **hashTable, int key, int newData);

/* returnd data mapped to key from the hash table */
void cHashRetrieve (cHashTable **hashTable, int key);

/* returns size of the hash table */
int cHashSize (cHashTable **hashTable);

#endif
