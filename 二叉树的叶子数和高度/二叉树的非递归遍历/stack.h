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
Stack CreatStack(int MaxSize);	//����һ��ջ
void Push(Stack S, DataType x);		//��ջ
DataType TopAndPop(Stack S);		//����ջ��,����ջ
void Destory(Stack S);				//����ջ