# Data Structure Library 

## Singly Linked Lists (SLL) & Doubly Linked Lists (DLL)
Due to the similarity of both implementations, their documentations are combined into one section.
The SLL implementation uses the following structure:
```c
struct sllNode {
	int data;
	struct sllNode *next;
};
```
The SLL implementation uses the following structure:
```c
struct dllNode {
	int data;
	struct dllNode *next;
	struct dllNode *prev;
};
```
The Linked List is represented by a pointer that points the the first node of the list. Stack & Queue behavior can also be modeled using these Linked List implementation.

---
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
</td>
<td>

Inserts `data` at the beginning of the list.

`Runtime: θ(1)`
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
</td>
<td>

Inserts `data` at the end of the list.

`Runtime: θ(n)`
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
</td>
<td>

Removes & frees all elements from the list.

`Runtime: θ(n)`
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
</td>
<td>

Returns 1 if `data` is found in the list, 0 otherwise.

`Runtime: θ(n)`
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
</td>
<td>

Reverses the order of the linked list.

`Runtime: θ(n)`
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
</td>
<td>

Returns the first occurence of `data`, or -1 if `data` is not in the list.

`Runtime: θ(n)`
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
</td>
<td>

Returns the data from the first node in the list.

`Runtime: θ(1)`
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
</td>
<td>

Returns the data from the last node in the list.

`Runtime: θ(n)`
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
</td>
<td>

Prints a string representation of the list.

`Runtime: θ(n)`
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
</td>
<td>

Removes the first occurrence of `data` from the list, if it exists.

`Runtime: θ(n)`
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
</td>
<td>

Removes and returns the first element of the list.

`Runtime: θ(1)`
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
</td>
<td>

Removes and returns the last element of the list.

`Runtime: θ(n)`
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
</td>
<td>

Returns the size of the list.

`Runtime: θ(n)`
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
</td>
<td>

Sorts the list in increasing order using MergeSort algorithm.

`Runtime: θ(nlog(n))`
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
</td>
<td>

Sorts the list in increasing order using QuickSort algorithm.

`Runtime: θ(nlog(n))`
</td>
</tr>

</table>

---

