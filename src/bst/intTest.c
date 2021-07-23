#include "bst.h"
#include "treeTest.h"
#include <stdio.h>

int main() {

	int i, arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};
	struct bstNode *root = NULL;

	/* Testing
	 * bstClear
	 * bstInsert
	 * bstPrettyPrint
	 * bstPrint
	 * bstSize
	 * bstHeight
	 * bstMin
	 * bstMax
	 * bstMinGE
	 * bstMaxLE
	 * bstPredecessor
	 * bstSuccessor
	 * bstCountRange
	 * bstCountGE
	 * bstCountLE
	 * on different types of trees
	 */
	leftSkew(&root), pInfo(root);

	rightSkew(&root), pInfo(root);

	rootOnly(&root), pInfo(root);

	random(&root), pInfo(root);

	test1(&root), pInfo(root);

	/* testing bstSearch */
	test1(&root);
	printf("bstSearch test: \n");
	for (i = 0; i < 20; i++) {
		bstSearch(root, arr[i]) ? printf("  Tree has %i\n", arr[i]) : printf("  Tree doesn't have %i\n", arr[i]);
	}
	bstSearch(root, -1) ? printf("  Tree has -1\n") : printf("  Tree doesn't have -1\n");
	bstSearch(root, 75) ? printf("  Tree has 75\n") : printf("  Tree doesn't have 75\n");
	bstSearch(root, 101) ? printf("  Tree has 101\n") : printf("  Tree doesn't have 101\n");
	/* testing bstDelete */
	test1(&root);
	printf("bstDelete test: \n");
	printf("----- Original -----\n");
	bstPrettyPrint(root, 0);
	printf("-----\n");
	for (i = 0; i < 20; i++) {
		printf("  After Deleting %i:\n", arr[i]);
		bstDelete(&root, arr[i]);
		bstPrettyPrint(root, 0);
		printf("-----\n");
	}

	bstClear(&root);
	printf("\n");
	return 0;
}
