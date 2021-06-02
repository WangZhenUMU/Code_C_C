#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "heap.h"
// ��������
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// ��������
// ʱ�临�Ӷ�: O(N^2)		�ռ临�Ӷ�: O(1)		�ȶ���: �ȶ�
// Ӧ�ó���: �������� || ���ݽӽ�����(С�����ݾ�����ǰ��������ݾ������󣬲���С�����ݷ����м�)
void InsertSort(int array[], int size)
{
	// ��ֻ��һ�����ݻ���û�����ݵ�ʱ����Ҫ����
	if(size>1)
	{
		// ȡ��i��λ�õ�Ԫ�أ�����i��λ�õ�Ԫ�ز����i��Ԫ��֮ǰ�ʵ���λ��
		for (int i = 1; i < size; i++)
		{
			int end = i - 1;
			int key = array[i];
			// �ҳ����������ݵ�λ��
			while (end >= 0 && array[end] > key)
			{
				array[end + 1] = array[end];
				end--;
			}
			// ��������
			array[end+1] = key;
		}
	}
}

// ϣ������ 
// ϣ�������ǲ���������Ż�
// ��gap > 1ʱ����Ԥ����Ŀ������������ӽ������򡣵�gap == 1ʱ�������Ѿ��ӽ�������ˣ������ͻ�ܿ졣
// ʱ�临�Ӷ�; O(N^1.3��N^2��		�ռ临�Ӷ�: O(1)		�ȶ���: ���ȶ�
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
		{
			int end = i - gap;
			int key = array[i];
			while (end >= 0 && key < array[end])
			{
				array[end+gap] = array[end];
				end = end - gap;
			}
			array[end+gap] = key;
		}
	}
}
// ѡ������
//ʱ�临�Ӷ�:O(N^2)		 �ռ临�Ӷ�:O(1)		�ȶ���: ���ȶ� 
void SelectSort(int array[], int size)
{
	// ��ֻ��һ�����ݻ���û�����ݵ�ʱ����Ҫ����
	if (size > 1)
	{
		// ѭ�������ҳ�����ֵ��λ�ã����������size-i-1��Ԫ�ص�λ�ý��н���
		for (int i = 0 ; i < size-1; i++)
		{
			// ��¼���ֵ���±�
			int MAXPos = 0;
			for (int j = 1; j < size-i; j++)
			{
				if (array[j] > array[MAXPos])
					MAXPos = j;
			}
			//�����ֵ���size-i-1��Ԫ�ص�λ�ý��н���
			if (MAXPos != size - i - 1)
				Swap(&array[MAXPos], &array[size - i - 1]);
		}
	}
}
// ѡ������ �Ż� ͬʱ�ҳ������Сֵ�������ֵ�������Сֵ����ǰ
void SelectSortOP(int array[], int size)
{
	if (size > 1)
	{
		int begin = 0;
		int end = size - 1;
		while (begin < end)
		{
			int MAXpos = begin;
			int MINpos = begin;
			int index = begin + 1;
			// ���������һ���ҳ������е���Сֵ�����ֵ���±�
			while (index < end)
			{
				if (array[MAXpos] < array[index])
					MAXpos = index;
				if (array[MINpos] > array[index])
					MINpos = index;
				index++;
			}
			// �����ֵ��end����λ��
			if (MAXpos != end)
				Swap(&array[MAXpos], &array[end]);
			// �����Сֵǡ����endλ�ã���ı�MINpos��ָ��
			if (MINpos == end)
				MINpos = MAXpos;
			// ����Сֵ��begin����λ��
			if (MINpos != begin)
				Swap(&array[MINpos], &array[begin]);
			begin++;
			end--;
		}
	}
}

// ������
// �����򽨴�ѣ��Ž���С��
// ʱ�临�Ӷ�: O(NlogN)		�ռ临�Ӷ�: O(1)		�ȶ���: ���ȶ�
int more(DataType left, DataType right)
{
	return left > right;
}
void HeapSort(int array[], int size)
{
	Heap heap;
	HeapCreate(&heap, array, size, more);
	int SIZE = heap.size;
	for (int i = 0; i < size; i++)
		HeapPop(&heap);
	heap.size = SIZE;
	for (int i = 0; i < size; i++)
		array[i] = heap.array[i];
}

// ð������
// ʱ�临�Ӷ�: O(N^2)		�ռ临�Ӷ�: O(1)		�ȶ���: �ȶ�
void BubbleSort(int array[], int size)
{
	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			//����һ����ǣ�Ĭ�ϱ��Ϊ0��������н��������Լӣ�
			//ÿ�α�������ж�flog�Ƿ����0���������0����֤��������������ѭ��
			int flog = 0;
			for (int j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					Swap(&array[j], &array[j + 1]);
					flog++;
				}
			}
			if (0 == flog)
				break;
		}
	}
}

// ��������
#define SIZE 16
int FindMid(int array[], int left,int right)
{
	int begin = left;
	int mid = (left + right) / 2;
	int end = left;
	if (array[begin] > array[mid])
		Swap(&begin, &mid);
	if (array[begin] > array[end])
		Swap(&begin, &end);
	if (array[mid] > array[end])
		Swap(&mid, &end);
	return mid;
}
// ����->����ָ��
void QuickSort1(int array[], int left, int right)
{
	int L = left+1;
	int R = right;
	int mid = FindMid(array, left, right);
	if (left != mid)
		Swap(&array[left], &array[mid]);
	int key = left;
	while (L < R)
	{
		while (L < R && array[R] > key)
			R--;
		while (L < R&&array[L] < key)
			L++;
		Swap(&array[L], &array[R]);
	}
	Swap(&array[key], array[L]);
	QuickSort1(array, left, L - 1);
	QuickSort1(array, L, right);
}
// ����->�ڿӷ�
void QuickSort2(int array[], int size)
{

}
// ����->ǰ��ָ�뷨
void QuickSort3(int array[], int size)
{

}