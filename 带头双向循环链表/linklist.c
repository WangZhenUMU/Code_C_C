#include"linklist.h"
// 创建返回链表的头结点.
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
//双向链表初始化
ListNode* ListInit()
{
	ListNode* pHead = ListCreate(0);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}
// 双向链表打印
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
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->_next);
}
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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
// 双向链表销毁
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