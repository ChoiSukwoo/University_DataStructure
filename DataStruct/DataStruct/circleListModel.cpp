#include <stdio.h>
#include <stdlib.h>
#include "circleListModel.h"


// 리스트의 항목 출력
void cirdleListModel::print_list(DataNodeType* head){
	DataNodeType* p;

	if (head == NULL) return;
	p = head; //head->linkBox;
	do {
		printf("%d->", p->dataBox);
		p = p->linkBox;
	} while (p != head);
	//printf("%d->", p->dataBox); // 마지막 노드 출력
}
DataNodeType* cirdleListModel::Finding_LastNode(DataNodeType* head)
{
	DataNodeType* i = NULL;

	for (i = head; (i->linkBox != head); i = i->linkBox)
	{
	}
	return i;  //마지막 노드의 시작주소가 리턴. 
}

DataNodeType* cirdleListModel::Finding_PreNode(DataNodeType* head, int pos)
{
	DataNodeType* PreNode = NULL;
	int i = 0;  //반복 횟수 저장용.	

	for (PreNode = head, i = 0; (i < pos - 2); i++)
		PreNode = PreNode->linkBox;

	return PreNode;
}
DataNodeType* cirdleListModel::insert_first(DataNodeType* head, element data)
{
	DataNodeType* LastNode = NULL;
	DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
	node->dataBox = data;
	if (head == NULL) {  //데이타노드가 0개이면. 
		node->linkBox = head;   //1. 뒤쪽 연결.
		head = node;            //2. 앞쪽 연결.
		node->linkBox = head;   //3. 원형 설정. 
	}
	else {
		LastNode = Finding_LastNode(head);  // 마지막 노드 주소 미리 찾아두기. 
		node->linkBox = head;        //1. 뒤쪽 연결.
		head = node;                //2. 앞쪽 연결.
		LastNode->linkBox = head;   //3. 원형 설정.
	}
	DataNode_Count++;  //데이타노드 갯수 1증가. 

	return head;	// 변경된 헤드 포인터를 반환한다. 
}

DataNodeType* cirdleListModel::insert_last(DataNodeType* head, element data)
{
	DataNodeType* LastNode = NULL; //리스트에서 젤 마지막 노드의 시작주소 저장. 

	DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
	node->dataBox = data;
	if (head == NULL) {  // 연결된 데이타노드가 0개 이면. 
		node->linkBox = head;  //1. 뒤쪽 연결
		head = node;           //2. 앞쪽 연결.
		node->linkBox = head;  //3. 원형 설정. 
	}
	else {
		LastNode = Finding_LastNode(head);// 직전 노드 찾기!!! 
		node->linkBox = LastNode->linkBox; //1. 뒤쪽 연결
		LastNode->linkBox = node;         //2. 앞쪽 연결.
		node->linkBox = head;              //3. 원형 설정.
	}
	DataNode_Count++;  //데이타노드 갯수 1증가. 

	return head;	// 변경된 헤드 포인터를 반환한다. 
}

DataNodeType* cirdleListModel::insert(DataNodeType* head, int pos, element data)
{
	DataNodeType* PreNode = NULL;
	//추가하기를 원하는 위치가 적절한가를 체크.
	if (((0 < pos) && (pos <= DataNode_Count + 1)) != TRUE)
	{
		printf("그 위치에는 데이타노드를 추가할수 없습니다.\n");
		return;
	}
	else
	{
		DataNode_Count++;
		DataNodeType* node = (DataNodeType*)malloc(sizeof(DataNodeType));
		node->dataBox = data;

		if (head == NULL) //데이타노드가 0개 이면. 
			return insert_first(head, data);
		else //데이타노드가 1개 이상 있으면.
		{
			/*
			1. 추가위치가 1이면, insert_first()호출.
			2. 추가위치가 젤끝이면(pos == DataNode_Count), insert_last()호출.
			3. 그 이외.
			*/
			if (pos == 1)
				return insert_first(head, data);
			else if (pos == DataNode_Count + 1)
				return insert_last(head, data);
			else
			{
				PreNode = Finding_PreNode(head, pos);      //0. 직전 노드를 찾기.	
				node->linkBox = PreNode->linkBox; //1. 뒤쪽 연결.
				PreNode->linkBox = node;          //2. 앞쪽 연결.

				return head;
			}
		}
	}
}

void cirdleListModel::RUN() {
	DataNodeType* headNode = NULL; //헤더노드. 

	headNode = insert_last(headNode, 40);
	headNode = insert_first(headNode, 10);
	headNode = insert_last(headNode, 20);
	headNode = insert_last(headNode, 30);
	headNode = insert_first(headNode, 7);
	headNode = insert(headNode, 6, 77);
	print_list(headNode);
	printf("현재 데이타노드의 총 갯수: %d \n", DataNode_Count);

}