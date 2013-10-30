#include <stdio.h>
#include "../src/single_list/single_list.h"

typedef char ElemType;
void Display(SgList *sglist);
int CharCmp(void *a, void *b);

int main() {
	ElemType num;
	SgList sglist;
	int i = 0;
	char test[] = {
		'a', 'b', 'h', 'k', 'e'
	};

	SgListNew(&sglist, sizeof(int));
	 
	while (i < sizeof(test) / sizeof(char)) {
		SgListAdd(&sglist, &test[i++]);
	}
	Display(&sglist);
	if (SgListEmpty(&sglist)) {
		printf("The single list is empty!\n");
	} else {
		printf("The single is not empty!\n");
		printf("The length of the single list is %d\n", 
			   SgListLength(&sglist));
	}

	SgListDelete(&sglist, 0);
	Display(&sglist);
    printf("The length of the single list is %d\n", 
		   SgListLength(&sglist));
	i = SgListFindElem(&sglist, &test[2]);
	printf("%d\n", i);
	SgListSort(&sglist, CharCmp);
	Display(&sglist);
	SgListFree(&sglist);
	return 0;
}

void Display(SgList *sglist) {
	ElemType tmp;
	int i, len;
	len = SgListLength(sglist);
	for (i = 0; i < len; ++i) {
		SgListGetElem(sglist, i, &tmp);
		printf("%c ", tmp);
	}
	printf("\n");
}

int CharCmp(void *a, void *b) {
	return *(char *)a - *(char *)b;
}
