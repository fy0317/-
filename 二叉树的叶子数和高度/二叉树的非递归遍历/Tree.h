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
	int flag;	//节点标志
}TreeNode;

void Non_Recursion(const Tree root);		//非递归遍历
