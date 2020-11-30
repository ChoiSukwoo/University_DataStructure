#pragma once
#include <stdio.h>
#include "week12.h"

#include <stdlib.h>

ListNode2* LinkList2::insertFirst(ListNode2* head, int value) {
	ListNode2* p = (ListNode2*)malloc(sizeof(ListNode2));
	p->data = value;
	p->link = head;
	head = p;

	return head;
}

ListNode2* LinkList2::insertNode(ListNode2* head, int Pos, int value) {
	printf("%d��° ��忡 %d���� �õ� \n", Pos, value);

	if (Pos == 0) {//0����ġ ������ insertFirst �̿�
		head = insertFirst(head, value);
	}
	else {
		ListNode2* p = (ListNode2*)malloc(sizeof(ListNode2));
		ListNode2* pre = findNode(head, Pos);
		if (pre != NULL) {
			p->data = value;
			p->link = pre->link;
			pre->link = p;
		}
		else
		{
		}
	}

	printList(head);
	return head;
}

ListNode2* LinkList2::deleteFirst(ListNode2* head) {

	ListNode2* remove;
	if (head == NULL) {
		return NULL;
	}
	remove = head;
	head = remove->link;
	free(remove);

	return head;
}

ListNode2* LinkList2::deleteNode(ListNode2* head, int Pos) {

	printf("%d��° ��� ���� �õ� \n", Pos);

	if (Pos == 0) {//0����ġ ������ deleteFirst �̿�
		head = deleteFirst(head);
	}
	else {
		ListNode2* remove;
		ListNode2* pre = findNode(head, Pos);
		if (pre != NULL && pre->link != NULL) {
			remove = pre->link;
			pre->link = remove->link;
			free(remove);
		}
		else
		{
			printf("�ش� ����Ʈ�� ũ�⺸�� ū���� �Է��޽��ϴ�.\n");
		}
	}

	printList(head);
	return head;
}


void LinkList2::printList(ListNode2* head) {
	ListNode2* p = head;
	for (p; p->link != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("%d \n\n", p->data);
}

ListNode2* LinkList2::findNode(ListNode2* head, int Pos) {
	ListNode2* NodeP = head;
	ListNode2* NodePre = head;
	int check = 0;
	while (NodeP != NULL) {//�迭ũ�� ��ŭ Ȯ��
		if (Pos == check) {//��ġ�� ��ġ�ϸ� �ڱ� �ճ�� ��ȯ
			return NodePre;
		}
		else//��ȯ ���ǿ� ���� ������ �������� ��ü
		{
			NodePre = NodeP;
			NodeP = NodeP->link;
		}
		check++;
	}
	if (check >= Pos) {
		return NodePre;
	}
	else
	{
		//while���� ��ȯ�� �ȵ����� �ش� �迭���� ū���� �Է¹��� ����̴�.
		printf("�ش� ����Ʈ�� ũ��� %d�Դϴ�. %d �� �Է¹����� �����ϴ�.\n", check, Pos);
		return NULL;
	}

}


void LinkList2::DeletAllNode(ListNode2* head) {
	while (head != NULL)
	{
		ListNode2* p = head;
		head = head->link;
		free(p);
	}
}



void LinkList2::Run() {

	printf("\n\n-----------------LinkList TEST----------------\n\n");

	ListNode2* head = NULL;
	printf("������ \n");
	head = insertNode(head, 0, 0);

	printf("0��° ��� �߰� \n");
	head = insertNode(head, 0, 1);

	printf("���Ĺ� ��� �߰� \n");
	head = insertNode(head, 2, 2);

	printf("�߰� ��� �߰� \n");
	head = insertNode(head, 1, 3);

	printf("������ 0��° ��� �߰�(�ȵǴ°� ����) \n");
	head = insertNode(head, 5, 8);

	printf("�ƿ� ������ ��� �߰�(�ȵǴ°� ����) \n");
	head = insertNode(head, 6, 8);

	printf("0��° ��� ���� \n");
	head = deleteNode(head, 0);


	printf("�߰� ��� ���� \n");
	head = deleteNode(head, 1);

	printf("���Ĺ� ��� ���� \n");
	head = deleteNode(head, 1);

	printf("������ 0��° ��� ����(�ȵǴ°� ����) \n");
	head = deleteNode(head, 1);

	printf("�ƿ� ������ ��� ����(�ȵǴ°� ����) \n");
	head = deleteNode(head, 4);

	printf("------------------��� ��带 �����մϴ�.----------------------\n\n");
	DeletAllNode(head);

	printf("------------------���ο� ��带 �����մϴ�.---------------------\n\n");
	head = NULL;
	int position = 0;
	int user_data = 0;
	int key = 0;
	while (1) {

		printf("0 : ��� �߰� |  1 : ��� ���� |  2 : ���� \n");
		scanf_s("%d", &key);

		switch (key)
		{
		case 0:
			printf("��带 �߰��մϴ� �ű� �߰��� ��ġ�� ���° �ΰ���? : ");
			scanf_s("%d", &position);
			printf("�ű� �߰��� ����Ÿ�� ������?(����) : ");
			scanf_s("%d", &user_data);
			head = insertNode(head, position, user_data);
			break;
		case 1:
			printf("��带 �����մϴ� ������ ����� ��ġ�� ���° �ΰ���? : ");
			scanf_s("%d", &position);
			head = deleteNode(head, position);
			break;
		case 2:
			return;
		default:
			printf("�ٽ� �Է��Ͻÿ�\n");
			break;
		}

	}
}
