#include "../src/my_set/my_set.h"
#include <stdio.h>

#define MaxSize 100
void Display(SgList *list);
int Compare(void *a, void *b);

int main() {
	int i, count, tmp;
	int arr[] = {5, 4, 3, 2, 1, 2, 6};
	int arr1[] = {1, 2, 7, 8, 19, 4};
	SgList sglist, sglist1, sglist2, sglist3, sglist4;
	i = count = 0;
	SgListNew(&sglist, sizeof(int));
	SgListNew(&sglist1, sizeof(int));
	SgListNew(&sglist2, sizeof(int));
	while (i < sizeof(arr) / sizeof(int)) {
		SgListAdd(&sglist, &arr[i]);
		++i;
	}
	i = 0;
	while (i < sizeof(arr1) / sizeof(int)) {
		SgListAdd(&sglist1, &arr1[i]);
		++i;
	}
	printf("After Initialize:\n");
	printf("list 1:\n");
	Display(&sglist);
	printf("list 1:\n");
	Display(&sglist1);
	
	SgListUnion(&sglist, &sglist1, &sglist2);
	printf("list 1 and list 2 union:\n");
	SgListSort(&sglist2, Compare);
	Display(&sglist2);

	SgListIntersection(&sglist, &sglist1, &sglist2);
	printf("list 1 and list 2 intersection: \n");
	SgListSort(&sglist2, Compare);
	Display(&sglist2);

	SgListComplements(&sglist, &sglist1, &sglist2);
	printf("list 1 and list 2 complements: \n");
	SgListSort(&sglist2, Compare);
	Display(&sglist2);

	SgListFree(&sglist);
	SgListFree(&sglist1);
	SgListFree(&sglist2);
	return 0;
}

void Display(SgList *list) {
	int len , i, *data;
	len = SgListLength(list);
	for (i = 0; i < len; ) {
		data = SgListGetElem(list, i);
		if (data) {
			printf("%d ", *(int *)data);
		}
		if (++i % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

int Compare(void *p1, void *p2) {
	return *(int *)p1 - *(int *)p2;
}
