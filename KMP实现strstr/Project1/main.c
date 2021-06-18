#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* my_strstr(const char* text, const char* pattern)
{
	if (text == NULL || pattern == NULL) return NULL;
	int Tlen = strlen(text);
	int Plen = strlen(pattern);
	if (Plen == 0 || Tlen < Plen)
		return NULL;
	int Ti = 0, Pi = 0;
	while (Ti < Tlen && Pi < Plen)
	{
		if (*(text + Ti) == *(pattern + Pi))
			Ti++, Pi++;
		else
		{
			Ti = Ti - Pi + 1;
			Pi = 0;
		}
	}
	if (Pi == Plen)
	{
		printf("找到了\n");
		return text + Ti - Pi;
	}
	else 
	{
		printf("没找到\n");
		return NULL;
	}
}

void GetNext(const char* pattern, int* next)
{
	int len = strlen(pattern);
	next[0] = -1;
	int i = 0;
	int k = -1;
	while (i < len - 1)
	{
		if (k < 0 || pattern[k] == pattern[i])
		{
			next[++i] = ++k;
		}
		else k = next[k];
	}
}

char* KMP_strstr(const char* text, const char* pattern)
{
	if (text == NULL || pattern == NULL)
		return NULL;
	int Tlen = strlen(text);
	int Plen = strlen(pattern);
	if (Plen == 0 || Plen > Tlen)
		return NULL;
	int* next = malloc(sizeof(int) * Plen);
	if (next == NULL)  return NULL;
	GetNext(pattern, next);
	int Pi = 0, Ti = 0;
	while (Pi < Plen && Ti < Tlen)
	{
		if (text[Ti] == pattern[Pi])
		{
			Pi++;
			Ti++;
		}
		else
		{
			Pi = next[Pi];
		}
	}
	free(next);
	return Pi == Plen ? text + Ti - Pi : NULL;

}

void test1()
{
	char text[] = "abcdefg";
	char pattern[] = "abab";
	printf("%s\n", my_strstr(text, pattern));
	printf("%s\n", strstr(text, pattern));
}

void test2()
{
	char text[] = "aaaaaaab";
	char pattern[] = "aaaabd";
	printf("%s\n", KMP_strstr(text, pattern));
	printf("%s\n", strstr(text, pattern));
}

int main()
{
	//test1();
	test2();
	return 0;
}

