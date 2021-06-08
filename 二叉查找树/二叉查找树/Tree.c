#include"Tree.h"

Tree MakeEmpty(Tree tree)		//��ʼ��
{
	if (tree != NULL)
	{
		MakeEmpty(tree->left);
		MakeEmpty(tree->right);
		free(tree);
	}
	return NULL;
}

Tree find(int x, const Tree tree)		//����Ԫ��
{
	if (tree == NULL) return NULL;
	if (x < tree->data)
		return find(x, tree->left);
	else if (x > tree->data)
		return find(x, tree->right);
	else return tree;
}

Tree FindMin(const Tree tree)			//������Сֵ
{
	if (tree == NULL) return NULL;
	else if (tree->left == NULL) return tree;
	else return FindMin(tree->left);
}

Tree FindMax(const Tree tree)			//�������ֵ
{
	if (tree == NULL) return NULL;
	else if (tree->right == NULL) return tree;
	else return FindMin(tree->right);
}

//�ǵݹ�ʵ��
Tree FindMax1(const Tree tree)			//�������ֵ
{
	if (tree == NULL) return NULL;
	Tree tmp = tree;
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
	}
	return tmp;
}

Tree Insert(int x, Tree tree)			//����Ԫ��
{
	if (tree == NULL)
	{
		tree = malloc(sizeof(struct TreeNode));
		if (tree == NULL)
			return NULL;
		else
		{
			tree->data = x;
			tree->left = NULL;
			tree->right = NULL;
		}
	}
	else if (x < tree->data)
		tree->left = Insert(x, tree->left);
	else if (x > tree->data)
		tree->right = Insert(x, tree->right);
	return tree;
}
 
Tree Delete(int x, Tree tree)			//ɾ��Ԫ��
{
	if (tree == NULL) return NULL;
	Tree tmp;
	if (tree->data > x)
		tree->left = Delete(x, tree->left);
	else if (x > tree->data)
		tree->right = Delete(x, tree->right);
	else if (tree->left && tree->right)
	{
		tmp = FindMin(tree->right);
		tree->data = tmp->data;
		tree->right = Delete(tree->data, tree->right);
	}
	else
	{
		tmp = tree;
		if (tree->left == NULL)
			tree = tree->right;
		else if (tree->right == NULL)
			tree = tree->left;
		free(tmp);
	}
	return tree;
}

Tree CreatTree(Tree T)		//�����������д���һ��������
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T == NULL;
	else
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL) return;
		T->data = ch;
		CreatTree(T->left);		//����������
		CreatTree(T->right);		//����������
	}
	return T;
}
