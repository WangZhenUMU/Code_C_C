#include<stdio.h>
#include"queue.h"
int main()
{
	Queue Q;
	Queue* pQ = &Q;
	QueueInit(pQ);
	QueuePush(pQ, 1);
	QueuePush(pQ, 2);
	QueuePush(pQ, 3);
	QueuePush(pQ, 4);
	QueuePush(pQ, 5);
	printf("队头元素为：%d\n",QueueFront(pQ));
	printf("队尾元素为：%d\n",QueueBack(pQ));
	printf("队内有效元素个数：%d\n", QueueSize(pQ));
	printf("执行一次出队操作\n");
	QueuePop(pQ);
	printf("队头元素为：%d\n", QueueFront(pQ));
	printf("队尾元素为：%d\n", QueueBack(pQ));
	printf("队内有效元素个数：%d\n", QueueSize(pQ));
	printf("执行一次出队操作\n");
	QueuePop(pQ);
	printf("队头元素为：%d\n", QueueFront(pQ));
	printf("队尾元素为：%d\n", QueueBack(pQ));
	printf("队内有效元素个数：%d\n", QueueSize(pQ));
	QueueDestroy(pQ);
	return 0;
}