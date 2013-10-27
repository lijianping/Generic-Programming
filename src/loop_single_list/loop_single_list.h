#ifndef __LOOP_SINGLE_LIST_H_
#define __LOOP_SINGLE_LIST_H_

typedef struct LSgList {
	int elem_size;
	int *elem;
} LSgList;

void LSgListNew(LSgList *lsglist, int elem_size);

void LSgListFree(LSgList *lsglist);

void LSgListAdd(LSgList *lsglist, void *elem_addr);

int LSgListLength(LSgList *lsglist);

int LSgListEmpty(LSgList *lsglist);

#endif
