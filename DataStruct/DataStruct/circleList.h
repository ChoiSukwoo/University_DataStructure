#pragma once
#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#define QUESIZE 5

typedef struct circleListNode {
	int dataBox;
	struct circleListNode* link;
}circleListNode;


class circleList
{
public:
	circleListNode* insertNode(circleListNode* head, int value);
	circleListNode* deleteNode(circleListNode* head);
	void printList(circleListNode* head);

	void Run();
};



#endif // !CIRCLEQUE_H
