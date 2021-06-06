#include"Tree.h"
#include"stack.h"
void test1()
{
	//创建节点
	TreeNode node1 = { 'A', NULL,  NULL, 0 };
	TreeNode node2 = { 'B', NULL,  NULL ,0 };
	TreeNode node3 = { 'C', NULL,  NULL ,0 };
	TreeNode node4 = { 'D', NULL,  NULL ,0 };
	TreeNode node5 = { 'E', NULL,  NULL ,0 };
	TreeNode node6 = { 'F', NULL,  NULL ,0 };
	TreeNode node7 = { 'G', NULL,  NULL ,0 };
	TreeNode node8 = { 'H', NULL,  NULL ,0 };
	//节点关系
	node1.Left = &node2;
	node1.Right = &node3;
	node2.Left = &node4;
	node4.Left = &node6;
	node4.Right = &node7;
	node3.Right = &node5;
	node5.Right = &node8;
	Non_Recursion(&node1);
}
int main()
{
	test1();
	return 0;
}
void Non_Recursion(const Tree root)		//非递归遍历
{
	Stack myStack = CreatStack(8);
	Push(myStack, root);
	while (myStack->size > 0)
	{
		Tree tmp = TopAndPop(myStack);
		if (tmp->flag == 0)
		{
			tmp->flag = 1;
			if (root->Right != NULL)
				Push(myStack, tmp->Right);
			if (root->Left != NULL)
				Push(myStack, tmp->Left);
			Push(myStack, tmp);
			continue;
		}
		if (tmp->flag == 1)
		{
			printf("%c\n", tmp->data);
			continue;
		}
	}
	Destory(myStack);
}
