#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "heap.h"
// 交换俩数
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// 插入排序
// 时间复杂度: O(N^2)		空间复杂度: O(1)		稳定性: 稳定
// 应用场景: 数据量少 || 数据接近有序(小的数据尽量靠前，大的数据尽量靠后，不大不小的数据放在中间)
void InsertSort(int array[], int size)
{
	// 当只有一个数据或者没有数据的时候不需要排序
	if(size>1)
	{
		// 取第i个位置的元素，将第i个位置的元素插入第i个元素之前适当的位置
		for (int i = 1; i < size; i++)
		{
			int end = i - 1;
			int key = array[i];
			// 找出待插入数据的位置
			while (end >= 0 && array[end] > key)
			{
				array[end + 1] = array[end];
				end--;
			}
			// 插入数据
			array[end+1] = key;
		}
	}
}

// 希尔排序 
// 希尔排序是插入排序的优化
// 当gap > 1时都是预排序，目的是让数组更接近于有序。当gap == 1时，数组已经接近有序的了，这样就会很快。
// 时间复杂度; O(N^1.3—N^2）		空间复杂度: O(1)		稳定性: 不稳定
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
// 选择排序
//时间复杂度:O(N^2)		 空间复杂度:O(1)		稳定性: 不稳定 
void SelectSort(int array[], int size)
{
	// 当只有一个数据或者没有数据的时候不需要排序
	if (size > 1)
	{
		// 循环依次找出最大的值的位置，并将其与第size-i-1个元素的位置进行交换
		for (int i = 0 ; i < size-1; i++)
		{
			// 记录最大值的下标
			int MAXPos = 0;
			for (int j = 1; j < size-i; j++)
			{
				if (array[j] > array[MAXPos])
					MAXPos = j;
			}
			//将最大值与第size-i-1个元素的位置进行交换
			if (MAXPos != size - i - 1)
				Swap(&array[MAXPos], &array[size - i - 1]);
		}
	}
}
// 选择排序 优化 同时找出最大最小值，将最大值放最后，最小值放最前
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
			// 将数组遍历一遍找出数组中的最小值和最大值的下标
			while (index < end)
			{
				if (array[MAXpos] < array[index])
					MAXpos = index;
				if (array[MINpos] > array[index])
					MINpos = index;
				index++;
			}
			// 将最大值与end交换位置
			if (MAXpos != end)
				Swap(&array[MAXpos], &array[end]);
			// 如果最小值恰巧在end位置，则改变MINpos的指向
			if (MINpos == end)
				MINpos = MAXpos;
			// 将最小值与begin交换位置
			if (MINpos != begin)
				Swap(&array[MINpos], &array[begin]);
			begin++;
			end--;
		}
	}
}

// 堆排序
// 排升序建大堆，排降序建小堆
// 时间复杂度: O(NlogN)		空间复杂度: O(1)		稳定性: 不稳定
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

// 冒泡排序
// 时间复杂度: O(N^2)		空间复杂度: O(1)		稳定性: 稳定
void BubbleSort(int array[], int size)
{
	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			//定义一个标记，默认标记为0，如果进行交换则标记自加；
			//每次遍历完后判断flog是否等于0，如果等于0，则证明数组有序，跳出循环
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

// 快速排序
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
// 快排->左右指针
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
// 快排->挖坑法
void QuickSort2(int array[], int size)
{

}
// 快排->前后指针法
void QuickSort3(int array[], int size)
{

}