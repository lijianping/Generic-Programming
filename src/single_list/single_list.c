#include "single_list.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

#define NodeSize(size) ((size) + sizeof(int *))

void SgListNew(SgList *sglist, int elem_size) {
	assert(sglist != 0);
    // set the elemenet size
	sglist->elem_size = elem_size;      
    // allocate the memory for the list header
	sglist->elem = malloc(NodeSize(sglist->elem_size)); 
	memset(sglist->elem, 0, NodeSize(sglist->elem_size));  
}

void SgListAdd(SgList *sglist, void *elem_addr) {
	int *target, *last;
	assert(sglist != 0);
	// allocate memory and store the data
	target = malloc(sglist->elem_size + sizeof(int *));
	memset(target, 0, NodeSize(sglist->elem_size));
	memcpy(target, elem_addr, sglist->elem_size);
	// find the last node
	last = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*last) {
		last = (int *)((char *)(*last) + sglist->elem_size);
	}
	*last = (int)target;
}

void SgListFree(SgList *sglist) {
	int *curr, *next;
	assert(sglist != 0);
	// Get the first element and free memory after it.
	curr = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*curr) {
		next = (int *)((char *)(*curr) + sglist->elem_size);
		free((int *)*curr);
		curr = next;
	}
	// free the list header
	free(sglist->elem);
}

int SgListEmpty(SgList *sglist) {
	int *last;
	assert(sglist != 0);
	last = (int *)((char *)sglist->elem + sglist->elem_size);
	if (*last) return 0;
	return 1;
}

int SgListLength(SgList *sglist) {
	int *last, len = 0;
	assert(sglist != 0);
	last = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*last) {
		++len;
		last = (int *)((char *)(*last) + sglist->elem_size);
	}
	return len;
}

void SgListInsert(SgList *sglist, int pos, void *elem_addr) {
	int *insert, *curr, *target;
	int i = 0;
	assert(sglist != 0);
	target = malloc(NodeSize(sglist->elem_size));
	assert(target != 0);
	memset(target, 0, NodeSize(sglist->elem_size));
	memcpy(target, elem_addr, sglist->elem_size);
	insert = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*insert && i < pos) {
		++i;
		insert = (int *)((char *)(*insert) + sglist->elem_size);
	}
	if (*insert == 0) {
		*insert = (int)target;
	} else {
       	curr = (int *)((char *)target + sglist->elem_size);
	    *curr = *insert;
	    *insert = (int)target;
	}
}

void SgListDelete(SgList *sglist, int pos) {
	int *del, *next, *tmp;
	int i = 0;
	assert(sglist != 0);
	assert(pos >= 0);
    del = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*del && i < pos) {
		++i;
		del = (int *)((char *)(*del) + sglist->elem_size);
	}
	if (*del) {
		tmp = (int *)*del;
		next = (int *)((char *)(*del) + sglist->elem_size);
		*del = *next;
		free(tmp);
	}
}

int SgListGetElem(SgList *sglist, int pos, void *elem_addr) {
	int *curr, i = 0;
	assert(sglist->elem != 0 && elem_addr != 0);
	assert(pos >= 0);
	curr = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*curr && i < pos) {
		++i;
		curr = (int *)((char *)(*curr) + sglist->elem_size);
	}
	if (*curr) {
		memcpy(elem_addr, (int *)*curr, sglist->elem_size);
		return 1;
	}
	return 0;
}

int SgListFindElem(SgList *sglist, void *elem_addr) {
	int *curr, i = 0;
	assert(sglist->elem != 0 && elem_addr != 0);
	curr = (int *)((char *)sglist->elem + sglist->elem_size);
	while (*curr && memcmp(elem_addr, (int *)*curr, sglist->elem_size) != 0) {
		++i;
		curr = (int *)((char *)(*curr) + sglist->elem_size);
	}
	if (*curr) {
		return i;
	}
	return -1;
}