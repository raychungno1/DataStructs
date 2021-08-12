#include "bHeap.h"
#include <stdio.h>
#include <stdlib.h>

int bHeapParent(int i) {
	return (i-1)/2;
}

int bHeapLeft(int i) {
	return (2*i)+1;
}

int bHeapRight(int i) {
	return (2*i)+2;
}

void bHeapSwap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void bHeapMaxHeapify(int *arr, int size, int i) {

	int largest, done = 0;

	do {
		/* find max between root, left, & right child */
		largest = i;
		if (bHeapLeft(i) <= size && arr[bHeapLeft(i)] > arr[largest]) largest = bHeapLeft(i);
		if (bHeapRight(i) <= size && arr[bHeapRight(i)] > arr[largest]) largest = bHeapRight(i);

		/* swap if root is not the largest */
		if (i != largest) bHeapSwap(arr+i, arr+largest); 
		else done = 1; /* exit otherwise */

		i = largest; /* repeat w/ child node */
	} while (!done);
}

void bHeapMinHeapify(int *arr, int size, int i) {

	int smallest, done = 0;

	do {
		/* find max between root, left, & right child */
		smallest = i;
		if (bHeapLeft(i) <= size && arr[bHeapLeft(i)] < arr[smallest]) smallest = bHeapLeft(i);
		if (bHeapRight(i) <= size && arr[bHeapRight(i)] < arr[smallest]) smallest = bHeapRight(i);

		/* swap if root is not the largest */
		if (i != smallest) bHeapSwap(arr+i, arr+smallest); 
		else done = 1; /* exit otherwise */

		i = smallest; /* repeat w/ child node */
	} while (!done);
}

/* build heap from input array */
void bHeapBuildMax (int *arr, int size) {
	int index = (size/2)-1; /* heapify each non leaf node in reverse order */
	while (index >= 0) bHeapMaxHeapify(arr, size, index--);
}

void bHeapBuildMin (int *arr, int size) {
	int index = (size/2)-1; /* heapify each non leaf node in reverse order */
	while (index >= 0) bHeapMinHeapify(arr, size, index--);
}

/* extract methods */
int bHeapExtractMax (int *arr, int *size) {

	int max; /* max var */

	if (*size < 1) return 0; /* return if heap is empty */

	max = arr[0]; /* save max value */
	arr[0] = arr[*size-1]; /* copy last array value over */
	(*size)--; /* decrement size */

	bHeapMaxHeapify(arr, *size, 0); /* sift the copied value down */

	return max; /* output */
}

int bHeapExtractMin (int *arr, int *size) {

	int min; /* max var */

	if (*size < 1) return 0; /* return if heap is empty */

	min = arr[0]; /* save max value */
	arr[0] = arr[*size-1]; /* copy last array value over */
	(*size)--; /* decrement size */

	bHeapMinHeapify(arr, *size, 0); /* sift the copied value down */

	return min; /* output */
}

/* insert methods */
void bHeapInsertMax (int *arr, int *size, int data) {

	int i = *size; /* index of initial insert */	

	arr[i] = data; /* adding data at end of array */
	
	/* while node value is greater than parent value */
	while (i > 0 && arr[bHeapParent(i)] < arr[i]) {
		bHeapSwap(arr+i, arr+bHeapParent(i)); /* swap node w/ parent */
		i = bHeapParent(i); /* update i to its parent */
	}
	(*size)++; /* increment heap size */
}

void bHeapInsertMin (int *arr, int *size, int data) {

	int i = *size; /* index of initial insert */	

	arr[i] = data; /* adding data at end of array */
	
	/* while node value is less than parent value */
	while (i > 0 && arr[bHeapParent(i)] > arr[i]) {
		bHeapSwap(arr+i, arr+bHeapParent(i)); /* swap node w/ parent */
		i = bHeapParent(i); /* update i to its parent */
	}
	(*size)++; /* increment heap size */
}

/* prettyprints tree with an in order traversal */
void bHeapPrettyPrint (int *arr, int size, int startIndex, int depth) {

	int i = startIndex;

	/* return if empty tree */
	if (size == 0) return;

	if (bHeapLeft(i) < size) bHeapPrettyPrint(arr, size, bHeapLeft(i), depth + 1);

	bHeapPrintSpaces(i, depth);
	if (i != 0) {
		if (bHeapLeft(bHeapParent(i)) == i) {
			printf(",-");
		} else {
			printf("`-");
		}
		printf("[%i]\n", arr[i]);
	} else {
		printf("-[%i]\n", arr[i]);
	}

	if (bHeapRight(i) < size) bHeapPrettyPrint(arr, size, bHeapRight(i), depth + 1);

}

void bHeapPrintSpaces(int startIndex, int depth) {

	int l = 3*depth; /* length parameter */
	int lStreak = 1; /* represents a streak of left nodes */
	int rStreak = 1; /* represents a streak of right nodes */
	int i = startIndex;

	/* malloc padding for indenting */
	char *str = malloc(l*sizeof(char) + 1);

	/* if memory allocation fails */
	if (str == NULL) return;

	/* Add null terminator */
	str[l--] = '\0';

	/* until the padding string fills up */	
	while (l > 0) {

		/* if parsing a left child w/ a left streak or a right child w/ a right streak */
		if ((bHeapLeft(bHeapParent(i)) == i && lStreak) ||
		    (bHeapRight(bHeapParent(i)) == i && rStreak)) {
			str[l--] = ' '; /* print space */
		} else {
			str[l--] = '|'; /* print '|' */
		}

		/* updating streaks */
		if (bHeapLeft(bHeapParent(i)) == i) {
			lStreak = 1, rStreak = 0;
		} else {
			lStreak = 0, rStreak = 1;
		}

		str[l--] = ' ', str[l--] = ' '; /* pad two additional spaces per level */
		i = bHeapParent(i); /* move to parent node */
	}

	/* print resulting string */
	printf("%s", str);

	/* free string */
	free(str), str = NULL;
}
void bHeapPrint (int *arr, int size) {

	int i = 0; /* index variable */

	printf("{");/* opening bracket */

	if (size > 0) {
		/* until end of array */
		while (i < size) {
			printf("%i", arr[i]); /* print array value */
			if (i+1 < size) printf(", "); /* print comma if value is not the last value in the array */
			i++;
		}
	}

	printf("}\n");/* closing bracket */
}

