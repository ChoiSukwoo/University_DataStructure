#pragma once
#ifndef LIST_H
#define LIST_H
#define MAX 100

typedef struct {
	int array[MAX];
	int size;
} arrayListType;


class List {
public:

	void error(char* message);
	void init(arrayListType* L);
	int is_empty(arrayListType* L);
	int is_full(arrayListType* L);
	int get_entry(arrayListType* L, int pos);
	void PrintList(arrayListType* L);
	void insertLast(arrayListType* L, int item);
	void insert(arrayListType* L, int pos, int item);
	int Delet(arrayListType* L, int pos);

	void Run();


};

#endif // !LIST_H


