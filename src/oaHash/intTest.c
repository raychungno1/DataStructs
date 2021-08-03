#include "oaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hashPrint(struct oaHashTable *hashTable) {
	oaHashPrettyPrint(hashTable);
	printf("Size: %i\n", oaHashSize(hashTable));
}

int main() {

	int i, arr[25], temp;
	/* oaHashInit test */
	struct oaHashTable *hashTable = oaHashInit(25);
	struct oaHashTable *nullTable = oaHashInit(5);
	srand(time(0));

	/* oaHashInsert test */
	printf("----- oaHashInsert test -----\n");
	printf("Randomly inserting <= 25 elements\n");
	for (i = 0; i < 25; i++) {
		arr[i] = rand()%100;
		oaHashInsert(hashTable, arr[i], i);
	}
	hashPrint(hashTable);

	/* oaHashContainsKey test */
	printf("----- oaHashContainsKey test -----\n");
	for(i = 0; i < 25; i+=10) {
		if (oaHashContainsKey(hashTable, arr[i])) printf("  Hash Table contains key %i.\n", arr[i]);
		else printf("  Hash Table doesn't contain key %i.\n", arr[i]);
	}
	if (oaHashContainsKey(hashTable, 100)) printf("  Hash Table contains key %i.\n", 100);
	else printf("  Hash Table doesn't contain key %i.\n", 100);
	for(i = 0; i < 25; i+=10) {
		if (oaHashContainsKey(nullTable, arr[i])) printf("  Null Hash Table contains key %i.\n", arr[i]);
		else printf("  Null Hash Table doesn't contain key %i.\n", arr[i]);
	}
	
	/* oaHashContainsValue test */
	printf("----- oaHashContainsValue test -----\n");
	for(i = 0; i < 25; i+=10) {
		if (oaHashContainsValue(hashTable, i)) printf("  Hash Table contains value %i.\n", i);
		else printf("  Hash Table doesn't contain value %i.\n", i);
	}
	if (oaHashContainsKey(hashTable, 100)) printf("  Hash Table contains value %i.\n", 100);
	else printf("  Hash Table doesn't contain value %i.\n", 100);
	for(i = 0; i < 25; i+=10) {
		if (oaHashContainsValue(nullTable, i)) printf("  Null Hash Table contains value %i.\n", i);
		else printf("  Null Hash Table doesn't contain value %i.\n", i);
	}

	/* oaHashRetrieve test */
	printf("----- oaHashRetrieve test -----\n");
	for(i = 0; i < 25; i+=10) printf("  Value associated w/ %i is %i.\n", arr[i], oaHashRetrieve(hashTable, arr[i]));
	for(i = 0; i < 25; i+=10) printf("  Value associated w/ %i is %i (Null Table).\n", arr[i], oaHashRetrieve(nullTable, arr[i]));
	
	/* oaHashReplace test */
	printf("----- oaHashReplace test -----\n");
	for(i = 0; i < 25; i+=10) {
		temp = oaHashReplace(hashTable, arr[i], 25);
		printf("  Value %i replaced with %i.\n", temp, oaHashRetrieve(hashTable, arr[i]));
	}
	for(i = 0; i < 25; i+=10) {
		temp = oaHashReplace(nullTable, arr[i], 25);
		printf("  Value %i replaced with %i (Null Table).\n", temp, oaHashRetrieve(nullTable, arr[i]));
	}
	/* oaHashRemove test */
	printf("----- oaHashRemove test -----\n");
	printf("Randomly removing <= 12 elements\n");
	for (i = 0; i < 12; i++) oaHashRemove(hashTable, arr[2*i]);
	oaHashRemove(hashTable, 100);
	hashPrint(hashTable);
	printf("Removing from Null Hash Table... ");
	oaHashRemove(nullTable, 12);
	printf("no error.\n");

	/* oaHashClear test */
	printf("----- oaHashClear test -----\n");
	oaHashClear(&hashTable);
	printf("  Clearing non-null hashtable... success!\n");
	oaHashClear(&hashTable);
	printf("  Clearing null hashtable... success!\n");
	oaHashClear(&nullTable);
	printf("  Clearing empty hashtable... success!\n");

	printf("\n");
	return 0;
}
