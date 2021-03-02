#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct DataNodeType {
	int dataBox;
	struct DataNodeType* link;
}DataNodeType;

class LinkList {
public:

	DataNodeType* insertFirst(DataNodeType* head, int value);
	DataNodeType* insertNode(DataNodeType* head, DataNodeType* pre, int value);
	DataNodeType* deleteFirst(DataNodeType* head);
	DataNodeType* deleteNode(DataNodeType* head, DataNodeType* pre);
	void printList(DataNodeType* head);

	void Run();
};

#endif // !LINKLIST_H