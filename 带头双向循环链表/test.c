#include"linklist.h"
int main()
{
	ListNode *head = ListInit();
	//先头插5个元素1，2，3，4，5
	printf("先将1，2，3，4，5头插入链表得：\n");
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPushFront(head, 5);
	ListPrint(head);
	printf("再将6，7，8尾插入链表得：\n");
	//再尾插3个元素6，7，8
	ListPushBack(head, 6);
	ListPushBack(head, 7);
	ListPushBack(head, 8);
	ListPrint(head);
	//头删1个结点
	printf("头删一个节点得：\n");
	ListPopFront(head);
	ListPrint(head);
	printf("尾删一个节点得：\n");
	ListPopBack(head);
	ListPrint(head);
	printf("找出值等于2的节点并删除:\n");
	ListErase(ListFind(head, 2));
	ListPrint(head);
	printf("在值等于1的元素前插入888:\n");
	ListInsert(ListFind(head, 1), 888);
	ListPrint(head);
	ListDestory(head);
}