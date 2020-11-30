#pragma once
#ifndef DECK_H
#define DECK_H
#define QUESIZE 10

typedef struct customQue {
	int front;
	int back;

	int BODY[QUESIZE];
}CustomQue;


class Deck
{
public:
	void initQue(CustomQue* que);
	void inFront(CustomQue* que, int value);
	void inBack(CustomQue* que, int value);
	int DeBack(CustomQue* que);
	int DeFront(CustomQue* que);
	void PrintQue(CustomQue* que);
	void Run();


};


#endif // !DECK_H
