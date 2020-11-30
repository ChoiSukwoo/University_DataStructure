#include<stdio.h>
#include "deck.h"





	//큐 초기화 함수
	void Deck::initQue(CustomQue* que) {
		que->back = que->front = 0;
		for (int  i = 0; i < QUESIZE; i++)
		{
			que->BODY[i] = 0;
		}
	}


	void Deck::inFront(CustomQue* que, int value) {
		//가득 찻는지 확인 back이 front 바로 앞인지 확인
		if ((que->back + 1) % QUESIZE == que->front) {
			printf("큐가 가득 찻습니다.\n");
			return;
		}
		que->back = (++que->back) % QUESIZE;
		que->BODY[que->back] = value;
		printf("%d 추가\n", value);
	}

	void Deck::inBack(CustomQue* que, int  value) {
		//가득 찻는지 확인
		if (((que->front - 1) + QUESIZE) % QUESIZE == que->back) {
			printf("큐가 가득 찻습니다.\n");
			return;
		}
		que->BODY[que->front] = value;
		que->front = ((--que->front) + QUESIZE) % QUESIZE;

		printf("%d 추가\n", value);
	}


	int Deck:: DeBack(CustomQue* que) {
		//가득 찻는지 확인
		if (que->back == que->front) {
			printf("큐가 비엇습니다.\n");
			return -1;
		}
		que->front = ++que->front % QUESIZE;
		int item = que->BODY[que->front];
		printf("%d 삭제\n", item);
		return item;
	}

	int Deck:: DeFront(CustomQue* que) {
		//가득 찻는지 확인
		if (que->front == que->back) {
			printf("큐가 비엇습니다.\n");
			return -1;
		}
		int item = que->BODY[que->back];
		que->back = --que->back % QUESIZE;
		printf("%d 삭제\n", item);
		return item;
	}

	void Deck::PrintQue(CustomQue* que) {
		int front = que->front;
		int end = que->back;

		while (front != end) {
			printf("%d ", que->BODY[(++front) % QUESIZE]);
			front = front % QUESIZE;
		}
		printf("\n");
	}



	void Deck::Run() {

		printf("\n\n--------------------Deck-----------------\n\n");

		CustomQue Que1;
		initQue(&Que1);

		for (int i = 1; i < 6; i++) {
			inFront(&Que1, i);
			PrintQue(&Que1);
		}

		for (int i = 0; i < 5; i++) {
			inBack(&Que1, 10 + i);
			PrintQue(&Que1);
		}

		for (int i = 0; i < 3; i++)
		{
			DeBack(&Que1);
			PrintQue(&Que1);
		}

		for (int i = 0; i < 3; i++)
		{
			DeFront(&Que1);
			PrintQue(&Que1);
		}

	}