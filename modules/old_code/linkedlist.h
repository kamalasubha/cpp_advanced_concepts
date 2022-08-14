// linkedlist.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
	int data;
	struct Node* next;
};

void display(struct Node* temp);

#endif
