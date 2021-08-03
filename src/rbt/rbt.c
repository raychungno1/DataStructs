#include "rbt.h"
#include <stdio.h>
#include <stdlib.h>

void rbtClear (struct rbtNode **rootPtr) {
	
	/* exit if empty tree */
	if (*rootPtr == NULL) return;

	/* clear left & right children */
	rbtClear(&((*rootPtr)->left));
	rbtClear(&((*rootPtr)->right));

	/* clear root */
	free(*rootPtr), *rootPtr = NULL;
}

int rbtCountRange (struct rbtNode *root, int min, int max) {

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
		cLeft = rbtCountGE(root->left, min); /* add nodes in left tree >= min */
		cRight = rbtCountLE(root->right, max); /* add nodes in right tree <= max */
		return 1 + cLeft + cRight; /* return root & subtree nodes */
	}

	/* if a node is not found */
	return 0;
}

int rbtCountGE (struct rbtNode *root, int min) {

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

int rbtCountLE (struct rbtNode *root, int max) {

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

void rbtDelete (struct rbtNode **rootPtr, int key) {
  
	/* find the node */
	struct rbtNode *node = rbtSearch(*rootPtr, key), *replacement, *successorParent, *x = NULL;
	int nodeIsRed;

	/* empty tree or if key is not in the tree */
	if (node == NULL) return;

	/* stores deleted node color */
	nodeIsRed = node->isRed;

	/* if node only has one child */
	if (node->left == NULL) {
		successorParent = node->parent;
		x = node->right;
		rbtSwap(rootPtr, node, node->right);
		rbtFixSize(node->parent);
	} else if (node->right == NULL) {
		successorParent = node->parent;
		x = node->left;
		rbtSwap(rootPtr, node, node->left);
		rbtFixSize(node->parent);

	/* if both nodes are present */
	} else {
		/* find successor node */
		replacement = rbtMin(node->right);
		x = replacement->right;
		successorParent = replacement;
		nodeIsRed = replacement->isRed;

		/* if successor node is not the right node */
		if (replacement != node->right) {
			/* swap sucessor's right node into sucessor's place */
			successorParent = replacement->parent;
			rbtSwap(rootPtr, replacement, replacement->right);

			/* set sucessor's right node to be the node's right node */
			replacement->right = node->right;
			(replacement->right)->parent = replacement;
		}
		/* swap node w/ sucessor */
		rbtSwap(rootPtr, node, replacement);
		replacement->left = node->left;
		replacement->left->parent = replacement;
		/* sets the successor's color to match the node that was removed */
		/* this prevents any rbt violations for successor */
		replacement->isRed = node->isRed;

		/* fix size */
		rbtFixSize(successorParent);
	}

	/* if node removed was BLACK, then violarions in the red black tree may occur */
	if (!nodeIsRed) rbtDeleteFix(rootPtr, x, successorParent);

	/* free node */
	free(node), node = NULL;
}

void rbtSwap (struct rbtNode **rootPtr, struct rbtNode *x, struct rbtNode *y) {

	/* parent node */
	struct rbtNode *parent = x->parent;

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

void rbtFixSize (struct rbtNode *node) {

	/* traverse until root node */
	while (node != NULL) {
		node->size = 1; /* default size */
		if (node->left != NULL) node->size += (node->left)->size; /* add left child */
		if (node->right != NULL) node->size += (node->right)->size; /* add right chile */
		node = node->parent; /* update to parent node */
	}
}

void rbtDeleteFix (struct rbtNode **rootPtr, struct rbtNode *node, struct rbtNode *nodeParent) {

	/* sibling node */
	struct rbtNode *sibling;

	/* while node is black & we havent reached the root */
	while (node != *rootPtr && (node == NULL || !node->isRed)) {
		sibling = (node == nodeParent->left) ? nodeParent->right : nodeParent->left;
		rbtDeleteFixA(rootPtr, node, &sibling, nodeParent);
		rbtDeleteFixB(rootPtr, &node, sibling, &nodeParent);
	}

	/* CASE 0: if node is red */
	if (node != NULL) node->isRed = 0;
}

void rbtDeleteFixA(struct rbtNode **rootPtr, struct rbtNode *node, struct rbtNode **sibling, struct rbtNode *parent) {

	/* CASE 1: if the sibling is red */
	if ((*sibling)->isRed) {
		(*sibling)->isRed = 0; /* color sibling black */
		parent->isRed = 1; /* color parent red */

		if (node == parent->left) {
			rbtLeftRotate(rootPtr, parent); /* left rotate parent if x is a left child */
			*sibling = parent->right; /* update sibling */
		} else {
			rbtRightRotate(rootPtr, parent); /* right rotate parent if x is a right child */
			*sibling = parent->left; /* update sibling */
		}
	}
}

void rbtDeleteFixB(struct rbtNode **rootPtr, struct rbtNode **node, struct rbtNode *sibling, struct rbtNode **parent) {

	/* CASE 2: if both of the sibling's children are black */
	if ((sibling->left == NULL || !sibling->left->isRed) && (sibling->right == NULL || !sibling->left->isRed)) {
		sibling->isRed = 1; /* color sibling red */
		*node = *parent; /* update node & parent */
		*parent = (*parent)->parent;
		return;
	}

	if (*node == (*parent)->left) {
		/* CASE 3: x is the left child, sibling's left child is red, & sibling's right child is black */
		if (sibling->right == NULL || !sibling->right->isRed) {
			sibling->left->isRed = 0; /* color sibling's left child black */
			sibling->isRed = 1; /* color sibling node red */
			rbtRightRotate(rootPtr, sibling); /* right rotate & update sibling */
			sibling = (*parent)->right;
		}
		/* CASE 4: x is the left child * sibling's right child is red */
		sibling->isRed = (*parent)->isRed; /* match sibling w/ parent color */
		(*parent)->isRed = 0; /* color parent black */
		sibling->right->isRed = 0; /* color sibling's right child black */
		rbtLeftRotate(rootPtr, *parent); /* left rotate parent */
	} else {
		/* CASE 3: x is the right child, sibling's right child is red, & sibling's left child is black */
		if (sibling->left == NULL || !sibling->left->isRed) {
			sibling->right->isRed = 0; /* color sibling's right child black */
			sibling->isRed = 1; /* color sibling node red */
			rbtLeftRotate(rootPtr, sibling); /* left rotate & update sibling */
			sibling = (*parent)->left;
		}
		/* CASE 4: x is the right child * sibling's left child is red */
		sibling->isRed = (*parent)->isRed; /* match sibling w/ parent color */
		(*parent)->isRed = 0; /* color parent black */
		sibling->left->isRed = 0; /* color sibling's left child black */
		rbtRightRotate(rootPtr, *parent); /* right rotate parent */
	}
	*node = *rootPtr;
}

void rbtLeftRotate(struct rbtNode **rootPtr, struct rbtNode *node) {

	struct rbtNode *newParent = node->right;

	/* swap node w/ left shild */	
	rbtSwap (rootPtr, node, newParent);
	
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
}

void rbtRightRotate (struct rbtNode **rootPtr, struct rbtNode *node) {

	struct rbtNode *newParent = node->left;

	/* swap node w/ left shild */	
	rbtSwap (rootPtr, node, newParent);
	
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
}

int rbtHeight (struct rbtNode *root) {
	
	/* count variable */
	int height = 1, leftH, rightH;

	/* return 0 for empty tree */
	if (root == NULL) return 0;

	/* return 0 for leaf node */
	if (root->left == NULL && root->right == NULL) return 0;

	/* get height of left & right trees */
	leftH = rbtHeight(root->left);
	rightH = rbtHeight(root->right);

	/* add the taller of the two children */
	height = (leftH > rightH) ? height + leftH : height + rightH;
	
	/* output */
	return height;
}

void rbtInsert (struct rbtNode **rootPtr, int data) {

	/* find parent node */
	struct rbtNode *node = malloc(sizeof(struct rbtNode));
	struct rbtNode *parent = rbtLocateParent(*rootPtr, data);

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
	node->isRed = 1;

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

	/* fix coloring & tree height */
	rbtInsertFix(rootPtr, node);
}

struct rbtNode *rbtLocateParent(struct rbtNode *root, int data) {

	/* parent node */
	struct rbtNode *parent = NULL;

	/* traverse until leaf node */
	while (root != NULL) {
		parent = root; /* update parent & root node */
		root = (root->data > data) ? root->left : root->right;
	}

	/* output */
	return parent;
}

struct rbtNode *rbtSibling (struct rbtNode *node) {

	/* if node is a left node, return right node */
	if (node->parent->left == node) return node->parent->right;
	return node->parent->left; /* else, left node */
}

void rbtInsertFix (struct rbtNode **rootPtr, struct rbtNode *node) {
	
	/* perform three cases required to fix the tree */
	rbtInsertFixA(&node);
	rbtInsertFixB(rootPtr, &node);
	rbtInsertFixC(rootPtr, node);
	(*rootPtr)->isRed = 0;	
}

void rbtInsertFixA(struct rbtNode **node) {

	/* sibling node */
	struct rbtNode *sibling;

	/* loop until root node or node parent is black */
	while ((*node)->parent != NULL && (*node)->parent->isRed == 1) {

		/* getting sibling node */
		sibling = rbtSibling((*node)->parent);
		if (sibling == NULL || sibling->isRed == 0) return;

		/* coloring parent & uncle nodes black */
		(*node)->parent->isRed = 0;
		sibling->isRed = 0;

		/* update node to its grandparent */
		(*node) = (*node)->parent->parent;
		(*node)->isRed = 1; /* set grandparent to red */
	}		
}

void rbtInsertFixB (struct rbtNode **rootPtr, struct rbtNode **node) {

	
	/* parent & grandparent nodes */
	struct rbtNode *parent, *grandParent;

	/* return if we are ar root or is parent is black */
	if (*node == *rootPtr || (*node)->parent->isRed == 0) return;

	parent = (*node)->parent; /* assign parent & grandparent nodes */
	grandParent = parent->parent;

	/* if node is a left child & parent is a right child */
	if (*node == parent->left && parent == grandParent->right) {
		*node = parent; /* right rotate on parent */
		rbtRightRotate(rootPtr, *node);

	/* if node if a right child & parent is a left child */
	} else if (*node == parent->right && parent == grandParent->left) {
		*node = parent; /* left rotate on parent */
		rbtLeftRotate(rootPtr, *node);
	}

}

void rbtInsertFixC (struct rbtNode **rootPtr, struct rbtNode *node) {

	/* parent & grandparent nodes */
	struct rbtNode *parent, *grandParent;

	/* return if we are ar root or is parent is black */
	if (node == *rootPtr || node->parent->isRed == 0) return;

	parent = node->parent; /* assign parent & grandparent nodes */
	grandParent = node->parent->parent;	

	/* if both node & parent are left children */
	if (node == parent->left && parent == grandParent->left) {
		rbtRightRotate(rootPtr, grandParent);
		parent->isRed = 0; /* right rotate & recolor nodes */
		grandParent->isRed = 1;

	/* if both node & parent are right children */
	} else if (node == parent ->right && parent == grandParent->right) {
		rbtLeftRotate(rootPtr, grandParent);
		parent->isRed = 0; /* left rotate & recolor nodes */
		grandParent->isRed = 1;
	}
}

struct rbtNode *rbtMin (struct rbtNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down left nodes */
	while (root->left != NULL) root = root->left;

	/* output */
	return root;
}

/* returns min node greater than or equal to 'key' */
struct rbtNode *rbtMinGE (struct rbtNode *root, int key) {

	/* store the current best node */
	struct rbtNode *best = NULL;

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

struct rbtNode *rbtMax (struct rbtNode *root) {

	/* if called on empty tree */
	if (root == NULL) return root;

	/* traverse down right nodes */
	while (root->right != NULL) root = root->right;

	/* output */
	return root;
}

struct rbtNode *rbtMaxLE (struct rbtNode *root, int key) {

	/* store the current best node */
	struct rbtNode *best = NULL;

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

struct rbtNode *rbtPredecessor (struct rbtNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->left != NULL) return rbtMax(node->left);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->left) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

void rbtPrettyPrint (struct rbtNode *root, int depth) {

	/* return if empty tree */
	if (root == NULL) return;

	rbtPrettyPrint(root->left, depth + 1);
	printSpaces(root, depth);
	if (root->parent != NULL) {
		(root->parent->left == root) ? printf(",-") : printf("`-");
		(root->isRed) ? printf("[%i]\n", root->data) : printf("(%i)\n", root->data);
	} else {
		printf("-(%i)\n", root->data);
	}
	rbtPrettyPrint(root->right, depth + 1);

}

void printSpaces(struct rbtNode *node, int depth) {

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

void rbtPrint (struct rbtNode *root) {
	
	/* return if empty tree */
	if (root == NULL) return;

	/* print the tree in order */
	rbtPrint(root->left);
	printf("%i ", root->data);
	rbtPrint(root->right);
}

int rbtSize (struct rbtNode *root) {

	/* output */
	return root->size;
}

struct rbtNode *rbtSearch (struct rbtNode *root, int key) {

	/* while tree is not empty or data is not in root node */
	while (root != NULL && key != root->data) {
		/* traverse down the tree accordingly */
		root = (key < root->data) ? root->left : root->right; 
	}

	/* output */
	return root;
}

struct rbtNode *rbtSuccessor (struct rbtNode *node) {

	/* if right tree is not empty */
	if (node == NULL || node->right != NULL) return rbtMin(node->right);

	/* fint the closest ancestor where node is in the left subtree of */
	while (node->parent != NULL && node == (node->parent)->right) {
		node = node->parent;
	}

	/* output */
	return node->parent;
}

