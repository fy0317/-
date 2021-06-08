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

Tree MakeEmpty(Tree tree);		//初始化

Tree find(int x, const Tree tree);		//查找元素

Tree FindMin(const Tree tree);			//查找最小值

Tree FindMax(const Tree tree);			//查找最大值

Tree Insert(int x, Tree tree);			//插入元素

Tree Delete(int x, Tree tree);			//删除元素

int Retrieve(Tree P);					//

Tree CreatTree(Tree T);		//根据先序序列创建一个二叉树
