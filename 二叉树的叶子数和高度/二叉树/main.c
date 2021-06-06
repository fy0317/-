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
	int num = 0;
	calculate(&node1, &num);
	printf("叶子的数为 ：%d\n", num);
	int height = high(&node1);
	printf("树的高度：%d\n", height);
	printf("先序遍历：\n");
	Pre_Recursion(&node1);
	printf("\n");
	printf("中序遍历：\n");
	In_Recursion(&node1);
	printf("\n");
	printf("后序遍历：\n");
	Back_Recursion(&node1);
	printf("\n");
	Tree newTree = copyTree(&node1);
	printf("拷贝的树：\n");
	Pre_Recursion(newTree);
	printf("树的高度%d\n",high(newTree));
	FreeTree(newTree);
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

void calculate(const Tree root, int* p)			//统计叶子的数目
{
	if (root == NULL) return;
	if (root->Left == NULL && root->Right == NULL)
		(*p)++;
	calculate(root->Left, p);
	calculate(root->Right, p);
}
int high(const Tree root)						//二叉树的高度
{
	if (root == NULL)return 0;
	int left = high(root->Left);
	int right = high(root->Right);
	return 1 + (left > right ? left : right);
}

Tree copyTree(const Tree root)		//拷贝二叉树
{
	if (root == NULL) return NULL;
	Tree left = copyTree(root->Left);
	Tree right = copyTree(root->Right);
	Tree newTree = malloc(sizeof(TreeNode));
	if (newTree)
	{
		newTree->Left = left;
		newTree->Right = right;
		newTree->data = root->data;
	}
	return newTree;
}
void FreeTree(Tree root)			//释放二叉树,先释放左子树，再释放右子树
{
	if (root == NULL)return;
	FreeTree(root->Left);
	FreeTree(root->Right);
	printf("%c被释放了\n", root->data);
	free(root);
}