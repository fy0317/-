#include"Stack.h"
#include"Tree.h"

Stack* Initial()				//初始化栈
{
	Stack* my_Stack = malloc(sizeof(Stack));
	if (my_Stack == NULL) return NULL;
	my_Stack->size = 0;
	my_Stack->capacity = MAXSIZE;
	my_Stack->data = malloc(sizeof(void*) * my_Stack->capacity);
	return my_Stack;
}

void PushStack(void* data, Stack* S)		//入栈
{
	if (data == NULL || S == NULL)return;
	if (S->size == S->capacity)
	{
		void** tmp = realloc(S->data, S->capacity * 2);
		if (tmp)
		{
			S->data = tmp;
			S->capacity *= 2;
			S->data[S->size] = data;
			S->size++;
		}
	}
	else
	{
		S->data[S->size] = data;
		S->size++;
	}
}

int IsEmpty_Stack(const Stack* S)
{
	return S->size == 0;
}

void* TopAndPop(Stack* S)			//返回栈顶元素并出栈
{
	if (S == NULL) return NULL;
	if (S->size == 0) return NULL;
	S->size--;
	return S->data[S->size];
}

void Destory_Stack(Stack* S)		//销毁栈
{
	if (S == NULL) return;
	free(S->data);
	free(S);
}