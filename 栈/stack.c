#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 5);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->capacity = 5;
	ps->size = 0;
}
//检查容量
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->array = (DataType*)realloc(ps->array, sizeof(DataType)*(ps->capacity) * 2);
		if (NULL == ps->array)
		{
			assert(0);
			return;
		}
		ps->capacity *= 2;
	}
}
//压栈
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}
//返回栈顶元素值
DataType StackTop(Stack* ps)
{
	assert(ps&&StackEmpty(ps)==0);
	return ps->array[ps->size - 1];
}
//返回压入栈的元素数量
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
//判断栈空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0==ps->size;
}
//销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}