#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct listNode {
	int data;
	struct listNode* link;
}ListNode;

class LinkList {
public:

	ListNode* insertFirst(ListNode* head, int value);
	ListNode* insertNode(ListNode* head, ListNode* pre, int value);
	ListNode* deleteFirst(ListNode* head);
	ListNode* deleteNode(ListNode* head, ListNode* pre);
	void printList(ListNode* head);

	void Run();
};

#endif // !LINKLIST_H