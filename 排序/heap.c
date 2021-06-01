#include"heap.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int Less(DataType left, DataType right)
{
	return left < right;
}
int Greater(DataType left, DataType right)
{
	return left > right;
}
//void Swap(DataType* left, DataType* right)
//{
//	DataType temp = *left;
//	*left = *right;
//	*right = temp;
//}
//�ѵĳ�ʼ��
void HeapInit(Heap *hp, int cap, CMP cmp)
{
	assert(hp&&(&cap));
	cap = cap > 10 ? cap : 10;
	hp->array = (DataType*)malloc(sizeof(DataType)*cap);
	//����ڶ��������ڴ��Ƿ�ɹ�
	if (NULL==hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = cap;
	hp->size = 0;
	hp->cmp = cmp;
}
//���µ���
void AdjustDown(Heap* hp, int parent)
{
	assert(hp&&(&parent));
	int size = hp->size;
	int* array = hp->array;
	// ��child���parent�Ľ�С�ĺ���---Ĭ���ȱ��parent������
	int child = parent * 2 + 1;
	while (child < size)
	{
		// �ҵ�parent���������н�С�ĺ���,
		if (child + 1 < size && hp->cmp(array[child + 1], array[child]))
			child += 1;
		// ���parent�Ƿ�����ѵ�����
		if (hp->cmp(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
//���ϵ���
void AdjustUp(Heap* hp, int child)
{
	assert(hp);
	//��parent��Ǻ��ӵ�˫��
	int size = hp->size;
	int* array = hp->array;
	int parent = (child - 2) / 2;
	while (child)
	{
		if (hp->cmp(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (parent - 2) / 2;
		}
	}
}
// �ѵĹ���
void HeapCreate(Heap* hp, DataType* arr, int size, CMP cmp)
{
	assert(hp);
	HeapInit(hp, size, cmp);
	memcpy(hp->array, arr, sizeof(DataType)*size);
	hp->size = size;
	for (int root = (size - 2)/2+1; root >=0; root--)
	{
		AdjustDown(hp, root);
	}
}
//�������
void CheckCapacity(Heap* hp)
{
	assert(hp);
	//����Ƿ����
	if (hp->capacity = hp->size)
	{
		//�����������realloc�������¿���һ�����Ŀռ�
		 hp->array = (DataType*)realloc(hp->array, sizeof(DataType)*hp->capacity * 2);
		//����Ƿ񿪱ٳɹ�
		if (hp->array)
		{
			assert(0);
			return;
		}
		//��������
		hp->capacity *= 2;
	}
}
// �ѵĲ���
void HeapPush(Heap* hp, DataType x)
{
	assert(hp&&(&x));
	CheckCapacity(hp);//�������
	hp->array[hp->size++] = x;//��β����������
	AdjustUp(hp, hp->size - 1);//���ϵ���
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	//����Ƿ�Ϊ��
	if (HeapEmpty(hp))
	{
		return;
	}
	//��������������һ��Ҷ�ӵ�λ��
	Swap(&(hp->array[0]), &(hp->array[hp->size - 1]));
	//ɾ��Ҷ��
	hp->size--;
	//����������µ���
	AdjustDown(hp, 0);
}
// ȡ�Ѷ�������
DataType HeapTop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp))
	{
		printf("NO DATA!");
		return 0;
	}
	return hp->array[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}
// ��������ж�����
//void HeapSort(int* a, int n)
//{
//	assert(a&&(&n));
//	Heap hp;
//	HeapCreate(&hp, a, n, Less);
//	int k = hp.size;
//	for(int i=0;i<k;i++)
//		HeapPop(&hp);
//	hp.size = k;
//	for (int i = 0; i < n; i++)
//		a[i] = hp.array[i];
//}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	free(hp);
	hp = NULL;
}