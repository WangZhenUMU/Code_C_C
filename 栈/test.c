#include<stdio.h>
#include"stack.h"
int main()
{
	Stack p;
	Stack *ps = &p;
	StackInit(ps);
	printf("��2��3��4��5��6����ѹ��ջ\n");
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);
	StackPush(ps, 6);
	printf("ջ��Ԫ��ֵΪ%d\n", StackTop(ps));
	printf("ջ��Ԫ������Ϊ%d\n\n", StackSize(ps));
	printf("��ջ\n");
	StackPop(ps);
	printf("ջ��Ԫ��ֵΪ%d\n", StackTop(ps));
	printf("ջ��Ԫ������Ϊ%d\n\n", StackSize(ps));
	printf("��ջ\n");
	StackPop(ps);
	printf("ջ��Ԫ��ֵΪ%d\n", StackTop(ps));
	printf("ջ��Ԫ������Ϊ%d\n\n", StackSize(ps));
	printf("��ջ\n");
	StackPop(ps);
	printf("ջ��Ԫ��ֵΪ%d\n", StackTop(ps));
	printf("ջ��Ԫ������Ϊ%d\n\n", StackSize(ps));
	StackDestroy(ps);
	return 0;
}
