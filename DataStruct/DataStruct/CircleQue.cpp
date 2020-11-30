#pragma once
#include<stdio.h>
#include"CircleQue.h"



	//큐 초기화 함수
	void CircleQue::initQue(CustomCircleQue* que) {
		que->now = que->start = 0;
		for (int i = 0; i < QUESIZE; i++)
		{
			que->BODY[i] = 0;
		}
	}


	void CircleQue::inQue(CustomCircleQue* que, int value) {
		//가득 찻는지 확인
		if ((que->now + 1) % QUESIZE == que->start) {
			printf("큐가 가득 찻습니다.\n");
			return;
		}
		que->now = (++que->now) % QUESIZE;
		que->BODY[que->now] = value;
		printf("%d 추가\n", value);
	}


	int CircleQue::DeQue(CustomCircleQue* que) {
		//가득 찻는지 확인
		if (que->now == que->start) {
			printf("큐가 비엇습니다.\n");
			return -1;
		}
		que->start = ++que->start % QUESIZE;
		int item = que->BODY[que->start];
		printf("%d 삭제\n", item);
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
