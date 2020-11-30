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
	printf("%d번째 노드에 %d삽입 시도 \n", Pos, value);

	if (Pos == 0) {//0번위치 삭제는 insertFirst 이용
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

	printf("%d번째 노드 제거 시도 \n", Pos);

	if (Pos == 0) {//0번위치 삭제는 deleteFirst 이용
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
			printf("해당 리스트의 크기보다 큰값을 입력햇습니다.\n");
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
	while (NodeP != NULL) {//배열크기 만큼 확인
		if (Pos == check) {//위치가 일치하면 자기 앞노드 반환
			return NodePre;
		}
		else//반환 조건에 맞지 않으면 다음노드로 교체
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
		//while에서 반환이 안됫으면 해당 배열보다 큰값을 입력받은 경우이다.
		printf("해당 리스트의 크기는 %d입니다. %d 는 입력받을수 없습니다.\n", check, Pos);
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
	printf("노드생성 \n");
	head = insertNode(head, 0, 0);

	printf("0번째 노드 추가 \n");
	head = insertNode(head, 0, 1);

	printf("최후방 노드 추가 \n");
	head = insertNode(head, 2, 2);

	printf("중간 노드 추가 \n");
	head = insertNode(head, 1, 3);

	printf("범위밖 0번째 노드 추가(안되는게 정상) \n");
	head = insertNode(head, 5, 8);

	printf("아예 범위밖 노드 추가(안되는게 정상) \n");
	head = insertNode(head, 6, 8);

	printf("0번째 노드 삭제 \n");
	head = deleteNode(head, 0);


	printf("중간 노드 삭제 \n");
	head = deleteNode(head, 1);

	printf("최후방 노드 삭제 \n");
	head = deleteNode(head, 1);

	printf("범위밖 0번째 노드 삭제(안되는게 정상) \n");
	head = deleteNode(head, 1);

	printf("아예 범위밖 노드 삭제(안되는게 정상) \n");
	head = deleteNode(head, 4);

	printf("------------------모든 노드를 삭제합니다.----------------------\n\n");
	DeletAllNode(head);

	printf("------------------새로운 노드를 생성합니다.---------------------\n\n");
	head = NULL;
	int position = 0;
	int user_data = 0;
	int key = 0;
	while (1) {

		printf("0 : 노드 추가 |  1 : 노드 제거 |  2 : 종료 \n");
		scanf_s("%d", &key);

		switch (key)
		{
		case 0:
			printf("노드를 추가합니다 신규 추가할 위치가 몇번째 인가요? : ");
			scanf_s("%d", &position);
			printf("신규 추가할 데이타는 뭔가요?(정수) : ");
			scanf_s("%d", &user_data);
			head = insertNode(head, position, user_data);
			break;
		case 1:
			printf("노드를 저거합니다 제거할 노드의 위치가 몇번째 인가요? : ");
			scanf_s("%d", &position);
			head = deleteNode(head, position);
			break;
		case 2:
			return;
		default:
			printf("다시 입력하시오\n");
			break;
		}

	}
}
