#include "bHeapKV.h"
#include <stdio.h>
#include <stdlib.h>

int bHeapKVParent(int i) {
	return (i-1)/2;
}

int bHeapKVLeft(int i) {
	return (2*i)+1;
}

int bHeapKVRight(int i) {
	return (2*i)+2;
}

void bHeapKVSwap(struct bHeapKVNode *x, struct bHeapKVNode *y) {
	y->key = x->key ^ y->key;
	x->key = x->key ^ y->key;
	y->key = x->key ^ y->key;
	y->value = x->value ^ y->value;
	x->value = x->value ^ y->value;
	y->value = x->value ^ y->value;
}

void bHeapKVMaxHeapify(struct bHeapKV *heap, int size, int i) {

	int largest, done = 0, left = bHeapKVLeft(i), right = bHeapKVRight(i);

	do {
		/* find max between root, left, & right child */
		largest = i;
		if (left <= size && (heap->arr+left)->key > (heap->arr+largest)->key) largest = left;
		if (right <= size && (heap->arr+right)->key > (heap->arr+largest)->key) largest = right;

		/* swap if root is not the largest */
		if (i != largest) bHeapKVSwap(heap->arr+i, heap->arr+largest); 
		else done = 1; /* exit otherwise */

		i = largest; /* repeat w/ child node */
		left = bHeapKVLeft(i), right = bHeapKVRight(i);
	} while (!done);
}

void bHeapKVMinHeapify(struct bHeapKV *heap, int size, int i) {

	int smallest, done = 0,	left = bHeapKVLeft(i), right = bHeapKVRight(i);

	do {
		/* find max between root, left, & right child */
		smallest = i;
		if (left <= size && (heap->arr+left)->key < (heap->arr+smallest)->key) smallest = left;
		if (right <= size && (heap->arr+right)->key < (heap->arr+smallest)->key) smallest = right;

		/* swap if root is not the largest */
		if (i != smallest) bHeapKVSwap(heap->arr+i, heap->arr+smallest); 
		else done = 1; /* exit otherwise */

		i = smallest; /* repeat w/ child node */
		left = bHeapKVLeft(i), right = bHeapKVRight(i);
	} while (!done);
}

/* initializes a heap of size 'size' */
struct bHeapKV *bHeapKVInit (int size) {
	
	/* allocate memory for heap */
	struct bHeapKV *heap = malloc (sizeof(struct bHeapKV));
	if (heap) { /* initialize structure values */
		heap->arr = malloc(size * sizeof(struct bHeapNKVNode));
		heap->size = 0;
		heap->MAX_SIZE = size;
	
		if (!heap) { /* If array allocation fails */
			printf("Error allocating memory for heap array.\n");
			free(heap), heap = NULL;
		}
	} else { /* if memory allocation fails */
		printf("Error allocating memory for heap.\n");
	}
	return heap; /* output */
}

/* clears & frees a heap */
struct bHeapKV *bHeapKVClear (struct bHeapKV *heap) {
	free(heap->arr), heap->arr = NULL;
	free(heap), heap = NULL;
	return NULL;
}

/* build heap from input array */
struct bHeapKV *bHeapKVBuildMax (int *arr, int size) {
	int index = (size/2)-1; /* heapify each non leaf node in reverse order */
	while (index >= 0) bHeapKVMaxHeapify(arr, size, index--);
}

struct bHeapKV *bHeapKVBuildMin (int *arr, int size) {
	int index = (size/2)-1; /* heapify each non leaf node in reverse order */
	while (index >= 0) bHeapKVMinHeapify(arr, size, index--);
}

/* extract methods */
struct bHeapKVNode *bHeapKVExtractMax (struct bHeapKV *heap) {

	struct bHeapKVNode *max = malloc(sizeof(struct bHeapKVNode)); /* max var */
	if (!max) { /* if memory allocation fails */
		printf("Error allocating memory for max node.\n");
		return NULL;
	}

	if (*size < 1) return 0; /* return if heap is empty */

	max->key = heap->arr->key; /* save max value */
	max->value = heap->arr->value;

	heap->size--; /* decrement size */
	heap->arr->key = (heap->arr+(heap->size))->key; /* copy last array value over */
	heap->arr->value = (heap->arr+(heap->size))->value;

	bHeapKVMaxHeapify(heap, heap->size, 0); /* sift the copied value down */

	return max; /* output */
}

struct bHeapKVNode *bHeapKVExtractMin (struct bHeapKV *heap) {

	struct bHeapKVNode *min = malloc(sizeof(struct bHeapKVNode)); /* max var */
	if (!min) { /* if memory allocation fails */
		printf("Error allocating memory for max node.\n");
		return NULL;
	}

	if (*size < 1) return 0; /* return if heap is empty */

	min->key = heap->arr->key; /* save min value */
	min->value = heap->arr->value;

	heap->size--; /* decrement size */
	heap->arr->key = (heap->arr+(heap->size))->key; /* copy last array value over */
	heap->arr->value = (heap->arr+(heap->size))->value;

	bHeapKVMinHeapify(heap, heap->size, 0); /* sift the copied value down */

	return min; /* output */
}

/* insert methods */
void bHeapKVInsertMax (struct bHeapKV *heap, int key, int value) {

	int i = heap->size; /* index of initial insert */

	if (heap->size == heap->MAX_SIZE) {
		printf("Overflow.\n");
		return; /* returns if heap is full */
	}

	(heap->arr+i)->key = key; /* adding data at end of array */
	(heap->arr+i)->value = value; 
	
	/* while node value is greater than parent value */
	while (i > 0 && (heap->arr+bHeapKVParent(i))->key < (heap->arr+i)->key) {
		bHeapKVSwap(heap->arr+i, heap->arr+bHeapKVParent(i)); /* swap node w/ parent */
		i = bHeapKVParent(i); /* update i to its parent */
	}
	heap->size++; /* increment heap size */
}

void bHeapKVInsertMin (int *arr, int *size, int data) {

	int i = heap->size; /* index of initial insert */

	if (heap->size == heap->MAX_SIZE) {
		printf("Overflow.\n");
		return; /* returns if heap is full */
	}

	(heap->arr+i)->key = key; /* adding data at end of array */
	(heap->arr+i)->value = value; 
	
	/* while node value is less than parent value */
	while (i > 0 && (heap->arr+bHeapKVParent(i))->key > (heap->arr+i)->key) {
		bHeapKVSwap(heap->arr+i, heap->arr+bHeapKVParent(i)); /* swap node w/ parent */
		i = bHeapKVParent(i); /* update i to its parent */
	}
	heap->size++; /* increment heap size */
}

/* prettyprints tree with an in order traversal */
void bHeapKVPrettyPrint (struct bHeapKV *heap) {bHeapKVPrettyPrintRec(heap, 0, 0);}

void bHeapKVPrettyPrintRec (struct bHeapKV *heap, int startIndex, int depth) {

	int i = startIndex;

	/* return if empty tree */
	if (heap->size == 0) return;

	if (bHeapKVLeft(i) < heap->size) bHeapKVPrettyPrintRec(heap, bHeapKVLeft(i), depth + 1);

	bHeapKVPrintSpaces(i, depth);
	if (i != 0) {
		if (bHeapKVLeft(bHeapKVParent(i)) == i) {
			printf(",-");
		} else {
			printf("`-");
		}
		printf("[%i, %i]\n", (heap->arr+i)->key, (heap->arr+i)->value);
	} else {
		printf("-[%i, %i]\n", (heap->arr+i)->key, (heap->arr+i)->value);
	}

	if (bHeapKVRight(i) < heap->size) bHeapKVPrettyPrintRec(heap, bHeapKVRight(i), depth + 1);
}

void bHeapKVPrintSpaces(int startIndex, int depth) {

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
		if ((bHeapKVLeft(bHeapKVParent(i)) == i && lStreak) ||
		    (bHeapKVRight(bHeapKVParent(i)) == i && rStreak)) {
			str[l--] = ' '; /* print space */
		} else {
			str[l--] = '|'; /* print '|' */
		}

		/* updating streaks */
		if (bHeapKVLeft(bHeapKVParent(i)) == i) {
			lStreak = 1, rStreak = 0;
		} else {
			lStreak = 0, rStreak = 1;
		}

		str[l--] = ' ', str[l--] = ' '; /* pad two additional spaces per level */
		i = bHeapKVParent(i); /* move to parent node */
	}

	/* print resulting string */
	printf("%s", str);

	/* free string */
	free(str), str = NULL;
}

void bHeapKVPrint (struct bHeapKV *heap) {

	int i = 0; /* index variable */

	printf("{");/* opening bracket */

	if (size > 0) {
		/* until end of array */
		while (i < size) {
			printf("(%i, %i)", (heap->arr+i)->key, (heap->arr+i)->value); /* print array value */
			if (i+1 < size) printf(", "); /* print comma if value is not the last value in the array */
			i++;
		}
	}

	printf("}\n");/* closing bracket */
}

