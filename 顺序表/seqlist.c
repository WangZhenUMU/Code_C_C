#include"seqlist.h"
// ˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl != NULL);
	if (capacity == 0)
	{
		printf("input capacity error!");
		return 0;
	}
	psl->array = (SeqList*)malloc(sizeof(SeqList)*capacity);
	assert(psl->array != NULL);
	psl->capicity = capacity;
	psl->size = 0;
}
// ˳�������
void SeqListDestory(SeqList* psl)
{
	assert(psl != NULL);
	free(psl->array);
	if (psl->array != NULL)
	{
		psl = NULL;
		psl->capicity = psl->size = 0;
	}
}
// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->array != NULL)
	{
		for (int i; i < psl->size; i++)
			printf("%-7d", &psl->array[i]);
	}
}
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl) 
{
	assert(psl != NULL);
	if (psl->size >= psl->capicity)
	{
		psl->array = realloc(psl->array, psl->capicity * 2);
		psl->capicity *= 2;
	}
}
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x) 
{
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl != NULL);
	psl->size--;
	psl->array[psl->size]=0;
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	for (int i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = x;
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->size == 0)
	{
		printf("ARRAY IS EMPTY");
		return;
	}
	else
	{
		for (int i = 0; i < psl->size - 1; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
		psl->size--;
	}
}
// ˳������
int SeqListFind(SeqList* psl, SLDataType x) 
{
	assert(psl != NULL);
	if (psl->size == 0)
	{
		printf("ARRAY IS EMPTY");
		return 0;
	}
	else
	{
		for (int i = 0; i < psl->size; i++)
		{
			if (psl->array == x)
				return 1;
		}
		return 0;
	}
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl == NULL);
	if (pos < 0)
	{
		printf("POS ERROR!");
		return 0;
	}
	else if (pos >= psl->size)
	{
		psl->array[psl->size] = x;
		psl->size++;
	}
	else
	{
		for (int i = psl->size; i > pos; i++)
		{
			psl->array[i] = psl->array[i - 1];
		}
		psl->array[pos] = x;
	}
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl != NULL);
	if (pos<0 || pos>psl->size - 1)
	{
		printf("POS ERROR!");
	}
	else
	{
		for (int i = pos; i < psl->size - 1; i++)
		{
			psl->array[i] = psl->array[i + 1];
		}
	}
}