#pragma once
#include<stdio.h>
#include"CircleQue.h"



	//ť �ʱ�ȭ �Լ�
	void CircleQue::initQue(CustomCircleQue* que) {
		que->now = que->start = 0;
		for (int i = 0; i < QUESIZE; i++)
		{
			que->BODY[i] = 0;
		}
	}


	void CircleQue::inQue(CustomCircleQue* que, int value) {
		//���� ������ Ȯ��
		if ((que->now + 1) % QUESIZE == que->start) {
			printf("ť�� ���� �����ϴ�.\n");
			return;
		}
		que->now = (++que->now) % QUESIZE;
		que->BODY[que->now] = value;
		printf("%d �߰�\n", value);
	}


	int CircleQue::DeQue(CustomCircleQue* que) {
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

	void CircleQue::PrintQue(CustomCircleQue* que) {
		int start = que->start;
		int end = que->now;

		while (start != end) {
			printf("%d ", que->BODY[(start + 1) % QUESIZE]);
			start = ++start % QUESIZE;
		}
		printf("\n");
	}


	void CircleQue::Run() {

		printf("\n\n---------------CircleQue-----------------\n\n");

		int TestNum = 0;

		printf("a");
		CustomCircleQue Que1;
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
