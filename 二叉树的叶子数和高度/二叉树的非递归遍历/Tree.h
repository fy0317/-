#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;
typedef struct TreeNode
{
	char data;
	Tree Left;		//����
	Tree Right;		//�к��� 
	int flag;	//�ڵ��־
}TreeNode;

void Non_Recursion(const Tree root);		//�ǵݹ����
