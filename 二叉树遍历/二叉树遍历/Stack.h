#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef struct Stack
{
	void** data;
	int size;		//��С
	int capacity;	//����
}Stack;


Stack* Initial();				//��ʼ��ջ

void PushStack(void* data, Stack* S);		//��ջ
void* TopAndPop(Stack* S);			//����ջ��Ԫ�ز���ջ
int IsEmpty_Stack(const Stack* S);	//�ж��Ƿ��ջ
void Destory_Stack(Stack* S);		//����ջ