#include"stack.h"
Stack CreatStack(int MaxSize)	//创建一个栈
{
	Stack  myStack = malloc(sizeof(struct StackRecord));
	if (!myStack) return NULL;
	myStack->data = malloc(sizeof(DataType) * MaxSize);
	if (!myStack->data)
	{
		free(myStack);
		return NULL;
	}
	myStack->size = 0;
	myStack->capacity = MaxSize;
	return myStack;
}

void Push(Stack S, DataType x)		//进栈
{
	if (S == NULL || x == NULL)return;
	S->data[S->size] = x;
	S->size++;
}

DataType TopAndPop(Stack S)		//返回栈顶,并出栈
{
	if (S == NULL)return NULL;
	if (S->size == 0) return NULL;
	S->size--;
	return S->data[S->size];
}

void Destory(Stack S)				//销毁栈
{
	if (S == NULL) return;
	free(S->data);
	free(S);
}



