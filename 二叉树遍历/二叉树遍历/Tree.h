#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct TreeNode;
typedef struct TreeNode* Tree;
struct TreeNode
{
	void* data;
	Tree left;
	Tree right;
};

typedef struct Person
{
	char name[20];
	int age;
}Person;
void FrontTraverse(const Tree root);		//ǰ�����

void MidTraverse(const Tree root);		//�������

void BackTraverse(const Tree root);		//�������

void Traverse(const Tree root);		//��������ķǵݹ��㷨

void Destory(Tree* root, int size);		//������
