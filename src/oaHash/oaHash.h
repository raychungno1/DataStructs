#ifndef OAHASH_H
#define OAHASH_H

struct oaHashNode {
	int key;
	int data;
	char collisionFlag;
};

struct oaHashTable {
	struct oaHashNode *arr;
	int arrSize; /* number of 'buckets' in hash table */
	int size; /* total number of elements in hash table */
};

/* clears & frees hashTable */
void oaHashClear (struct oaHashTable **hashTable);

/* returns 1 if key is in the hash table, 0 otherwise */
int oaHashContainsKey (struct oaHashTable *hashTable, int key);

/* returns 1 if value is in the hash table, 0 otherwise */
int oaHashContainsValue (struct oaHashTable *hashTable, int data);

/* initializes hash table */
struct oaHashTable *oaHashInit(int hashSize);

/* generates hashCode for int */
int oaHashHC (int key, int j);

/* inserts (key, data) into the hash table */
void oaHashInsert (struct oaHashTable *hashTable, int key, int data);

/* pretty prints hashTable */
void oaHashPrettyPrint(struct oaHashTable *hashTable);

	/* pretty prints linked list */
	void oaHashLLPrint(struct oaHashNode *head);

/* removes key from the hash table & returns its data, if exists */
int oaHashRemove (struct oaHashTable *hashTable, int key);

/* replaces data associated with key with newData, returning the original data */
int oaHashReplace (struct oaHashTable *hashTable, int key, int newData);

/* returns data mapped to key from the hash table */
int oaHashRetrieve (struct oaHashTable *hashTable, int key);

/* returns size of the hash table */
int oaHashSize (struct oaHashTable *hashTable);

#endif
