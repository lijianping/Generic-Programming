#include "loop_single_list.h"
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define NodeSize(size) ((size) + sizeof(int *))

void LSgListNew(LSgList *lsglist, int elem_size) {
	int *tmp = 0;
	assert(lsglist != 0);
	lsglist->elem_size = elem_size;
	lsglist->elem = (int *)malloc(NodeSize(lsglist->elem_size));
	assert(lsglist->elem != 0);
	memset(lsglist->elem, 0, NodeSize(lsglist->elem_size));
	tmp = (int *)((char *)lsglist->elem + lsglist->elem_size);
	*tmp = (int)lsglist->elem;
}

void LSgListFree(LSgList *lsglist) {
	int *curr = 0, *tmp = 0;
	// move the pointer to the head node's next pointer field
	tmp = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*tmp != (int)lsglist->elem) {
		// store the next node pointer
		curr = tmp;
		tmp = (int *)((char *)*tmp + lsglist->elem_size);
		// free the current node
		free((int *)*curr);
		printf("-");
	}
	// free the head node 
	free(lsglist->elem);
	printf("-\n");
}

void LSgListAdd(LSgList *lsglist, void *elem_addr) {
	int *last = 0, *target = 0, *tmp = 0;
	assert(lsglist != 0 && elem_addr != 0);
	// allocate the memory and assign
	target = (int *)malloc(NodeSize(lsglist->elem_size));
	assert(target != 0);
	memset(target, 0, NodeSize(lsglist->elem_size));
	memcpy(target, elem_addr, lsglist->elem_size);
	// add the element at the end of the list
	// find the last node
	last = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*last != (int)lsglist->elem) {
		// move the pointer to the next node
		last = (int *)((char *)*last + lsglist->elem_size);
	}
	// set the target's next point to the head 
	tmp = (int *)((char *)target + lsglist->elem_size);
	*tmp = *last;
	// set the last pointer point to the new element
	*last = (int)target;
}

int LSgListLength(LSgList *lsglist) {
	int *tmp = 0, len = 0;
	tmp = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*tmp != (int)lsglist->elem) {
		++len;
		tmp = (int *)((char *)*tmp + lsglist->elem_size);
	}
	return len;
}

int LSgListEmpty(LSgList *lsglist) {
	int *tmp = 0;
	assert(lsglist != 0);
	tmp = (int *)((char *)lsglist->elem + lsglist->elem_size);
	if (*tmp != (int)lsglist->elem) return 0;
	return 1;
}

void LSgListInsert(LSgList *lsglist, int pos, void *elem_addr) {
	int *insert = 0, *curr = 0, *target = 0, i = 0;
	assert(lsglist != 0 && elem_addr != 0);
	target = (int *)malloc(NodeSize(lsglist->elem_size));
	assert(target != 0);
	memset(target, 0, NodeSize(lsglist->elem_size));
	memcpy(target, elem_addr, lsglist->elem_size);
	insert = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*insert != (int)lsglist->elem && i < pos) {
		++i;
		insert = (int *)((char *)*insert + lsglist->elem_size);
	}
	curr = (int *)((char *)target + lsglist->elem_size);
	*curr = *insert;
	*insert = (int)target;
}

void LSgListDelete(LSgList *lsglist, int pos) {
	int *del = 0, *next = 0, *tmp = 0, i = 0;
	assert(lsglist != 0 && pos >= 0);
	del = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*del != (int)lsglist->elem && i < pos) {
		++i;
		del = (int *)((char *)*del + lsglist->elem_size);
	}
	if (*del != (int)lsglist->elem) {
		next = (int *)((char *)*del + lsglist->elem_size);
		tmp = (int *)*del;
		*del = *next;
		free(tmp);
	}
}

int LSgListGetElem(LSgList *lsglist, int pos, void *elem_addr) {
	int *curr = 0, i = 0;
	assert(lsglist != 0 && elem_addr != 0);
	assert(pos >= 0);
	curr = (int *)((char *)lsglist->elem + lsglist->elem_size);
	while (*curr != (int)lsglist->elem && i < pos) {
		++i;
		curr = (int *)((char *)*curr + lsglist->elem_size);
	}
	if (*curr != (int)lsglist->elem) {
		memcpy(elem_addr, (int *)*curr, lsglist->elem_size);
		return 1;
	}
	return 0;
}
