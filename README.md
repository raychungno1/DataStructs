# Data Structure Library 

## Table of Contents
* **[Linked Lists](#linked-lists-singly-linked-sll-doubly-linked-dll--circular-linked-cll)**<br>
  * Queue
  * Stack
* **[Binary Search Trees](#binary-search-trees-bst)**<br>

---

## Linked Lists: Singly Linked (SLL), Doubly Linked (DLL), & Circular Linked (CLL)
Due to the similarity of the SLL, DLL, and CLL implementations, their documentations are combined into one section. The CLL implementation is also doubly linked.

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

## Search Trees: Binary Search Trees (BST) & Red-Black Trees (RBT)
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
---
When analyzing runtimes:<br>
* n = size of tree
* h = height of tree (log(n) <= h <= n)

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
</td>
<td>

Clears & frees the entire tree.

`BST Runtime: θ(n)`

`RBT Runtime: θ(n)`

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
</td>
<td>

Counts the number of nodes that lie within a range of values (inclusive).

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Counts the number of nodes that are greater than or equal to min.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Counts the number of nodes that are less than or equal to max.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Deletes the upper-most node with `key`, if it exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns the height of the tree. 

`BST Runtime: θ(n)`

`RBT Runtime: θ(n)`

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
</td>
<td>

Inserts `data` into the tree.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns a pointer to the smallest node in the tree. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns a pointer to the smallest node greater than or equal to `key`. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns a pointer to the biggest node in the tree. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns a pointer to the biggest node less than or equal to `key`. 

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Returns a pointer to the previous node in the inorder sequence, if exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

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
</td>
<td>

Pretty-prints an ASCII representation of the tree.

`BST Runtime: θ(n*h)`

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
</td>
<td>

Prints the tree in an inorder sequence.

`BST Runtime: θ(n)`

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
</td>
<td>

Returns the size of the tree.

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
</td>
<td>

Returns a pointer to the node with `key`, if exists.

`BST Runtime: θ(h)`

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
</td>
<td>

Returns a pointer to the next node in the inorder sequence, if exists.

`BST Runtime: θ(h)`

`RBT Runtime: θ(log(n))`

</td>
</tr>

</table>

---
