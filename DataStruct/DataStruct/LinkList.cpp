#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

	DataNodeType* LinkList::insertFirst(DataNodeType* head, int value) {
		DataNodeType* p = (DataNodeType*)malloc(sizeof(DataNodeType));
		p->dataBox = value;
		p->link = head;
		head = p;
		return head;
	}

	DataNodeType* LinkList::insertNode(DataNodeType* head, DataNodeType* pre, int value) {
		DataNodeType* p = (DataNodeType*)malloc(sizeof(DataNodeType));
		p->dataBox = value;
		p->link = pre->link;
		pre->link = p;
		return head;
	}

	DataNodeType* LinkList::deleteFirst(DataNodeType* head) {

		DataNodeType* remove;
		if (head == NULL) {
			return NULL;
		}
		remove = head;
		head = remove->link;
		free(remove);
		return head;
	}

	DataNodeType* LinkList::deleteNode(DataNodeType* head, DataNodeType* pre) {

		DataNodeType* remove;
		remove = pre->link;
		pre->link = remove->link;
		free(remove);
		return head;
	}


	void LinkList::printList(DataNodeType* head) {
		if (head != NULL) {
			DataNodeType* p = head;
			for (p; p->link != NULL; p = p->link) {
				printf("%d-> ", p->dataBox);
			}
			printf("%d \n\n", p->dataBox);
		}
	}

	void LinkList::Run() {

		printf("\n\n-----------------LinkList----------------\n\n");

		DataNodeType* head = NULL;
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
