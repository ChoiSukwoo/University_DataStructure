#include "CircleList.h"
#include <stdio.h>
#include <stdlib.h>



circleListNode* circleList::insertNode(circleListNode* head, int value) {
	circleListNode* p = (circleListNode*)malloc(sizeof(circleListNode));
	p->dataBox = value;

	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else
	{
		circleListNode* pre = (circleListNode*)malloc(sizeof(circleListNode));

		pre = head;
		while (pre->link!=head)
		{
			pre = pre->link;
		}
		pre->link = p;
		p->link = head;
	}
	return head;
}


circleListNode* circleList::deleteNode(circleListNode* head) {
	if (head->link == head) {
		free(head);
		head = NULL;
	}
	else
	{
		//전전 노드
		circleListNode* pre = (circleListNode*)malloc(sizeof(circleListNode));
		circleListNode* remove;

		pre = head;
		while (pre->link->link != head)
		{
			pre = pre->link;
		}
		remove = pre->link;
		pre->link = head;
		free(remove);
	}
	return head;
}


void circleList::printList(circleListNode* head) {
	if (head != NULL) {
		circleListNode* p = head;
		while (p->link != head) {
			printf("%d-> ", p->dataBox);
			p = p->link;
		}
		printf("%d \n\n", p->dataBox);
	}
}

void circleList::Run() {

	printf("\n\n-----------------circleList----------------\n\n");

	circleListNode* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		head = insertNode(head, i*10);
		printList(head);
	}


	for (int i = 0; i < 5; i++)
	{
		head = deleteNode(head);
		printList(head);
	}
}
