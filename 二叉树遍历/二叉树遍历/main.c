#include"Tree.h"
#include"Stack.h"
void test1()
{
	Person p[] =
	{
		{ "aaa", 19 },
		{ "bbb", 20 },
		{ "ccc", 21 },
		{ "ddd", 22 },
		{ "eee", 25 },
		{ "fff", 24 },
		{ "ggg", 28 },
		{ "hhh", 31 },
		{ "iii", 26 }
	};
	//�������Ľڵ�����
	Tree* root = malloc(sizeof(Tree) * 9);
	//��ÿ���ڵ����ռ�
	for (int i = 0; i < 9; i++)
	{
		root[i] = malloc(sizeof(struct TreeNode));
	}
	for (int i = 0; i < 9; i++)
	{
		root[i]->data = &p[i];
	}
	root[0]->left = root[1];
	root[0]->right = root[2];
	root[1]->left = root[3];
	root[1]->right = root[4];
	root[4]->left = NULL;
	root[4]->right = NULL;
	root[3]->right = root[6];
	root[3]->left = NULL;
	root[6]->right = root[8];
	root[6]->left = NULL;
	root[8]->left = NULL;
	root[8]->right = NULL;
	root[2]->left = root[5];
	root[2]->right = NULL;
	root[5]->left = NULL;
	root[5]->right = root[7];
	root[7]->left = NULL;
	root[7]->right = NULL;
	printf("���������\n");
	FrontTraverse(root[0]);
	printf("���������\n");
	MidTraverse(root[0]);
	printf("���������\n");
	BackTraverse(root[0]);
	printf("����ǵݹ������\n");
	Traverse(root[0]);
	Destory(root, 9);

}
int main()
{
	test1();
	return 0;
}