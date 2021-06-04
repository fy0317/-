//#include <stdio.h>
//#include <stdlib.h>
///*
//1.����Ҫ���ж���ʽ�Ķ��룬���캯��ReadPoly����
//2.���ж���ʽ�ӷ������캯��AddPoly����
//3.���ж���ʽ�˷������캯��MultyPoly����
//4.���ж���ʽ�������PrintPoly����
//*/
//typedef struct PolyNode* Polynomial;
//struct PolyNode {
//	int coef;
//	int expon;
//	Polynomial link;
//};
//void Attach(int c, int e, Polynomial* rear);//���¶����ϵ����ָ���ӵ�����ʽ��ĩβ 
//Polynomial ReadPoly();//�������ʽ 
//Polynomial AddPoly(Polynomial P1, Polynomial P2);//������������ʽ֮�� 
//Polynomial MultyPoly(Polynomial P1, Polynomial P2);//������������ʽ�� 
//void PrintPoly(Polynomial P);
//int main()
//{
//	Polynomial P1 = ReadPoly();
//	Polynomial P2 = ReadPoly();
//	Polynomial PA = AddPoly(P1, P2);
//	Polynomial PP = MultyPoly(P1, P2);
//	PrintPoly(PP);
//	PrintPoly(PA);
//}
//void Attach(int c, int e, Polynomial* rear)
//{
//	Polynomial input = (Polynomial)malloc(sizeof(struct PolyNode));
//	//�����½ڵ㲢����ֵ 
//	input->coef = c;
//	input->expon = e;
//	input->link = NULL;
//	(*rear)->link = input;
//	*rear = input; //�޸�ĩβָ�룬��Ϊ���޸�ָ�룬�ʴ˴�ʹ��ָ���ָ�� 
//}
//Polynomial ReadPoly()
//{
//	Polynomial P1, rear, t;
//	int N;//����ʽ���� 
//	int c, e;//�����ݴ�ϵ����ָ�� 
//	P1 = (Polynomial)malloc(sizeof(struct PolyNode));//����ͷ�ڵ� 
//	//����ͷ�ڵ���Ϊ�˷���ʹ��Attach����ʱ����������rear�ǿջ��Ƿǿգ�����ͷ�ڵ㶼�Ƿǿգ����뷽�� 
//	P1->link = NULL;
//
//	rear = P1;//βָ��ָ��ͷ�ڵ� 
//	scanf("%d", &N);
//	while (N--)
//	{
//		scanf("%d %d", &c, &e);
//		Attach(c, e, &rear);
//	}
//	t = P1;
//	P1 = P1->link;
//	free(t);//ͷ�ڵ㷽������ʹ����ɣ��ͷ�ͷ�ڵ�
//	return P1;
//}
//Polynomial AddPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial t1, t2, rear, t;
//	t1 = P1;
//	t2 = P2;
//	Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
//	P->link = NULL;
//	rear = P;
//	while (t1 && t2)
//	{
//		if (t1->expon == t2->expon)//���ָ����ͬ�������� 
//		{
//			if (t1->coef + t2->coef)//���ϵ����Ӳ�Ϊ�㣬�򽫼���������P�� 
//			{
//				Attach(t1->coef + t2->coef, t1->expon, &rear);
//			}
//			t1 = t1->link;
//			t2 = t2->link;
//		}
//		else if (t1->expon > t2->expon)//�ҵ�ָ����ļ��뵽P�� 
//		{
//
//			Attach(t1->coef, t1->expon, &rear);
//			t1 = t1->link;
//		}
//		else
//		{
//			Attach(t2->coef, t2->expon, &rear);
//			t2 = t2->link;
//		}
//	}
//	while (t1)//���t1���ж���ڵ㣬��������� 
//	{
//		Attach(t1->coef, t1->expon, &rear);
//		t1 = t1->link;
//	}
//	while (t2)//���t2���ж���ڵ㣬��������� 
//	{
//		Attach(t2->coef, t2->expon, &rear);
//		t2 = t2->link;
//	}
//	t = P;
//	P = P->link;
//	free(t);//�ͷ�ͷ�ڵ� 
//	return P;
//}
//Polynomial MultyPoly(Polynomial P1, Polynomial P2)
//{
//	Polynomial P, t1, t2, t, rear;
//	int c, e;
//	P = (Polynomial)malloc(sizeof(struct PolyNode));	//ͷ�ڵ�
//	P->link = NULL;
//
//	t1 = P1;
//	t2 = P2;
//	rear = P;	//βָ��
//
//	if (!t1 || !t2)//�����һ������ʽΪ�գ���˷����Ϊ�� 
//		return NULL;
//
//	while (t2)//����P1�ĵ�һ�����P2����һ������ʽ���ڲ��� 
//	{
//		c = t1->coef * t2->coef;
//		e = t1->expon + t2->expon;
//		Attach(c, e, &rear);
//		t2 = t2->link;
//	}
//	t1 = t1->link;//t1ָ��ڶ��� 
//	while (t1)
//	{
//		t2 = P2;//��ָ������ָ��P2�Ŀ�ͷ 
//		rear = P;//����Ѱ�Һ��ʵĲ���λ�� 
//		while (t2)
//		{
//			c = t1->coef * t2->coef;
//			e = t1->expon + t2->expon;
//			while (rear->link && rear->link->expon > e)//��rearָ��ָ����e��Ȼ��eС�Ľڵ�֮ǰһ��λ��	
//				rear = rear->link;
//			if (rear->link && rear->link->expon == e)//���rear��Ϊ����rear֮��Ľڵ�ָ����e��ȣ��������� 
//			{
//				if (c + rear->link->coef)//�����Ӳ�Ϊ0
//				{
//					rear->link->coef += c;
//					rear = rear->link;
//				}
//				else//��ӽ��Ϊ0 ,ɾ��rear֮��Ľڵ� 
//				{
//					t = rear->link;
//					rear->link = t->link;
//					free(t);
//				}
//			}
//			else //����һ���½ڵ���뵽rear֮�� 
//			{
//				t = (Polynomial)malloc(sizeof(struct PolyNode));
//				t->coef = c;
//				t->expon = e;
//				t->link = rear->link;
//				rear->link = t;
//				rear = rear->link;
//			}
//			t2 = t2->link;
//		}
//		t1 = t1->link;
//	}
//	t = P;
//	P = P->link;
//	free(t);//�ͷŵ�ͷ�ڵ�
//	return P;
//}
//void PrintPoly(Polynomial P)
//{
//	int flag = 0;
//	if (!P)
//	{
//		printf("0 0\n");
//		return;
//	}
//	while (P)
//	{
//		if (!flag)
//			flag = 1;
//		else
//			printf(" ");
//		printf("%d %d", P->coef, P->expon);
//		P = P->link;
//	}
//	printf("\n");
//}