#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode
{
	char data;
	Tree left;
	Tree right;
};

Tree MakeEmpty(Tree tree);		//��ʼ��

Tree find(int x, const Tree tree);		//����Ԫ��

Tree FindMin(const Tree tree);			//������Сֵ

Tree FindMax(const Tree tree);			//�������ֵ

Tree Insert(int x, Tree tree);			//����Ԫ��

Tree Delete(int x, Tree tree);			//ɾ��Ԫ��

int Retrieve(Tree P);					//

Tree CreatTree(Tree T);		//�����������д���һ��������
