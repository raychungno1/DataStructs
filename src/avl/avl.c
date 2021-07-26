#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void avlClear (struct avlNode **rootPtr) {
	
	/* exit if empty tree */
	if (*rootPtr == NULL) return;

	/* clear left & right children */
	avlClear(&((*rootPtr)->left));
	avlClear(&((*rootPtr)->right));

	/* clear root */
	free(*rootPtr), *rootPtr = NULL;
}

int avlCountRange (struct avlNode *root, int min, int max) {

	/* count variable */
	int cLeft, cRight;

	/* finds a root that is inside the range */
	while (root != NULL && (root->data < min || max < root->data)) {
		if (root->data <= min) {
			root = root->right; /* traverse to right tree if data <= min */
		} else if (root->data >= max) {
			root = root->left; /* traverse to left tree if data >= max */
		}
	}	

	/* if a node is found */	
	if (root != NULL) {
		cLeft = avlCountGE(root->left, min); /* add nodes in left tree >= min */
		cRight = avlCountLE(root->right, max); /* add nodes in right tree <= max */
		return 1 + cLeft + cRight; /* return root & subtree nodes */
	}

	/* if a node is not found */
	return 0;
}

int avlCountGE (struct avlNode *root, int min) {

	/* count variable */
	int count = 0;

	/* until a leaf node is reached */
	while (root != NULL) {
		/* if root is greater than min */
		if (root->data >= min) {
			count ++; /* increment count & add size of right tree */
			if (root->right != NULL) count += (root->right)->size;
			root = root->left;
		} else {
			root = root->right;
		}
	}

	/* output */
	return count;
}

int avlCountLE (struct avlNode *root, int max) {

	/* count variable */
	int count = 0;

	/* until a leaf node is reached */
	while (root != NULL) {
		/* if root is greater than min */
		if (root->data <= max) {
			count ++; /* increment count & add size of right tree */
			if (root->left != NULL) count += (root->left)->size;
			root = root->right;
		} else {
			root = root->left;
		}
	}

	/* output */
	return count;
}

void avlDelete (struct avlNode **rootPtr, int key) {

	/* find the node */
	struct avlNode *node = avlSearch(*rootPtr, key), *successor, *successorParent;

	/* empty tree or if key is not in the tree */
	if (node == NULL) return;

	/* if node only has one child */
	if (node->left == NULL) {
		avlSwap(rootPtr, node, node->right);
		avlFixStats(node->parent);
		avlDeleteFix(rootPtr, node->parent);
	} else if (node->right == NULL) {
		avlSwap(rootPtr, node, node->left);
		avlFixStats(node->parent);
		avlDeleteFix(rootPtr, node->parent);

	/* if both nodes are present */
	} else {
		/* find successor node */
		successor = avlMin(node->right);
		successorParent = successor->parent;

		/* if successor node is not the right node */
		if (successor != node->right) {
			/* swap sucessor's right node into sucessor's place */
			avlSwap(rootPtr, successor, successor->right);

			/* set sucessor's right node to be the node's right node */
			successor->right = node->right;
			(successor->right)->parent = successor;
		}
		/* swap node w/ sucessor */
		avlSwap(rootPtr, node, successor);
		successor->left = node->left;
		(successor->left)->parent = successor;

		/* fix size */
		avlFixStats(successorParent);
		avlDeleteFix(rootPtr, successorParent);
	}

	/* free node */
	free(node), node = NULL;
}

void avlSwap (struct avlNode **rootPtr, struct avlNode *x, struct avlNode *y) {

	/* parent node */
	struct avlNode *parent = x->parent;

	/* connect parent to correct node */
	if (parent == NULL) {
		*rootPtr = y;
	} else if (x == parent->left) {
		parent->left = y;
	} else {
		parent->right = y;
	}

	/* set parent node */
	if (y != NULL) y->parent = parent;
}

void avlUpdateHeight (struct avlNode *node) {
		node->height = (avlHeight(node->left) > avlHeight(node->right)) ? 1+avlHeight(node->left) : 1+avlHeight(node->right);
}

void avlFixStats (struct avlNode *node) {

	/* height vars */
	/* traverse until root node */
	while (node != NULL) {
		node->size = 1; /* default size */
		if (node->left != NULL) node->size += node->left->size; /* add left child */
		if (node->right != NULL) node->size += node->right->size; /* add right chile */

		/* update size */
		avlUpdateHeight(node);
		node = node->parent; /* update to parent node */
	}
}

void avlDeleteFix(struct avlNode **rootPtr, struct avlNode *node) {

	struct avlNode *child, *grandchild;

	do {
		/* traverse until an unbalanced node is reached */
		while (node != NULL && 
		       -1 <= (avlHeight(node->left) - avlHeight(node->right)) &&
		             (avlHeight(node->left) - avlHeight(node->right)) <= 1) node = node->parent;
	
		/* return if tree is balanced */
		if (node == NULL) return;
	
		/* assign child & grandchild */
		child = (avlHeight(node->left) > avlHeight(node->right)) ? node->left : node->right;
		grandchild = (avlHeight(child->left) > avlHeight(child->right)) ? child->left : child->right;
	
		/* if child is left node */
		if (child == node->left) {
			/* if grandchild is right node */
			if (grandchild == child->right) avlLeftRotate(rootPtr, child);
			avlRightRotate(rootPtr, node); /* if grandchild is left node */
	
		/* if child is right node */
		} else {
			/* if grandchild is left node */
			if (grandchild == child->left) avlRightRotate(rootPtr, child);
			avlLeftRotate(rootPtr, node); /* if crandchild is right node */
		}
	} while (node != NULL);
}

void avlLeftRotate(struct avlNode **rootPtr, struct avlNode *node) {

	struct avlNode *newParent = node->right;

	/* swap node w/ left shild */	
	avlSwap (rootPtr, node, newParent);
	
	/* sets the new node's right child to be its old right child's left child */
	node->right = newParent->left;

	/* assigns the new right node's parent */
	if (node->right != NULL) node->right->parent = node;

	/* linking the old node to the left node */
	newParent->left = node;
	node->parent = newParent;

	/* updating sizes */
	newParent->size = node->size;
	node->size = 1;
	if (node->left != NULL) node->size += node->left->size;
	if (node->right != NULL) node->size += node->right->size;

	/* update size */
	avlUpdateHeight(node);
	avlUpdateHeight(newParent);
}

void avlRightRotate (struct avlNode **rootPtr, struct avlNode *node) {

	struct avlNode *newParent = node->left;

	/* swap node w/ left shild */	
	avlSwap (rootPtr, node, newParent);
	
	/* sets the new node's left child to be its old left child's right child */
	node->left = newParent->right;

	/* assigns the new left node's parent */
	if (node->left != NULL) node->left->parent = node;

	/* linking the old node to the left node */
	newParent->right = node;
	node->parent = newParent;

	/* updating sizes */
	newParent->size = node->size;
	node->size = 1;
	if (node->left != NULL) node->size += node->left->size;
	if (node->right != NULL) node->size += node->right->size;

	/* update size */
	avlUpdateHeight(node);
	avlUpdateHeight(newParent);
}

int avlHeight (struct avlNode *root) {
	
	/* output 0 or the node's height */
	if (root == NULL) return 0;	
	return root->height;
}

void avlInsert (struct avlNode **rootPtr, int data) {

	/* find parent node */
	struct avlNode *node = malloc(sizeof(struct avlNode));
	struct avlNode *parent = avlLocateParent(*rootPtr, data);

	/* exit if node allocation fails */
	if (node == NULL) {
		printf("Error allocating memory for node.\n");
		return;
	}
	
	/* add node data */
	node->data = data;
	node->size = 1;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	if (parent == NULL) {
		*rootPtr = node; /* if empty tree, set node to root */
	} else if (data < parent->data) {
		parent->left = node; /* if data < parent, set node to left */
	} else {
		parent->right = node; /* otherwise, set node ro right */
	}

	/* update size & height of parents */
	while (parent != NULL) {
		parent->size++;
		avlUpdateHeight(parent);
		parent = parent->parent;
	}

	avlInsertFix(rootPtr, node);
}

struct avlNode *avlLocateParent(struct avlNode *root, int data) {

	/* parent node */
	struct avlNode *parent = NULL;

	/* traverse until leaf node */
	while (root != NULL) {
		parent = root; /* update parent & root node */
		root = (root->data > data) ? root->left : root->right;
	}

	/* output */
	return parent;
}

void avlInsertFix(struct avlNode **rootPtr, struct avlNode *node) {

	struct avlNode *child, *grandchild;

	/* traverse until an unbalanced node is reached */
	while (node != NULL &&
	       -1 <= (avlHeight(node->left) - avlHeight(node->right)) &&
	             (avlHeight(node->left) - avlHeight(node->right)) <= 1) {
		if (child != NULL) grandchild = child;
		child = node;
		node = node->parent;
	}

	/* return if tree is balanced */
	if (node == NULL) return;

	/* if child is left node */
	if (child == node->left) {
		/* if grandchild is right node */
		if (grandchild == child->right) avlLeftRotate(rootPtr, child);
		avlRightRotate(rootPtr, node); /* if grandchild is left node */

	/* if child is right node */
	} else {
		/* if grandchild is left node */
		if (grandchild == child->left) avlRightRotate(rootPtr, child);
		avlLeftRotate(rootPtr, node); /* if crandchild is right node */
	}
}

struct avlNode *avlMin (struct avlNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down left nodes */
	while (root->left != NULL) root = root->left;

	/* output */
	return root;
}

/* returns min node greater than or equal to 'key' */
struct avlNode *avlMinGE (struct avlNode *root, int key) {

	/* store the current best node */
	struct avlNode *best = NULL;

	/* if called on empty tree */
	if (root == NULL) return best;

	/* until a leaf is reached */
	while (root != NULL) {

		/* if left node is greater than key */
		if (root->data >= key) {
			best = root; /* search left tree */
			root = root->left;
		} else {
			root = root->right; /* else search right tree */
		}
	}
	
	/* output */
	return best;
}

struct avlNode *avlMax (struct avlNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down right nodes */
	while (root->right != NULL) root = root->right;

	/* output */
	return root;
}

struct avlNode *avlMaxLE (struct avlNode *root, int key) {

	/* store the current best node */
	struct avlNode *best = NULL;

	/* if called on empty tree */
	if (root == NULL) return best;

	/* until a leaf is reached */
	while (root != NULL) {

		/* if left node is greater than key */
		if (root->data <= key) {
			best = root; /* search left tree */
			root = root->right;
		} else {
			root = root->left; /* else search right tree */
		}
	}
	
	/* output */
	return best;
}

struct avlNode *avlPredecessor (struct avlNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->left != NULL) return avlMax(node->left);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->left) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

void avlPrettyPrint (struct avlNode *root, int depth) {

	/* return if empty tree */
	if (root == NULL) return;

	avlPrettyPrint(root->left, depth + 1);
	printSpaces(root, depth);
	if (root->parent != NULL) {
		if (root->parent->left == root) {
			printf(",-");
		} else {
			printf("`-");
		}
		printf("[%i]\n", root->data);
	} else {
		printf("-[%i]\n", root->data);
	}
	avlPrettyPrint(root->right, depth + 1);

}

void printSpaces(struct avlNode *node, int depth) {

	int l = 3*depth; /* length parameter */
	int lStreak = 1; /* represents a streak of left nodes */
	int rStreak = 1; /* represents a streak of right nodes */

	/* malloc padding for indenting */
	char *str = malloc(l*sizeof(char) + 1);

	/* if memory allocation fails */
	if (str == NULL) return;

	/* Add null terminator */
	str[l--] = '\0';

	/* until the padding string fills up */	
	while (l > 0) {

		/* if parsing a left child w/ a left streak or a right child w/ a right streak */
		if ((node->parent->left == node && lStreak) ||
		    (node->parent->right == node && rStreak)) {
			str[l--] = ' '; /* print space */
		} else {
			str[l--] = '|'; /* print '|' */
		}

		/* updating streakd */
		if (node->parent->left == node) {
			lStreak = 1, rStreak = 0;
		} else {
			lStreak = 0, rStreak = 1;
		}

		str[l--] = ' ', str[l--] = ' '; /* pad two additional spaces per level */
		node = node->parent; /* move to parent node */
	}

	/* print resulting string */
	printf("%s", str);

	/* free string */
	free(str), str = NULL;
}

void avlPrint (struct avlNode *root) {
	
	/* return if empty tree */
	if (root == NULL) return;

	/* print the tree in order */
	avlPrint(root->left);
	printf("%i ", root->data);
	avlPrint(root->right);
}

int avlSize (struct avlNode *root) {

	/* output */
	return root->size;
}

struct avlNode *avlSearch (struct avlNode *root, int key) {

	/* while tree is not empty or data is not in root node */
	while (root != NULL && key != root->data) {
		/* traverse down the tree accordingly */
		root = (key < root->data) ? root->left : root->right; 
	}

	/* output */
	return root;
}

struct avlNode *avlSuccessor (struct avlNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->right != NULL) return avlMin(node->right);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->right) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

