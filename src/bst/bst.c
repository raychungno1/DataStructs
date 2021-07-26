#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void bstClear (struct bstNode **rootPtr) {
	
	/* exit if empty tree */
	if (*rootPtr == NULL) return;

	/* clear left & right children */
	bstClear(&((*rootPtr)->left));
	bstClear(&((*rootPtr)->right));

	/* clear root */
	free(*rootPtr), *rootPtr = NULL;
}

int bstCountRange (struct bstNode *root, int min, int max) {

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
		cLeft = bstCountGE(root->left, min); /* add nodes in left tree >= min */
		cRight = bstCountLE(root->right, max); /* add nodes in right tree <= max */
		return 1 + cLeft + cRight; /* return root & subtree nodes */
	}

	/* if a node is not found */
	return 0;
}

int bstCountGE (struct bstNode *root, int min) {

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

int bstCountLE (struct bstNode *root, int max) {

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

void bstDelete (struct bstNode **rootPtr, int key) {

	/* find the node */
	struct bstNode *node = bstSearch(*rootPtr, key), *successor, *successorParent;

	/* empty tree or if key is not in the tree */
	if (node == NULL) return;

	/* if node only has one child */
	if (node->left == NULL) {
		bstSwap(rootPtr, node, node->right);
		bstFixSize(node->parent);
	} else if (node->right == NULL) {
		bstSwap(rootPtr, node, node->left);
		bstFixSize(node->parent);

	/* if both nodes are present */
	} else {
		/* find successor node */
		successor = bstMin(node->right);
		successorParent = successor->parent;

		/* if successor node is not the right node */
		if (successor != node->right) {
			/* swap sucessor's right node into sucessor's place */
			bstSwap(rootPtr, successor, successor->right);

			/* set sucessor's right node to be the node's right node */
			successor->right = node->right;
			(successor->right)->parent = successor;
		}
		/* swap node w/ sucessor */
		bstSwap(rootPtr, node, successor);
		successor->left = node->left;
		(successor->left)->parent = successor;

		/* fix size */
		bstFixSize(successorParent);
	}

	/* free node */
	free(node), node = NULL;
}

void bstSwap (struct bstNode **rootPtr, struct bstNode *x, struct bstNode *y) {

	/* parent node */
	struct bstNode *parent = x->parent;

	/* connect parent to correct node */
	if (parent == NULL) {
		*rootPtr = y;
	}else if (x == parent->left) {
		parent->left = y;
	} else {
		parent->right = y;
	}

	/* set parent node */
	if (y != NULL) y->parent = parent;
}

void bstFixSize (struct bstNode *node) {

	/* traverse until root node */
	while (node != NULL) {
		node->size = 1; /* default size */
		if (node->left != NULL) node->size += (node->left)->size; /* add left child */
		if (node->right != NULL) node->size += (node->right)->size; /* add right chile */
		node = node->parent; /* update to parent node */
	}
}

int bstHeight (struct bstNode *root) {
	
	/* count variable */
	int height = 1, leftH, rightH;

	/* return 0 for empty tree */
	if (root == NULL) return 0;

	/* get height of left & right trees */
	leftH = bstHeight(root->left);
	rightH = bstHeight(root->right);

	/* add the taller of the two children */
	height = (leftH > rightH) ? height + leftH : height + rightH;
	
	/* output */
	return height;
}

void bstInsert (struct bstNode **rootPtr, int data) {

	/* find parent node */
	struct bstNode *node = malloc(sizeof(struct bstNode));
	struct bstNode *parent = bstLocateParent(*rootPtr, data);

	/* exit if node allocation fails */
	if (node == NULL) {
		printf("Error allocating memory for node.\n");
		return;
	}
	
	/* add node data */
	node->data = data;
	node->size = 1;
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

	/* update size of parents */
	while (parent != NULL) {
		parent->size++;
		parent = parent->parent;
	}
}

struct bstNode *bstLocateParent(struct bstNode *root, int data) {

	/* parent node */
	struct bstNode *parent = NULL;

	/* traverse until leaf node */
	while (root != NULL) {
		parent = root; /* update parent & root node */
		root = (root->data > data) ? root->left : root->right;
	}

	/* output */
	return parent;
}

struct bstNode *bstMin (struct bstNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down left nodes */
	while (root->left != NULL) root = root->left;

	/* output */
	return root;
}

/* returns min node greater than or equal to 'key' */
struct bstNode *bstMinGE (struct bstNode *root, int key) {

	/* store the current best node */
	struct bstNode *best = NULL;

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

struct bstNode *bstMax (struct bstNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down right nodes */
	while (root->right != NULL) root = root->right;

	/* output */
	return root;
}

struct bstNode *bstMaxLE (struct bstNode *root, int key) {

	/* store the current best node */
	struct bstNode *best = NULL;

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

struct bstNode *bstPredecessor (struct bstNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->left != NULL) return bstMax(node->left);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->left) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

void bstPrettyPrint (struct bstNode *root, int depth) {

	/* return if empty tree */
	if (root == NULL) return;

	bstPrettyPrint(root->left, depth + 1);
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
	bstPrettyPrint(root->right, depth + 1);

}

void printSpaces(struct bstNode *node, int depth) {

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

void bstPrint (struct bstNode *root) {
	
	/* return if empty tree */
	if (root == NULL) return;

	/* print the tree in order */
	bstPrint(root->left);
	printf("%i ", root->data);
	bstPrint(root->right);
}

int bstSize (struct bstNode *root) {

	/* output */
	return root->size;
}

struct bstNode *bstSearch (struct bstNode *root, int key) {

	/* while tree is not empty or data is not in root node */
	while (root != NULL && key != root->data) {
		/* traverse down the tree accordingly */
		root = (key < root->data) ? root->left : root->right; 
	}

	/* output */
	return root;
}

struct bstNode *bstSuccessor (struct bstNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->right != NULL) return bstMin(node->right);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->right) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

