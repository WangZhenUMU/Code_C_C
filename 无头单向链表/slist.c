#include"slist.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x) 
{
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == node)
	{
		printf("BUYSListNode Error��");
		return NULL;
	}
	node->data = x;
	node->next = NULL;
	return node;
}
// �������ӡ
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
// ������β��
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
// �������βɾ
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist != NULL);
	SListNode *node = BuySListNode(x);
	node->next = *pplist;
	*pplist=node;
}
// ������ͷɾ
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
// ���������
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
// ��������posλ��֮�����x
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
// ������ɾ��posλ��֮���ֵ
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
// �����������
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