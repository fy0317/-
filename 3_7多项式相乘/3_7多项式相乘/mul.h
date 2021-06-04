#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct LinkNode
{
	double coef;	//系数
	int index;		//指数
	struct LinkNode* next;
}LinkNode;

LinkNode* CreatLinkNode();

LinkNode* Mul(const LinkNode* L1, const LinkNode* L2);
double Sum(const LinkNode* L, double x);
void Destory(LinkNode* L);
LinkNode* Add(const LinkNode* L1, const LinkNode* L2);
