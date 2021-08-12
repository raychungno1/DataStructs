#include "bHeapKV.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int arr[25], size = 0, arrSize = 25;
	struct bHeapKV *heap = bHeapKVInit(25);
	struct bHeapKVNode *node;
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
	while (heap->size < heap->MAX_SIZE) bHeapKVInsertMax(heap, rand()%100, 1);
	printf("----- Random Max Heap -----\n");
	bHeapKVPrint(heap);
	bHeapKVPrettyPrint(heap);

	printf("----- Removing 15 Elements... -----\n");
	while (heap->size > 10) {
		node = bHeapKVExtractMax(heap);
		printf("(%i, %i) ", node->key, node->value);
		free(node), node = NULL;
	}
		
	printf("\n");
	bHeapKVPrettyPrint(heap);

	printf("----- Removing Remaining Elements... -----\n");
	while (heap->size > 0) {
		node = bHeapKVExtractMax(heap);
		printf("(%i, %i) ", node->key, node->value);
		free(node), node = NULL;
	}
	printf("\n");
	printf("-----\n");

	/* MIN HEAP TEST */
	heap = bHeapKVClear(heap);
	heap = bHeapKVInit(25);
	while (heap->size < heap->MAX_SIZE) bHeapKVInsertMin(heap, rand()%100, 1);
	printf("----- Random Min Heap -----\n");
	bHeapKVPrint(heap);
	bHeapKVPrettyPrint(heap);

	printf("----- Removing 15 Elements... -----\n");
	while (heap->size > 10) {
		node = bHeapKVExtractMin(heap);
		printf("(%i, %i) ", node->key, node->value);
		free(node), node = NULL;
	}
		
	printf("\n");
	bHeapKVPrettyPrint(heap);

	printf("----- Removing Remaining Elements... -----\n");
	while (heap->size > 0) {
		node = bHeapKVExtractMin(heap);
		printf("(%i, %i) ", node->key, node->value);
		free(node), node = NULL;
	}
	printf("\n");
	printf("-----\n");

	/* BUILD MAX HEAP TEST */
/*	heap = bHeapKVClear(heap);
	heap = bHeapKVInit(25);
	size = 0;
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Max Heap from array ");
	bHeapKVPrint(heap);
	bHeapKVBuildMax(arr, size);
	bHeapKVPrint(heap);
	bHeapKVPrettyPrint(heap);
	printf("-----\n");*/

	/* BUILD MIN HEAP TEST */
/*	heap = bHeapKVClear(heap);
	heap = bHeapKVInit(25);
	size = 0;
	while (size < 25) arr[size++] = rand()%100;
	printf("Build Min Heap from array ");
	bHeapKVPrint(heap);
	bHeapKVBuildMin(arr, size);
	bHeapKVPrint(heap);
	bHeapKVPrettyPrint(heap);
	printf("-----\n");*/

	bHeapKVClear(heap);
	printf("\n");
	return 0;
}

