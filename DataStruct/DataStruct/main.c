#include<stdio.h>
#define QUESIZE 5


typedef struct customQue {
	int start;
	int now;

	int BODY[QUESIZE];
}CustomQue;

int TestNum = 0;

//ť �ʱ�ȭ �Լ�
void initQue(CustomQue* que) {
	que->now = que->start = 0;
	for (int i = 0; i < QUESIZE; i++)
	{
		que->BODY[i] = 0;
	}
}


void inQue(CustomQue* que, int value) {
	//���� ������ Ȯ��
	if ((que->now + 1) % QUESIZE == que->start) {
		printf("ť�� ���� �����ϴ�.\n");
		return;
	}
	que->now = (++que->now) % QUESIZE;
	que->BODY[que->now] = value;
	printf("%d �߰�\n", value);
}

int DeQue(CustomQue* que) {
	//���� ������ Ȯ��
	if (que->now == que->start) {
		printf("ť�� ������ϴ�.\n");
		return -1;
	}
	que->start = ++que->start % QUESIZE;
	int item = que->BODY[que->start];
	printf("%d ����\n", item);
	return item;
}

void PrintQue(CustomQue* que) {
	int start = que->start;
	int end = que->now;

	while (start != end) {
		printf("%d ", que->BODY[(start + 1) % QUESIZE]);
		start = ++start % QUESIZE;
	}
	printf("\n");
}


void main() {

	CustomQue Que1;
	initQue(&Que1);

	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	inQue(&Que1, ++TestNum);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
	DeQue(&Que1);
	PrintQue(&Que1);
}