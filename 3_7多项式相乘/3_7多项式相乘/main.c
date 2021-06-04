#include"mul.h"
void test1()
{
	LinkNode* L1 = CreatLinkNode();
	LinkNode* L2 = CreatLinkNode();
	LinkNode* sum_Node = Mul(L1, L2); 
	double x;
	printf(" ‰»Î≤Œ ˝x£∫\n");
	scanf("%lf", &x);
	double sum = Sum(sum_Node, x);
	printf("%lf\n", sum);
	Destory(L1);
	Destory(L2);
	Destory(sum_Node);
}
int main()
{
	test1();
	return 0;
}