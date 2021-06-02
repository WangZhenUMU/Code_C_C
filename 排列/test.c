#include <stdio.h>

#include "sort.h"

void PrintArray(int array[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d -> ", array[i]);
	}
	printf("NULL\n");
}

void main()
{
	int array[] = { 1,9,2,8,3,7,4,6,5,0 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	BubbleSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}