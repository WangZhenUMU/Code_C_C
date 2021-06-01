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
//堆的初始化
void HeapInit(Heap *hp, int cap, CMP cmp)
{
	assert(hp&&(&cap));
	cap = cap > 10 ? cap : 10;
	hp->array = (DataType*)malloc(sizeof(DataType)*cap);
	//检查在堆区开辟内存是否成功
	if (NULL==hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = cap;
	hp->size = 0;
	hp->cmp = cmp;
}
//向下调整
void AdjustDown(Heap* hp, int parent)
{
	assert(hp&&(&parent));
	int size = hp->size;
	int* array = hp->array;
	// 用child标记parent的较小的孩子---默认先标记parent的左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		// 找到parent两个孩子中较小的孩子,
		if (child + 1 < size && hp->cmp(array[child + 1], array[child]))
			child += 1;
		// 检测parent是否满足堆的性质
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
//向上调整
void AdjustUp(Heap* hp, int child)
{
	assert(hp);
	//用parent标记孩子的双亲
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
// 堆的构建
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
//检查容量
void CheckCapacity(Heap* hp)
{
	assert(hp);
	//检查是否存满
	if (hp->capacity = hp->size)
	{
		//如果存满，用realloc函数重新开辟一块更大的空间
		 hp->array = (DataType*)realloc(hp->array, sizeof(DataType)*hp->capacity * 2);
		//检查是否开辟成功
		if (hp->array)
		{
			assert(0);
			return;
		}
		//更新容量
		hp->capacity *= 2;
	}
}
// 堆的插入
void HeapPush(Heap* hp, DataType x)
{
	assert(hp&&(&x));
	CheckCapacity(hp);//检查容量
	hp->array[hp->size++] = x;//从尾部插入数据
	AdjustUp(hp, hp->size - 1);//向上调整
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	//检查是否为空
	if (HeapEmpty(hp))
	{
		return;
	}
	//交换根结点与最后一个叶子的位置
	Swap(&(hp->array[0]), &(hp->array[hp->size - 1]));
	//删除叶子
	hp->size--;
	//将根结点向下调整
	AdjustDown(hp, 0);
}
// 取堆顶的数据
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
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}
// 对数组进行堆排序
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
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	free(hp);
	hp = NULL;
}