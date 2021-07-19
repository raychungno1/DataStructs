# Data Structure Library 

## Singly Linked Lists
This implementation uses the following structure:
```c
struct sllNode {
	int data;
	struct sllNode *next;
};
```
The Linked List is represented by a sllNode pointer `struct sllNode*` that points the the first node of the list. 
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
</td>
<td>Inserts 'data' at the beginning of the list.</td>
</tr>

<tr>
<td>

```c
void sllAddLast (struct sllNode **headPtr, int data)
```
</td>
<td>Inserts 'data' at the end of the list.</td>
</tr>

<tr>
<td>

```c
void sllClear (struct sllNode **headPtr)
```
</td>
<td>Removes & frees all elements from the list.</td>
</tr>

<tr>
<td>

```c
int sllContains (struct sllNode **headPtr, int data)
```
</td>
<td>Returns 1 if 'data' is found in the list, 0 otherwise.</td>
</tr>

<tr>
<td>

```c
void sllFlip (struct sllNode **headPtr)
```
</td>
<td>Reverses the order of the linked list.</td>
</tr>

<tr>
<td>

```c
void sllPrint (struct sllNode **headPtr)
```
</td>
<td>Prints a string representation of the list.</td>
</tr>

<tr>
<td>

```c
void sllRemove (struct sllNode **headPtr, int data)
```
</td>
<td>Removes the first occurrence of 'data' from the list, if it exists.</td>
</tr>

<tr>
<td>

```c
int sllRemoveFirst (struct sllNode **headPtr)
```
</td>
<td>Removes and returns the first element of the list.</td>
</tr>

<tr>
<td>

```c
int sllRemoveLast (struct sllNode **headPtr)
```
</td>
<td>Removes and returns the last element of the list.</td>
</tr>

<tr>
<td>

```c
void sllSize (struct sllNode **headPtr)
```
</td>
<td>Returns the size of the list.</td>
</tr>

<tr>
<td>

```c
void sllSort (struct sllNode **headPtr)
```
</td>
<td>Sorts the list in increasing order using QuickSort algorithm.</td>
</tr>
</table>

* sllAddFirst
* sllAddLast
* sllClear
* sllContains
* sllFlip
* sllPrint
* sllRemove
* sllRemoveFirst
* sllRemoveLast
* sllSize
* sllSort
