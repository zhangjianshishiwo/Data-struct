#pragma once
#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//Status是函数的类型，其值是函数结果状态代码
typedef char SElemType;

//-----栈的顺序存储表示-----
#define STACK_INIT_SIZE 100  //存储空间初始分配量
#define STACKINCREMENT 10    //存储空间分配增量
typedef struct SNode {
	SElemType data;//数据域
	struct SNode* next;//
}SNode,*LinkStack;
//-----基本操作的函数原型说明-----
Status InitStack(LinkStack& S);
//构造一个空栈S
Status DestroyStack(LinkStack& S);
//销毁栈S，S不再存在
Status ClearStack(LinkStack& S);
//把S置为空栈
Status StackEmpty(LinkStack S);
//若栈S为空栈，则返回TRUE,否则返回FALSE
int StackLength(LinkStack S);
//返回S的元素个数，即栈的长度
Status GetTop(LinkStack S, SElemType& e);
//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
Status Push(LinkStack& S, SElemType e);
//插入元素e为新的栈顶元素
Status Pop(LinkStack& S, SElemType& e);
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status StackTraverse(LinkStack S, void(*visit)(SElemType));
//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
Status StackTraverse_Top(LinkStack S, Status(*pfn_visit)(SElemType));
//从栈顶到栈底依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
