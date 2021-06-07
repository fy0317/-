#include"Tree.h"
#include"Stack.h"
void FrontTraverse(const Tree root)		//前序遍历
{
	if (root == NULL) return;
	Person* tmp = root->data;
	printf("姓名：%s， 年龄： %d\n", tmp->name, tmp->age);
	FrontTraverse(root->left);
	FrontTraverse(root->right);
}

void MidTraverse(const Tree root)		//中序遍历
{
	if (root == NULL) return;
	MidTraverse(root->left);
	Person* tmp = root->data;
	printf("姓名：%s， 年龄： %d\n", tmp->name, tmp->age);
	MidTraverse(root->right);
}

void BackTraverse(const Tree root)		//后序遍历
{
	if (root == NULL) return;
	BackTraverse(root->left);
	BackTraverse(root->right);
	Person* tmp = root->data;
	printf("姓名：%s， 年龄： %d\n", tmp->name, tmp->age);
}


void Traverse(const Tree root)		//中序遍历的非递归算法
{
	if (root == NULL)return;
	Tree tmp = root;
	Stack* myStack = Initial();
	if (myStack == NULL) return;
	Tree p;
	Person* my_Person;

	//当节点不为空，或者栈不为空时，进行循环
	//
	// 
	//先将当前节点入栈，然后打印它的左子树
	//如果它的左子树为空，则返回栈顶的节点并打印这个节点的数据
	//同时也说明此时  这个栈顶节点的   左子树已经访问结束，访问这个节点的右子树
	//
	//当tmp为空，并且栈也为空时，说明所有节点都遍历完毕
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
			printf("姓名：%s， 年龄： %d\n", my_Person->name, my_Person->age);
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