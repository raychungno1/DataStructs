#ifndef BHEAP_H
#define BHEAP_H

/* helper functions */
int bHeapParent(int i);

int bHeapLeft(int i);

int bHeapRight(int i);

void bHeapSwap(int *x, int *y);

void bHeapMaxHeapify(int *arr, int size, int index);

void bHeapMinHeapify(int *arr, int size, int index);

/* build heap from input array */
void bHeapBuildMax (int *arr, int size);

void bHeapBuildMin (int *arr, int size);

/* extract methods */
int bHeapExtractMax (int *arr, int *size);

int bHeapExtractMin (int *arr, int *size);

/* insert methods */
void bHeapInsertMax (int *arr, int *size, int data);

void bHeapInsertMin (int *arr, int *size, int data);

/* prettyprints heap */
void bHeapPrettyPrint (int *arr, int size, int startIndex, int depth);

	void bHeapPrintSpaces(int *arr, int size, int startIndex, int depth);

/* prints array holding the heap */
void bHeapPrint (int *arr, int size);

#endif
