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
	Tree Left;		//左孩子
	Tree Right;		//有孩子 
}TreeNode;

void Pre_Recursion(const Tree root);		//先序遍历
void In_Recursion(const  Tree root);		//中序遍历
void Back_Recursion(const Tree root);		//后序遍历