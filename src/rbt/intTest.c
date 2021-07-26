#include "rbt.h"
#include "treeTest.h"
#include <stdio.h>

int main() {

	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	struct rbtNode *root = NULL;

	/* Testing
	 * rbtClear
	 * rbtInsert
	 * rbtPrettyPrint
	 * rbtPrint
	 * rbtSize
	 * rbtHeight
	 * rbtMin
	 * rbtMax
	 * rbtMinGE
	 * rbtMaxLE
	 * rbtPredecessor
	 * rbtSuccessor
	 * rbtCountRange
	 * rbtCountGE
	 * rbtCountLE
	 * on different types of trees
	 */
	leftSkew(&root), pInfo(root);

	rightSkew(&root), pInfo(root);

	rootOnly(&root), pInfo(root);

	random(&root), pInfo(root);

	test1(&root), pInfo(root);

	/* testing rbtSearch */
	test1(&root);
	printf("rbtSearch test: \n");
	for (i = 0; i < 20; i++) {
		rbtSearch(root, arr[i]) ? printf("  Tree has %i\n", arr[i]) : printf("  Tree doesn't have %i\n", arr[i]);
	}
	rbtSearch(root, -1) ? printf("  Tree has -1\n") : printf("  Tree doesn't have -1\n");
	rbtSearch(root, 75) ? printf("  Tree has 75\n") : printf("  Tree doesn't have 75\n");
	rbtSearch(root, 101) ? printf("  Tree has 101\n") : printf("  Tree doesn't have 101\n");
	/* testing rbtDelete */
	test1(&root);
	printf("rbtDelete test: \n");
	printf("----- Original -----\n");
	rbtPrettyPrint(root, 0);
	printf("-----\n");
	for (i = 0; i < 20; i++) {
		printf("  After Deleting %i:\n", arr[i]);
		rbtDelete(&root, arr[i]);
		rbtPrettyPrint(root, 0);
		printf("-----\n");
	}
/*	for (i = 100; i > 0; i-=10) {
		printf("  After Deleting %i:\n", i);
		rbtDelete(&root, i);
		rbtPrettyPrint(root, 0);
		printf("-----\n");
	}*/

	rbtClear(&root);
	printf("\n");
	return 0;
}
