#include"slist.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//动态申请一个节点
SListNode* BuySListNode(SLTDateType x) 
{
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == node)
	{
		printf("BUYSListNode Error！");
		return NULL;
	}
	node->data = x;
	node->next = NULL;
	return node;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode *current = plist;
	while (current!=NULL)
	{
		printf("%d --> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode *current = *pplist;
	if (*pplist==NULL)
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = BuySListNode(x);
	}
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist != NULL);
	SListNode *current = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	else if (NULL==(*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		while (current->next->next)
		{
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode *node = BuySListNode(x);
	node->next = *pplist;
	*pplist=node;
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode *current = NULL;
	assert(pplist != NULL);
	if (NULL==*pplist)
	{
		return;
	}
	else
	{
		current = *pplist;
		*pplist = (*pplist)->next;
		free(current);
	}
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode *current = plist;
	while (current)
	{
		if (x==current->data)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{

	SListNode *node = NULL;
	if (NULL == pos)
	{
		printf("POS ERROR\n");
		return;
	}
	node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	SListNode *node = NULL;
	if (NULL == pos)
	{
		printf("POS ERROR\n");
		return;
	}
	node = pos->next;
	pos->next = node->next;
	free(node);
}
// 单链表的销毁
void SListDestory(SListNode** pplist)
{
	SListNode *node = NULL;
	if (NULL == *pplist)
	{
		return;
	}
	while (NULL!=(*pplist))
	{
		node = *pplist;
		(*pplist) = (*pplist)->next;
		free(node);
	}
}