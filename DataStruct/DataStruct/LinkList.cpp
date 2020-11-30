#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

	ListNode* LinkList::insertFirst(ListNode* head, int value) {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = head;
		head = p;
		return head;
	}

	ListNode* LinkList::insertNode(ListNode* head, ListNode* pre, int value) {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = pre->link;
		pre->link = p;
		return head;
	}

	ListNode* LinkList::deleteFirst(ListNode* head) {

		ListNode* remove;
		if (head == NULL) {
			return NULL;
		}
		remove = head;
		head = remove->link;
		free(remove);
		return head;
	}

	ListNode* LinkList::deleteNode(ListNode* head, ListNode* pre) {

		ListNode* remove;
		remove = pre->link;
		pre->link = remove->link;
		free(remove);
		return head;
	}


	void LinkList::printList(ListNode* head) {
		for (ListNode* p = head; p != NULL; p = p->link) {
			printf("%d-> ", p->data);
		}
		printf("\n");

	}

	void LinkList::Run() {

		printf("\n\n-----------------LinkList----------------\n\n");

		ListNode* head = NULL;
		for (int i = 0; i < 5; i++)
		{
			head = insertFirst(head, i);
			printList(head);
		}


		for (int i = 0; i < 5; i++)
		{
			head = deleteFirst(head);
			printList(head);
		}
	}
