#include "bHeapKV.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int arr[25], size = 0, arrSize = 25;
/*
	bHeapKVInsertMax(arr, &size, 1);
		printf("-----\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);
	bHeapKVPrint(arr, size);
		printf("-----\n");
	bHeapKVInsertMax(arr, &size, 2);
		printf("-----\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);
	bHeapKVPrint(arr, size);
		printf("-----\n");
	bHeapKVInsertMax(arr, &size, 3);
		printf("-----\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);
	bHeapKVPrint(arr, size);
		printf("-----\n");
	bHeapKVInsertMax(arr, &size, 4);
		printf("-----\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);
	bHeapKVPrint(arr, size);
		printf("-----\n");
	bHeapKVInsertMax(arr, &size, 5);
		printf("-----\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);
	bHeapKVPrint(arr, size);
		printf("-----\n");
*/
	/* MAX HEAP TEST */
	srand(time(0));
	while (size <= arrSize) bHeapKVInsertMax(arr, &size, rand()%100);
	printf("----- Random Max Heap -----\n");
	bHeapKVPrint(arr, size);
	bHeapKVPrettyPrint(arr, size, 0, 0);

	printf("----- Removing 15 Elements... -----\n");
	while (size > 10) printf("%i ", bHeapKVExtractMax(arr, &size));
	printf("\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);

	printf("----- Removing Remaining Elements... -----\n");
	while (size > 0) printf("%i ", bHeapKVExtractMax(arr, &size));
	printf("\n");
	printf("-----\n");

	/* MIN HEAP TEST */
	while (size <= arrSize) bHeapKVInsertMin(arr, &size, rand()%100);
	printf("----- Random Min Heap -----\n");
	bHeapKVPrint(arr, size);
	bHeapKVPrettyPrint(arr, size, 0, 0);

	printf("----- Removing 15 Elements... -----\n");
	while (size > 10) printf("%i ", bHeapKVExtractMin(arr, &size));
	printf("\n");
	bHeapKVPrettyPrint(arr, size, 0, 0);

	printf("----- Removing Remaining Elements... -----\n");
	while (size > 0) printf("%i ", bHeapKVExtractMin(arr, &size));
	printf("\n");
	printf("-----\n");

	/* BUILD MAX HEAP TEST */
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Max Heap from array ");
	bHeapKVPrint(arr, size);
	bHeapKVBuildMax(arr, size);
	bHeapKVPrint(arr, size);
	bHeapKVPrettyPrint(arr, size, 0, 0);
	printf("-----\n");

	/* BUILD MIN HEAP TEST */
	size = 0;
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Min Heap from array ");
	bHeapKVPrint(arr, size);
	bHeapKVBuildMin(arr, size);
	bHeapKVPrint(arr, size);
	bHeapKVPrettyPrint(arr, size, 0, 0);
	printf("-----\n");
	printf("\n");
	return 0;
}
