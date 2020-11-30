#pragma once
#ifndef WEEK12_H
#define WEEK12_H

typedef struct ListNode2 {
	int data;
	struct ListNode2* link;
}ListNode2;

class LinkList2 {
public:

	ListNode2* insertFirst(ListNode2* head, int value);
	ListNode2* insertNode(ListNode2* head, int Pos, int value);
	ListNode2* deleteFirst(ListNode2* head);
	ListNode2* deleteNode(ListNode2* head, int Pos);
	void printList(ListNode2* head);
	ListNode2* findNode(ListNode2* head, int Pos);
	void DeletAllNode(ListNode2* head);
	void Run();
};

#endif // !WEEK12_H