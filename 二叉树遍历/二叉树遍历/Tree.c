#include"Tree.h"
#include"Stack.h"
void FrontTraverse(const Tree root)		//ǰ�����
{
	if (root == NULL) return;
	Person* tmp = root->data;
	printf("������%s�� ���䣺 %d\n", tmp->name, tmp->age);
	FrontTraverse(root->left);
	FrontTraverse(root->right);
}

void MidTraverse(const Tree root)		//�������
{
	if (root == NULL) return;
	MidTraverse(root->left);
	Person* tmp = root->data;
	printf("������%s�� ���䣺 %d\n", tmp->name, tmp->age);
	MidTraverse(root->right);
}

void BackTraverse(const Tree root)		//�������
{
	if (root == NULL) return;
	BackTraverse(root->left);
	BackTraverse(root->right);
	Person* tmp = root->data;
	printf("������%s�� ���䣺 %d\n", tmp->name, tmp->age);
}


void Traverse(const Tree root)		//��������ķǵݹ��㷨
{
	if (root == NULL)return;
	Tree tmp = root;
	Stack* myStack = Initial();
	if (myStack == NULL) return;
	Tree p;
	Person* my_Person;

	//���ڵ㲻Ϊ�գ�����ջ��Ϊ��ʱ������ѭ��
	//
	// 
	//�Ƚ���ǰ�ڵ���ջ��Ȼ���ӡ����������
	//�������������Ϊ�գ��򷵻�ջ���Ľڵ㲢��ӡ����ڵ������
	//ͬʱҲ˵����ʱ  ���ջ���ڵ��   �������Ѿ����ʽ�������������ڵ��������
	//
	//��tmpΪ�գ�����ջҲΪ��ʱ��˵�����нڵ㶼�������
	while (tmp || myStack->size != 0)
	{
		if (tmp)
		{
			PushStack(tmp, myStack);
			tmp = tmp->left;
		}
		else
		{
			p = TopAndPop(myStack);
			my_Person = p->data;
			printf("������%s�� ���䣺 %d\n", my_Person->name, my_Person->age);
			tmp = p->right;
		}
	}
	Destory_Stack(myStack);
}


void Destory(Tree* root, int size)
{
	if (root == NULL) return;
	for (int i = 0; i < size; i++)
		free(root[i]);
	free(root);
}