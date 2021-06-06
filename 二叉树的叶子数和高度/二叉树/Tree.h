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
}TreeNode;

void Pre_Recursion(const Tree root);		//�������
void In_Recursion(const  Tree root);		//�������
void Back_Recursion(const Tree root);		//�������
void calculate(const Tree root, int* p);			//ͳ��Ҷ�ӵ���Ŀ
int high(const Tree root);						//�������ĸ߶�
Tree copyTree(const Tree root);		//����������
void FreeTree(Tree root);			//�ͷŶ�����	�����ͷ�

