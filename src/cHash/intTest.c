#include "cHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hashPrint(struct cHashTable *hashTable) {
	cHashPrettyPrint(hashTable);
	printf("Size: %i\n", cHashSize(hashTable));
}

int main() {

	int i, arr[50], temp;
	/* cHashInit test */
	struct cHashTable *hashTable = cHashInit(10);
	struct cHashTable *nullTable = cHashInit(5);
	srand(time(0));

	/* cHashInsert test */
	printf("----- cHashInsert test -----\n");
	printf("Randomly inserting <= 50 elements\n");
	for (i = 0; i < 50; i++) {
		arr[i] = rand()%100;
		cHashInsert(hashTable, arr[i], i);
	}
	hashPrint(hashTable);

	/* cHashContainsKey test */
	printf("----- cHashContainsKey test -----\n");
	for(i = 0; i < 50; i+=10) {
		if (cHashContainsKey(hashTable, arr[i])) printf("  Hash Table contains key %i.\n", arr[i]);
		else printf("  Hash Table doesn't contain key %i.\n", arr[i]);
	}
	for(i = 0; i < 50; i+=10) {
		if (cHashContainsKey(nullTable, arr[i])) printf("  Null Hash Table contains key %i.\n", arr[i]);
		else printf("  Null Hash Table doesn't contain key %i.\n", arr[i]);
	}
	
	/* cHashContainsValue test */
	printf("----- cHashContainsValue test -----\n");
	for(i = 0; i < 50; i+=10) {
		if (cHashContainsValue(hashTable, i)) printf("  Hash Table contains value %i.\n", i);
		else printf("  Hash Table doesn't contain value %i.\n", i);
	}
	for(i = 0; i < 50; i+=10) {
		if (cHashContainsValue(nullTable, i)) printf("  Null Hash Table contains value %i.\n", i);
		else printf("  Null Hash Table doesn't contain value %i.\n", i);
	}

	/* cHashRetrieve test */
	printf("----- cHashRetrieve test -----\n");
	for(i = 0; i < 50; i+=10) printf("  Value associated w/ %i is %i.\n", arr[i], cHashRetrieve(hashTable, arr[i]));
	for(i = 0; i < 50; i+=10) printf("  Value associated w/ %i is %i (Null Table).\n", arr[i], cHashRetrieve(nullTable, arr[i]));
	
	/* cHashReplace test */
	printf("----- cHashReplace test -----\n");
	for(i = 0; i < 50; i+=10) {
		temp = cHashReplace(hashTable, arr[i], 50);
		printf("  Value %i replaced with %i.\n", temp, cHashRetrieve(hashTable, arr[i]));
	}
	for(i = 0; i < 50; i+=10) {
		temp = cHashReplace(nullTable, arr[i], 50);
		printf("  Value %i replaced with %i (Null Table).\n", temp, cHashRetrieve(nullTable, arr[i]));
	}
	/* cHashRemove test */
	printf("----- cHashRemove test -----\n");
	printf("Randomly removing <= 25 elements\n");
	for (i = 0; i < 25; i++) cHashRemove(hashTable, arr[2*i]);
	hashPrint(hashTable);
	printf("Removing from Null Hash Table... ");
	cHashRemove(nullTable, 12);
	printf("no error.\n");

	/* cHashClear test */
	printf("----- cHashClear test -----\n");
	cHashClear(&hashTable);
	printf("  Clearing non-null hashtable... success!\n");
	cHashClear(&hashTable);
	printf("  Clearing null hashtable... success!\n");
	cHashClear(&nullTable);
	printf("  Clearing empty hashtable... success!\n");

	printf("\n");
	return 0;
}
