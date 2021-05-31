#include<assert.h>
#include<stdlib.h>
#include"queue.h"
QNode* BuyQueueNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}

	node->data = data;
	node->next = NULL;

	return node;
}
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = BuyQueueNode(0);
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	q->rear->next = BuyQueueNode(data);
	q->rear = q->rear->next;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	QNode* DelNode = NULL;
	if (QueueEmpty(q))
		return;
	DelNode = q->front->next;
	q->front->next = DelNode->next;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q&&!QueueEmpty(q));
	return q->front->next->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q && 0 == QueueEmpty(q));
	if (NULL==q->front->next)
		return 0;
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	int count=0;
	QNode* pcurrent = q->front->next;
	while (pcurrent)
	{
		count++;
		pcurrent = pcurrent->next;
	}
	return count;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL==q->front->next;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* pcurrent = q->front;
	while (pcurrent)
	{
		q->front = pcurrent->next;
		free(pcurrent);
		pcurrent = q->front;
	}
	q->rear = NULL;
}

