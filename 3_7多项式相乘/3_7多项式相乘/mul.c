#include"mul.h"

#define len sizeof(LinkNode)
//创建节点
LinkNode* CreatLinkNode()
{
	LinkNode* head, * p1, * p2;
	head = malloc(len);
	p1 = head, p2 = head;
	double data = 0;	//系数
	int my_index = 0;	//指数
	printf("输入系数及其对应的指数：\n");
	scanf("%lf %d", &data, &my_index);
	while (data)
	{
		p1->next = malloc(len);
		p1 = p1->next;
		p1->coef = data;
		p1->index = my_index;
		scanf("%lf %d", &data, &my_index);
	}
	p1->next = NULL;
	return head;
}
void Destory(LinkNode* L)
{
	LinkNode* curr = L->next;
	LinkNode* next = curr;

	while (next)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(L);
}

LinkNode* Mul(const LinkNode* L1, const LinkNode* L2)
{
	if (L1 == NULL || L2 == NULL)return NULL;
	LinkNode* node1 = L1->next;
	LinkNode* node2 = L2->next;
	if (!node1) return L2;
	if (!node2) return L1;
	LinkNode* newnode = malloc(len);
	LinkNode* tmp = newnode;
	while (node1)
	{
		node2 = L2->next;
		while (node2)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->coef = node1->coef * node2->coef;
			tmp->index = node1->index + node2->index;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	tmp->next = NULL;
	tmp = newnode->next;
	while (tmp)
	{
		LinkNode* next = tmp->next;
		LinkNode* pre = tmp;
		LinkNode* cur = next;
		while (next)
		{
			if (next->index == tmp->index)
			{
				tmp->coef += next->coef;
				next = next->next;
				free(cur);
				cur = next;
				pre->next = next;
			}
			else
			{
				pre = cur;
				next = next->next;
				cur = next;
			}
		}
		tmp = tmp->next;
	}
	return newnode;
}

double Sum(const LinkNode* L, double x)
{
	if (L == NULL) return 0;
	LinkNode* tmp = L->next;
	double sum = 0;
	while (tmp)
	{
		sum += tmp->coef * pow(x, tmp->index);
		tmp = tmp->next;
	}
	return sum;
}

LinkNode* Add(const LinkNode* L1, const LinkNode* L2)
{
	if (L1 == NULL && L2 == NULL) return NULL;
	if (!L1->next) return L2;
	if (!L2->next) return L1;
	L1 = L1->next;
	L2 = L2->next;
	LinkNode* newnode = malloc(len);
	LinkNode* tmp = newnode;
	while (L1 && L2)
	{
		if (L1->index == L2->index)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L1->index;
			tmp->coef = L1->coef + L2->coef;
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->index > L2->index)
		{
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L1->index;
			tmp->coef = L1->coef;
			L1 = L1->next;
		}
		else {
			tmp->next = malloc(len);
			tmp = tmp->next;
			tmp->index = L2->index;
			tmp->coef = L2->coef;
			L2 = L2->next;
		}
	}
	while (L1)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->index = L1->index;
		tmp->coef = L1->coef;
		L1 = L1->next;
	}
	while (L2)
	{
		tmp->next = malloc(len);
		tmp = tmp->next;
		tmp->index = L2->index;
		tmp->coef = L2->coef;
		L2 = L2->next;
	}
	tmp->next = NULL;
	return newnode;
}