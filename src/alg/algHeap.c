#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

int algHeapParent(int i) {
	return (i-1)/2;
}

int algHeapLeft(int i) {
	return (2*i)+1;
}

int algHeapRight(int i) {
	return (2*i)+2;
}

void algHeapSwap(struct algHeap *heap, int x, int y) {

	int temp;
	struct algStorage *p1 = heap->arr+x, *p2 = heap->arr+y;

	temp = heap->pos[p1->vertex]; /* swap pos array */
	heap->pos[p1->vertex] = heap->pos[p2->vertex];
	heap->pos[p2->vertex] = temp;
	
	temp = p1->vertex; /* swap vertex */
	p1->vertex = p2->vertex;
	p2->vertex = temp;

	temp = p1->parent; /* swap parent */
	p1->parent = p2->parent;
	p2->parent = temp;

	temp = p1->key; /* swap key */
	p1->key = p2->key;
	p2->key = temp;
}

void algHeapMinHeapify(struct algHeap *heap, int size, int i) {

	int smallest, done = 0,	left = algHeapLeft(i), right = algHeapRight(i);

	do {
		/* find max between root, left, & right child */
		smallest = i;
		if (left <= size && (heap->arr+left)->key < (heap->arr+smallest)->key) smallest = left;
		if (right <= size && (heap->arr+right)->key < (heap->arr+smallest)->key) smallest = right;

		/* swap if root is not the largest */
		if (i != smallest) algHeapSwap(heap, i, smallest); 
		else done = 1; /* exit otherwise */

		i = smallest; /* repeat w/ child node */
		left = algHeapLeft(i), right = algHeapRight(i);
	} while (!done);
}

/* initializes a heap of size 'size' */
struct algHeap *algHeapInit (int size) {
	
	/* allocate memory for heap */
	struct algHeap *heap = malloc (sizeof(struct algHeap));
	if (heap) { /* initialize structure values */
		heap->arr = malloc(size * sizeof(struct algStorage));
		heap->size = 0;
		heap->MAX_SIZE = size;
	
		if (!heap->arr) { /* If array allocation fails */
			printf("Error allocating memory for heap array.\n");
			free(heap), heap = NULL;
		}

		heap->pos = malloc(size * sizeof(int));
		if (!heap->pos) { /* if array allocation fails */
			printf("Error allocating memory for parent array.\n");
			free(heap->arr), heap->arr = NULL;
			free(heap), heap = NULL;
		}
	} else { /* if memory allocation fails */
		printf("Error allocating memory for heap.\n");
	}
	return heap; /* output */
}

/* clears & frees a heap */
struct algHeap *algHeapClear (struct algHeap *heap) {
	free(heap->arr), heap->arr = NULL;
	free(heap->pos), heap->pos = NULL;
	free(heap), heap = NULL;
	return NULL;
}

/* extract method */
struct algStorage *algHeapExtractMin (struct algHeap *heap) {

	struct algStorage *min = malloc(sizeof(struct algStorage)); /* max var */
	if (!min) { /* if memory allocation fails */
		printf("Error allocating memory for min node.\n");
		return NULL;
	}

	if (heap->size < 1) {
		printf("Empty heap.\n");
		return 0; /* return if heap is empty */
	}

	min->vertex = heap->arr->vertex; /* save min value */
	min->parent = heap->arr->parent;
	min->key = heap->arr->key;
	heap->pos[min->vertex] = -1; /* remove element from the pos array */

	heap->size--; /* decrement size */
	heap->arr->vertex = (heap->arr+(heap->size))->vertex; /* copy last array value over */
	heap->arr->parent = (heap->arr+(heap->size))->parent;
	heap->arr->key = (heap->arr+(heap->size))->key;
	heap->pos[heap->arr->vertex] = 0;

	algHeapMinHeapify(heap, heap->size, 0); /* sift the copied value down */

	return min; /* output */
}

/* insert method */
void algHeapInsert (struct algHeap *heap, int weight, int vertex, int parent) {

	int i = heap->size; /* index of initial insert */

	if (heap->size == heap->MAX_SIZE) {
		printf("Overflow.\n");
		return; /* returns if heap is full */
	}

	(heap->arr+i)->vertex = vertex; /* adding data at end of array */
	(heap->arr+i)->parent = parent; 
	(heap->arr+i)->key = weight;
	heap->pos[vertex] = i;
	heap->size++; /* increment heap size */

	/* while node value is less than parent value */
	while (i > 0 && (heap->arr+algHeapParent(i))->key > (heap->arr+i)->key) {
		algHeapSwap(heap, i, algHeapParent(i)); /* swap node w/ parent */
		i = algHeapParent(i); /* update i to its parent */
	}
}

/* decreaseKey function */
void algHeapDecreaseKey (struct algHeap *heap, int vertex, int newParent, int newKey) {

	int i = heap->pos[vertex]; /* index of vertex to be replaced */

	/* replace new parent & key */
	(heap->arr+i)->parent = newParent;
	(heap->arr+i)->key = newKey;

	/* while node value is less than parent value */
	while (i > 0 && (heap->arr+algHeapParent(i))->key > (heap->arr+i)->key) {
		algHeapSwap(heap, i, algHeapParent(i)); /* swap node w/ parent */
		i = algHeapParent(i); /* update i to its parent */
	}
}

void algHeapPrint (struct algHeap *heap) {

	int i = 0; /* index variable */

	printf("{");/* opening bracket */

	if (heap->size > 0) {
		/* until end of array */
		while (i < heap->size) {
			printf("(%i, %i)", (heap->arr+i)->key, (heap->arr+i)->vertex); /* print array value */
			if (i+1 < heap->size) printf(", "); /* print comma if value is not the last value in the array */
			i++;
		}
	}

	printf("}\n");/* closing bracket */

	for (i = 0; i < heap->size; i++) {
		printf("%i ", heap->pos[i]);
	}
	printf("\n");
}

