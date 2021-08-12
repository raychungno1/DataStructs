#ifndef BHEAPKV_H
#define BHEAPKV_H

struct bHeapKV {
	struct bHeapKVNode *arr;
	int size;
	int MAX_SIZE;
};

struct bHeapKVNode {
	int key;
	int value;
};

/* helper functions */
int bHeapKVParent(int i);

int bHeapKVLeft(int i);

int bHeapKVRight(int i);

void bHeapKVSwap(struct bHeapKVNode *x, struct bHeapKVNode *y);

void bHeapKVMaxHeapify(struct bHeapKV *heap, int size, int index);

void bHeapKVMinHeapify(struct bHeapKV *heap, int size, int index);

/* initializes a heap of size 'size' */
struct bHeapKV *bHeapKVInit (int size);

/* clears & frees a heap */
struct bHeapKV *bHeapKVClear (struct bHeapKV *heap);

/* extract methods */
struct bHeapKVNode *bHeapKVExtractMax (struct bHeapKV *heap);

struct bHeapKVNode *bHeapKVExtractMin (struct bHeapKV *heap);

/* insert methods */
void bHeapKVInsertMax (struct bHeapKV *heap, int key, int value);

void bHeapKVInsertMin (struct bHeapKV *heap, int key, int value);

/* prettyprints heap */
void bHeapKVPrettyPrint (struct bHeapKV *heap);

	void bHeapKVPrettyPrintRec (struct bHeapKV *heap, int startIndex, int depth);

	void bHeapKVPrintSpaces(int startIndex, int depth);

/* prints array holding the heap */
void bHeapKVPrint (struct bHeapKV *heap);

#endif
