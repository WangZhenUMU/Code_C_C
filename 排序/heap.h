#ifndef __HEAP_H__
#define __HEAP_H__
typedef int DataType;
int Less(DataType left, DataType right);
int Greater(DataType left, DataType right);
int(*Cmp)(DataType left, DataType right);
// 函数指针变量: 可以指向任何有两个HDataType参数以及一个int类型返回值的所有函数
// Cmp是函数指针变量,Cmp既可以指向Less，也可以指向Greater
typedef int(*CMP)(DataType, DataType);
typedef struct Heap
{
	DataType* array;
	int capacity;
	int size;
	CMP cmp;
}Heap;
//堆的初始化
void HeapInit(Heap *hp, int capacity, CMP cmp);
// 堆的构建
void HeapCreate(Heap* hp, DataType* array, int size,CMP cmp);
// 堆的插入
void HeapPush(Heap* hp, DataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
DataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 对数组进行堆排序
//void HeapSort(int* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
#endif // !__HEAP_H__

