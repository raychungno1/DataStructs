# Data Structure Library 

## Table of Contents
* **[Linked Lists](#linked-lists-singly-linked-sll-doubly-linked-dll--circular-linked-cll)**<br>
  * Singly Linked Lists
  * Double Linked Lists
  * Circular Linked Lists
* **[Hash Tables](#hash-tables-chained-hash-chash--open-address-hash-oahash)**<br>
  * Chained Hash
  * Open Address Hash
* **[Heaps](#heaps-binary-heaps-bheap)**<br>
  * Binary Heaps (keys only)
  * Binary Heaps (key-value pairs)
* **[Search Trees](#search-trees-binary-search-trees-bst-red-black-trees-rbt--avl-trees-avl)**<br>
  * Binary Search Trees
  * Red Black Trees
  * AVL Trees
* **[Graphs](#graphs-adjacency-list-alg)**<br>
  * Adjacency List Graphs

---

## Linked Lists: Singly Linked (SLL), Doubly Linked (DLL), & Circular Linked (CLL)
These Linked Lists are represented by a pointer that points the the first node of the list. Stack & Queue behavior can also be modeled using these Linked List implementations.

The SLL implementation uses the following structure:
```c
struct sllNode {
	int data;
	struct sllNode *next;
};
```
The DLL implementation uses the following structure:
```c
struct dllNode {
	int data;
	struct dllNode *next;
	struct dllNode *prev;
};
```
The CLL Implementation uses the following structure: 
```c
struct cllNode {
	int data;
	struct cllNode *next;
	struct cllNode *prev;
};
```
---
When analyzing runtimes:<br>
* n = size of linked list

This implementation includes the following methods:

<table style="width:100%">
<colgroup>
<col style="width:50%">
</colgroup>

<tr>
<th>Function Prototype</th>
<th>Description</th>
</tr>

<tr>
<td>

```c
void sllAddFirst (struct sllNode **headPtr, int data)
```
```c
void dllAddFirst (struct dllNode **headPtr, int data)
```
```c
void cllAddFirst (struct cllNode **headPtr, int data)
```
</td>
<td>

Inserts `data` at the beginning of the list.

`SLL Runtime: θ(1)`

`DLL Runtime: θ(1)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
void sllAddLast (struct sllNode **headPtr, int data)
```
```c
void dllAddLast (struct dllNode **headPtr, int data)
```
```c
void cllAddLast (struct cllNode **headPtr, int data)
```
</td>
<td>

Inserts `data` at the end of the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
void sllClear (struct sllNode **headPtr)
```
```c
void dllClear (struct dllNode **headPtr)
```
```c
void cllClear (struct cllNode **headPtr)
```
</td>
<td>

Removes & frees all elements from the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
int sllContains (struct sllNode **headPtr, int data)
```
```c
int dllContains (struct dllNode **headPtr, int data)
```
```c
int cllContains (struct cllNode **headPtr, int data)
```
</td>
<td>

Returns 1 if `data` is found in the list, 0 otherwise.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
void sllFlip (struct sllNode **headPtr)
```
```c
void dllFlip (struct dllNode **headPtr)
```
```c
void cllFlip (struct cllNode **headPtr)
```
</td>
<td>

Reverses the order of the linked list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
int sllIndexOf (struct sllNode **headPtr, int data)
```
```c
int dllIndexOf (struct dllNode **headPtr, int data)
```
```c
int cllIndexOf (struct cllNode **headPtr, int data)
```
</td>
<td>

Returns the first occurence of `data`, or -1 if `data` is not in the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
int sllPeekFirst (struct sllNode **headPtr)
```
```c
int dllPeekFirst (struct dllNode **headPtr)
```
```c
int cllPeekFirst (struct cllNode **headPtr)
```
</td>
<td>

Returns the data from the first node in the list.

`SLL Runtime: θ(1)`

`DLL Runtime: θ(1)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
int sllPeekLast (struct sllNode **headPtr)
```
```c
int dllPeekLast (struct dllNode **headPtr)
```
```c
int cllPeekLast (struct cllNode **headPtr)
```
</td>
<td>

Returns the data from the last node in the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
void sllPrint (struct sllNode **headPtr)
```
```c
void dllPrint (struct dllNode **headPtr)
```
```c
void cllPrint (struct cllNode **headPtr)
```
</td>
<td>

Prints a string representation of the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
void sllRemove (struct sllNode **headPtr, int data)
```
```c
void dllRemove (struct dllNode **headPtr, int data)
```
```c
void cllRemove (struct cllNode **headPtr, int data)
```
</td>
<td>

Removes the first occurrence of `data` from the list, if it exists.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
int sllRemoveFirst (struct sllNode **headPtr)
```
```c
int dllRemoveFirst (struct dllNode **headPtr)
```
```c
int cllRemoveFirst (struct cllNode **headPtr)
```
</td>
<td>

Removes and returns the first element of the list.

`SLL Runtime: θ(1)`

`DLL Runtime: θ(1)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
int sllRemoveLast (struct sllNode **headPtr)
```
```c
int dllRemoveLast (struct dllNode **headPtr)
```
```c
int cllRemoveLast (struct cllNode **headPtr)
```
</td>
<td>

Removes and returns the last element of the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(1)`
</td>
</tr>

<tr>
<td>

```c
void sllSize (struct sllNode **headPtr)
```
```c
void dllSize (struct dllNode **headPtr)
```
```c
void cllSize (struct cllNode **headPtr)
```
</td>
<td>

Returns the size of the list.

`SLL Runtime: θ(n)`

`DLL Runtime: θ(n)`

`CLL Runtime: θ(n)`
</td>
</tr>

<tr>
<td>

```c
void sllSortMS (struct sllNode **headPtr)
```
```c
void dllSortMS (struct dllNode **headPtr)
```
```c
void cllSortMS (struct cllNode **headPtr)
```
</td>
<td>

Sorts the list in increasing order using MergeSort algorithm.

`SLL Runtime: θ(nlog(n))`

`DLL Runtime: θ(nlog(n))`

`CLL Runtime: θ(nlog(n))`
</td>
</tr>

<tr>
<td>

```c
void sllSortQS (struct sllNode **headPtr)
```
```c
void dllSortQS (struct dllNode **headPtr)
```
```c
void cllSortQS (struct cllNode **headPtr)
```
</td>
<td>

Sorts the list in increasing order using QuickSort algorithm.

`SLL Runtime: θ(nlog(n))`

`DLL Runtime: θ(nlog(n))`

`CLL Runtime: θ(nlog(n))`
</td>
</tr>

</table>

---
## Hash Tables: Chained Hash (cHash) & Open Address Hash (oaHash)
These Hash Tables are represented by a pointer to their implementation's HashTable structure. 

The cHash implementation uses the following structures:
```c
struct cHashNode {
	int key;
	int data;
	struct cHashNode *next;
};

struct cHashTable {
	struct cHashNode **arr;
	int arrSize; /* number of 'buckets' in hash table */
	int size; /* total number of elements in hash table */
};
```
The oaHash implementation uses the following structure:
```c
struct oaHashNode {
	int key;
	int data;
	char collisionFlag;
};

struct oaHashTable {
	struct oaHashNode *arr;
	int arrSize; /* number of 'buckets' in hash table */
	int size; /* total number of elements in hash table */
};
```
---
When analyzing runtimes:<br>
* n = number of elements in the hash table
* m = size of hash table (number of 'buckets')

If (n/m) <= 1/2, `θ(1 + n/m)` can be viewed as `θ(1)`

This implementation includes the following methods: 

<table style="width:100%">
<colgroup>
<col style="width:50%">
</colgroup>

<tr>
<th>Function Prototype</th>
<th>Description</th>
</tr>

<tr>
<td>

```c
void cHashClear (struct cHashTable **hashTable)
```
```c
void oaHashClear (struct oaHashTable **hashTable)
```
</td>
<td>

Clears & frees a hash table.

`cHash Runtime: θ(m + n)`

`oaHash Runtime: θ(m)`

</td>
</tr>

<tr>
<td>

```c
int cHashContainsKey (struct cHashTable *hashTable, int key)
```
```c
int oaHashContainsKey (struct oaHashTable *hashTable, int key)
```
</td>
<td>

Returns 1 if 'key' is in the hash table, 0 otherwise.

`cHash Runtime: θ(1 + n/m)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
int cHashContainsValue (struct cHashTable *hashTable, int data)
```
```c
int oaHashContainsValue (struct oaHashTable *hashTable, int data)
```
</td>
<td>

Returns 1 if 'data' is in the hash table, 0 otherwise.

`cHash Runtime: θ(m + n)`

`oaHash Runtime: θ(m)`

</td>
</tr>

<tr>
<td>

```c
struct cHashTable *cHashInit (int hashSize)
```
```c
struct oaHashTable *oaHashInit (int hashSize)
```
</td>
<td>

Initializes a hashTable of size 'hashSize'.

`cHash Runtime: θ(1)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
void cHashInsert (struct cHashTable *hashTable, int key, int data)
```
```c
void oaHashInsert (struct oaHashTable *hashTable, int key, int data)
```
</td>
<td>

Inserts (key, data) into the hash table, if key is not already in the table.

`cHash Runtime: θ(1 + n/m)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
void cHashPrettyPrint (struct cHashTable *hashTable)
```
```c
void oaHashPrettyPrint (struct oaHashTable *hashTable)
```
</td>
<td>

Pretty-prints an ASCII representation of the hash table.

`cHash Runtime: θ(n + m)`

`oaHash Runtime: θ(m)`

</td>
</tr>

<tr>
<td>

```c
int cHashRemove (struct cHashTable *hashTable, int key)
```
```c
int oaHashRemove (struct oaHashTable *hashTable, int key)
```
</td>
<td>

Removes 'key' from the hash table & returns its data, if exists.

`cHash Runtime: θ(1 + n/m)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
int cHashReplace (struct cHashTable *hashTable, int key, int newData)
```
```c
int oaHashReplace (struct oaHashTable *hashTable, int key, int newData)
```
</td>
<td>

If the key exists, changes the data associated with 'key' to 'newData'.

`cHash Runtime: θ(1 + n/m)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
int cHashRetrieve (struct cHashTable *hashTable, int key)
```
```c
int oaHashRetrieve (struct oaHashTable *hashTable, int key)
```
</td>
<td>

Returns the data associated with 'key', if the key exists.

`cHash Runtime: θ(1 + n/m)`

`oaHash Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
int cHashSize (struct cHashTable *hashTable)
```
```c
int oaHashSize (struct oaHashTable *hashTable)
```
</td>
<td>

Returns the number of elements in the hash table.

`cHash Runtime: θ(1)`

`oaHash Runtime: θ(1)`

</td>
</tr>

</table>

---
## Heaps: Binary Heaps (bHeap)
These Heaps are represented by an array. Specific implementation details are below:<br>
* bHeap - the heap uses an array which has already been previously allocated. It is important to keep track of the size of the array as well as the number of elements currently in the heap.
* bHeapKV - the heap is represented by a pointer to the bHeapKV structure. 

The bHeapKV implementation uses the following structure:
```c
struct bHeapKV {
	struct bHeapKVNode *arr;
	int size;
	int MAX_SIZE;
};

struct bHeapKVNode {
	int key;
	int value;
};
```
---
When analyzing runtimes:<br>
* n = size of heap

This implementation includes the following methods: 

<table style="width:100%">
<colgroup>
<col style="width:50%">
</colgroup>

<tr>
<th>Function Prototype</th>
<th>Description</th>
</tr>

<tr>
<td>

```c
struct bHeapKV *bHeapKVInit (int size);
```
</td>
<td>

Initializes an empty heap w/ 'size' elements.

`bHeapKV Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
struct bHeapKV *bHeapKVClear (struct bHeapKV *heap);
```
</td>
<td>

Clears & frees a heap.

`bHeapKV Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
void bHeapBuildMax (int *arr, int size);
void bHeapBuildMin (int *arr, int size);
```
</td>
<td>

Builds a max/min heap from an input array.

`bHeap Runtime: θ(n)`

</td>
</tr>

<tr>
<td>

```c
int bHeapExtractMax (int *arr, int *size);
int bHeapExtractMin (int *arr, int *size);
```
```c
struct bHeapKVNode *bHeapKVExtractMax (struct bHeapKV *heap);
struct bHeapKVNode *bHeapKVExtractMin (struct bHeapKV *heap);
```
</td>
<td>

Extracts the max element of a max heap, or the min element of a min heap.

`bHeap Runtime: θ(log(n))`

`bHeapKV Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
void bHeapInsertMax (int *arr, int *size, int data);
void bHeapInsertMin (int *arr, int *size, int data);
```
```c
void bHeapKVInsertMax (struct bHeapKV *heap, int key, int value);
void bHeapKVInsertMin (struct bHeapKV *heap, int key, int value);
```
</td>
<td>

Inserts an element into a max/min heap.

`bHeap Runtime: θ(log(n))`

`bHeapKV Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
void bHeapPrettyPrint (int *arr, int size)
```
```c
void bHeapKVPrettyPrint (struct bHeapKV *heap)
```
</td>
<td>

Pretty-prints an ASCII representation of the heap.

`bHeap Runtime: θ(nlog(n))`

`bHeapKV Runtime: θ(nlog(n))`

</td>
</tr>

<tr>
<td>

```c
void bHeapPrint (int *arr, int size)
```
```c
void bHeapPrint (struct bHeapKV *heap)
```
</td>
<td>

Prints the array storing the heap.  

`bHeap Runtime: θ(n)`

`bHeapKV Runtime: θ(n)`

</td>
</tr>

</table>

---
## Search Trees: Binary Search Trees (BST), Red-Black Trees (RBT), & AVL Trees (AVL)
These Search Trees are represented by a pointer that points to the root node of the tree. 

The BST implementation uses the following structure:
```c
struct bstNode {
	int data;
	int size;
	struct bstNode *parent;
	struct bstNode *left;
	struct bstNode *right;	
}
```
The RBT implementation uses the following structure:
```c
struct rbtNode {
	int data;
	int size;
	char isRed;
	struct rbtNode *parent;
	struct rbtNode *left;
	struct rbtNode *right;	
}
```
The AVL implementation uses the following structure:
```c
struct avlNode {
	int data;
	int size;
	int height;
	struct avlNode *parent;
	struct avlNode *left;
	struct avlNode *right;	
}
```
---
When analyzing runtimes:<br>
* n = size of tree
* h = height of tree `log(n) <= h <= n`

This implementation includes the following methods: 

<table style="width:100%">
<colgroup>
<col style="width:50%">
</colgroup>

<tr>
<th>Function Prototype</th>
<th>Description</th>
</tr>

<tr>
<td>

```c
void bstClear (struct bstNode **rootPtr)
```
```c
void rbtClear (struct rbtNode **rootPtr)
```
```c
void avlClear (struct avlNode **rootPtr)
```
</td>
<td>

Clears & frees the entire tree.

`BST Runtime: θ(n)`

`RBT Runtime: θ(n)`

`AVL Runtime: θ(n)`

</td>
</tr>

<tr>
<td>

```c
int bstCountRange (struct bstNode *root, int min, int max)
```
```c
int rbtCountRange (struct rbtNode *root, int min, int max)
```
```c
int avlCountRange (struct avlNode *root, int min, int max)
```
</td>
<td>

Counts the number of nodes that lie within a range of values (inclusive).

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</td>
</tr>

<tr>
<td>

```c
int bstCountGE (struct bstNode *root, int min)
```
```c
int rbtCountGE (struct rbtNode *root, int min)
```
```c
int avlCountGE (struct avlNode *root, int min)
```
</td>
<td>

Counts the number of nodes that are greater than or equal to min.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
int bstCountLE (struct bstNode *root, int max)
```
```c
int rbtCountLE (struct rbtNode *root, int max)
```
```c
int avlCountLE (struct avlNode *root, int max)
```
</td>
<td>

Counts the number of nodes that are less than or equal to max.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
void bstDelete (struct bstNode **rootPtr, int key)
```
```c
void rbtDelete (struct rbtNode **rootPtr, int key)
```
```c
void avlDelete (struct avlNode **rootPtr, int key)
```
</td>
<td>

Deletes the upper-most node with `key`, if it exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
int bstHeight (struct bstNode *root)
```
```c
int rbtHeight (struct rbtNode *root)
```
```c
int avlHeight (struct avlNode *root)
```
</td>
<td>

Returns the height of the tree. 

`BST Runtime: θ(n)`

`RBT Runtime: θ(n)`

`AVL Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
void bstInsert (struct bstNode **rootPtr, int data)
```
```c
void rbtInsert (struct rbtNode **rootPtr, int data)
```
```c
void avlInsert (struct avlNode **rootPtr, int data)
```
</td>
<td>

Inserts `data` into the tree.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstMin (struct bstNode *root)
```
```c
struct rbtNode *rbtMin (struct rbtNode *root)
```
```c
struct avlNode *avlMin (struct avlNode *root)
```
</td>
<td>

Returns a pointer to the smallest node in the tree. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstMinGE (struct bstNode *root, int key)
```
```c
struct rbtNode *rbtMinGE (struct rbtNode *root, int key)
```
```c
struct avlNode *avlMinGE (struct avlNode *root, int key)
```
</td>
<td>

Returns a pointer to the smallest node greater than or equal to `key`. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstMax (struct bstNode *root)
```
```c
struct rbtNode *rbtMax (struct rbtNode *root)
```
```c
struct avlNode *avlMax (struct avlNode *root)
```
</td>
<td>

Returns a pointer to the biggest node in the tree. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstMaxLE (struct bstNode *root, int key)
```
```c
struct rbtNode *rbtMaxLE (struct rbtNode *root, int key)
```
```c
struct avlNode *avlMaxLE (struct avlNode *root, int key)
```
</td>
<td>

Returns a pointer to the biggest node less than or equal to `key`. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstPredecessor (struct bstNode *node)
```
```c
struct rbtNode *rbtPredecessor (struct rbtNode *node)
```
```c
struct avlNode *avlPredecessor (struct avlNode *node)
```
</td>
<td>

Returns a pointer to the previous node in the inorder sequence, if exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`AVL Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
void bstPrettyPrint (struct bstNode *root, int depth)
```
```c
void rbtPrettyPrint (struct rbtNode *root, int depth)
```
```c
void avlPrettyPrint (struct avlNode *root, int depth)
```
</td>
<td>

Pretty-prints an ASCII representation of the tree.

`BST Runtime: θ(n*h)`

`RBT Runtime: θ(n*h)`

`RBT Runtime: θ(n*h)`

</td>
</tr>

<tr>
<td>

```c
void bstPrint (struct bstNode *root)
```
```c
void rbtPrint (struct rbtNode *root)
```
```c
void avlPrint (struct avlNode *root)
```
</td>
<td>

Prints the tree in an inorder sequence.

`BST Runtime: θ(n)`

`RBT Runtime: θ(n)`

`RBT Runtime: θ(n)`

</td>
</tr>

<tr>
<td>

```c
void bstSize (struct bstNode *root)
```
```c
void rbtSize (struct rbtNode *root)
```
```c
void avlSize (struct avlNode *root)
```
</td>
<td>

Returns the size of the tree.

`BST Runtime: θ(1)`

`BST Runtime: θ(1)`

`BST Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstSearch (struct bstNode *root, int key)
```
```c
struct rbtNode *rbtSearch (struct rbtNode *root, int key)
```
```c
struct avlNode *avlSearch (struct avlNode *root, int key)
```
</td>
<td>

Returns a pointer to the node with `key`, if exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`RBT Runtime: θ(log(n))`

</td>
</tr>

<tr>
<td>

```c
struct bstNode *bstSuccessor (struct bstNode *node)
```
```c
struct rbtNode *rbtSuccessor (struct rbtNode *node)
```
```c
struct avlNode *avlSuccessor (struct avlNode *node)
```
</td>
<td>

Returns a pointer to the next node in the inorder sequence, if exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

`RBT Runtime: θ(log(n))`

</td>
</tr>

</table>

---

## Graphs: Adjacency List (ALG)
These Graphs are represented by a pointer that points to their implementation's Graph structure.

The ALG implementation uses the following structures:
```c
struct algNode {
	int dest;
	int weight;
	struct algNode *next;
};

struct algGraph {
	int V;
	int E;
	struct algNode **adjList;
};
```
---
When analyzing runtimes:<br>
* V = number of verticies in the graph
* E = number of edges in the graph `V-1 <= E <= V(V-1)/2`

This implementation includes the following methods: 

<table style="width:100%">
<colgroup>
<col style="width:50%">
</colgroup>

<tr>
<th>Function Prototype</th>
<th>Description</th>
</tr>

<tr>
<td>

```c
void algAddEdge (struct algGraph *graph, int src, int dest, int weight)
```
</td>
<td>

Adds an edge to an undirected graph.

`ALG Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algBFS (struct algGraph *graph, int start)
```
</td>
<td>

Conducts a breadth first search starting from vertex 'start'. Returns a BFS tree (must be freed w/ 'algClear').

`ALG Runtime: θ(V + E)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algClear (struct algGraph *graph)
```
</td>
<td>

Clears & frees a graph.

`ALG Runtime: θ(V + E)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algDFS (struct algGraph *graph, int start)
```
</td>
<td>

Conducts a depth first search starting from vertex 'start'. Returns a DFS tree (must be freed w/ 'algClear').

`ALG Runtime: θ(V + E)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algInit (int V)
```
</td>
<td>

Initializes a graph with 'V' verticies.

`ALG Runtime: θ(1)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algMST (struct algGraph *graph)
```
</td>
<td>

Finds a minimum spanning tree using Prim's algorithm. Returns a MST (must be freed w/ 'algClear').

`ALG Runtime: θ((V+E)log(V))`

</td>
</tr>

<tr>
<td>

```c
void algPrint (struct algGraph *graph)
```
</td>
<td>

Prints out the adjacency list.

`ALG Runtime: θ(V + E)`

</td>
</tr>

<tr>
<td>

```c
struct algGraph *algSPT (struct algGraph *graph, int start)
```
</td>
<td>

Finds the shortest paths to every vertex from vertex 'start' using Dijkstra's algorithm. Returns a shortest paths tree (must be freed w/ 'algClear').

`ALG Runtime: θ((V+E)log(V))`

</td>
</tr>

</table>

---

