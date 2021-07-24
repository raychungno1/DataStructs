#include "rbt.h"
#include "treeTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pInfo(struct rbtNode *root) {
	struct rbtNode *min, *max, *temp;
	printf("----------\n");
	/* rbtPrettyPrint */
	rbtPrettyPrint(root, 0);
	printf("In order traversal: ");
	/* rbtPrint */
	rbtPrint(root);
	/* rbtSize */
	printf("\nSize: %i\n", rbtSize(root));
	/* rbtHeight */
	printf("Height: %i\n", rbtHeight(root));
	/* rbtMin */
	min = rbtMin(root);
	printf("Min: %i\n", min->data);
	/* rbtSuccessor */
	printf("  Sucessor(s): ");
	while (min = rbtSuccessor(min)) printf("%i ", min->data);
	printf("\n");
	/* rbtMax */
	max = rbtMax(root);
	printf("Max: %i\n", max->data);
	/* rbtPredecessor */
	printf("  Predecessor(s): ");
	while (max = rbtPredecessor(max)) printf("%i ", max->data);
	printf("\n");
	/* rbtMinGE */
	printf("Min Node >= 25: ");
	(min = rbtMinGE(root, 25)) ? printf("%i\n", min->data) : printf("NULL\n");
	/* rbtMaxLE */
	printf("Max Node <= 75: ");
	(max = rbtMaxLE(root, 75)) ? printf("%i\n", max->data) : printf("NULL\n");
	/* rbtCountRange */
	printf("# Nodes between 25 & 75: %i\n", rbtCountRange(root, 25, 75));
	/* rbtCountGE */
	printf("# Nodes >= 25: %i\n", rbtCountGE(root, 25));
	/* rbtCountLE */
	printf("# Nodes <= 75: %i\n", rbtCountLE(root, 75));
}

void leftSkew(struct rbtNode **head) {
	int i;
	rbtClear(head);
	for (i = 90; i >= 0; i-=10) rbtInsert(head, i);
}

void rightSkew(struct rbtNode **head) {
	int i;
	rbtClear(head);
	for (i = 0; i < 100; i+=10) rbtInsert(head, i);
}

void rootOnly(struct rbtNode **head) {
	rbtClear(head);
	rbtInsert(head, 100);
}

void random(struct rbtNode **head) {
	int i;
	srand(time(0));
	rbtClear(head);
	for (i = 0; i < 25; i++) rbtInsert(head, rand()%100);
}

void test1(struct rbtNode **head) {
	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	rbtClear(head);
	for (i = 0; i < 20; i++) rbtInsert(head, arr[i]);
}

