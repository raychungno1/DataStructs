#include "avl.h"
#include "treeTest.h"
#include <stdio.h>

int main() {

	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	struct avlNode *root = NULL;

	/* Testing
	 * avlClear
	 * avlInsert
	 * avlPrettyPrint
	 * avlPrint
	 * avlSize
	 * avlHeight
	 * avlMin
	 * avlMax
	 * avlMinGE
	 * avlMaxLE
	 * avlPredecessor
	 * avlSuccessor
	 * avlCountRange
	 * avlCountGE
	 * avlCountLE
	 * on different types of trees
	 */
	leftSkew(&root), pInfo(root);

	rightSkew(&root), pInfo(root);

	rootOnly(&root), pInfo(root);

	random(&root), pInfo(root);

	test1(&root), pInfo(root);

	/* testing avlSearch */
	test1(&root);
	printf("avlSearch test: \n");
	for (i = 0; i < 20; i++) {
		avlSearch(root, arr[i]) ? printf("  Tree has %i\n", arr[i]) : printf("  Tree doesn't have %i\n", arr[i]);
	}
	avlSearch(root, -1) ? printf("  Tree has -1\n") : printf("  Tree doesn't have -1\n");
	avlSearch(root, 75) ? printf("  Tree has 75\n") : printf("  Tree doesn't have 75\n");
	avlSearch(root, 101) ? printf("  Tree has 101\n") : printf("  Tree doesn't have 101\n");
	/* testing avlDelete */
	test1(&root);
	printf("avlDelete test: \n");
	printf("----- Original -----\n");
	avlPrettyPrint(root, 0);
	printf("-----\n");
	for (i = 0; i < 20; i++) {
		printf("  After Deleting %i:\n", arr[i]);
		avlDelete(&root, arr[i]);
		avlPrettyPrint(root, 0);
		printf("-----\n");
	}

	avlClear(&root);
	printf("\n");
	return 0;
}
