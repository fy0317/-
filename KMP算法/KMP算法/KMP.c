#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void move_prefix_table(int prefix[], int n);
//void prefix_table(char pattern[], int prefix[], int n)		//创建前缀表
//{
//	prefix[0] = 0;
//	int len = 0;
//	int i = 1;
//	while (i < n) {
//		if (pattern[i] == pattern[len]) {
//			len++;
//			prefix[i] = len;
//			i++;
//		}
//		else {
//			if (len > 0) {
//				len = prefix[len - 1];
//			}
//			else {
//				prefix[i] = len;
//				i++;
//			}
//		}
//	}
//}
//
//void kmp_search(char text[], char pattern[]) {
//	int n = strlen(pattern);
//	int* prefix = malloc(sizeof(int) * n);
//	prefix_table(pattern, prefix, n);
//	move_prefix_table(prefix, n);
//	//text用i表示下表，用m表示长度， pattern用j表示下标，用n表示长度
//	int i = 0, j = 0;
//	int m = strlen(text);
//	while (i < m)
//	{
//		if (text[i] == pattern[j])
//		{
//			if (j == n - 1)
//			{
//				printf("在%d处找到了", i - j);
//				j = prefix[j];
//			}
//			else 
//			 {
//				i++;
//				j++;
//			}
//		}
//		else
//		{
//			j = prefix[j];
//			if (j == -1)
//			{
//				i++;
//				j++;
//			}
//		}
//	}
//
//}
//void move_prefix_table(int prefix[], int n) {
//	int i;
//	for (i = n - 1; i > 0; i--)
//	{
//		prefix[i] = prefix[i - 1];
//	}
//	prefix[0] = -1;
//}
//
//int GetNext(char ch[], int next[], int length)
//{
//	next[1] = 0;
//	int i = 1, j = 0;
//	while (i <= length)
//	{
//		if (j == 0 || ch[i] == ch[j])next[++i] = ++j;
//		else j = next[j];
//	}
//}

int BF(const char* text, const char* pattern)		//text为文本串，pattern为模式串
{
	if (text == NULL || pattern == NULL)return -1;
	int Tlen = strlen(text);
	int Plen = strlen(pattern);		//Tlen为文本串长度， Plen为模式串长度
	if (Plen == 0)return -1;		//规定模式串长度为0，认为pattern不是text子串，返回-1
	if (Plen > Tlen)return -1;		//如果Plen > Tlen，pattern肯定不是text子串，返回-1

	//Plen不为0且Plen < Tlen
	int ti = 0;		//text指针
	int pi = 0;		//pattern指针
	while(ti < Tlen && pi < Plen)
	{
		if (text[ti] == pattern[pi])		//匹配成功，pi和ti后移
			ti++, pi++;
		else
		{
			//匹配失败，pi和ti回溯
			ti = ti - pi + 1;		//ti后移一位
			//pi的大小就是已经匹配成功的字符数，ti - pi 回到开始比较的字符位置，再加1完成向后移动1位
			pi = 0;		//pi重头开始
		}
	}
	//循环结束ti == Tlen 或者pi == Plen
	if (pi == Plen)
		return ti - pi;		//pi ==Plen，表示完全匹配成功，返回ti - pi 即开始比较的字符位置
	else
		return -1;		//匹配失败，返回-1
}
void GetNext(const char* pattern, int* next);
int KMP(const char* text, const char* pattern)
{
	if (text == NULL || pattern == NULL) return -1;		//判断空指针情况
	int Tlen = strlen(text);		//text字符串长度
	int Plen = strlen(pattern);		//模式串长度
	if (Tlen == 0 || Plen == 0)return -1;		//规定如果模式串长度为0，则返回-1

	if (Tlen < Plen) return -1;					//如果文本字符长度小于模式串字符长度，一定不能匹配成功返回-1

	int* next = malloc(sizeof(int) * Plen);		//创建next数组
	if (next == NULL)					//打印错误信息
		perror("next创建失败");

	GetNext(pattern, next);			//求next数组
	int ti = 0, pi = 0;					//ti，pi分别为文本串和模式串的指针
	while (ti < Tlen && pi < Plen)		
	{
		if (pi < 0 || text[ti] == pattern[pi])	//如果pi<0，表示回溯到了模式串首端，只能从头进行匹配（只回溯pi）
		{										//如果当前位置匹配成功，将ti和pi都后移
			ti++;
			pi++;
		}
		else
		{
			pi = next[pi];		//匹配失败，对pi回溯
		}

	}
	free(next);		
	//循环结束时，ti == tlen || pi == plen ，如果pi == plen表示匹配完成，返回起始匹配位置下标，否则返回-1
	return pi == Plen ? ti - Plen : -1;
}
void GetNext(const char* pattern, int* next)		
{
	//因为GetNext函数是在KMP函数中调用，在KMP中已经判断过空指针的情况，因此这里就不再判断

	int len = strlen(pattern);		//模式串长度
	next[0] = -1;			//next[0]设为-1
	int i = 0;		
	int k = -1;			//因为next[0]为-1，k的初始值设为-1
	while (i < len- 1)
	{
		if (k < 0 || pattern[i] == pattern[k])	//如果k回溯到了-1，或者pattern[i] == pattern[k]，则将k和i向后移动
		{
			//k++, i++;
			next[++i] = ++k;		//因为下标k也是next[i]的值，当满足if条件时，next[i+1] == next[i]+1
		}
		else k = next[k];			//当不满足条件时，对k进行回溯，解释见博客正文部分
	}
}

void test1()
{
	char text[] = "abcabaaaabaacac";
	char pattern[] = "cac";

	int ret = KMP(text, pattern);
	printf("%d", ret);
}
int main()
{
	test1();

	return 0;
}

