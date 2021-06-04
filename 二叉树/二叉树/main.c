#include"Tree.h"

void test1()
{
	//创建节点
	TreeNode node1 = { 'A', NULL,  NULL };
	TreeNode node2 = { 'B', NULL,  NULL };
	TreeNode node3 = { 'C', NULL,  NULL };
	TreeNode node4 = { 'D', NULL,  NULL };
	TreeNode node5 = { 'E', NULL,  NULL };
	TreeNode node6 = { 'F', NULL,  NULL };
	TreeNode node7 = { 'G', NULL,  NULL };
	TreeNode node8 = { 'H', NULL,  NULL };
	//节点关系
	node1.Left = &node2;
	node1.Right = &node3;
	node2.Left = &node4;
	node4.Left = &node6;
	node4.Right = &node7;
	node3.Right = &node5;
	node5.Right = &node8;
	printf("先序遍历：\n");
	Pre_Recursion(&node1);
	printf("\n");
	printf("中序遍历：\n");
	In_Recursion(&node1);
	printf("\n");
	printf("后序遍历：\n");
	Back_Recursion(&node1);
	printf("\n");
}
int main()
{
	test1();
	return 0;
}


void Pre_Recursion(const Tree root)		//先序遍历
{
	if (root == NULL) return;
	printf("%c ", root->data);
	Pre_Recursion(root->Left);
	Pre_Recursion(root->Right);

}


void In_Recursion(const Tree root)		//中序遍历
{
	if (root == NULL)  return;
	In_Recursion(root->Left);
	printf("%c ", root->data);
	In_Recursion(root->Right);
}

void Back_Recursion(const Tree root)		//后序遍历
{
	if (root == NULL) return;
	Back_Recursion(root->Left);
	Back_Recursion(root->Right);
	printf("%c ", root->data);
}