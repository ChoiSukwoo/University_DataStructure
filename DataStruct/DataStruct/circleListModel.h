#pragma once
#ifndef CIRCLELISTMODEL_H
#define CIRCLELISTMODEL_H

#define TRUE  1
#define FALSE 0

//����Ÿ����� �� ���� ����.(insert �Ǵ� delete�� ����������, ����) 
int DataNode_Count = 0;

typedef int element;
typedef struct ListNode { 	// ����Ÿ��� ����. 
	element dataBox;
	struct DataNodeType* linkBox;
} DataNodeType;

class cirdleListModel
{
public:
	// ����Ʈ�� �׸� ���
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
