#include "cHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int i, arr[50];
	struct cHashTable *hashTable = cHashInit(10);
	srand(time(0));
	/* insert test */
	printf("----- Randomly inserting 50 elements -----\n");
	for (i = 0; i < 50; i++) {
		arr[i] = rand()%100;
		cHashInsert(hashTable, arr[i], 0);
	}
	cHashPrettyPrint(hashTable);
	printf("----- Randomly removing 25 elements -----\n");
	for (i = 0; i < 25; i++) {
		cHashRemove(hashTable, arr[2*i]);
	}
	cHashPrettyPrint(hashTable);
	cHashClear(hashTable);

	/* MAX HEAP TEST */
/*	while (size <= arrSize) bHeapInsertMax(arr, &size, rand()%100);
	printf("----- Random Max Heap -----\n");
	bHeapPrint(arr, size);
	bHeapPrettyPrint(arr, size, 0, 0);

	printf("----- Removing 15 Elements... -----\n");
	while (size > 10) printf("%i ", bHeapExtractMax(arr, &size));
	printf("\n");
	bHeapPrettyPrint(arr, size, 0, 0);

	printf("----- Removing Remaining Elements... -----\n");
	while (size > 0) printf("%i ", bHeapExtractMax(arr, &size));
	printf("\n");
	printf("-----\n");*/

	printf("\n");
	return 0;
}
