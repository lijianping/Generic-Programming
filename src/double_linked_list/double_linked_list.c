#include "double_linked_list.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define NodeSize(size) ((size) + 2 * sizeof(int *))
#define PreSize(size) ((size))
#define NextSize(size) ((size) + sizeof(int *))

void DbListNew(DbList *dblist, int elem_size) {
	int *tmp = 0;
	assert(dblist != 0);
	dblist->elem_size = elem_size;
	tmp = (int *)malloc(NodeSize(dblist->elem_size));
	assert(tmp != 0);
	memset(tmp, 0, NodeSize(dblist->elem_size));
	dblist->elem = tmp;
}

void DbListFree(DbList *dblist) {
	int *tmp = 0, *curr = 0;
	assert(dblist != 0);
	tmp = (int *)((char *)dblist->elem + NextSize(dblist->elem_size));
	while (*tmp) {
		curr = tmp;
		tmp = (int *)((char *)(*tmp) + NextSize(dblist->elem_size));
		free((int *)(*curr));
		printf("-");
	}
	free(dblist->elem);
	printf("-\n");
}

void DbListAdd(DbList *dblist, void *elem_addr) {
	int *curr = 0, *last = 0, *pre = 0;
	assert(dblist != 0);
	curr = (int *)malloc(NodeSize(dblist->elem_size));
	assert(curr != 0);
	memset(curr, 0, NodeSize(dblist->elem_size));
	memcpy(curr, elem_addr, dblist->elem_size);
	last = (int *)((char *)dblist->elem + NextSize(dblist->elem_size));
	pre = dblist->elem;
	while (*last) {
		pre = (int *)(*last);
		last = (int *)((char *)(*last) + NextSize(dblist->elem_size));
	}
	*last = (int)curr;
	curr = (int *)((char *)(*last) + PreSize(dblist->elem_size));
	*curr = (int)pre;
}

int DbListLength(DbList *dblist) {
	int len = 0, *tmp = 0;
	assert(dblist != 0);
	tmp = (int *)((char *)dblist->elem + NextSize(dblist->elem_size));
	while (*tmp) {
		++len;
		tmp = (int *)((char *)(*tmp) + NextSize(dblist->elem_size));
	}
	return len;
}

int DbListEmpty(DbList *dblist) {
	int *tmp;
	tmp = (int *)((char *)(dblist->elem) + NextSize(dblist->elem_size));
	if (*tmp) return 0;
	return 1;
}

void DbListInsert(DbList *dblist, int pos, void *elem_addr) {
	int *insert = 0, *pre = 0, *curr = 0, *target = 0;
	int i = 0;
	assert(dblist != 0);
	target = (int *)malloc(NodeSize(dblist->elem_size));
	assert(target != 0);
	memset(target, 0, NodeSize(dblist->elem_size));
	memcpy(target, elem_addr, dblist->elem_size);
	insert = (int *)((char *)dblist->elem + NextSize(dblist->elem_size));
	pre = dblist->elem;
	while(*insert && i < pos) {
		++i;
		pre = (int *)(*insert);
		insert = (int *)((char *)(*insert) + dblist->elem_size);
	}
	if (*insert == 0) {
		*insert = (int)target;
		curr = (int *)((char *)target + PreSize(dblist->elem_size));
		*curr = (int)pre;
	} else {
		// move the pointer to the prior pointer
		curr = (int *)((char *)target + PreSize(dblist->elem_size));
		*curr = (int)pre;
		curr++;  // move the pointer to the next pointer
		*curr = *insert;
		*insert = (int)target;
		curr = (int *)((char *)(*curr) + PreSize(dblist->elem_size));
		*curr = (int)target;
	}
}
