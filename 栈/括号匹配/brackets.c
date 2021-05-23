#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
//≈–∂œ¿®∫≈ «∑Ò≈‰∂‘
bool PairingBracket(char* str)
{
	assert(str);
	Stack* ps = (Stack*)malloc(sizeof(Stack));
	int i = 0;
	StackInit(ps);
	while (str[i])
	{
		if ('(' == str[i] || '[' == str[i] || '{' == str[i])
		{
			StackPush(ps, str[i]);
		}
		if (')' == str[i] || ']' == str[i] || '}' == str[i])
		{
				if (0 == StackEmpty(ps) && ((')' == str[i] && '(' == StackTop(ps)) || \
					(']' == str[i] && '[' == StackTop(ps)) || \
					('}' == str[i] && '{' == StackTop(ps))     ))
					StackPop(ps);
				else
				{
					free(ps);
					return false;
				}
		}
		i++;
	}
	if (0 == StackEmpty(ps))
	{
		free(ps);
		return false;
	}
	free(ps);
	return true;
}
int main()
{
	char str[100];
	scanf("%s", str);
	if (PairingBracket(str))
	{
		printf("¿®∫≈ÕÍ»´∆•≈‰\n");
	}
	else
		printf("¿®∫≈∆•≈‰ ß∞‹\n");
	return 0;
}