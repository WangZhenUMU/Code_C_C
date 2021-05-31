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
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = BuyQueueNode(0);
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	q->rear->next = BuyQueueNode(data);
	q->rear = q->rear->next;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	QNode* DelNode = NULL;
	if (QueueEmpty(q))
		return;
	DelNode = q->front->next;
	q->front->next = DelNode->next;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q&&!QueueEmpty(q));
	return q->front->next->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q && 0 == QueueEmpty(q));
	if (NULL==q->front->next)
		return 0;
	return q->rear->data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL==q->front->next;
}
// 销毁队列 
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

