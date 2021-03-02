#include <stdio.h>
#include <stdlib.h>
#include "circleListModel.h"


// ����Ʈ�� �׸� ���
void cirdleListModel::print_list(DataNodeType* head){
	DataNodeType* p;

	if (head == NULL) return;
	p = head; //head->linkBox;
	do {
		printf("%d->", p->dataBox);
		p = p->linkBox;
	} while (p != head);
	//printf("%d->", p->dataBox); // ������ ��� ���
}
DataNodeType* cirdleListModel::Finding_LastNode(DataNodeType* head)
{
	DataNodeType* i = NULL;

	for (i = head; (i->linkBox != head); i = i->linkBox)
	{
	}
	return i;  //������ ����� �����ּҰ� ����. 
}

DataNodeType* cirdleListModel::Finding_PreNode(DataNodeType* head, int pos)
{
	DataNodeType* PreNode = NULL;
	int i = 0;  //�ݺ� Ƚ�� �����.	

	for (PreNode = head, i = 0; (i < pos - 2); i++)
		PreNode = PreNode->linkBox;

	return PreNode;
}
DataNodeType* cirdleListModel::insert_first(DataNodeType* head, element data)
{
	DataNodeType* LastNode = NULL;
	DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
	node->dataBox = data;
	if (head == NULL) {  //����Ÿ��尡 0���̸�. 
		node->linkBox = head;   //1. ���� ����.
		head = node;            //2. ���� ����.
		node->linkBox = head;   //3. ���� ����. 
	}
	else {
		LastNode = Finding_LastNode(head);  // ������ ��� �ּ� �̸� ã�Ƶα�. 
		node->linkBox = head;        //1. ���� ����.
		head = node;                //2. ���� ����.
		LastNode->linkBox = head;   //3. ���� ����.
	}
	DataNode_Count++;  //����Ÿ��� ���� 1����. 

	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

DataNodeType* cirdleListModel::insert_last(DataNodeType* head, element data)
{
	DataNodeType* LastNode = NULL; //����Ʈ���� �� ������ ����� �����ּ� ����. 

	DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
	node->dataBox = data;
	if (head == NULL) {  // ����� ����Ÿ��尡 0�� �̸�. 
		node->linkBox = head;  //1. ���� ����
		head = node;           //2. ���� ����.
		node->linkBox = head;  //3. ���� ����. 
	}
	else {
		LastNode = Finding_LastNode(head);// ���� ��� ã��!!! 
		node->linkBox = LastNode->linkBox; //1. ���� ����
		LastNode->linkBox = node;         //2. ���� ����.
		node->linkBox = head;              //3. ���� ����.
	}
	DataNode_Count++;  //����Ÿ��� ���� 1����. 

	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

DataNodeType* cirdleListModel::insert(DataNodeType* head, int pos, element data)
{
	DataNodeType* PreNode = NULL;
	//�߰��ϱ⸦ ���ϴ� ��ġ�� �����Ѱ��� üũ.
	if (((0 < pos) && (pos <= DataNode_Count + 1)) != TRUE)
	{
		printf("�� ��ġ���� ����Ÿ��带 �߰��Ҽ� �����ϴ�.\n");
		return;
	}
	else
	{
		DataNode_Count++;
		DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
		node->dataBox = data;

		if (head == NULL) //����Ÿ��尡 0�� �̸�. 
			return insert_first(head, data);
		else //����Ÿ��尡 1�� �̻� ������.
		{
			/*
			1. �߰���ġ�� 1�̸�, insert_first()ȣ��.
			2. �߰���ġ�� �����̸�(pos == DataNode_Count), insert_last()ȣ��.
			3. �� �̿�.
			*/
			if (pos == 1)
				return insert_first(head, data);
			else if (pos == DataNode_Count + 1)
				return insert_last(head, data);
			else
			{
				PreNode = Finding_PreNode(head, pos);      //0. ���� ��带 ã��.	
				node->linkBox = PreNode->linkBox; //1. ���� ����.
				PreNode->linkBox = node;          //2. ���� ����.

				return head;
			}
		}
	}
}

void cirdleListModel::RUN() {
	DataNodeType* headNode = NULL; //������. 

	headNode = insert_last(headNode, 40);
	headNode = insert_first(headNode, 10);
	headNode = insert_last(headNode, 20);
	headNode = insert_last(headNode, 30);
	headNode = insert_first(headNode, 7);
	headNode = insert(headNode, 6, 77);
	print_list(headNode);
	printf("���� ����Ÿ����� �� ����: %d \n", DataNode_Count);

}