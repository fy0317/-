#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef struct Stack
{
	void** data;
	int size;		//大小
	int capacity;	//容量
}Stack;


Stack* Initial();				//初始化栈

void PushStack(void* data, Stack* S);		//入栈
void* TopAndPop(Stack* S);			//返回栈顶元素并出栈
int IsEmpty_Stack(const Stack* S);	//判断是否空栈
void Destory_Stack(Stack* S);		//销毁栈