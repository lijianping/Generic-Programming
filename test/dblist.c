#include "../src/double_linked_list/double_linked_list.h"
#include <stdio.h>

int main() {
	int i, arr[] = {1, 2, 3, 4, 5};
	DbList dblist;
	DbListNew(&dblist, sizeof(int));
	for (i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		DbListAdd(&dblist, &arr[i]);
	}
	if (DbListEmpty(&dblist)) {
		printf("The double linked list is empty\n");
	} else {
		i = DbListLength(&dblist);
		printf("The double linked list length is %d\n", i);
	}
	DbListInsert(&dblist, 0, &arr[0]);
	DbListFree(&dblist);
	return 0;
}

