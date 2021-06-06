#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
typedef Tree  DataType;
struct StackRecord
{
	int size;
	int capacity;
	DataType* data;
};
typedef struct StackRecord* Stack;
Stack CreatStack(int MaxSize);	//创建一个栈
void Push(Stack S, DataType x);		//进栈
DataType TopAndPop(Stack S);		//返回栈顶,并出栈
void Destory(Stack S);				//销毁栈