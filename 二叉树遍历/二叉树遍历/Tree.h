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
void FrontTraverse(const Tree root);		//前序遍历

void MidTraverse(const Tree root);		//中序遍历

void BackTraverse(const Tree root);		//后序遍历

void Traverse(const Tree root);		//中序遍历的非递归算法

void Destory(Tree* root, int size);		//销毁树
