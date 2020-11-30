#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
	int data;
	struct ListNode* link;
}LsitNode;


ListNode* insertFirst(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insertNode(ListNode* head,ListNode * pre, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* deleteFirst(ListNode* head) {

	ListNode* remove;
	if (head == NULL) {
		return NULL;
	}
	remove = head;
	head = remove->link;
	free(remove);
	return head;
}

ListNode* deleteNode(ListNode* head,ListNode* pre) {

	ListNode* remove;
	remove = pre->link;
	pre->link = remove->link;
	free(remove);
	return head;
}


void printList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("\n");

}

void main() {
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