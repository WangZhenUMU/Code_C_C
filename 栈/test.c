#include<stdio.h>
#include"stack.h"
int main()
{
	Stack p;
	Stack *ps = &p;
	StackInit(ps);
	printf("将2，3，4，5，6依次压入栈\n");
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);
	StackPush(ps, 6);
	printf("栈顶元素值为%d\n", StackTop(ps));
	printf("栈内元素数量为%d\n\n", StackSize(ps));
	printf("出栈\n");
	StackPop(ps);
	printf("栈顶元素值为%d\n", StackTop(ps));
	printf("栈内元素数量为%d\n\n", StackSize(ps));
	printf("出栈\n");
	StackPop(ps);
	printf("栈顶元素值为%d\n", StackTop(ps));
	printf("栈内元素数量为%d\n\n", StackSize(ps));
	printf("出栈\n");
	StackPop(ps);
	printf("栈顶元素值为%d\n", StackTop(ps));
	printf("栈内元素数量为%d\n\n", StackSize(ps));
	StackDestroy(ps);
	return 0;
}
