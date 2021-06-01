#ifndef __HEAP_H__
#define __HEAP_H__
typedef int DataType;
int Less(DataType left, DataType right);
int Greater(DataType left, DataType right);
int(*Cmp)(DataType left, DataType right);
// ����ָ�����: ����ָ���κ�������HDataType�����Լ�һ��int���ͷ���ֵ�����к���
// Cmp�Ǻ���ָ�����,Cmp�ȿ���ָ��Less��Ҳ����ָ��Greater
typedef int(*CMP)(DataType, DataType);
typedef struct Heap
{
	DataType* array;
	int capacity;
	int size;
	CMP cmp;
}Heap;
//�ѵĳ�ʼ��
void HeapInit(Heap *hp, int capacity, CMP cmp);
// �ѵĹ���
void HeapCreate(Heap* hp, DataType* array, int size,CMP cmp);
// �ѵĲ���
void HeapPush(Heap* hp, DataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
DataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
//void HeapSort(int* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
#endif // !__HEAP_H__

