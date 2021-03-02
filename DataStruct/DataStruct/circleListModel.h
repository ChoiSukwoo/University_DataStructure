#pragma once
#ifndef CIRCLELISTMODEL_H
#define CIRCLELISTMODEL_H

#define TRUE  1
#define FALSE 0

//데이타노드의 총 갯수 저장.(insert 또는 delete가 있을때마다, 가감) 
int DataNode_Count = 0;

typedef int element;
typedef struct ListNode { 	// 데이타노드 구조. 
	element dataBox;
	struct DataNodeType* linkBox;
} DataNodeType;

class cirdleListModel
{
public:
	// 리스트의 항목 출력
	void print_list(DataNodeType* head);
	DataNodeType* Finding_LastNode(DataNodeType* head);
	DataNodeType* Finding_PreNode(DataNodeType* head, int pos);
	DataNodeType* insert_first(DataNodeType* head, element data);
	DataNodeType* insert_last(DataNodeType* head, element data);
	DataNodeType* insert(DataNodeType* head, int pos, element data);
	void RUN();
private:

};




#endif // !CIRCLEQUE_H
