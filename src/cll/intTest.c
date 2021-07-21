#include "cll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int arr[20] = {46, 22, 73, 36, 29, 52, 50, 84, 87, 76, 6, 68, 100, 56, 52, 78, 90, 6, 78, 26};

	/* generate linked list */
	struct cllNode *head = NULL;

	/* test cllAddFirst */	
	printf("\n----- cllAddFirst Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) cllAddFirst(&head, i);
	cllPrint(&head);
	cllClear(&head);

	/* test cllAddFirst */	
	printf("\n----- cllAddLast Test: -----\nTest - Adding 10 Elements:\n\t");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	cllPrint(&head);

	/* test cllClear */
	printf("\n----- cllClear: -----\n");
	cllClear(&head);
	printf("Test - Clearing list of length 10... success\n");
	cllClear(&head);
	printf("Test - Clearing empty list... success\n");

	/* test cllContains */
	printf("\n----- cllContains Test:-----\nTest - Empty list {}:\n");
	cllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);

	printf("\nTest - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	for (i = 0; i < 11; i++) {
		cllContains(&head, i) ? printf("\tList contains %i.\n", i) : printf("\tList doesn't contain %i.\n",i);
	}

	/* test cllPrint */
	printf("\n----- cllPrint Test: -----\n");
	printf("Test - List of length 10:\n\t");
	cllPrint(&head);
	cllClear(&head);

	printf("Test - List of length 1:\n\t");
	cllAddFirst(&head, 25);
	cllPrint(&head);
	cllClear(&head);

	printf("Test - Empty list:\n\t");
	cllPrint(&head);

	/* test cllRemove */
	printf("\n----- cllRemove Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) cllAddLast(&head, i);
	printf("\tRemoving first element(0)...\t\t");
	cllRemove(&head, 0);
	cllPrint(&head);
	
	printf("\tRemoving middle element(2)...\t\t");
	cllRemove(&head, 2);
	cllPrint(&head);

	printf("\tRemoving last element(4)...\t\t");
	cllRemove(&head, 4);
	cllPrint(&head);

	printf("\tRemoving element(1)...\t\t\t");
	cllRemove(&head, 1);
	cllPrint(&head);

	printf("\tRemoving non-existent element(6)...\t");
	cllRemove(&head, 6);
	cllPrint(&head);

	printf("\tRemoving element(3) to empty list...\t");
	cllRemove(&head, 3);
	cllPrint(&head);

	printf("Test - Empty list {}:\n\tRemoving non-existent element...\t");
	cllRemove(&head, 0);
	cllPrint(&head);

	/* test cllRemoveFirst */
	printf("\n----- cllRemoveFirst Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) cllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		cllRemoveFirst(&head);
		printf("\t");
		cllPrint(&head);
	}
	cllClear(&head);

	printf("Test - Empty list {}:\n");
	cllRemoveFirst(&head);
	printf("\t");
	cllPrint(&head);

	/* test cllRemoveLasst */
	printf("\n----- cllRemoveLast Test: -----\n");
	printf("Test - List of length 5 {0, 1, 2, 3, 4}:\n");
	for (i = 0; i < 5; i++) cllAddLast(&head, i);
	for (i = 0; i < 5; i++) {
		cllRemoveLast(&head);
		printf("\t");
		cllPrint(&head);
	}
	cllClear(&head);

	printf("Test - Empty list {}:\n");
	cllRemoveLast(&head);
	printf("\t");
	cllPrint(&head);

	/* test cllSize */
	printf("\n----- cllSize Test: -----\n");
	printf("Test - Empty list {}:\n");
	printf("\tSize: %i\n", cllSize(&head));

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	printf("\tSize: %i\n", cllSize(&head));
	cllClear(&head);

	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	printf("\tSize: %i\n", cllSize(&head));

	/* test cllFlip */
	printf("\n----- cllFlip Test: -----\n");
	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	cllFlip(&head);
	printf("\t");
	cllPrint(&head);
	cllClear(&head);

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	printf("\t");
	cllClear(&head);

	printf("Test - Empty list {}:\n");
	cllFlip(&head);
	printf("\t");
	cllPrint(&head);

	/* test cllSortQS */
	printf("\n----- cllSortQS Test: -----\n");
	printf("Test - Empty list {}:\n");
	cllSortQS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	cllSortQS(&head);
	printf("\t");
	cllPrint(&head);
	cllClear(&head);

	printf("Test - Already sorted list of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	cllSortQS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - Reverse-sorted list of length 10 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}:\n");
	cllClear(&head);
	for (i = 0; i < 10; i++) cllAddFirst(&head, i);
	cllSortQS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - Random list of length 20: ");
	cllClear(&head);
	for (i = 0; i < 20; i++) cllAddLast(&head, arr[i]);
	cllPrint(&head);
	cllSortQS(&head);
	printf("\t");
	cllPrint(&head);

	/* test cllSortMS */
	printf("\n----- cllSortMS Test: -----\n");
	printf("Test - Empty list {}:\n");
	cllClear(&head);
	cllSortMS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	cllSortMS(&head);
	printf("\t");
	cllPrint(&head);
	cllClear(&head);

	printf("Test - Already sorted list of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	cllSortMS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - Reverse-sorted list of length 10 {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}:\n");
	cllClear(&head);
	for (i = 0; i < 10; i++) cllAddFirst(&head, i);
	cllSortMS(&head);
	printf("\t");
	cllPrint(&head);

	printf("Test - Random list of length 20: ");
	cllClear(&head);
	for (i = 0; i < 20; i++) cllAddLast(&head, arr[i]);
	cllPrint(&head);
	cllSortMS(&head);
	printf("\t");
	cllPrint(&head);
	printf("\tRandom Test of sllFlip: ");
	cllFlip(&head);
	cllPrint(&head);

	/* test cllIndexOf */
	printf("\n----- cllSortIndexOf Test: -----\n");
	printf("Test - Empty list {}:\n");
	cllClear(&head);
	printf("\tIndex of 1 is: %i\n", cllIndexOf(&head, 1));

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	printf("\tIndex of 25 is: %i\n", cllIndexOf(&head, 25));
	printf("\tIndex of 1 is: %i\n", cllIndexOf(&head, 1));
	cllClear(&head);

	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	printf("\tIndex of 0 is: %i\n", cllIndexOf(&head, 0));
	printf("\tIndex of 5 is: %i\n", cllIndexOf(&head, 5));
	printf("\tIndex of 9 is: %i\n", cllIndexOf(&head, 9));
	printf("\tIndex of 10 is: %i\n", cllIndexOf(&head, 10));

	/* test cllPeekFirst & cllPeekLast */
	printf("\n----- cllPeekFirst & cllPeekLast Test: -----\n");
	printf("Test - Empty list {}:\n");
	cllClear(&head);
	printf("\tFirst element: %i\n\tLast element: %i\n", cllPeekFirst(&head), cllPeekLast(&head));

	printf("Test - List of length 1 {25}:\n");
	cllAddFirst(&head, 25);
	printf("\tFirst element: %i\n\tLast element: %i\n", cllPeekFirst(&head), cllPeekLast(&head));
	cllClear(&head);
	
	printf("Test - List of length 10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}:\n");
	for (i = 0; i < 10; i++) cllAddLast(&head, i);
	printf("\tFirst element: %i\n\tLast element: %i\n", cllPeekFirst(&head), cllPeekLast(&head));

	printf("\n");
	cllClear(&head);

	return 0;
}


