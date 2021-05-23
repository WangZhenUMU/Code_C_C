#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"slist.h"
void test_Back()
{
	SListNode *head = NULL;
	printf("Œ≤≤Â≤‚ ‘\n");
	SListPushBack(&head, 1);
	SListPrint(head);
	SListPushBack(&head, 2);
	SListPrint(head);
	SListPushBack(&head, 3);
	SListPrint(head);
	SListPushBack(&head, 4);
	SListPrint(head);
	SListPushBack(&head, 5);
	SListPrint(head);
	printf("Œ≤…æ≤‚ ‘\n");
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListDestory(&head);
}
void test_Front()
{
	SListNode *head = NULL;
	printf("Õ∑≤Â≤‚ ‘\n");
	SListPushFront(&head, 1);
	SListPrint(head);
	SListPushFront(&head, 2);
	SListPrint(head);
	SListPushFront(&head, 3);
	SListPrint(head);
	SListPushFront(&head, 4);
	SListPrint(head);
	SListPushFront(&head, 5);
	SListPrint(head);
	printf("Õ∑…æ≤‚ ‘\n");
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListDestory(&head);
}
void test()
{
	SListNode *head = NULL;
	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);
	SListPushFront(&head, 6);
	SListPushFront(&head, 7);
	SListPushFront(&head, 8);
	SListPushFront(&head, 9);
	SListPrint(head);
	printf("÷∏∂®Œª÷√÷Æ∫Û…æ≥˝≤‚ ‘£∫\n");
	SListEraseAfter(SListFind(head, 7));
	SListPrint(head);
	printf("÷∏∂®Œª÷√÷Æ∫Û≤Â»Î≤‚ ‘£∫\n");
	SListInsertAfter(SListFind(head, 7), 6);
	SListPrint(head);
	SListDestory(&head);
}
int main()
{
	//test_Back();
	//test_Front();
	test();
	return 0;
}
