#pragma once
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//Status是函数的类型，其值是函数结果状态代码
typedef int ElemType;

//-----线性表的动态分配顺序存储结构-----
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量
typedef struct SqList {
	ElemType* elem;//存储空间基址
	int length;//当前长度
	int listsize;//当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList_Sq(SqList& L);
//操作结果：构造一个空的线性表L。
void DestroyList_Sq(SqList& L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。
Status ClearList_Sq(SqList& L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。
Status ListEmpty_Sq(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE,否则返回FALSE。
int ListLength_Sq(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素个数。
Status GetElem_Sq(SqList L, int i, ElemType& e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//操作结果：返回L中第1个满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType& pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱，否则操作失败，pre_e无定义。
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType& next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L的数据元素，且不是第一个，则用next_e返回他的后继，否则操作失败，pre_e无定义。
Status ListInsert_Sq(SqList& L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1。
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。
Status ListDelete_Sq(SqList& L, int i, ElemType& e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L)。
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。
Status ListTraverse_Sq(SqList L, void (*visit)(ElemType*));
//初始条件：线性表L已存在。
//操作结果：依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。
void MergeList_Sq(SqList La, SqList Lb, SqList& Lc);
//合并有序非递减顺序表。//这个操作不是课本中12个基本操作的一个。
//归并La,Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列。
void union_Sq(SqList& La, SqList Lb);
//将所有在线性表Lb中但不在La中的数据元素插入到La中
Status equal(ElemType c1, ElemType c2); /* 数据元素判定函数(相等关系) */