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
	printf("��ͷԪ��Ϊ��%d\n",QueueFront(pQ));
	printf("��βԪ��Ϊ��%d\n",QueueBack(pQ));
	printf("������ЧԪ�ظ�����%d\n", QueueSize(pQ));
	printf("ִ��һ�γ��Ӳ���\n");
	QueuePop(pQ);
	printf("��ͷԪ��Ϊ��%d\n", QueueFront(pQ));
	printf("��βԪ��Ϊ��%d\n", QueueBack(pQ));
	printf("������ЧԪ�ظ�����%d\n", QueueSize(pQ));
	printf("ִ��һ�γ��Ӳ���\n");
	QueuePop(pQ);
	printf("��ͷԪ��Ϊ��%d\n", QueueFront(pQ));
	printf("��βԪ��Ϊ��%d\n", QueueBack(pQ));
	printf("������ЧԪ�ظ�����%d\n", QueueSize(pQ));
	QueueDestroy(pQ);
	return 0;
}