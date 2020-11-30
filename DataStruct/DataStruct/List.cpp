#include "list.h"
#include <stdio.h>


	void List::error(char* message) {
		fprintf(stderr, "%s\n", message);

	}

	void List::init(arrayListType* L) {
		L->size = 0;
	}

	int List::is_empty(arrayListType* L) {
		return L->size == 0;
	}

	int List::is_full(arrayListType* L) {
		return L->size == MAX;
	}

	int List::get_entry(arrayListType* L, int pos) {
		if (pos < 0 || pos >= L->size) {
			//error("위치 오류");
		}
		return L->array[pos];
	}


	void List::PrintList(arrayListType* L) {
		int i;
		for (int i = 0; i < L->size; i++)
		{
			printf("%d  ", L->array[i]);
		}
		printf("\n");
	}


	void List::insertLast(arrayListType* L, int item) {
		if (L->size >= MAX) {
			//error("리스트 오버플로우");
		}
		L->array[L->size++] = item;
	}

	void List::insert(arrayListType* L, int pos, int item) {
		if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
			for (int i = (L->size - 1); i >= pos; i--)
			{
				L->array[i + 1] = L->array[i];
			}
			L->array[pos] = item;
			L->size++;
		}
	}

	int List::Delet(arrayListType* L, int pos) {
		int item;
		if ((pos < 0) || (pos >= L->size)) {
			//error("위치오류");
		}
		item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++)
		{
			L->array[i] = L->array[i + 1];
		}
		L->size--;
		return item;
	}

	void List::Run() {

		printf("\n\n-------------------List------------------\n\n");



		arrayListType list;

		init(&list);
		insert(&list, 0, 10);	PrintList(&list);
		insert(&list, 0, 20);	PrintList(&list);
		insert(&list, 0, 30);	PrintList(&list);
		insertLast(&list, 40);	PrintList(&list);
		Delet(&list, 0);	PrintList(&list);

	}

