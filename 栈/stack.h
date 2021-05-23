#ifndef __STACK_H__
#define __STACK_H__
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;
//��ʼ��ջ
void StackInit(Stack* ps);
//�������
void CheckCapacity(Stack* ps);
//ѹջ
void StackPush(Stack* ps, DataType data);
//��ջ
void StackPop(Stack* ps);
//����ջ��Ԫ��ֵ
DataType StackTop(Stack* ps);
//����ѹ��ջ��Ԫ������
int StackSize(Stack* ps);
//�ж�ջ��
int StackEmpty(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);

#endif // !__STACK_H__

