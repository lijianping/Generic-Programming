#include "../src/double_linked_list/double_linked_list.h"
#include <stdio.h>
#include <assert.h>

void Display(DbList *dblist);

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
	Display(&dblist);
	DbListInsert(&dblist, 0, &arr[0]);
	Display(&dblist);
	i = DbListLength(&dblist);
	printf("The double linked list length is %d\n", i);
	DbListDelete(&dblist, 1);
	Display(&dblist);
	i = DbListLength(&dblist);
	printf("The double linked list length is %d\n", i);
	DbListFree(&dblist);
	return 0;
}

void Display(DbList *dblist) {
	int len = 0, i, elem;
	len = DbListLength(dblist);
	for (i = 0; i < len; ++i) {
		assert(1 == DbListGetElem(dblist, i, &elem));
		printf("%d ", elem);
	}
	printf("\n");
}
