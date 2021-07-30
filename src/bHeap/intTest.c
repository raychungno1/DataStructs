#include "bHeap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int arr[25], size = 0, arrSize = 25;
/*
	bHeapInsertMax(arr, &size, 1);
		printf("-----\n");
	bHeapPrettyPrint(arr, size, 0, 0);
	bHeapPrint(arr, size);
		printf("-----\n");
	bHeapInsertMax(arr, &size, 2);
		printf("-----\n");
	bHeapPrettyPrint(arr, size, 0, 0);
	bHeapPrint(arr, size);
		printf("-----\n");
	bHeapInsertMax(arr, &size, 3);
		printf("-----\n");
	bHeapPrettyPrint(arr, size, 0, 0);
	bHeapPrint(arr, size);
		printf("-----\n");
	bHeapInsertMax(arr, &size, 4);
		printf("-----\n");
	bHeapPrettyPrint(arr, size, 0, 0);
	bHeapPrint(arr, size);
		printf("-----\n");
	bHeapInsertMax(arr, &size, 5);
		printf("-----\n");
	bHeapPrettyPrint(arr, size, 0, 0);
	bHeapPrint(arr, size);
		printf("-----\n");
*/
	/* MAX HEAP TEST */
	srand(time(0));
	while (size <= arrSize) bHeapInsertMax(arr, &size, rand()%100);
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
	printf("-----\n");

	/* MIN HEAP TEST */
	while (size <= arrSize) bHeapInsertMin(arr, &size, rand()%100);
	printf("----- Random Min Heap -----\n");
	bHeapPrint(arr, size);
	bHeapPrettyPrint(arr, size, 0, 0);

	printf("----- Removing 15 Elements... -----\n");
	while (size > 10) printf("%i ", bHeapExtractMin(arr, &size));
	printf("\n");
	bHeapPrettyPrint(arr, size, 0, 0);

	printf("----- Removing Remaining Elements... -----\n");
	while (size > 0) printf("%i ", bHeapExtractMin(arr, &size));
	printf("\n");
	printf("-----\n");

	/* BUILD MAX HEAP TEST */
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Max Heap from array ");
	bHeapPrint(arr, size);
	bHeapBuildMax(arr, size);
	bHeapPrint(arr, size);
	bHeapPrettyPrint(arr, size, 0, 0);
	printf("-----\n");

	/* BUILD MIN HEAP TEST */
	size = 0;
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Min Heap from array ");
	bHeapPrint(arr, size);
	bHeapBuildMin(arr, size);
	bHeapPrint(arr, size);
	bHeapPrettyPrint(arr, size, 0, 0);
	printf("-----\n");
	printf("\n");
	return 0;
}
