#include"linklist.h"
int main()
{
	ListNode *head = ListInit();
	//��ͷ��5��Ԫ��1��2��3��4��5
	printf("�Ƚ�1��2��3��4��5ͷ��������ã�\n");
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPushFront(head, 5);
	ListPrint(head);
	printf("�ٽ�6��7��8β��������ã�\n");
	//��β��3��Ԫ��6��7��8
	ListPushBack(head, 6);
	ListPushBack(head, 7);
	ListPushBack(head, 8);
	ListPrint(head);
	//ͷɾ1�����
	printf("ͷɾһ���ڵ�ã�\n");
	ListPopFront(head);
	ListPrint(head);
	printf("βɾһ���ڵ�ã�\n");
	ListPopBack(head);
	ListPrint(head);
	printf("�ҳ�ֵ����2�Ľڵ㲢ɾ��:\n");
	ListErase(ListFind(head, 2));
	ListPrint(head);
	printf("��ֵ����1��Ԫ��ǰ����888:\n");
	ListInsert(ListFind(head, 1), 888);
	ListPrint(head);
	ListDestory(head);
}