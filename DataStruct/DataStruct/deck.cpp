//#include<stdio.h>
//#define QUESIZE 10
//
//typedef struct customQue {
//	int front;
//	int back;
//
//	int BODY[QUESIZE];
//}CustomQue;
//
//int TestNum = 0;
//
////ť �ʱ�ȭ �Լ�
//void initQue(CustomQue* que) {
//	que->back = que->front = 0;
//	for (int i = 0; i < QUESIZE; i++)
//	{
//		que->BODY[i] = 0;
//	}
//}
//
//
//void inFront(CustomQue* que, int value) {
//	//���� ������ Ȯ�� back�� front �ٷ� ������ Ȯ��
//	if ((que->back + 1) % QUESIZE == que->front) {
//		printf("ť�� ���� �����ϴ�.\n");
//		return;
//	}
//	que->back = (++que->back) % QUESIZE;
//	que->BODY[que->back] = value;
//	printf("%d �߰�\n", value);
//}
//
//void inBack(CustomQue* que, int value) {
//	//���� ������ Ȯ��
//	if (((que->front - 1) + QUESIZE) % QUESIZE == que->back) {
//		printf("ť�� ���� �����ϴ�.\n");
//		return;
//	}
//	que->BODY[que->front] = value;
//	que->front = ((--que->front) + QUESIZE) % QUESIZE;
//
//	printf("%d �߰�\n", value);
//}
//
//
//int DeBack(CustomQue* que) {
//	//���� ������ Ȯ��
//	if (que->back == que->front) {
//		printf("ť�� ������ϴ�.\n");
//		return -1;
//	}
//	que->front = ++que->front % QUESIZE;
//	int item = que->BODY[que->front];
//	printf("%d ����\n", item);
//	return item;
//}
//
//int DeFront(CustomQue* que) {
//	//���� ������ Ȯ��
//	if (que->front == que->back) {
//		printf("ť�� ������ϴ�.\n");
//		return -1;
//	}
//	int item = que->BODY[que->back];
//	que->back = --que->back % QUESIZE;
//	printf("%d ����\n", item);
//	return item;
//}
//
//void PrintQue(CustomQue* que) {
//	int front = que->front;
//	int end = que->back;
//
//	while (front != end) {
//		printf("%d ", que->BODY[(++front) % QUESIZE]);
//		front = front % QUESIZE;
//	}
//	printf("\n");
//}
//
//
//
//void CircleDeckQuemain() {
//
//	CustomQue Que1;
//	initQue(&Que1);
//
//	for (int i = 1; i < 6; i++) {
//		inFront(&Que1, i);
//		PrintQue(&Que1);
//	}
//
//	for (int i = 0; i < 5; i++) {
//		inBack(&Que1, 10 + i);
//		PrintQue(&Que1);
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		DeBack(&Que1);
//		PrintQue(&Que1);
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		DeFront(&Que1);
//		PrintQue(&Que1);
//	}
//
//}