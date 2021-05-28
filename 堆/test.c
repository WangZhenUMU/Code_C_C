#pragma once
#include"heap.h"
#include<stdio.h>
int main()
{
	int a[9] = {1,3,2,4,5,7,6,9,8};
	int k = 9;
	for(int i=0;i<k;i++)
	{
		printf("%d->", a[i]);
	}
	printf("NULL\n");
	HeapSort(a, 9);
	for(int i=0;i<k;i++)
	{
		printf("%d->", a[i]);
	}
	printf("NULL\n");
}
