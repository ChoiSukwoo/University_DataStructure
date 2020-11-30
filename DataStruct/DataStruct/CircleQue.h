#pragma once
#ifndef CIRCLEQUE_H
#define CIRCLEQUE_H
#define QUESIZE 5

typedef struct customCircleQue {
	int start;
	int now;

	int BODY[QUESIZE];
}CustomCircleQue;

class CircleQue
{
public:
	void initQue(CustomCircleQue* que);
	void inQue(CustomCircleQue* que, int value);
	int DeQue(CustomCircleQue* que);
	void PrintQue(CustomCircleQue* que);
	void Run();
};



#endif // !CIRCLEQUE_H
