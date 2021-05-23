#ifndef __STACK_H__
#define __STACK_H__
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;
//初始化栈
void StackInit(Stack* ps);
//检查容量
void CheckCapacity(Stack* ps);
//压栈
void StackPush(Stack* ps, DataType data);
//出栈
void StackPop(Stack* ps);
//返回栈顶元素值
DataType StackTop(Stack* ps);
//返回压入栈的元素数量
int StackSize(Stack* ps);
//判断栈空
int StackEmpty(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);

#endif // !__STACK_H__

