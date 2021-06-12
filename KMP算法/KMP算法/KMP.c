#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void move_prefix_table(int prefix[], int n);
//void prefix_table(char pattern[], int prefix[], int n)		//����ǰ׺��
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
//	//text��i��ʾ�±���m��ʾ���ȣ� pattern��j��ʾ�±꣬��n��ʾ����
//	int i = 0, j = 0;
//	int m = strlen(text);
//	while (i < m)
//	{
//		if (text[i] == pattern[j])
//		{
//			if (j == n - 1)
//			{
//				printf("��%d���ҵ���", i - j);
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

int BF(const char* text, const char* pattern)		//textΪ�ı�����patternΪģʽ��
{
	if (text == NULL || pattern == NULL)return -1;
	int Tlen = strlen(text);
	int Plen = strlen(pattern);		//TlenΪ�ı������ȣ� PlenΪģʽ������
	if (Plen == 0)return -1;		//�涨ģʽ������Ϊ0����Ϊpattern����text�Ӵ�������-1
	if (Plen > Tlen)return -1;		//���Plen > Tlen��pattern�϶�����text�Ӵ�������-1

	//Plen��Ϊ0��Plen < Tlen
	int ti = 0;		//textָ��
	int pi = 0;		//patternָ��
	while(ti < Tlen && pi < Plen)
	{
		if (text[ti] == pattern[pi])		//ƥ��ɹ���pi��ti����
			ti++, pi++;
		else
		{
			//ƥ��ʧ�ܣ�pi��ti����
			ti = ti - pi + 1;		//ti����һλ
			//pi�Ĵ�С�����Ѿ�ƥ��ɹ����ַ�����ti - pi �ص���ʼ�Ƚϵ��ַ�λ�ã��ټ�1�������ƶ�1λ
			pi = 0;		//pi��ͷ��ʼ
		}
	}
	//ѭ������ti == Tlen ����pi == Plen
	if (pi == Plen)
		return ti - pi;		//pi ==Plen����ʾ��ȫƥ��ɹ�������ti - pi ����ʼ�Ƚϵ��ַ�λ��
	else
		return -1;		//ƥ��ʧ�ܣ�����-1
}
void GetNext(const char* pattern, int* next);
int KMP(const char* text, const char* pattern)
{
	if (text == NULL || pattern == NULL) return -1;		//�жϿ�ָ�����
	int Tlen = strlen(text);		//text�ַ�������
	int Plen = strlen(pattern);		//ģʽ������
	if (Tlen == 0 || Plen == 0)return -1;		//�涨���ģʽ������Ϊ0���򷵻�-1

	if (Tlen < Plen) return -1;					//����ı��ַ�����С��ģʽ���ַ����ȣ�һ������ƥ��ɹ�����-1

	int* next = malloc(sizeof(int) * Plen);		//����next����
	if (next == NULL)					//��ӡ������Ϣ
		perror("next����ʧ��");

	GetNext(pattern, next);			//��next����
	int ti = 0, pi = 0;					//ti��pi�ֱ�Ϊ�ı�����ģʽ����ָ��
	while (ti < Tlen && pi < Plen)		
	{
		if (pi < 0 || text[ti] == pattern[pi])	//���pi<0����ʾ���ݵ���ģʽ���׶ˣ�ֻ�ܴ�ͷ����ƥ�䣨ֻ����pi��
		{										//�����ǰλ��ƥ��ɹ�����ti��pi������
			ti++;
			pi++;
		}
		else
		{
			pi = next[pi];		//ƥ��ʧ�ܣ���pi����
		}

	}
	free(next);		
	//ѭ������ʱ��ti == tlen || pi == plen �����pi == plen��ʾƥ����ɣ�������ʼƥ��λ���±꣬���򷵻�-1
	return pi == Plen ? ti - Plen : -1;
}
void GetNext(const char* pattern, int* next)		
{
	//��ΪGetNext��������KMP�����е��ã���KMP���Ѿ��жϹ���ָ���������������Ͳ����ж�

	int len = strlen(pattern);		//ģʽ������
	next[0] = -1;			//next[0]��Ϊ-1
	int i = 0;		
	int k = -1;			//��Ϊnext[0]Ϊ-1��k�ĳ�ʼֵ��Ϊ-1
	while (i < len- 1)
	{
		if (k < 0 || pattern[i] == pattern[k])	//���k���ݵ���-1������pattern[i] == pattern[k]����k��i����ƶ�
		{
			//k++, i++;
			next[++i] = ++k;		//��Ϊ�±�kҲ��next[i]��ֵ��������if����ʱ��next[i+1] == next[i]+1
		}
		else k = next[k];			//������������ʱ����k���л��ݣ����ͼ��������Ĳ���
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

