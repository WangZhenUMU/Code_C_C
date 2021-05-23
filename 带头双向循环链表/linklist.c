#include"linklist.h"
// �������������ͷ���.
ListNode* ListCreate(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == node)
	{
		assert(0);
	}
	node->_data = x;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}
//˫�������ʼ��
ListNode* ListInit()
{
	ListNode* pHead = ListCreate(0);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* pcurrent = pHead->_next;
	printf("head --> ");
	while (pHead != pcurrent)
	{
		printf("%d --> ", pcurrent->_data);
		pcurrent = pcurrent->_next;
	}
	printf("head\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_next);
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* pcurrent = pHead->_next;
	while (pcurrent != pHead)
	{
		if (x == pcurrent->_data)
			return pcurrent;
		pcurrent = pcurrent->_next;
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	if (NULL == pos)
	{
		return;
	}
	ListNode* newnode = ListCreate(x);
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	if (NULL == pos)
	{
		return;
	}
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	while (pHead->_next != pHead)
	{
		ListErase(pHead->_next);
	}
	free(pHead);
	pHead = NULL;
}