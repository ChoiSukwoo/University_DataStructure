//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 100
//
//typedef struct {
//	int array[MAX];
//	int size;
//} arrayListType;
//
//
//void error(char* message) {
//	fprintf(stderr, "%s\n", message);
//
//}
//
//void init(arrayListType* L) {
//	L->size = 0;
//}
//
//int is_empty(arrayListType* L) {
//	return L->size == 0;
//}
//
//int is_full(arrayListType* L) {
//	return L->size == MAX;
//}
//
//int get_entry(arrayListType* L, int pos) {
//	if (pos < 0 || pos >= L->size) {
//		//error("위치 오류");
//	}
//	return L->array[pos];
//}
//
//
//void PrintList(arrayListType* L) {
//	int i;
//	for (int i = 0; i < L->size; i++)
//	{
//		printf("%d  ", L->array[i]);
//	}
//	printf("\n");
//}
//
//
//void insertLast(arrayListType* L, int item) {
//	if (L->size >= MAX) {
//		//error("리스트 오버플로우");
//	}
//	L->array[L->size++] = item;
//}
//
//void insert(arrayListType* L, int pos, int item) {
//	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
//		for (int i = (L->size - 1); i >= pos; i--)
//		{
//			L->array[i + 1] = L->array[i];
//		}
//		L->array[pos] = item;
//		L->size++;
//	}
//}
//
//int Delet(arrayListType* L, int pos) {
//	int item;
//	if ((pos < 0) || (pos >= L->size)) {
//		//error("위치오류");
//	}
//	item = L->array[pos];
//	for (int i = pos; i < (L->size - 1); i++)
//	{
//		L->array[i] = L->array[i + 1];
//	}
//	L->size--;
//	return item;
//}
//
//
//void Listmain() {
//	arrayListType list;
//
//	init(&list);
//	insert(&list, 0, 10);	PrintList(&list);
//	insert(&list, 0, 20);	PrintList(&list);
//	insert(&list, 0, 30);	PrintList(&list);
//	insertLast(&list, 40);	PrintList(&list);
//	Delet(&list, 0);	PrintList(&list);
//
//
//}